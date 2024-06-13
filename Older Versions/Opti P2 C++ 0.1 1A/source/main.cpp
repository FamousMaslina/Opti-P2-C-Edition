#include <iostream>
#include <cstdlib>

using namespace std;

void cls()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void help()
{
    cout << "\n" << endl;
    cout << "Commands: " << endl;
    cout << "OS Related: " <<endl;
    cout << "  info - Display information about the OS " << endl;
    cout << "  cls - Clear the screen " << endl;
    cout << "\n" << endl;
}
int main()
{
    string nameo = "Opti P2 C++ Edition ";
    string strver = "0.1";
    string build = "Build 1A";
    string userinp;
    float flver = 0.1;

    cout << nameo << strver << endl;

    while (true)
    {
        cout << "O:/> ";
        cin >> userinp;

        if (userinp == "info")
        {
            cout << "\n" << endl;
            cout << nameo << strver << endl;
            cout << build << endl;
            cout << "\n" << endl;
        }
        else if (userinp == "cls")
        {
            cls();
        }
        else if (userinp == "help")
        {
            help();
        }
        else
        {
            cout << "Bad command" << endl;
        }
    }

    return 0;
}
