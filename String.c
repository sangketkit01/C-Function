#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "String.h"

char *upper;
char *lower;
char *newString;
char* trimString;
char *afterReplace;
char **split_array;
char *repeatString;
char *sub;
char *join_Array;
char *join_String;

int len(char *s);

char *uppercase(char *s);
bool isUpper(char *s);
char *lowercase(char *s);
bool isLower(char *s);

bool compare(char *s1, char *s2);
bool compareIgnoreCase(char *s1, char *s2);

char *removeSpace(char *s);
char *trim(char *s);

char *replace(char *s, char oldChar, char newChar);

bool startsWith(char *s, char *start);
bool startsWithIgnoreCase(char *s, char *start);
bool endsWith(char *s, char *end);
bool endsWithIgnoreCase(char *s, char *end);

int indexOf(char *s, char target);
int indexOfWithIgnoreCase(char *s, char target);
int lastIndexOf(char *s, char target);
int lastIndexOfWithIgnoreCase(char *s, char target);

char **split(char *s, char separator);

bool isEmpty(char *s);
bool isBlank(char *s);

char charAt(char *s, int index);

char *stringRepeat(char *s, int repeat);

char *subString(char *s, int beginIndex);

char *joinArray(char joiner, char *s[]);
char *joinString(char joiner, char *s);

void cleanMalloc();

int main(void)
{
    // Try any function here;

    
    cleanMalloc();
    return 0;
}

