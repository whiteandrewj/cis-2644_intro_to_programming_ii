#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

string encrypt(string istring, map<char,char> key) {
    string ostring = "";
    for(char c : istring) {
        ostring.push_back(key[c]);
    }
    return ostring;
}
string decrypt(string istring, map<char,char> key) {
    
    map<char,char> reverseKey;
    for(auto p = key.begin(); p != key.end(); p++) {
        reverseKey.insert({p->second,p->first});
    }

    string ostring = "";
    for(char c : istring) {
        ostring.push_back(reverseKey[c]);
    }
    return ostring;
}

int main()
{
    string plaintext = "the quick brown fox jumped over the lazy dog";
    
    map<char, char> key;
    for (int i = 0; i < 26; i++) {
        key.insert({i+97,i+33});
    }
    key.insert({32,59}); //add key for space

    /*
    for (auto c = key.begin(); c != key.end(); c++) {
        cout << c->first << c->second << endl;
    }
    */

    string ciphertext = encrypt(plaintext, key);
    cout << ciphertext << endl;

    string plaintext2 = decrypt(ciphertext, key);
    cout << plaintext2 << endl;

    return 0;
}