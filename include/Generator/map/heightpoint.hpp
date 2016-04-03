#ifndef HEIGHTPOINT_H
#define HEIGHTPOINT_H

#include <iostream>
#include <memory>
#include "zone.hpp"

class   HeightPoint
{
public:
    HeightPoint() : x(0.0), y(0.0), z(0.0), zone(nullptr) {}
    HeightPoint(double nx, double ny) : x(nx), y(ny), z(0.0), zone(nullptr) {}

    inline friend std::ostream &operator<<(std::ostream &os, const HeightPoint &p)
    { return os << "(" << p.x << ", " << p.y << ", " << p.z << ")"; }

    inline bool operator==(const HeightPoint &other)
    { return (x == other.x) && (y == other.y); }

    inline bool operator!=(const HeightPoint &other)
    { return !(*this == other); }

    double  x;
    double  y;
    double  z;

    std::shared_ptr<MAP_NAMESPACE::Zone>     zone;
};

#endif // HEIGHTPOINT_H
