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


    // Printing Fibonacci series using loops
    unsigned int a = 1;
    unsigned int b = 1;
    int N = 100;
    for(int i = 0; i<N; i++)
        {
            if(i<=1)
            {
                cout << i+1 << " " << 1 << endl;
            }
            else
            {
                unsigned int temp = b;
                cout << i+1 << " " << a + b << endl;
                b = a + b;
                a = temp;
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