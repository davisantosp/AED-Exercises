#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int priority;
} Patient;

Patient newPatient(int id, int priority);
void quickSort(Patient *array, int low, int high, int size);
int partition(Patient *array, int low, int high, int size);
int pivotChoice(Patient *array, int size);
void swap(Patient *n1, Patient *n2);
void printArray(Patient *array, int size);

int main()
{
    int n;
    scanf("%d", &n);
    Patient *patientArray = malloc(sizeof(Patient) * n);
    for (int i = 0; i < n; i++)
    {
        int id, priority;
        scanf("%d %d", &id, &priority);
        Patient patient = newPatient(id, priority);

        patientArray[i] = patient;
    }

    printArray(patientArray, n);
    return 0;
}

void quickSort(Patient *array, int low, int high, int size)
{
    if (low < high)
    {
        int mid = partition(array, low, high, size);
        quickSort(array, low, mid - 1, size);
        quickSort(array, mid + 1, high, size);
    }
}
int partition(Patient *array, int low, int high, int size)
{
    Patient pivot = array[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (array[j].priority >= pivot.priority)
        {
            swap(&array[++i], &array[j]);
        }
    }
    swap(&array[++i], &array[high]);
    return i;
}

// int pivotChoice(int *array, int size)
// {
//     int n1 = array[0], n2 = array[size / 2], n3 = array[size - 1];
//     if (n1 > n2 && n3 > n2)
//         return n3 > n1 ? n1 : n3;
//     if (n2 > n3 && n1 > n3)
//         return n1 > n2 ? n2 : n1;
//     if (n3 > n1 && n2 > n1)
//         return n2 > n3 ? n3 : n2;
// }

void swap(Patient *n1, Patient *n2)
{
    Patient temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void printIdArray(Patient *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i].id);
    }
    printf("\n");
}
