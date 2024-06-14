#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

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
    cout << "OS Related: " << endl;
    cout << "  info - Display information about the OS " << endl;
    cout << "  cls - Clear the screen " << endl;
    cout << "\n" << endl;
}

void getCpuInfo(int cpuNumber, string& cpuName, float& cpuSpeed)
{
    switch (cpuNumber)
    {
        case 1:
            cpuName = "Generic 186 CPU";
            cpuSpeed = 1.8;
            break;
        case 2:
            cpuName = "Intel i386DX-40";
            cpuSpeed = 40.0;
            break;
        case 3:
            cpuName = "MIPS R3000";
            cpuSpeed = 34.0;
            break;
        case 4:
            cpuName = "NEC D70325L-8";
            cpuSpeed = 8.0;
            break;
        case 5:
            cpuName = "AMD 80386DX-40";
            cpuSpeed = 40.0;
            break;
        default:
            cpuName = "Unknown CPU";
            cpuSpeed = 0.0;
            break;
    }
}

bool readConfig(string& cpuName, float& cpuSpeed)
{
    ifstream configFile("config.ini");
    if (!configFile.is_open())
    {
        //cout << "Could not open config.ini file." << endl;
        return false;
    }

    string line;
    while (getline(configFile, line))
    {
        if (line.find("cpu") != string::npos)
        {
            size_t pos = line.find("=");
            if (pos != string::npos)
            {
                int cpuNumber = stoi(line.substr(pos + 1));
                getCpuInfo(cpuNumber, cpuName, cpuSpeed);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string nameo = "Opti P2 C++ Edition ";
    string strver = "0.1.1";
    string build = "Build 1A";
    string userinp;
    float flver = 0.1;

    string cpuName;
    float cpuSpeed;

    cout << nameo << strver << endl;

    if (readConfig(cpuName, cpuSpeed))
    {
        //cout << "CPU Information from config.ini:" << endl;
        //cout << "CPU Name: " << cpuName << endl;
        //cout << "CPU Speed: " << cpuSpeed << " MHz" << endl;
    }
    else
    {
        //cout << "Using default CPU settings." << endl;
        cpuName = "Generic Unidentified CPU";
        cpuSpeed = 1.0;
    }

    while (true)
    {
        cout << "O:/> ";
        cin >> userinp;

        if (userinp == "info")
        {
            cout << "\n" << endl;
            cout << nameo << strver << endl;
            cout << build << endl;
            cout << "Running on: " << cpuName << " at " << cpuSpeed << " MHz" << endl;
            //cout << cpuSpeed << " MHz" << endl;
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
