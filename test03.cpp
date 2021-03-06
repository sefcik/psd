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
#include <thread>

double final = 0;
std::mutex final_mutex;

void calculate(long int n, double &out) {
    double average=0;
    for(long int i=0; i<n; i++) {
        double random = (double)rand() / RAND_MAX * 2*M_PI;
        average += sin(random) + 0.5;
    }
    average /= n;
    {
        std::lock_guard<std::mutex> lock(final_mutex);
        printf("Average = %f\n",average);
        out += average;
    }
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
    
    n /= num_threads;
    std::thread* t = new std::thread[num_threads];
    //Launch a thread
    for(int i=0; i<num_threads; i++) {
        t[i] = std::thread(calculate,n,std::ref(final));
    }
    
    //Join the thread with the main thread
    for(int i=0; i<num_threads; i++) {
        t[i].join();
    }
    final /= num_threads;
    printf("Final average = %f\n",final);
    
    delete[] t;
    return 0;
}
