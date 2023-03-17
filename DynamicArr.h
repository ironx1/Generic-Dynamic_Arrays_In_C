#include <stdlib.h>
#include <stdio.h>

#ifndef DYNAMICARR_LIBRARY_H
#define DYNAMICARR_LIBRARY_H
#define PRINTUPTOINDEX 4
typedef char *string;
#define add(type) type* add_##type(type* arr, type data){   \
    static int index=0;                                     \
    static int s=1;                                         \
    if(arr==NULL){                                          \
    arr = (type*)realloc(arr, sizeof(type));                \
    arr[index++] = data;                                    \
    return arr;                                             \
    }                                                       \
    if(s>=index){                                           \
        arr = (type*)realloc(arr, ++s * (sizeof(type)));    \
        arr[index++]=data;                                  \
        return arr;                                         \
    }                                                       \
}

#define printArr(format, type, len) void printArr_##type(type* arr){    \
    if(arr==NULL)                                                       \
        return;                                                         \
    for(int i=0; i<len; i++){                                           \
        printf("%"#format" ", arr[i]);                                  \
    }                                                                   \
}

add(int)

add(char)

add(string)

add(double)

add(float)

printArr(d, int, PRINTUPTOINDEX)

printArr(c, char, PRINTUPTOINDEX)

printArr(s, string, PRINTUPTOINDEX)

printArr(lf, double, PRINTUPTOINDEX)

printArr(f, float, PRINTUPTOINDEX)

#define addToArr(arr, val) _Generic((val),  \
int:add_int,                                \
char:add_char,                              \
double:add_double,                          \
float:add_float,                            \
string:add_string                           \
)(arr, val)
#define  print(arr) _Generic((arr),         \
int*:printArr_int,                          \
string*:printArr_string,                    \
char*:printArr_char,                        \
double*:printArr_double,                    \
float*:printArr_float                       \
)(arr)

#endif //DYNAMICARR_LIBRARY_H
