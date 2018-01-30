//
// Created by 董宸 on 30/01/2018.
//

#include <vector>
#include <assimp/material.h>
#include "GLModel.hpp"

namespace ReOpenGL{
    void GLModel::Draw(GLShader shader) {

    }

    void GLModel::loadModel(std::string path) {
        Assimp::Importer import;
        const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

        if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
            return;
        }
        directory = path.substr(0, path.find_last_of('/'));

        processNode(scene->mRootNode, scene);
    }

    void GLModel::processNode(aiNode *node, const aiScene *scene) {
        // 处理节点所有的网格（如果有的话）
        for(unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(mesh, scene));
        }
        // 接下来对它的子节点重复这一过程
        for(unsigned int i = 0; i < node->mNumChildren; i++)
        {
            processNode(node->mChildren[i], scene);
        }
    }

    GLMesh GLModel::processMesh(aiMesh *mesh, const aiScene *scene) {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        for(unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            Vertex vertex;
            // 处理顶点位置、法线和纹理坐标
            ...
            vertices.push_back(vertex);
        }
        // 处理索引
        ...
        // 处理材质
        if(mesh->mMaterialIndex >= 0)
        {
            ...
        }

    }

    std::vector<Texture> GLModel::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName) {
        return std::vector<Texture>();
    }
}