#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line, body;
    ifstream myfile;
    myfile.open("modest_proposal.txt");
    //myfile >> filetext;
    while (myfile.good()) {
        getline(myfile,line);
        body.append(line);
    }

    myfile.close();

    cout << body;


    return 0;
}
