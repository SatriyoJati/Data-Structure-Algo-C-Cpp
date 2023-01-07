#include <stdio.h>
#include <stdlib.h>

int FindMax(int *A)
{
    int max = A[0];

    for (int i = 0; i < 10; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void FindDupUnsortedHash(int *arr)
{
    int i, j, maxVal;
    maxVal = FindMax(arr);
    int *B = (int *)malloc(maxVal * sizeof(int));

    for (j = 0; j < maxVal + 1; j++)
    {
        B[j] = 0;
    }

    // int D[] = {3,2,4,1,5,4,2,3,8,9,1,0,6};

    for (i = 0; i < 10; i++)
    {
        (B[arr[i]])++;
    }

    for (i = 0; i < maxVal; i++)
    {
        printf("%d", B[i]);
    }
    printf("\n");

    for (i = 0; i < maxVal + 1; i++)
    {
        if (B[i] != 0 && B[i] > 1)
        {
            printf("Found duplicate of %d using HashMap\n", i);
        }
    }
}

int main()
{

    int D[] = {3, 2, 4, 1, 5, 4, 2, 3, 8, 9, 1, 0, 6};

    FindDupUnsortedHash(D);

    return 0;
}