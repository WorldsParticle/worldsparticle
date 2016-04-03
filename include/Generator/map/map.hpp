#ifndef MAP_NAMESPACE_H
#define MAP_NAMESPACE_H

#include <map>
#include <memory>
#include "point.hpp"
#include "zone.hpp"
#include "corner.hpp"
#include "crossededge.hpp"

namespace MAP_NAMESPACE
{

class Map
{
public:
    Map(unsigned int xMax = 0, unsigned int yMax = 0, unsigned int zoneNumber = 0);
    ~Map();

    inline std::map<int, std::shared_ptr<Zone>>        &zones()
    { return _zones; }
    inline std::map<int, std::shared_ptr<Corner>>      &corners()
    { return _corners; }
    inline std::map<int, std::shared_ptr<CrossedEdge>> &edges()
    { return _edges; }

    inline double xMax()
    { return _xMax; }
    inline double yMax()
    { return _yMax; }
    inline unsigned int zoneNumber()
    { return _zoneNumber; }

private:

    std::map<int, std::shared_ptr<Zone>>         _zones;
    std::map<int, std::shared_ptr<Corner>>       _corners;
    std::map<int, std::shared_ptr<CrossedEdge>>  _edges;

    double    _xMax;
    double    _yMax;
    unsigned int    _zoneNumber;
};

}

#endif // MAP_NAMESPACE_H
