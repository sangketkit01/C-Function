#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "Array.h"

#define size(arr) (sizeof(arr) / sizeof((arr)[0]))

char *toString;

void selectionSortInteger(int array[], int n);
void selectionSortDouble(double array[], int n);
void selectionSortString(char **array, int n);

void bubbleSortInteger(int array[], int n);
void bubbleSortDouble(double array[], int n);
void bubbleSortString(char **array, int n);

int linearSearchInteger(int array[], int n, int target);
int linearSearchDouble(double array[], int n, double target);
int linearSearchString(char **array, int n, char *target);
int linearSearchStringIgnoreCase(char **array, int n, char *target);

int binarySearchInteger(int array[], int n, int target);
int binarySearchDouble(double array[], int n, double target);
int binarySearchString(char **array, int n, char *target);
int binarySearchStringIgnoreCase(char **array, int n, char *target);

char *toStringInteger(int array[], int n);
char *toStringDouble(double array[], int n);
char *toStringStr(char *array[], int n);

bool equalInteger(int array1[],int n1,int array2[],int n2);
bool equalDouble(double array1[],int n1,double array2[],int n2);
bool equalString(char* array1[],int n1,char* array2[] ,int n2);
bool equalStringIgnoreCase(char* array1[],int n1,char* array2[],int n2);

void cleanMalloc();

int main(void)
{
    // Try any function here
    //  To find size of an array , you need to do this : int size = size(your_array);

    cleanMalloc();
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
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
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
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }

        double temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
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
            if (strcmp(array[j], array[min_idx]) < 0)
            {
                min_idx = j;
            }
        }

        char *temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}


void bubbleSortInteger(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
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
            if (array[j] > array[j + 1])
            {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
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
            if (strcmp(array[j], array[j + 1]) > 0)
            {
                char *temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
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


int binarySearchInteger(int array[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == target)
        {
            return mid;
        }
        else if (array[mid] < target)
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
        if (array[mid] == target)
        {
            return mid;
        }
        else if (array[mid] < target)
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
        int cmp = strcmp(array[mid], target);
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

int binarySearchStringIgnoreCase(char **array, int n, char *target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cmp = strcasecmp(array[mid], target);
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


char *toStringInteger(int array[], int n)
{
    int length = 2;
    for (int i = 0; i < n; i++)
    {
        if (array[i] < 10)
        {
            length += 2;
        }
        else
        {
            length += 2 + (int)(log10(array[i])) + 1;
        }
    }

    toString = malloc(length);
    if (toString == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    toString[index++] = '[';

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            toString[index++] = ',';
        }

        if (array[i] < 10)
        {
            toString[index++] = array[i] + '0';
        }
        else
        {
            char temp[20];
            sprintf(temp, "%d", array[i]);
            int j = 0;
            while (temp[j] != '\0')
            {
                toString[index++] = temp[j++];
            }
        }
    }

    toString[index++] = ']';
    toString[index] = '\0';

    return toString;
}

char *toStringDouble(double array[], int n)
{
    int length = 4;
    for (int i = 0; i < n; i++)
    {
        char temp[40];
        snprintf(temp, sizeof(temp), "%.*lf", (int)(log10(array[i])) + 1, array[i]);
        int j = 0;
        while (temp[j] != '\0')
        {
            length++;
            j++;
        }
    }

    toString = malloc(length);
    if (toString == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    toString[index++] = '[';

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            toString[index++] = ',';
        }

        char temp[40];
        snprintf(temp, sizeof(temp), "%.*lf", (int)(log10(array[i])) + 1, array[i]);
        int j = 0;
        while (temp[j] != '\0')
        {
            toString[index++] = temp[j++];
        }
    }

    toString[index++] = ']';
    toString[index] = '\0';

    return toString;
}

char *toStringStr(char *array[], int n)
{
    int length = 2 * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; array[i][j] != '\0'; j++)
        {
            length++;
        }
    }

    toString = malloc(length);
    if (toString == NULL)
    {
        fprintf(stderr, "Illegal NULL value\n");
        exit(EXIT_FAILURE);
    }
    int index = 0;
    toString[index++] = '[';
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            toString[index++] = ',';
            toString[index++] = ' ';
        }
        for (int j = 0; array[i][j] != '\0'; j++)
        {
            toString[index++] = array[i][j];
        }
    }
    toString[index++] = ']';
    toString[index] = '\0';
    return toString;
}

bool equalInteger(int array1[],int n1,int array2[],int n2){
    if(n1 != n2){
        return false;
    }

    for(int i = 0 ; i<n1;i++){
        if(array1[i] != array2[i]){
            return false;
        }
    }
    return true;
}

bool equalDouble(double array1[],int n1,double array2[],int n2){
    if(n1 != n2){
        return false;
    }
    for(int i = 0 ;i<n1;i++){
        if(array1[i] != array2[i]){
            return false;
        }
    }
    return true;
}

bool equalString(char* array1[],int n1,char* array2[] ,int n2){
    if(n1 != n2){
        return false;
    }
    for(int i = 0 ;i<n1;i++){
        if(strcmp(array1[i],array2[i]) != 0){
            return false;
        }
    }
    return true;
}

bool equalStringIgnoreCase(char *array1[], int n1, char *array2[], int n2)
{
    if (n1 != n2)
    {
        return false;
    }

    for (int i = 0; i < n1; i++)
    {
        if (strlen(array1[i]) != strlen(array2[i]))
        {
            return false;
        }

        char upperArray1[strlen(array1[i]) + 1];
        char upperArray2[strlen(array2[i]) + 1];

        for (int j = 0; array1[i][j] != '\0'; j++)
        {
            upperArray1[j] = toupper(array1[i][j]);
        }
        upperArray1[strlen(array1[i])] = '\0';

        for (int j = 0; array2[i][j] != '\0'; j++)
        {
            upperArray2[j] = toupper(array2[i][j]);
        }
        upperArray2[strlen(array2[i])] = '\0';

        if (strcmp(upperArray1, upperArray2) != 0)
        {
            return false;
        }
    }

    return true;
}

void cleanMalloc()
{
    free(toString);
}
