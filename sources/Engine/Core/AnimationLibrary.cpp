///
/// \file AnimationLibrary.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:32:30
///
/// \version 1.0.6
///

#include    "Engine/Core/AnimationLibrary.hpp"
#include    "Engine/Core/Animation.hpp"

namespace   Engine
{
    AnimationLibrary::AnimationLibrary(void) :
        Library<Animation *>()
    {
        // nothing to do.
    }

    AnimationLibrary::AnimationLibrary(aiAnimation **assimpAnimations,
            unsigned int size) :
        Library<Animation *>()
    {
        this->resources.reserve(size);
        for (unsigned int i = 0 ; i < size ; ++i)
        {
            this->resources.push_back(new Animation(assimpAnimations[i]));
        }
    }

    AnimationLibrary::AnimationLibrary(const AnimationLibrary &other) :
        Library<Animation *>()
    {
        this->resources.reserve(other.resources.size());
        for (Animation *resource : other.resources)
        {
            this->resources.push_back(new Animation(*resource));
        }
    }

    AnimationLibrary::~AnimationLibrary(void)
    {
        for (Animation *resource : this->resources)
        {
            delete resource;
        }
    }



    AnimationLibrary &
    AnimationLibrary::operator=(const AnimationLibrary &other)
    {
        this->resources.reserve(other.resources.size());
        for (Animation *resource : other.resources)
        {
            this->resources.push_back(new Animation(*resource));
        }
        return *this;
    }
}
