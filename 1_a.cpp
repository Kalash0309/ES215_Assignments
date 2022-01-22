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
    int N = 30;

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

    // Code defining number of iterations i.e number of terms in fibonacci series
    for(int i = 0; i<N; i++)
        {
            cout << i+1 << " " << term(i) << endl;
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
