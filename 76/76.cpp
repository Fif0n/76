#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class cipher{
    public:
        ifstream fIn1;
        ifstream fIn2;
        ifstream fIn3;
        ofstream fOut;

        cipher();
        ~cipher();
        string encryption(string word, vector <int> code);
        string decryption(string word, vector <int> code);
};

cipher::cipher() {
    fIn1.open("c:\\szyfr1.txt");
    fIn2.open("c:\\szyfr2.txt");
    fIn3.open("c:\\szyfr3.txt");
    fOut.open("c:\\wyniki_szyfr1.txt");
}

cipher::~cipher() {
    fIn1.close();
    fIn2.close();
    fIn3.close();
    fOut.close();
}

string cipher::encryption(string word, vector <int> code) {
    int length = word.length();
    for (int i = 0; i < length ; i++) {
        int bufor = word[i];
        
        word[i] = word[code[i % code.size()]-1];
        word[code[i % code.size()]-1] = bufor;
    }

    return word;
}

string cipher::decryption(string word, vector <int> code) {
    int length = word.length();
    for (int i = length; i >= 0; i--) {
        int bufor = word[i];

        word[i] = word[code[i % code.size()] - 1];
        word[code[i % code.size()] - 1] = bufor;
    }

    return word;
}


int main()
{
    cipher c1;
    cout << "76.1" << endl;
    vector <string> s1;
    for (int i = 0; i < 6; i++) {
        string temp;
        c1.fIn1 >> temp;
        s1.push_back(temp);
    }
    vector <int> code1;
    while (!c1.fIn1.eof()) {
        int temp;
        c1.fIn1 >> temp;
        code1.push_back(temp);
    }
    for (int i = 0; i < 6; i++) {
        cout << c1.encryption(s1[i], code1)<<endl;
    }
    

    string s2;
    vector <int> code2;
    c1.fIn2 >> s2;
    while (!c1.fIn2.eof()) {
        int temp;
        c1.fIn2 >> temp;
        code2.push_back(temp);
    }
    cout << "76.2" << endl;
    cout << c1.encryption(s2, code2) << endl;
    cout << "76.3" << endl;
    string s3;
    c1.fIn3 >> s3;
    vector <int> code3;
    code3.push_back(6);
    code3.push_back(2);
    code3.push_back(4);
    code3.push_back(1);
    code3.push_back(5);
    code3.push_back(3);
    cout << c1.decryption(s3, code3);
}

