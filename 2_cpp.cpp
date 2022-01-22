#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    
    auto begin = std::chrono::high_resolution_clock::now();
    int N = 512;
    unsigned int A[N][N], B[N][N], C[N][N];

    // Storing elements of first matrix.

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            A[i][j] = rand();
        }

    // Storing elements of second matrix.

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            B[i][j] = rand();
        }

    // Initializing elements of matrix mult to 0.
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            C[i][j] = 0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }

    // Displaying the multiplication of two matrix.

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
    {
        cout << " " << C[i][j];
        if(j == N-1)
            cout << endl;
    }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    return 0;
}