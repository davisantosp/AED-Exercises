// Davi dos Santos Pinto RA 185623 AED2-N
#include <stdio.h>
#include <stdlib.h>

// Global count for swaps
long long countSwaps = 0;

typedef struct
{
    int id;
    int priority;
} Patient;

Patient newPatient(int id, int priority);
void quickSort(Patient *array, int low, int high);
int partition(Patient *array, int low, int high);
int priority(Patient patient1, Patient patient2);
void threeMedianPivot(Patient *array, int low, int high);
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
    quickSort(patientArray, 0, n - 1);
    printIdArray(patientArray, n);
    printf("Swaps: %lld", countSwaps);
    return 0;
}

Patient newPatient(int id, int priority)
{
    Patient patient = {id, priority};
    return patient;
}

void quickSort(Patient *array, int low, int high)
{
    if (low < high)
    {
        int mid = partition(array, low, high);
        quickSort(array, low, mid - 1);
        quickSort(array, mid + 1, high);
    }
}

int partition(Patient *array, int low, int high)
{
    threeMedianPivot(array, low, high);
    Patient pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (priority(array[j], pivot))
            swap(&array[++i], &array[j]);
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

// Adjust the median of three to be in the last position
void threeMedianPivot(Patient *array, int low, int high)
{
    int mid = low + (high - low) / 2;

    if (priority(array[mid], array[low]))
        swap(&array[mid], &array[low]);
    if (priority(array[high], array[low]))
        swap(&array[high], &array[low]);
    if (priority(array[high], array[mid]))
        swap(&array[high], &array[mid]);

    swap(&array[mid], &array[high]);
}

// Compare the priorities and IDs according to the problem's demands
int priority(Patient patient1, Patient patient2)
{
    if (patient1.priority > patient2.priority)
        return 1;
    if (patient1.priority < patient2.priority)
        return 0;
    if (patient1.id < patient2.id)
        return 1;
    return 0;
}

void swap(Patient *n1, Patient *n2)
{
    // No swap if equals or same register in priority and ID
    if (n1 == n2)
        return;
    if (n1->priority == n2->priority && n1->id == n2->id)
        return;
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
