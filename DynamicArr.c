#include "library.h"

int main() {
    string *strArr = NULL;
    int *intArr = NULL;
    float *floatArr = NULL;
    strArr = addToArr(strArr, "Cat");
    strArr = addToArr(strArr, "in");
    strArr = addToArr(strArr, "the");
    strArr = addToArr(strArr, "hat");
    intArr = addToArr(intArr, 10);
    intArr = addToArr(intArr, 20);
    intArr = addToArr(intArr, 30);
    intArr = addToArr(intArr, 40);
    floatArr = addToArr(floatArr, 1.44f);
    floatArr = addToArr(floatArr, 4.32f);
    floatArr = addToArr(floatArr, 6.11f);
    floatArr = addToArr(floatArr, 3.123f);
    print(strArr);
    printf("\n");
    print(intArr);
    printf("\n");
    print(floatArr);
    printf("\n");
}
/*
OUTPUT:
Cat in the hat
10 20 30 40
1.440000 4.320000 6.110000 3.123000
*/
