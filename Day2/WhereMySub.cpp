#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//I apologize for the code you're about to look through to solve
//the simple problem of parsing a string. I am sorry.

/* PART 1
int main(){
    ifstream myfile("input.txt");
    if(myfile.is_open()){
        string line;
        int H = 0;
        int D = 0;
        while(getline(myfile, line)){;
            int splitp = line.find(' ');
            stringstream dist(line.substr(splitp+1, line.length()-1));
            int sto = 0;
            dist >> sto;

            char dir = line.front();
            if(dir == 'f') {H += sto;}
            else if(dir == 'd') {D += sto;}
            else {D -= sto;}
            
        }
        cout << H * D << endl;
    }
    return 0;
}
*/

int main(){
    ifstream myfile("input.txt");
    if(myfile.is_open()){
        string line;
        int H = 0;
        int D = 0;
        int A = 0;
        while(getline(myfile, line)){;
            int splitp = line.find(' ');
            stringstream dist(line.substr(splitp+1, line.length()-1));
            int sto = 0;
            dist >> sto;

            char dir = line.front();
            if(dir == 'f') {H += sto; D += sto * A;}
            else if(dir == 'd') {A += sto;}
            else {A -= sto;}
            
        }
        cout << H * D << endl;
    }
    return 0;
}
