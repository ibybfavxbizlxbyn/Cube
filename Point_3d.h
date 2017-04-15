#ifndef POINT_3D_H_INCLUDED
#define POINT_3D_H_INCLUDED

#include "point_2d.h"

class Point_3d : public Point_2d
{
protected:
    double z;
public:
    Point_3d (double x = 0, double y = 0, double z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /*
        GET Method
    */

    double Get_Z () const
    {
        return z;
    }

    /*
        Set Method
    */

    void Set_Z (double z)
    {
        this->z = z;
    }
};

#endif // POINT_3D_H_INCLUDED
