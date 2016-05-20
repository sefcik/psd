//
//  test01.cpp
//  
//
//  Created by Michal Sefcik on 20/05/16.
//
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calculate(long int n) {
    double average=0;
    for(long int i=0; i<n; i++) {
        double random = (double)rand() / RAND_MAX * 2*M_PI;
        average += sin(random) + 0.5;
    }
    average /= n;
    printf("Average = %f\n",average);
}

int main() {
    srand(time(NULL));
    calculate(1e9);
    return 0;
}