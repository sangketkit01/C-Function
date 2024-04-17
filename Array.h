#ifndef STRING_H
#define STRING_H

#define size(arr) (sizeof(arr) / sizeof((arr)[0]))

extern  char *toString;

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

bool equalInteger(int array1[], int n1, int array2[], int n2);
bool equalDouble(double array1[], int n1, double array2[], int n2);
bool equalString(char *array1[], int n1, char *array2[], int n2);
bool equalStringIgnoreCase(char *array1[], int n1, char *array2[], int n2);

void cleanMalloc();

#endif