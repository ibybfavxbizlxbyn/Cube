#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#include "Point_3d.h"
#include "header.h"

class cube
{
private:
    Point_3d pic_coord[8]; // Cube pic coordinates (x;y;z)
    double a;              // Cube Edge Length
    double S;              // Cube Square
    double V;              // Cube Volume
    Point_3d center;       // Cube Center

    /*
        Calculate Pics
    */
    void Pic_calc ()
    {
        for (int i = 1; i < 8; i+=2)
            pic_coord[i].Set_X(pic_coord[0].Get_X()+a);
        for (int i = 2; i < 7; i+=2)
            pic_coord[i].Set_X(pic_coord[0].Get_X());

        for (int i = 1; i < 4; i++)
            pic_coord[i].Set_Y(pic_coord[0].Get_Y());
        for (int i = 4; i < 8; i++)
            pic_coord[i].Set_Y(pic_coord[0].Get_Y()+a);

        pic_coord[1].Set_Z(pic_coord[0].Get_Z());
        pic_coord[4].Set_Z(pic_coord[0].Get_Z());
        pic_coord[5].Set_Z(pic_coord[0].Get_Z());
        pic_coord[2].Set_Z(pic_coord[0].Get_Z()+a);
        pic_coord[3].Set_Z(pic_coord[0].Get_Z()+a);
        pic_coord[6].Set_Z(pic_coord[0].Get_Z()+a);
        pic_coord[7].Set_Z(pic_coord[0].Get_Z()+a);

        //Not Changes: 0 1 4 5
        //Changes:     2 3 6 7
    }

public:
    /*
        Constructor
    */
    cube (bool from_file)
    {
        cout << "Creating cube..." << endl;
        int x, y, z;
        if (from_file == true)
        {
            ifstream fin;
            fin.open("input.txt");
            fin >> x >> y >> z >> a;
            fin.close();
        } else
        {
            cin >> x >> y >> z >> a;
        }

        pic_coord[0].Set_X(x);
        pic_coord[0].Set_Y(y);
        pic_coord[0].Set_Z(z);

        //Pic calculation
        Pic_calc();

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

    /*
        Print Method
    */
    void print (bool to_file = false) const
    {
        if (to_file == false)
            for (int i = 0; i < 8; i++)
                cout << pic_coord[i].Get_X() << " " << pic_coord[i].Get_Y() << " " << pic_coord[i].Get_Z() << endl;
        else
            for (int i = 0; i < 8; i++)
                cout << pic_coord[i].Get_X() << " " << pic_coord[i].Get_Y() << " " << pic_coord[i].Get_Z() << endl;
    }

    /*

    */
    void Change_coords (bool from_file)
    {
        int x, y, z;
        if (from_file == true)
        {
            ifstream fin;
            fin.open("angle.txt");
            fin >> x >> y >> z;
            fin.close();
        } else
        {
            cin >> x >> y >> z;
        }

        for (int i = 0; i < 8; i++)
        {
            int x_ = pic_coord[i].Get_X();
            int y_ = pic_coord[i].Get_Y();
            int z_ = pic_coord[i].Get_Z();
            pic_coord[i].Set_X(x_);
            pic_coord[i].Set_Y(y_*cos(x) + z_*sin(x));
            pic_coord[i].Set_Z(z_*cos(x) - y_*sin(x));
        }

        for (int i = 0; i < 8; i++)
        {
            int x_ = pic_coord[i].Get_X();
            int y_ = pic_coord[i].Get_Y();
            int z_ = pic_coord[i].Get_Z();
            pic_coord[i].Set_X(x_*cos(y) + z_*sin(y));
            pic_coord[i].Set_Y(y_);
            pic_coord[i].Set_Z(z_*cos(y) - x_*sin(y));
        }
        for (int i = 0; i < 8; i++)
        {
            int x_ = pic_coord[i].Get_X();
            int y_ = pic_coord[i].Get_Y();
            int z_ = pic_coord[i].Get_Z();
            pic_coord[i].Set_X(x_*cos(z) - y_*sin(z));
            pic_coord[i].Set_Y(x_*sin(z) + y_*cos(z));
            pic_coord[i].Set_Z(z_);
        }
        ofstream fout;
        fout.open("ouput.txt");
        print(true);
    }

};

#endif // CUBE_H_INCLUDED
