//List operation of Array ADT

/*
Operations :
1. Display()
2. Add (x) / Append(x)
3. Insert (x)
4. Delete(x)
5. Search(x)
6. Get(x)
7. Set(x)
8. Max(x)/Min(x)
9. Reverse()
10. Shift/Rotate()
*/

/*
Ways to create array 
1. int A[10];
2. int * A ;
3. A = new int[size] 
*/

/*
Data in array :
size and len
*/


#include <stdio.h>
#include <stdlib.h>

struct Array{
    int * A;
    int size;
    int len;
};


//Displaying an array data structure
void Display(struct Array arr)
{
    int i;

    printf("\nElements data:\n");
    for (i = 0; i < arr.len ; i++){
        printf("%d", arr.A[i]);
    }
}

//Adding data to an array ADT
void Add(struct Array *arr, int x)
{   
    //Check whether length no more than size (there is still room)
    if (arr->len < arr->size)
    {
        //add item at the end of array ADT
        arr->A[arr->len] = x;

        //update length
        arr->len++;
    }
}

//Inserting data to an array ADT
void Insert(struct Array *arr, int x, int pos)
{
    //check whether pos not more than size
    if (pos > arr->size)
    {
        printf("Index array more than expected");
    }
    else
    {
        //Shift the pos to right
        for (int i = arr->len; i >= pos; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        //insert new item to pos
        arr->A[pos] = x;
        //update length
        arr->len++;
    }
}

int main()
{
    struct Array arr;
    printf("Enter size of an array :");
    scanf("%d", &arr.size);
    int n,i;

    //Dynamic Array for C lan using malloc and cast
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.len =0;

    printf("Enter how many numbers :\n");
    scanf("%d", &n);

    printf("Enter all element : \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.len = n ;

    Display(arr);

}
