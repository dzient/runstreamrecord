// runstreamrecord2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <stdio.h>
#include <stdlib.h>

#define SR "streamrecord.exe"
#define TL "tl.txt"

#include <iostream>
#include <istream>
#include <ostream>
using namespace std;
//#include <ifstream.h>

bool parseFile(const char fn[])
{
    FILE *fp = NULL;
    //ifstream ifs(fn, ios::in);
    //istream ifs((char *)fn, ios::in);
    char buffer[1024];

    if ((fp = fopen(fn,"r")) != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s", buffer);
            //ifs.getline(buffer, 80, '\n');
            if (strncmp(buffer, SR,strlen(SR)) == 0)
            {
                //We found streamrecord.exe; no need to continue
                fclose(fp);
                return true;
            }
        }
    }
    if (fp != NULL)
        fclose(fp);
    // We didn't find streamrecord.exe - Not good
    return false;
}
bool checkProgram()
{
    //Invoke the command:
    while (1)
    {
        system("tasklist>tl.txt");
        //Parse the file:
        if (!parseFile(TL))
            system("streamrecord.exe");
    }
}

int main()
{
    //std::cout << "Hello World!\n";
    checkProgram();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
