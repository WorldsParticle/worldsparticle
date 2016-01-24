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

#include    <log4cpp/Category.hh>

#include    "Engine/Core/SceneGraphNode.hpp"
#include    "Engine/Core/SceneGraph.hpp"
#include    "Engine/Core/AssimpScene.hpp"
#include    "Engine/Core/PerspectiveCamera.hpp"
#include    "Engine/Core/Light.hpp"
#include    "Engine/Core/Object.hpp"

using namespace     log4cpp;

namespace   Engine
{
    /// TODO add GSL NOT NULL
    SceneGraphNode::SceneGraphNode(SceneGraph *scenegraph,
            SceneGraphNode *parent) :
        name(""),
        parent(parent),
        childrens(),
        scenegraph(scenegraph),
        scene(scenegraph->getScene()),
        entity(nullptr),
        transform()
    {

    }

    SceneGraphNode::SceneGraphNode(const AssimpScene &assimpScene,
            const aiNode *assimpNode, SceneGraph *scenegraph,
            SceneGraphNode *parent) :
        name(assimpNode->mName.C_Str()),
        parent(parent),
        childrens(),
        scenegraph(scenegraph),
        scene(scenegraph->getScene()),
        entity(nullptr),
        transform(assimpNode->mTransformation)
    {
        Category &root = Category::getRoot();
        root << Priority::DEBUG << "SceneGraphNode : " << this->name;
        if (!this->name.empty())
        {
            const aiCamera  *camera = nullptr;
            const aiLight   *light = nullptr;
            if ((camera = assimpScene.getCamera(this->name)) != nullptr)
            {
                this->entity = new PerspectiveCamera(camera, this);
            }
            else if ((light = assimpScene.getLight(this->name)) != nullptr)
            {
                 this->entity = new Light(light, this);
            }
        }
        if (assimpNode->mNumMeshes > 0)
        {
            // if the name is empty and the meshes related to the node > 0
            // the node is an object.
            this->entity = new Object(assimpNode, this);
        }
        // we just need to create the others child.
        for (unsigned int i = 0 ; i < assimpNode->mNumChildren ; ++i)
        {
            SceneGraphNode  *child = new SceneGraphNode(assimpScene,
                    assimpNode->mChildren[i], scenegraph, this);
            this->childrens.push_back(child);
        }
    }

    SceneGraphNode::~SceneGraphNode(void)
    {
        for (SceneGraphNode *node : this->childrens)
        {
            delete node;
        }
    }



    void
    SceneGraphNode::update(void)
    {
        //Category &root = Category::getRoot();

        //root << Priority::DEBUG << "SceneGraphNode update";
        //

        if (this->entity != nullptr)
        {
            this->entity->update();
        }
        for (SceneGraphNode *node : this->childrens)
        {
             node->update();
        }
    }



    const std::string &
    SceneGraphNode::getName(void) const
    {
         return this->name;
    }

    SceneGraphNode *
    SceneGraphNode::getParent(void) const
    {
        return this->parent;
    }

    Scene *
    SceneGraphNode::getScene(void) const
    {
         return this->scene;
    }

    const Transform &
    SceneGraphNode::getTransform(void) const
    {
         return this->transform;
    }

}

