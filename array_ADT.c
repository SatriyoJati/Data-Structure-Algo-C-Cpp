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


void swap(int*,int*);

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
        printf("%d ", arr.A[i]);
    }
    printf("\n");
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

//Delete data to an array ADT
void Delete(struct Array *arr , int pos)
{
    if (pos > arr->size)
        printf("Out of range index array");
    else
    {
        for (int i = pos; i <= arr->len; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->len--;
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

//Search method Linear Search and Binary Search
//Linear Search 
int LinearSearch (struct Array arr, int key)
{
    /*
    In linear search the best case : O(1) when the key to be searched is in the index 1
    O(n) --> when the key to be searchd is in the last index
    */
    for (int i=0;i<arr.len;i++)
    {
        if (key == arr.A[i])
            return i;
    }
    return -1;
}

//Linear Search Improved 

int LinearSearchImproved (struct Array *arr, int key)
{
    for (int i=0;i<arr->len;i++)
    {
        if (key== arr->A[i])
        {
            swap(arr->A[i], arr->A[i+1]);
            return i;
        }
    }
    return -1;
}

//Linear Search Improved Move to Front

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y ;
    *y = temp;
}

int BinSearch(struct Array arr, int key)
{
    int l,mid,h;
    l=0;
    h=arr.len-1;

    while (l <= h)
    {
        //calculate mid
        mid = (l+h)/2;

        //if equal then found, return index
        if (key == arr.A[mid])
            return mid;
        //if key below mid point, update h
        else if (key < arr.A[mid])
        {
            h = mid - 1; //update h index 
        }
        //if key above mid point, update low
        else if (key > arr.A[mid])
        {
            l= mid + 1; //update low index
        }
    }

    return -1;//not found key in array
}

int RBinSearch(struct Array arr, int l, int h , int key)
{
    if (l <= h)
    { 
        int mid = (l+h)/2;
        if (key==arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            return RBinSearch(arr, l, mid-1,key);
        }
        else if(key > arr.A[mid])
        {
            return RBinSearch(arr, mid+1, h, key);
        }
    }
}


//Operation in array ADT
/*
1. Get (x)

    if ( index >= 0 && index < length)
        return A[index] O(1)
2. Set (x, index)
    if ( index >= 0 && index < length)
        return A[index] = x O(1)
3. Max (x)
    unsorted :

4. Min (x)
5. Sum (x)
6. Avg (x)
*/

int max(struct Array arr)
{   
    /*
    Time complexity O(n)

    */
    int max = arr.A[0];
    for (int i=1;i<arr.len;i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int min (struct Array arr)
{
    int min = arr.A[0];
    for(int i = 1;i<arr.len;i++)
    {
        if (arr.A[i] < min)
        min = arr.A[i];
    }
    return min;
}

int sum (struct Array arr)
{
    int Total = 0;
    for(int i=0 ; i < arr.len ; i++)
    {
        Total += arr.A[i];
    }
    return Total;
}

int avg (struct Array arr)
{
    int Total = 0;
    Total  = sum(arr);
    return Total/arr.len;
}

//Reversing Elements of array :
/*
    1. Reverse 
    2. Left Shift
    3. Left Rotate
    4. Right Shift
    5. Right rotate
*/

void Reverse(struct Array arr)
{
    for (int i = arr.len , int j = 0;i>=0; i--,j++)
    {
        B[j]
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
    // Delete(&arr, 3);
    Display(arr);
    printf("Searching number of %d\n", 15);
    printf("\nResult search in index : %d", LinearSearch(arr, 15));
    printf("\nResult using BinSearch in index: %d", BinSearch(arr, 15));
    printf("\nMax value of array : %d", max(arr));
    printf("\nMin value of array : %d", min(arr));
    printf("\nSum of array is : %d", sum(arr));
}