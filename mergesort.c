#include<stdio.h>
#include<time.h> // for clock() function

void merge(int a[], int low, int mid, int high);
void mergeSort(int a[], int low, int high);
void inputArray(int a[], int n);
void outputArray(int a[], int n);

void mergeSort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, c[high + 1];
    i = low;
    k = low;
    j = mid + 1;
    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while(i <= mid)
    {
        c[k++] = a[i++];
    }
    while(j <= high)
    {
        c[k++] = a[j++];
    }
    for(i = low; i <= high; i++)
    {
        a[i] = c[i];
    }
}

void inputArray(int a[], int n)
{
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void outputArray(int a[], int n)
{
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];

    inputArray(a, n); // Function to input elements

    clock_t start_time = clock();

    mergeSort(a, 0, n - 1); // Perform merge sort

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    outputArray(a, n); // Function to output sorted array

    printf("Merge sort took %.6f seconds to sort %d elements.\n", time_taken, n);

    return 0;
}
