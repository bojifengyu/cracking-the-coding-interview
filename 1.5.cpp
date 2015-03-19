#include "1.5.h"
#include <assert.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>

char* compressString(char* str)
{
    int len = strlen(str);
    if (len >= 2)
    {
        char result[len];
        int counter = 0;
        int resulti = 0;
        for (int i = 1; i <= len; i++)
        {
            char c = i < len ? str[i] : '\0';
            char p = str[i-1];
            if (c == p)
            {
                counter++;
            }
            else
            {
                result[resulti++] = p;
                result[resulti++] = (char)(((int)'0')+counter+1);
                counter = 0;
            }
        }
        result[resulti++] = '\0';
        int resultLen = strlen(result);
        if (resultLen < len)
        {
            char* ret = (char*)malloc(resultLen+1);
            memcpy(ret, result, resultLen+1);
            return ret;
        }
    }
    char* ret = (char*)malloc(len+1);
    memcpy(ret, str, len+1);
    ret[len] = '\0';
    return ret;
}


void test1_5()
{
    char* result = compressString("aabcccccaaa");
    printf("%s\n", result);
    assert(strcmp(result, "a2b1c5a3") == 0);
    free(result);
}