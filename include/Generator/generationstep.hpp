#ifndef GENERATIONSTEP_H
#define GENERATIONSTEP_H

#include "map/map.hpp"

namespace GEN
{

class GenerationStep
{
public:
    enum STEP
    {
        FILL = 0,
        SHAPE,
        ELEVATE,
        MOISTING,
        RIVERING,
        BIOMIZATING
    };

    GenerationStep() : _map(nullptr), _step() {}

    inline void    generate(MAP_NAMESPACE::Map *map)
    { _map = map; run(); }

protected:
    virtual void    run() = 0;
    MAP_NAMESPACE::Map        *_map;
    STEP            _step;
};

}

#endif // GENERATIONSTEP_H
