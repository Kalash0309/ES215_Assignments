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
    unsigned int start_sec = ts.tv_sec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    cout << "Start time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;


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
    unsigned int end_sec = ts.tv_sec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    
    // Total Time Elapsed
    cout << "Execution Time: " << end_sec - start_sec << " s " << end - start << " ns" << endl;


    return 0;
}