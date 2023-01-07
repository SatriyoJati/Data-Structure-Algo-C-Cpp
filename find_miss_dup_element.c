#include <stdio.h>
#include <stdlib.h>

void FindMissNumber(int * arr)
{
    int diff = arr[0];
    for (int i = 1 ; i < 10;i++)
    {
        if (arr[i]-i != diff)
        {
            printf("the missing number is : %d\n", arr[i]-1);
            break;
        } 
    }
}

void FindMultiMissNumber(int *arr)
{
    int diff = arr[0];
    for(int i = 1; i < 10; i++)
    {
        if (arr[i] - i != diff)
        {
            while(diff < arr[i]-i)
            {
                printf("missing numb : %d\n", diff+i);
                diff++;
            }
        }
    }
}

int FindMax(int *A)
{
    int max = A[0];

    for (int i = 0;i < 10 ; i++)
    {
        if(A[i]> max)
        {
            max  = A[i];
        }
    }
    return max;
}

int FindMin(int * A)
{
    int min =A[0];
    for(int i=0; i < 10 ;i++)
    {
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

void FindMissHash(int * A)
{
    int maxVal = FindMax(A);
    int minVal = FindMin(A);
    int i;
    int * buff = (int *) malloc(maxVal*sizeof(int));
    for (i =0; i<maxVal+1;i++)
    {
        buff[i] = 0;
    }

    for (int i=0;i<10;i++)
    {
        buff[A[i]]++;
    }

    for (int i = minVal;i < maxVal+1 ; i++)
    {
        if (buff[i] == 0)
        {
            printf("missing number using Hash : %d\n", i);
        }
    }
}

int * FindDuplicate(int * A)
{
    int lastDuplicate, i,j;
    lastDuplicate=i=j=0;
    int *buff = (int*) malloc(12*sizeof(int));
    for (i=1; i < 10; i++)
    {
        if(A[i-1] == A[i])
        {
            if (lastDuplicate != A[i])
            {
                printf("duplicate found = %d\n", A[i]);
                lastDuplicate = A[i];
                buff[j++];
            }
        }
    }
    return buff;
}

void FindDuplicateCount(int * A )
{
    int lastDuplicate, i, j,k;
    lastDuplicate = i = j =k=0;
    int *buff = (int *)malloc(12 * sizeof(int));
    for (i = 1; i < 10; i++)
    {
        if (A[i - 1] == A[i])
        {
            j=i+1;
            while(A[j]==A[i])j++;
            printf("Duplicate %d occurs %d times\n", A[i] , (j- i));
            buff[k++] = A[i];
            i= j-1;
        }
    }
}

void FindDuplicateUnsorted(int *arr)
{
    int i,j;
    for(i = 0; i< 10 ; i++)
    {
        for(j=i+1 ; j<10;j++)
        {
            if (arr[j] == arr[i] && arr[j] !=  -1)
            {
                printf("Find duplicate unsorted %d \n", arr[j]);
                arr[j] = -1;
            }
        }
    }
}

int main()
{
    int A[] = {1,2,3,4,5,6,8,9,10,11,12};
    int B[] = {6,7,8,9,13,14,15,16,19,20};
    int C[] = {0,1,2,2,3,4,5,5,5,6,7,8,9};
    int D[] = {3,2,4,1,5,4,2,3,8,9,1,0};
    int sum,s = 0;

    for(int i = 0 ; i < 11; i++)
    {
        sum = sum + A[i];
    }

    s = A[10]*(A[10]+1)/2;

    printf("missing number is :  %d\n", s-sum);
    FindMissNumber(A);
    FindMultiMissNumber(B);
    FindMissHash(B);
    FindDuplicate(C);
    FindDuplicateCount(C);
    FindDuplicateUnsorted(D);
    return 0;
}