int len(char *s)
{
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

char *uppercase(char *s)
{
    upper = malloc(len(s) + 1); // upper has declared as a global variable

    if (upper == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int index;
    for (index = 0; s[index] != '\0'; index++)
    {
        upper[index] = s[index];
    }
    upper[index] = '\0';

    for (int i = 0; upper[i] != '\0'; i++)
    {
        if (upper[i] > 'Z' && upper[i] <= 'z')
        {
            upper[i] = upper[i] - 32;
        }
    }
    return upper;
}

bool isUpper(char *s)
{
    for (int i = 0; i < len(s); i++)
    {
        if (s[i] > 'Z')
        {
            return false;
        }
    }
    return true;
}

char *lowercase(char *s)
{
    lower = malloc(len(s) + 1); // lower has declared as a global variable

    if (lower == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int index;
    for (index = 0; s[index] != '\0'; index++)
    {
        lower[index] = s[index];
    }
    lower[index] = '\0';

    for (int i = 0; lower[i] != '\0'; i++)
    {
        if (lower[i] <= 'Z' && lower[i] >= 'A')
        {
            lower[i] = lower[i] + 32;
        }
    }
    return lower;
}

bool isLower(char *s)
{
    for (int i = 0; i < len(s); i++)
    {
        if (s[i] <= 'Z')
        {
            return false;
        }
    }
    return true;
}

bool compare(char *s1, char *s2)
{
    if (len(s1) != len(s2))
    {
        return false;
    }

    if (s1 == NULL || s2 == NULL)
    {
        fprintf(stderr, "Can't compare NULL string\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len(s1); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }

    return true;
}

bool compareIgnoreCase(char *s1, char *s2)
{
    if (len(s1) != len(s2))
    {
        return false;
    }

    if (s1 == NULL || s2 == NULL)
    {
        fprintf(stderr, "Can't compare NULL string\n");
        exit(EXIT_FAILURE);
    }

    char *newS1 = uppercase(s1);
    char *newS2 = uppercase(s2);
    for (int i = 0; newS1[i] != '\0' && newS2[i] != '\0'; i++)
    {
        if (newS1[i] != newS2[i])
        {
            return false;
        }
    }
    return true;
}

char *removeSpace(char *s)
{
    int newSize = 0;
    for (int i = 0; i < len(s); i++)
    {
        if (s[i] != ' ')
        {
            newSize++;
        }
    }

    newString = malloc(newSize + 1); // newString has declared as a global variable
    if (newString == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            newString[j++] = s[i];
        }
    }
    newString[j] = '\0';

    return newString;
}

char* trim(char* s){
    int begin_length = 0;
    int end_length = 0;

    for(int i = 0 ;i<len(s) ; i++){
        if(s[i] != ' ') break;
        begin_length++;
    }
    for(int j = len(s) - 1;j>=0;j--){
        if(s[j] != ' ') break;
        end_length++;
    }

    trimString = malloc(len(s) - begin_length - end_length + 1); // trim has declared as a global variable
    if(trimString == NULL){
        fprintf(stderr,"Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int length = 0;
    for(int k = begin_length ; k<len(s) - end_length ; k++){
        trimString[length++] = s[k];
    }
    trimString[length] = '\0';
    return trimString;
}

char *replace(char *s, char oldChar, char newChar)
{
    afterReplace = malloc(len(s) + 1); // afterReplace has declared as a global variable
    if (afterReplace == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int index;
    for (index = 0; s[index] != '\0'; index++)
    {
        afterReplace[index] = s[index];
    }
    afterReplace[index] = '\0';
    for (int i = 0; i < len(afterReplace); i++)
    {
        if (afterReplace[i] == oldChar)
        {
            afterReplace[i] = newChar;
        }
    }
    return afterReplace;
}

bool startsWith(char *s, char *start)
{
    if (s == NULL || start == NULL)
    {
        fprintf(stderr, "Illegal Null value\n");
        exit(EXIT_FAILURE);
    }

    if (len(start) == 0)
    {
        fprintf(stderr, "Value can't be empty\n");
        exit(EXIT_FAILURE);
    }
    
    if(len(start) > len(s)){
        return false;
    }

    for (int i = 0; i < len(start); i++)
    {
        if (s[i] != start[i])
        {
            return false;
        }
    }
    return true;
}

bool startsWithIgnoreCase(char *s, char *start)
{
    if (s == NULL || start == NULL)
    {
        fprintf(stderr, "Illegal Null value\n");
        exit(EXIT_FAILURE);
    }

    if (len(start) == 0)
    {
        fprintf(stderr, "Value can't be empty\n");
        exit(EXIT_FAILURE);
    }

    if(len(start) > len(s)){
        return false;
    }

    char *newS = uppercase(s);
    char *newStart = uppercase(start);
    for (int i = 0; i < len(newStart); i++)
    {
        if (newS[i] != newStart[i])
        {
            return false;
        }
    }
    return true;
}

bool endsWith(char *s, char *end)
{
    if (s == NULL || end == NULL)
    {
        fprintf(stderr, "Illegal Null value\n");
        exit(EXIT_FAILURE);
    }

    if (len(end) == 0)
    {
        fprintf(stderr, "Value can't be empty\n");
        exit(EXIT_FAILURE);
    }
    if(len(end) > len(s)){
        return false;
    }

    int startEnd = 0;
    for (int i = len(s) - len(end); i < len(s); i++)
    {
        if (s[i] != end[startEnd])
        {
            return false;
        }
        startEnd++;
    }
    return true;
}

bool endsWithIgnoreCase(char *s, char *end)
{
    if (s == NULL || end == NULL)
    {
        fprintf(stderr, "Illegal Null value\n");
        exit(EXIT_FAILURE);
    }

    if (len(end) == 0)
    {
        fprintf(stderr, "Value can't be empty\n");
        exit(EXIT_FAILURE);
    }

    if(len(end) > len(s)){
        return false;
    }
    
    char *newS = uppercase(s);
    char *newEnd = uppercase(end);

    int startEnd = 0;
    for (int i = len(newS) - len(newEnd); i < len(newS); i++)
    {
        if (newS[i] != newEnd[startEnd])
        {
            return false;
        }
        startEnd++;
    }
    return true;
}

int indexOf(char *s, char target)
{
    if (s == NULL)
    {
        fprintf(stderr, "Illegal NULL value\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len(s); i++)
    {
        if (s[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int indexOfWithIgnoreCase(char *s, char target)
{
    if (s == NULL)
    {
        fprintf(stderr, "Illegal NULL value\n");
        exit(EXIT_FAILURE);
    }

    char *newS = uppercase(s);
    char *newTarget = &target;
    if (*newTarget > 'Z' && *newTarget <= 'z')
    {
        *newTarget = target - 32;
    }

    for (int i = 0; i < len(newS); i++)
    {
        if (newS[i] == *newTarget)
        {
            return i;
        }
    }
    return -1;
}

int lastIndexOf(char *s, char target)
{
    if (s == NULL)
    {
        fprintf(stderr, "Illegal NULL value\n");
        exit(EXIT_FAILURE);
    }
    for (int i = len(s) - 1; i >= 0; i--)
    {
        if (s[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int lastIndexOfWithIgnoreCase(char *s, char target)
{
    if (s == NULL)
    {
        fprintf(stderr, "Illgal NULL value\n");
        exit(EXIT_FAILURE);
    }
    char *newS = uppercase(s);
    char *newTarget = &target;
    if (*newTarget > 'Z' && *newTarget <= 'Z')
    {
        *newTarget = target - 32;
    }

    for (int i = len(newS) - 1; i >= 0; i--)
    {
        if (newS[i] == *newTarget)
        {
            return i;
        }
    }
    return -1;
}

char **split(char *s, char separator)
{
    int separator_count = 0;
    const char *temp = s;
    while (*temp != '\0')
    {
        if (*temp == separator)
        {
            separator_count++;
        }
        temp++;
    }

    split_array = malloc((separator_count + 1) * sizeof(char *)); // split_array has declared as a global variable
    if (split_array == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    const char *start = s;
    int count = 0;
    while (*s != '\0')
    {
        if (*s == separator)
        {
            int length = s - start;
            split_array[count] = malloc(length + 1); // split_array has declared as a global variable
            if (split_array[count] == NULL)
            {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
            for (int i = 0; i < length; i++)
            {
                split_array[count][i] = start[i];
            }
            split_array[count][length] = '\0';
            count++;
            start = s + 1;
        }
        s++;
    }
    int length = s - start;
    split_array[count] = malloc(length + 1); // split_array has declared as a global variable
    if (split_array[count] == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++)
    {
        split_array[count][i] = start[i];
    }
    split_array[count][length] = '\0';
    count++;

    split_array[count] = NULL;

    return split_array;
}

bool isEmpty(char *s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    return false;
}

bool isBlank(char* s){
    if(s == NULL){
        fprintf(stderr,"Illgal NULL value\n");
        exit(EXIT_FAILURE);
    }
    if(isEmpty(s)){
        return false;
    }

    for(int i = 0 ; s[i] != '\0'; i++){
        if(s[i] != ' '){
            return false;
        }
    }
    return true;
}

char charAt(char *s, int index)
{
    if (index > len(s))
    {
        fprintf(stderr, "Index out of length\n");
        exit(EXIT_FAILURE);
    }
    if (s == NULL)
    {
        fprintf(stderr, "Illegal NULL value\n");
        exit(EXIT_FAILURE);
    }
    return s[index];
}

char *stringRepeat(char *s, int repeat)
{
    repeatString = malloc(repeat * len(s) + 1); // repeatString has declared as a global variable
    if (repeatString == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    for (int i = 0; i < repeat; i++)
    {
        for (int j = 0; j < len(s); j++)
        {
            repeatString[count++] = s[j];
        }
    }
    repeatString[count] = '\0';
    return repeatString;
}

char *subString(char *s, int beginIndex)
{
    sub = malloc(len(s) + 1 - beginIndex); // sub has declared as a global variable
    if (sub == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int i;
    int j = 0;
    for (i = beginIndex; s[i] != '\0'; i++)
    {
        sub[j++] = s[i];
    }
    sub[i] = '\0';
    return sub;
}

char *joinArray(char joiner, char *s[])
{
    int length = 0;
    for (int i = 0; s[i] != NULL; i++)
    {
        for (int j = 0; j < s[i][j] != '\0'; j++)
        {
            length++;
        }
        length++;
    }
    int count = 0;

    join_Array = malloc(length + 1); // join_array has declared as a global variable
    if (join_Array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; s[i] != NULL; i++)
    {
        for (int j = 0; s[i][j] != '\0'; j++)
        {
            join_Array[count++] = s[i][j];
        }
        join_Array[count++] = joiner;
    }
    join_Array[count - 1] = '\0';
    return join_Array;
}

char *joinString(char joiner, char *s)
{
    char *removeSpaceString = removeSpace(s);
    join_String = malloc(len(removeSpaceString) * 2 + 1); // join_String has declared as a global variable

    if (join_String == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int i;
    int j = 0;
    for (i = 0; removeSpaceString[j] != '\0'; i++)
    {
        if (i % 2 == 0)
        {
            join_String[i] = removeSpaceString[j];
            j++;
        }
        else
        {
            join_String[i] = joiner;
        }
    }
    join_String[i] = '\0';
    return join_String;
}

void cleanMalloc()
{
    free(split_array);
    free(upper);
    free(newString);
    free(lower);
    free(afterReplace);
    free(repeatString);
    free(sub);
    free(join_Array);
    free(join_String);
    free(trimString);
}
