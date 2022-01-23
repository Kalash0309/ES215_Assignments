//C++ code to find the Matrix Multiplication of two matrices with floating point numbers.
//Speed up is calculated keeping program (1.)using recursion as the baseline
//Speed up of program x over program y = time taken by y/ time taken by x



#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

int main()
{
    // Creating random double values
    double lower_bound = 0;
    double upper_bound = 1000;

    uniform_real_distribution<double> unif(lower_bound, upper_bound);
    default_random_engine re;


    // Initialization
    int N = 256; //{32, 64, 128, 256}
    float A[N][N], B[N][N], C[N][N];

    // Assigning elements to the first matrix A

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            A[i][j] = unif(re);
        }

    // Assigning elements to the second matrix B

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            B[i][j] = unif(re);
        }

    // Initializing the elements of matrix C to 0
    
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            C[i][j] = 0;
        }

    // Defining struct timespec ts that stores the time elapsed
    struct timespec ts;
    char buff[100];

    // Start Time
    timespec_get(&ts, TIME_UTC);
    unsigned int start = ts.tv_nsec;
    unsigned int start_sec = ts.tv_sec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    cout << "Start time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;


    // Multiplying matrix A and B and storing in array C.
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }

    
    // End Time
    timespec_get(&ts, TIME_UTC);
    unsigned int end = ts.tv_nsec;
    unsigned int end_sec = ts.tv_sec;

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    
    // Displaying the multiplication of two matrix.

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
    {
        cout << setprecision(10) << " " << C[i][j];
        if(j == N-1)
            cout << endl;
    }
    }

    // Printing the end time for multiplication (Only meat portion of the code)
    cout << "End time: "<< buff << "." << ts.tv_nsec << " UTC" << endl;

    // Total Time Elapsed
    cout << "Execution Time (Matrix Multiplication): " << end_sec - start_sec << " s " << end - start << " ns" << endl;

    return 0;
}