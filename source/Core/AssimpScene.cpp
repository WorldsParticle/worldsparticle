//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#include    "Engine/Core/AssimpScene.hpp"

namespace   Engine
{
    /// TODO GSL NOT NULL
    AssimpScene::AssimpScene(const aiScene *scene) :
        cameras(),
        lights(),
        materials(scene->mMaterials),
        animations(scene->mAnimations),
        meshes(scene->mMeshes),
        textures(scene->mTextures),
        rootNode(scene->mRootNode),
        materialsNumber(scene->mNumMaterials),
        animationsNumber(scene->mNumAnimations),
        meshesNumber(scene->mNumMeshes),
        texturesNumber(scene->mNumTextures)
    {
        for (unsigned int i = 0 ; i < scene->mNumCameras ; ++i)
        {
            std::string     name = scene->mCameras[i]->mName.C_Str();
            this->cameras[name] = scene->mCameras[i];
        }
        for (unsigned int i = 0; i < scene->mNumLights ; ++i)
        {
            std::string     name = scene->mLights[i]->mName.C_Str();
            this->lights[name] = scene->mLights[i];
        }
    }

    AssimpScene::~AssimpScene(void)
    {
        // nothing to do atm.
    }



    const aiLight *
    AssimpScene::getLight(const std::string &name) const
    {
        auto it = this->lights.find(name);

        if (it != this->lights.end())
            return it->second;
        return nullptr;
    }

    const aiCamera *
    AssimpScene::getCamera(const std::string &name) const
    {
        auto it = this->cameras.find(name);

        if (it != this->cameras.end())
            return it->second;
        return nullptr;
    }

    aiMaterial **
    AssimpScene::getMaterials(void) const
    {
        return this->materials;
    }

    aiAnimation **
    AssimpScene::getAnimations(void) const
    {
        return this->animations;
    }

    aiMesh **
    AssimpScene::getMeshes(void) const
    {
         return this->meshes;
    }

    aiTexture **
    AssimpScene::getTextures(void) const
    {
        return this->textures;
    }

    const aiNode *
    AssimpScene::getRootNode(void) const
    {
         return this->rootNode;
    }



    unsigned int
    AssimpScene::getMaterialsNumber(void) const
    {
        return this->materialsNumber;
    }

    unsigned int
    AssimpScene::getAnimationsNumber(void) const
    {
         return this->animationsNumber;
    }

    unsigned int
    AssimpScene::getMeshesNumber(void) const
    {
         return this->meshesNumber;
    }

    unsigned int
    AssimpScene::getTexturesNumber(void) const
    {
         return this->texturesNumber;
    }
}
