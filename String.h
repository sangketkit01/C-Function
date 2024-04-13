#ifndef STRING_H
#define STRING_H

int len(char *s);
char *uppercase(char *s);
bool isUpper(char *s);
char *lowercase(char *s);
bool isLower(char *s);
bool compare(char *s1, char *s2);
bool compareIgnoreCase(char *s1, char *s2);
char *removeSpace(char *s);
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

#endif
