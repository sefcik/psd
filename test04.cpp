//
//  test03.cpp
//  
//
//  Created by Michal Sefcik on 26/05/16.
//
//

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <omp.h>

void calculate(long int n, double &out) {
    double average=0;
    long int i;
    #pragma omp parallel for reduction (+:average) private (i) schedule (guided,(int)1e7)
    for(i=0; i<n; i++) {
        double random = (double)rand() / RAND_MAX * 2*M_PI;
        average += sin(random) + 0.5;
    }
    average /= n;
    out = average;
}

int main(int argc, char** argv) {
    srand(time(NULL));
    long int n=1e5;
    int num_threads=4;
    if (argc > 1) {
        n=(long int)atof(argv[1]);
    }
    if (argc > 2) {
        num_threads=(int)atof(argv[2]);
    }
    
    printf("n = %ld\n",n);
    printf("num_threads = %d\n",num_threads);
    
    double out = 0;
    calculate(n,out);
    printf("Final = %f\n",out);
    
    return 0;
}
