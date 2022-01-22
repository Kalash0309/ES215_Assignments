from __future__ import print_function
import random
import time
import timeit



def func(N):

    # Storing elements of first matrix.
    A = [[0]*N]*N
    for i in range(N):
        for j in range(N):
            A[i][j] = random.randint(1, 1000)

    # for x in range(N):
    #     for y in range(N):
    #         print(A[x][y], end=' ')
    #         if(y == N-1):
    #             print('\n')

    # Storing elements of second matrix.
    B = [[0]*N]*N
    for m in range(N):
        for n in range(N):
            B[m][n] = random.randint(1, 1000)

    # for x in range(N):
    #     for y in range(N):
    #         print(B[x][y], end=' ')
    #         if(y == N-1):
    #             print('\n')


    start = time.time()
    # Multiplying matrix a and b and storing in array mult.
    C = [[0]*N]*N
    for x in range(N):
        for y in range(N):
            for z in range(N):
                C[x][y] += A[x][z] + B[z][y]
            
    end = time.time()
    
    # Displaying the multiplication of two matrix.

    for x in range(N):
        for y in range(N):
            print(C[x][y], end=' ')
            if(y == N-1):
                print('\n')

    print(end - start)

func(32)


# print(timeit.timeit(stmt='pass', setup='pass', number=1))
