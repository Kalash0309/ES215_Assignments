#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;

//Function that returns the nth term of the fibonacci series

unsigned int term(int n, unsigned int memo[], int arr[])
{
    if(arr[n] == 1)
    {
        return memo[n];
    }
    else
    {
        unsigned int next_term = term(n-1, memo, arr) + term(n-2, memo, arr);
        arr[n] = 1;
        memo[n] = next_term;
        return next_term;
    }
}

int main()
{
    // Defining struct timespec ts that stores the time elapsed
    struct timespec ts;
    char buff[100];

    // Start Time
    timespec_get(&ts, TIME_UTC);
    unsigned int start = ts.tv_nsec;
    unsigned int start_sec = ts.tv_sec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    cout << "Start time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;


    // Printing Fibonacci series using Recursion and Memoization
    int N = 100;
    unsigned int memo[N];
    int arr[100] = {0};
    arr[0] = 1; arr[1] = 1;
    memo[0] = 1, memo[1] = 1;


    for(int i = 0; i<N; i++)
        {
            cout << i+1 << " " << term(i, memo, arr) << endl;
        }
    

    // End Time
    timespec_get(&ts, TIME_UTC);
    unsigned int end = ts.tv_nsec;
    unsigned int end_sec = ts.tv_sec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    
    // Total Time Elapsed
    cout << "Execution Time: " << end_sec - start_sec << " s " << end - start << " ns" << endl;


    return 0;
}