#include <stdio.h>
#include <stdlib.h>

#include "../FileSystem/FileOperation.h"


void UseFile();

int main(){
    UseFile();
    return 0;
}

void UseFile(){
    char* result;
    result = ReadFile("/Users/dongchen/Documents/CppProjects/LearnOpenGL/Common/CppTest/test.txt");
    printf("%s\n", result);
    free(result);
}