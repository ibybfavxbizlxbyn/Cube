#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#include "Point_3d.h"
#include "header.h"

class cube
{
private:
    Point_3d pic_coord[8]; // Cube top coordinates (x;y;z)
    double a;              // Cube Edge Length
    double S;              // Cube Square
    double V;              // Cube Volume
    Point_3d center;       // Cube Center
public:
    /*
        Constructor
    */
    cube(bool from_file)
    {
        if (from_file == true)
        {
            ifstream fin;
            fin.open("input.txt");
            for (int i = 0; i < 8; i++)
            {
                int x, y, z;
                fin >> x >> y >> z;
                pic_coord[i].Set_X(x);
                pic_coord[i].Set_Y(y);
                pic_coord[i].Set_Z(z);
            }
            fin.close();
        } else
        {
            for (int i = 0; i < 8; i++)
            {
                int x, y, z;
                cin >> x >> y >> z;
                pic_coord[i].Set_X(x);
                pic_coord[i].Set_Y(y);
                pic_coord[i].Set_Z(z);
            }
        }

        //Set a
        a = sqrt(pow(pic_coord[1].Get_X() - pic_coord[0].Get_X(), 2) + pow(pic_coord[1].Get_Y() - pic_coord[0].Get_Y(), 2) + pow(pic_coord[1].Get_Z() - pic_coord[0].Get_Z(), 2));
        //Set S
        S = pow(a, 2) * 6;
        //Set V
        V = pow(a, 3);
        //Set Center
        center.Set_X(pic_coord[0].Get_X() + a/2);
        center.Set_Y(pic_coord[0].Get_Y() + a/2);
        center.Set_Z(pic_coord[0].Get_Z() + a/2);
    }

    /*
        GET Methods
    */

    double Get_A () const
    {
        return a;
    }
    double Get_S () const
    {
        return S;
    }
    double Get_V () const
    {
        return V;
    }

};

#endif // CUBE_H_INCLUDED
