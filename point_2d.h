#ifndef POINT_2D_H_INCLUDED
#define POINT_2D_H_INCLUDED

class Point_2d
{
protected:
    double x;
    double y;
public:
    Point_2d (double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    /*
        GET Methods
    */

    double Get_X () const
    {
        return x;
    }
    double Get_Y () const
    {
        return y;
    }

    /*
        Set Methods
    */

    void Set_X (double x)
    {
        this->x = x;
    }
    void Set_Y (double y)
    {
        this->y = y;
    }
};

#endif // POINT_2D_H_INCLUDED
