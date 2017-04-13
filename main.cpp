#include "cube.h"

int main()
{
    cout << "Get DATA from file(y/n): ";
    char answer;
    cin >> answer;

    bool from_file;

    if (answer == 'y')
    {
        ifstream fin;
        fin.open("input.txt");
        if (!fin.is_open())
        {
            cout << "Error: no file \"input.txt\" detected. Creating file..." << endl;
            ofstream fout;
            fout.open("input.txt");
            fout.close();
            cout << "File \"input.txt\" has been successfully created." << endl;
        }
        fin.close();
        from_file = true;
    } else
    {
        from_file = false;
    }

    cube cube1 = new cube(from_file);



    return 0;
}
