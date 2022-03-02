
## Serial Monte Carlo

#### Gavin Wale

#### ME 471 Parallel Scientific Computing

### About
This program reads "N" as an input parameter and generates "N" random numbers. The numbers are checked on whether they fall into the unit circle or not. After all points are generated and checked, an estimation for the value of Pi is given and compared to the actual value.

### Analysis
As the number of trials "N" increases, so does the accuracy of the estimation. **The serial algorithm used the same seed for each run to limit variables in the search for optimal "N" value.** For all intensive purposes, this was the best way to graphically represent error with respect to test cases. For an N value of 1000, an the % error was found to be -.3% while an N value of 1,000,000 dropped the % error to a micro 0.002%. This proves the program is scalable and gets more accurate as the value of "N" increases (a key aspect of the Monte Carlo method). In the full report, a graph of accuracy vs trials from 1 to 1 billion is shown.