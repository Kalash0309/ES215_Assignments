//C++ code to find the Fibonacci series upto 100 terms
//Speed up is calculated keeping program (1.)using recursion as the baseline
//Speed up of program x over program y = time taken by y/ time taken by x

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

//Function that returns the nth term of the fibonacci series

long long int term(int n)
{
    if(n<=1)
    {
        return 1;
    }
    else
    {
        return term(n-1) + term(n-2);
    }
}

int main()
{
    int N = 50;

    // Defining struct timespec ts that stores the time elapsed
    struct timespec ts;
    char buff[100];

    // Start Time
    timespec_get(&ts, TIME_UTC);
    unsigned int start = ts.tv_nsec;
    unsigned int start_sec = ts.tv_sec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    cout << "Start time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;


    // Code defining number of iterations i.e number of terms in fibonacci series
    for(int i = 0; i<N; i++)
        {
            cout << i+1 << " " << term(i) << endl;
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
