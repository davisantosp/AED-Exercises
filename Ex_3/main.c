#include <stdio.h>
#include <stdlib.h>

long long countSwaps = 0;

typedef struct
{
    int id;
    int priority;
} Patient;

Patient newPatient(int id, int priority);
void quickSort(Patient *array, int low, int high, int size);
int partition(Patient *array, int low, int high, int size);
int priority(Patient patient1, Patient patient2);
void threeMedianPivot(Patient* array, int low, int high);
void swap(Patient *n1, Patient *n2);
void printIdArray(Patient *array, int size);

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
    quickSort(patientArray, 0, n-1, n);
    printIdArray(patientArray, n);
    printf("Swaps: %lld", countSwaps);
    return 0;
}

Patient newPatient(int id, int priority){
    Patient patient = {id, priority};
    return patient;
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
    threeMedianPivot(array, low, high);
    Patient pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high - 1; j++)
    {
        if (priority(j[array], pivot) && i != j)
            swap(&array[++i], &array[j]);
    }
    swap(&array[i++], &array[high]);
    return i;
}

void threeMedianPivot(Patient* array, int low, int high){
    int mid = low + (high - low)/2;

    if (priority(array[mid], array[low])) swap(&array[mid], &array[low]);
    if (priority(array[high], array[low])) swap(&array[high], &array[low]);
    if (priority(array[high], array[mid])) swap(&array[high], &array[mid]);

    swap(&array[mid], &array[high]);
}

int priority(Patient patient1, Patient patient2){
    if (patient1.priority < patient2.priority) return 1;
    else if (patient1.priority == patient2.priority && patient1.id > patient2.id) return 1;
    return 0;
}

void swap(Patient *n1, Patient *n2)
{
    Patient temp = *n1;
    *n1 = *n2;
    *n2 = temp;
    countSwaps++;
}

void printIdArray(Patient *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i].id);
    }
}
