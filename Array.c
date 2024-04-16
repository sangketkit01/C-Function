#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Array.h"

void selectionSortInteger(int array[], int n);
void selectionSortString(char **array, int n);
void selectionSortDouble(double array[], int n);

void bubbleSortInteger(int array[], int n);
void bubbleSortString(char **array, int n);
void bubbleSortDouble(double array[], int n);

int linearSearchInteger(int array[], int n, int target);
int linearSearchString(char **array, int n, char *target);
int linearSearchStringIgnoreCase(char **array, int n, char *target);
int linearSearchDouble(double array[], int n, double target);

int binarySearchInteger(int array[], int n, int target);
int binarySearchString(char **array, int n, char *target);
int binarySearchStringIgnoreCase(char **array, int n, char *target);
int binarySearchDouble(double array[], int n, double target);

int main(void)
{
    // Try any function here
    //  To find size of an array , you need to do this : int size = sizeof(yourArray) / sizeof(yourArray[0]);

    return 0;
}

void selectionSortInteger(int array[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void selectionSortString(char **array, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j], arr[min_idx]) < 0)
            {
                min_idx = j;
            }
        }

        char *temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void selectionSortDouble(double array[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        double temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSortInteger(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortString(char **array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDouble(double array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearchInteger(int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int linearSearchString(char **array, int size, char *target)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(array[i], target) == 0)
        {
            return i;
        }
    }

    return -1;
}

int linearSearchStringIgnoreCase(char **array, int size, char *target)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(array[i], target))
        {
            return i;
        }
    }

    return -1;
}

int linearSearchDouble(double array[], int size, double target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int binarySearchInteger(int array[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchString(char **array, int n, char *target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], target);
        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchStringIgnoreCase(char **array, int size, char *target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cmp = strcasecmp(arr[mid], target);
        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchDouble(double array[], int n, double target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}