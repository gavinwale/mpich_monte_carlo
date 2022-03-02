## Parallelized Monte Carlo

#### Gavin Wale

#### ME 471 Parallel Scientific Computing

### About
This program reads and generates "N" random numbers based on a generated seed based on the unix timestamp of execution and the processor rank that is generating the numbers. Every value is checked to see if it lies within the unit circle. After every point is generated and checked, an estimation for Pi is calculated. Each processor in communication sends it's Pi value that is then averaged on Rank 0 where it is compared with the C math library's Pi value.

### Analysis
Through strong and weak scaling experiments, it can be seen that the program is highly efficient and scalable (see full report). Strong scaling experiments proved that an increase in computational power causes a near equivalent decrease in execution time. Weak scaling experiments proved that with a linear relationship between number of processors and "N" iterations, the execution time remained almost constant at approximately .10 seconds. Further analysis on these concepts can be found in the full report.