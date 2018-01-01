#include "FileOperation.h"
#include <stdio.h>

char* ReadFile(char* path){
    FILE* pFile;
    long lSize;
    char* buffer;
    size_t result;

    pFile = fopen(path, "rb");
    if(pFile != NULL){
        //查看文件长度
        fseek(pFile, 0, SEEK_END);
        lSize = ftell(pFile);
        rewind(pFile);
        //获取相应长度的内存
        buffer = (char*)malloc(sizeof(char) * lSize);
        result = fread(buffer, 1, lSize, pFile);
    }else{
        printf("open failed!!!\n");
    }
    fclose(pFile);
    return buffer;
}