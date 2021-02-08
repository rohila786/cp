// C++ program for building Heap from Array
#include <stdio.h>
int size = 0;
void swap(int *a, int *b)  
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int max_element = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[max_element])
            max_element = l;
        if (r < size && array[r] > array[max_element])
            max_element = r;
        if (max_element != i)
        {
            swap(&array[i], &array[max_element]);
            heapify(array, size, max_element);
        }
    }
}

void insertion_into_array(int array[], int num)
{
    if (size == 0)
    {
        array[0] = num;
        size += 1;
    }
    else
    {
        array[size] = num;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
    }
}

void printMaxArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
        printf("\n");
}
int main()
{  printf("************* MAX HEAP BUILDER *************** \n\n");
    int n;
    printf("Enter number of insertions: ");
    scanf("%d", &n);
    int array[n], i, j, k;

    for (i = 0; i < n; i++)
    {
        printf("enter the %d element : ", i + 1);
        scanf("%d", &j);
        insertion_into_array(array, j);
        printf("Max Heap array is : ");
        printMaxArray(array, size);
    }
}
