/**
 * Estimation of Pi via Monte Carlo method
 *
 * Author: Gavin Wale
 */

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

/**
 * Returns a random number between 0 and 1
 * Seed: time(0) + irank
 * 
 * @return double 
 */

double random_number() {
    return (double)rand() / (double)RAND_MAX;
}


/**
 * Main function. Reads a command line argument of iterations. Separates these
 * iterations among the number of available processes and forms an estimation of
 * PI via the Monte Carlo method.
 * 
 * @param argc 
 * @param argv 
 * @return long int 
 */
long int main(int argc, char* argv[]) {

    int nproc, irank = 0;


    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Check communicator size
    MPI_Comm_size(MPI_COMM_WORLD,&nproc);

    // Check rank number
    MPI_Comm_rank(MPI_COMM_WORLD,&irank);

    // Number of iterations read through first command line argument
    long int N = atol(argv[1]);

    if (irank==0) {
	printf("N = %ld\n",N);
    }

    // Number of iterations for each processor, locally
    long N_loc = N/nproc;

    // Each processor will have a unique seed
    srand(time(0) + irank);

    // Start initial timer
    double startTime = MPI_Wtime();

    // Variables for calculations
    double x, y, localSum, countCi;

    // Iterate N/4 times times
    for (int i=0; i<N_loc; i++) {

        // Generate a random number for x and y from function
        x = random_number();
        y = random_number();

        // Calculate the localSum of squares
        localSum = x*x + y*y;

        // Check if the sum falls within the limit
        if (localSum <= 1) {
            countCi++; // Increment countCi
        }
    }

    // Estimate pi locally
    double piLoc = (4 * countCi) / (double)N_loc;

    // Variable to store reduction in
    double globalSum;

    // Reducing all local pi's into a globalSum
    MPI_Reduce(&piLoc, &globalSum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Stops the timer
    double endTime = MPI_Wtime();

    // Calculation of globalPi
    double globalPi = globalSum / nproc;

    // Stores the time the computation took
    double totalTime = endTime - startTime;

    // Variable to store the sum of all times
    double timeSum;

    // Reduction of all local times
    MPI_Reduce(&totalTime, &timeSum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Calculation of average time
    double avgTime = timeSum / nproc;

    // Calculation of local/global error
    double errorLocal = ((piLoc - M_PI) / M_PI) * 100;
    double errorGlobal = ((globalPi - M_PI) / M_PI) * 100;

    // Print process, local pi estimation, and local error
    printf("Process %i estimation/error of pi: %lf , %lf%\n",irank,piLoc,errorLocal);

    // Root rank prints the global sum, overall error, and execution time
    if (irank==0) {

        printf("Global estimation of Pi: %lf\n",globalPi);
        printf("Global error: %lf%\n",errorGlobal);
        printf("Parallel execution time (rank 0): %lf\n",totalTime);
	printf("Average parallel execution time: %lf\n",avgTime);

    }

    // Close MPI interface
    MPI_Finalize();





}
