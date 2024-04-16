#ifndef STRING_H
#define STRING_H

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

#endif