#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string scrubString(string istring) {
    string ostring = "";
    for (char c : istring) {
        if (c != '"' && c != '.' && c != ',' && c != ':' && c != ';' && c != '!' && c != '('
            && c != ')' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6'
            && c != '7' && c != '8' && c != '9' && c != '0' )
        {
            c = tolower(c);
            ostring.push_back(c);
        }
    }
    return ostring;
}
set<string> parseStringToSet(string istring, char delim) {
    set<string> uniqueWords;
    string word = "";
    stringstream strStream(istring);
    while(strStream.good()) {
        getline(strStream,word,delim);
        if(word != "") {
            uniqueWords.insert(word);
        }  
    } 
    return uniqueWords;
}

int main()
{
    string line, fullText;
    ifstream fileStream;
    fileStream.open("modest_proposal.txt");

    while (fileStream.good()) {
        getline(fileStream,line);
        if(line != "") {
            fullText.append(line);
            fullText.append(" ");
        } 
        
    }
    fileStream.close();
    //cout << fullText << endl << endl << endl;

    fullText = scrubString(fullText);
    //cout << fullText;  
    
    set<string> words = parseStringToSet(fullText,' ');
    for_each(words.begin(), words.end(), [] (string w) { cout << w << " "; });

    return 0;
}
