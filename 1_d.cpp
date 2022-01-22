#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <chrono>
using namespace std;

int main()
{
    // Defining struct timespec ts that stores the time elapsed
    struct timespec ts;
    char buff[100];

    // Start Time
    timespec_get(&ts, TIME_UTC);
    unsigned int start = ts.tv_nsec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    cout << "Current time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;
    cout << "Raw timespec.time_t: " << ts.tv_sec << endl;
    cout << "Raw timespec.tv_nsec: " << ts.tv_nsec << endl;


    // Printing Fibonacci series using Loops and Memoization
    int N = 100;
    unsigned int memo[100];
    int check[100] = {0};
    memo[0] = 1, memo[1] = 1;
    for(int i = 0; i<N; i++)
        {
            if(i == 0 || i == 1)
            {
                cout << i+1 << " " << memo[i] << endl;
            }
            else if(check[i] == 1)
            {
                cout << i+1 << " " << memo[i] << endl;
            }
            else
            {
                memo[i] = memo[i-1] + memo[i-2];
                check[i] = 1;
                cout << i+1 << " " << memo[i] << endl;
                
            }
        }
    
    
    // End Time
    timespec_get(&ts, TIME_UTC);
    unsigned int end = ts.tv_nsec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    cout << "Current time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;
    cout << "Raw timespec.time_t: " << ts.tv_sec << endl;
    cout << "Raw timespec.tv_nsec: " << ts.tv_nsec << endl;

    
    // Total Time Elapsed
    cout << "Time Elapsed: " << end - start << " nsec" << endl;


    return 0;
}