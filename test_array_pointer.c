#include <stdio.h>
#include <stdlib.h>

// struct MyArray
// {
//     int *A;
//     int size;
//     int len;
// };

int main()
{
    int* pArray[7];
    // struct MyArray arr;
    // int B[10];
    for(int i=0;i<7;i++)
    {
        printf("%d", pArray[i]);
    }
    // arr.A = (int*) malloc(10*sizeof(int));

    // struct MyArray arr = {{1,2,4,5,6,7,8},10,7};

    // for (int i=0;i< 10 ;i++)
    //     scanf("%d", &arr.A[i]);

    // for (int i=0; i < 10; i++)
    //     printf("%d ", arr.A[i]);

    return 0;
}