from __future__ import print_function
import random
import timeit


# Storing elements of a matrix.

def matrix_formation(N):
    A = [[0]*N]*N
    for i in range(N):
        for j in range(N):
            A[i][j] = round(random.uniform(0.0000, 999.9999), 4)

    return A

# Matrix Multiplication.

def Multiplication(N):
    start = timeit.default_timer()
    A = matrix_formation(N)
    B = matrix_formation(N)

    # Multiplying matrix A and B and storing in array mult.
    C = [[0]*N]*N
    for x in range(N):
        for y in range(N):
            for z in range(N):
                C[x][y] += A[x][z] + B[z][y]

    stop = timeit.default_timer()
    elapsed_time = stop - start
    return C, elapsed_time

# Printing resultant matrix.

def print_matrix(N):

    C, elapsed_time = Multiplication(N)
    for x in range(N):
        for y in range(N):
            print(C[x][y], end=' ')
            if(y == N-1):
                print('\n')

    print("Execution Time (Matrix Multiplication only): ", elapsed_time)

start_total = timeit.default_timer()

print_matrix(32)

stop_total = timeit.default_timer()

# Time Elapsed
print("Execution Time (Total): ", stop_total - start_total, " s")
