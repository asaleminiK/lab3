#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "complexType.h"
#include "complexDB.h"

using namespace std;

complexType toComplex(string &);

int main() {
    ifstream infile("C:\\Users\\ameen\\CLionProjects\\lab3\\126importHard.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
        exit(1);
    }
    string strinput;
    infile>>strinput;
    complexType initializer(toComplex(strinput));
    complexDB complexStorage(initializer);
    while (!infile.eof()) {
        infile >> strinput;
        if (!strinput.empty()) {
            complexType a(toComplex(strinput));
            complexStorage.add(a);
        }
    }
    infile.close();
    char option = ' ';
    while (option != 'q') {
        cout << "Would you like to add(a), delete(d), list(l), save(s), or quit(q)?" << endl;
        cin >> option;
        if (option == 'a') {
            cout << "Enter complex number in form of a+bi;" << endl;
            string line;
            cin >> line;
            complexStorage.add(toComplex(line));
        } else if (option == 'd') {
            cout << "Enter complex number in form of a+bi;" << endl;
            string line;
            cin >> line;
            complexStorage.deleteComplex(toComplex(line));
        } else if (option == 'l')
            complexStorage.list(std::cout);
        else if (option == 's') {
        cout << "Enter file name to save to (ex test.txt)" << endl;
        string line;
        cin >> line;
        complexStorage.save(line);
    }
        else cout <<"Invalid entry." << endl;
    }

    return 0;
}

complexType toComplex(string &s) {
    string realt = "0", imaginaryt = "0i";
    size_t pos = s.find("+");
    if (pos != string::npos) {
        realt = s.substr(0, pos);
        imaginaryt = s.substr(pos + 1, s.size() - 1);
        goto meme;
    }
    pos = s.find("-", 1);
    if (pos != string::npos) {
        realt = s.substr(0, pos);
        imaginaryt = s.substr(pos, s.size() - 1);
        goto meme;
    }
    pos = s.find("i");
    if (pos != string::npos) {
        imaginaryt = s;
        goto meme;
    }
    if (s.size() > 0) realt = s;
    meme:
    complexType A(realt, imaginaryt);
    return A;
}

