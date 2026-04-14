// Davi dos Santos Pinto RA 185623 AED2-N
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *array, int start, int end, long long *count);
void merge(int *array, int start, int mid, int end, long long *count);
void printArray(int *array, int size);

int main()
{
    int n;
    scanf("%d", &n);

    int *array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    long long count = 0;
    mergeSort(array, 0, n - 1, &count);

    printf("%lld\n", count);
    printArray(array, n);
    free(array);
    return 0;
}

void mergeSort(int *array, int start, int end, long long *count)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(array, start, mid, count);
        mergeSort(array, mid + 1, end, count);
        merge(array, start, mid, end, count);
    }
}

void merge(int *array, int start, int mid, int end, long long *count)
{
    // Define the size of the subarrays
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int arrayL[n1], arrayR[n2];

    // Copy from the main array into the subarrays
    int i = 0, j = 0;
    for (; i < n1; i++)
        arrayL[i] = array[start + i];

    for (; j < n2; j++)
        arrayR[j] = array[mid + j + 1];

    // Count the significant/drastic falls, iterating from the sorted left array, and comparing to the values on the right array.
    // Because they are sorted, the comparison never goes back and can be done in a linear way, O(n)
    // This can be seen since an element Nx from arrayL that is greater than a Ny from arrayR
    // Implies that Nx+1 element from arrayL is greater then Ny and Nx is also greater then Ny-1 element from arrayR,
    // Summarizing, if an element from one array is greater than one in the other array, then it is necessarily greater then the previous ones.
    int temp = 0;
    for (int i = 0; i < n1; i++)
    {
        while (temp < n2 && arrayL[i] > 2 * arrayR[temp])
            temp++;
        *count += temp;
    }

    i = 0;
    j = 0;
    int k = start;
    // do the merge logic comparing the elements and putting the lowest one first
    while (i < n1 && j < n2)
    {
        if (arrayL[i] <= arrayR[j])
        {
            array[k] = arrayL[i];
            k++;
            i++;
        }
        else
        {
            array[k] = arrayR[j];
            k++;
            j++;
        }
    }

    // if there are remaining elements int the subarrays, fill the main array back with it
    while (i < n1)
    {
        array[k] = arrayL[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = arrayR[j];
        j++;
        k++;
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
