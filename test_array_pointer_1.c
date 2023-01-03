#include <stdio.h>
#include <stdlib.h>

// struct MyArray
// {
//     int *A;
//     int size;
//     int len;
// };


struct Array 
{
    int *ptr;
    int len;
    int size;
};

int main()
{
    // int *ptr;
    int G[] = {1,2,3,4,5,6,7};
    struct Array arr = {G,7,10};

    // int G[] = {1, 2, 3, 4, 5, 6, 7};

    // arr.ptr = G;

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr.ptr[i]);
    }

    return 0;
}