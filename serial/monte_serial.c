/**
 * Estimation of Pi via Monte Carlo method
 *
 * Author: Gavin Wale
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

	// Returns a random double between 0 and 1

	double random_number() {
		return (double)rand() / (double)RAND_MAX;
	}

/**
 * Main function
 * Input: Number of trials (N)
 * Output: Estimation of Pi
 */

	int main(int argc, char* argv[]) {
		
		int N = atol(argv[1]);

		// Number of random values inside unit circle
		double countCi;

		printf("N = %d\n",N);

		double x,y;

		// Iterate through user input N times
		for (int i=0; i<N; i++) {
			
			// Random x and y values
			x = random_number();
			y = random_number();

			// Distance from origin
			double sum = x*x + y*y;

			// If inside circle, increment countCi
			if (sum <= 1) {
				countCi++;
			}
		}

		double pi = (4 * countCi) / (double)N;
		double err = ((pi - M_PI) / M_PI) * 100;

		printf("Estimation of pi: %lf\n",pi);
		printf("Err%: %lf\n",err);


	}
