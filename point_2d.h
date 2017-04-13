#ifndef POINT_2D_H_INCLUDED
#define POINT_2D_H_INCLUDED

class Point_2d
{
protected:
    int x;
    int y;
public:
    Point_2d (int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    /*
        GET Methods
    */

    int Get_X () const
    {
        return x;
    }
    int Get_Y () const
    {
        return y;
    }

    /*
        Set Methods
    */

    void Set_X (int x)
    {
        this->x = x;
    }
    void Set_Y (int y)
    {
        this->y = y;
    }
};

#endif // POINT_2D_H_INCLUDED
