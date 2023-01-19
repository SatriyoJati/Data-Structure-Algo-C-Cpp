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
    int *A;
    int size;
    int len;
};


//Displaying an array data structure
void Display(struct Array arr)
{
    int i;

    printf("\nElements data:\n");
    // printf("%d", *x);
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
            swap(&arr->A[i], &arr->A[i+1]);
            return i;
        }
    }
    return -1;
}

//Linear Search Improved Move to Front
void swap(int *x, int *y)
{
    int temp = 0;
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

void Reverse(struct Array *arr)
{
    int *B;
    B = (int *) malloc(arr->len*sizeof(int));

    for (int i = arr->len-1 ,j = 0; i>=0; i--, j++)
    {
        B[j] = arr->A[i];
    }

    for (int i = 0 ; i < arr->len; i++)
    {
        arr->A[i] = B[i];
    }
}

void ReverseV2(struct Array *arr)
{
    int i,j;
    for(i=0, j=arr->len-1 ; i<j ;i++,j--)
    {   
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x)
{
    int i=arr->len-1;
    if (arr->len == arr->size)
        return;
    while (i>=0 && arr->A[i] > x)
    {
        arr->A[i+1]= arr-> A[i];
        i--;
    }

    arr->A[i+1]=x;
    arr->len++;
}

int isSorted(struct Array arr)
{
    int i = 0;
    for(i=0 ;i < arr.len-1 ; i++)
    {
        if (arr.A[i] > arr.A[i+1])
            return -1;
    }

    return 0;
}

void RearrangeNegElement(struct Array *arr)
{
    int i,j=0;
    i=0;
    j = arr->len - 1;

    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j) swap(&arr->A[i] , &arr->A[j]);
    }
}

struct Array* MergeArray(struct Array* arr1 , struct Array * arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    //Copying array1 to array2 until one of index pointer greater than it's length
    while (i < arr1->len && j < arr2->len )
    {
        //printf("%d", arr1->A[0]);
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else 
            arr3->A[k++] = arr2->A[j++];
    }

    //Copy remaining element of longer array from array1
    for( ;i< arr1->len ;i++ )
        arr3->A[k++]=arr1->A[i++];

    //Copy remaining element of longer array from array2
    for(;j < arr2->len ;j++ )
        arr3->A[k++] = arr2->A[j++];

    arr3->len = arr1->len + arr2->len;
    arr3->size = arr1->size + arr2->size;

    return arr3; //return pointer new array
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // Copying array1 to array2 until one of index pointer greater than it's length
    while (i < arr1->len && j < arr2->len)
    {
        // printf("%d", arr1->A[0]);
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2 -> A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
    }

    // Copy remaining element of longer array from array1
    for (; i < arr1->len; i++)
        arr3->A[k++] = arr1->A[i++];

    // Copy remaining element of longer array from array2
    for (; j < arr2->len; j++)
        arr3->A[k++] = arr2->A[j++];

    arr3->len = k;
    arr3->size = 10;

    return arr3; // return pointer new array
}

struct Array *Intersection(struct Array  *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // Copying array1 to array2 until one of index pointer greater than it's length
    while (i < arr1->len && j < arr2->len)
    {
        // printf("%d", arr1->A[0]);
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
    }

    arr3->len = k;
    arr3->size = 10;

    return arr3; // return pointer new array
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // Copying array1 to array2 until one of index pointer greater than it's length
    while (i < arr1->len && j < arr2->len)
    {
        // printf("%d", arr1->A[0]);
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            k++;j++;
            i++;
        }
    }

    // Copy remaining element of longer array from array1
    for (; i < arr1->len; i++)
        arr3->A[k++] = arr1->A[i++];

    arr3->len = k;
    arr3->size = 10;

    return arr3; // return pointer new array
}

int main()
{
    int ch;

    int index, x;
    int key;
    struct Array arr;
    scanf("%d" , &arr.size);
    arr.A = (int*) malloc(arr.size*sizeof(int));
    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("enter your choice?");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value and index:\n");
            scanf("%d%d", &x, &index);
            Insert(&arr, x, index);
            break;
        case 2:
            printf("Delete value at index :?\n");
            scanf("%d", &index);
            Delete(&arr, index);
            break;

        case 3:
            printf("Search value in array, Enter the Key:\n");
            scanf("%d", &key);
            printf("Found key %d at index %d", key, BinSearch(arr, key));
            break;

        case 4:
            printf("Sum of array:\n");
            printf("Sum of array : %d", sum(arr));
            break;

        case 5:
            printf("Displaying on Array: \n");
            Display(arr);
            break;
        }
    } while (ch < 6);
    return 0;
}