#include <iostream>
#include <fstream>
//Yeah I know I'm using namespace. Plz let me just have this one.
using namespace std;
/* PART 1
int main(){
    ifstream myfile("input.txt");
    if(myfile.is_open()){
        int challenger;
        int c = 0;
        int curr;

        myfile >> curr;
        while(myfile >> challenger){
            if(challenger > curr) c++;
            curr = challenger;
        }

        cout << c;
    }

    myfile.close();
    return 0;
}
*/
//PART 2
int main(){
    ifstream myfile("input.txt");
    if(myfile.is_open()){

        int ind = 0;
        int c = 0;
        int queue[] = {0,0,0};

        myfile >> queue[ind++%3];
        myfile >> queue[ind++%3];
        myfile >> queue[ind++%3];
        
        int total = queue[0] + queue[1] + queue[2];
        int chalTot;

        while(myfile >> queue[ind++%3]){
            chalTot = queue[0] + queue[1] + queue[2];
            if(chalTot > total) c++;
            total = chalTot;
        }
        cout << c;
    }

    myfile.close();
    return 0;
}
