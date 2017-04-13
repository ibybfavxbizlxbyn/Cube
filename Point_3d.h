#ifndef POINT_3D_H_INCLUDED
#define POINT_3D_H_INCLUDED

#include "point_2d.h"

class Point_3d : public Point_2d
{
protected:
    int z;
public:
    Point_3d (int x = 0, int y = 0, int z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /*
        GET Method
    */

    int Get_Z () const
    {
        return z;
    }

    /*
        Set Method
    */

    void Set_Z (int z)
    {
        this->z = z;
    }
};

#endif // POINT_3D_H_INCLUDED
