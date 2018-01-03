#include "FileOperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

const char* ReadFile(const char* path){
    std::string VertexShaderCode;
	std::ifstream VertexShaderStream(path, std::ios::in);
	if(VertexShaderStream.is_open()){
		std::string Line = "";
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
        return VertexShaderCode.c_str();
	}else{
		return "";
	}
}