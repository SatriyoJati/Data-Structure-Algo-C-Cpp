#include <iostream>

using namespace std;

template <class T>
class Array
{
    private :
        T *A;
        T size;
        T len;

    public :

    Array()
    {
        size=10;
        A= new T[10];
        len = 0;
    }
    Array(T sz)
    {
        size=sz;
        len = 0;
        A= new T[size];

    }

    ~Array()
    {
        delete []A;
    }

    void Display();
    void Insert(int index, T x);
    T Delete(int index);

};


template <class T>
void Array<T>::Display()
{
    for (int i=0;i<len;i++)
    {
        cout<<A[i]<<" ";
    }
    cout << endl;
}

template <class T>
void Array<T>::Insert(int index, T x)
{
    if(index>= 0 && index <=len)
    {
        for(int i = len-1 ; i>=index; i--)
        {
            A[i+1] = A[i];
        }
        A[index] = x;
        len++;
    }
}

template <class T>
T Array<T>:: Delete(int index)
{
    int x=0;
    if(index>=0 && index< len)
    {
        x = A[index];
        for (int i=index;i<len-1;i++)
        {
            A[i] = A[i+1];
        }
        len--;
    }
    return x;
}

int main(int argc, const char * argv[])
{
    Array<int> arr(10);
    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,9);

    arr.Display();

    return 0;
}