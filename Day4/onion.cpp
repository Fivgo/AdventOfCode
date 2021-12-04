#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;




int main(){
    const int SIZE = 5;
    const int SIZEOFLIST = SIZE*SIZE;
    ifstream myfile("input.txt");

    if(!myfile.is_open()){
        return -1;
    }
    vector<int> nums;
    string snumbers;
    myfile >> snumbers;
    stringstream ss(snumbers);

    for(int i; ss>>i;){
        nums.push_back(i);
        if (ss.peek() == ',') ss.ignore();
    }

    int table[SIZEOFLIST];
    bool btable [SIZEOFLIST];

    //mfw they have been asking for the sum of the unpicked numbers
    //instead of the sum of winning bingo numbers.
    int winningsum;
    //PART 1
    //int champ = nums.size();
    
    //PART 2
    int champ = 0;
    while(!myfile.eof()){

        for(int i = 0; i < SIZEOFLIST; i++){
            myfile >> table[i];
            btable[i] = false;
        }
        //ENABLE FOR PART 1
        /*
        for( int i = 0; i < champ; i++){
            for(int j = 0; j < SIZEOFLIST; j++){
                if(table[j] == nums.at(i)){
                    btable[j] = true;
                    int row = j/SIZE;
                    int col = j%SIZE;
                    bool hbingo = true;
                    bool vbingo = true;
                    for(int k = 0; k < SIZE; k++){
                        if(!btable[k+row*SIZE]){
                            hbingo = false;
                            break;
                        }
                    }
                    for(int k = 0; k < SIZE; k++){
                        if(!btable[col+k*SIZE]){
                            vbingo = false;
                            break;
                        }
                    }
                    if(hbingo || vbingo){
                        //flush old value
                        winningsum = 0;
                        for(int k = 0; k < SIZEOFLIST; k++){
                             if(!btable[k]) winningsum += table[k];
                        }
                        champ = i;
                    }
                    break;
                }
            }
        }
        */
        
        //ENABLE FOR PART 2
        bool found = false;
        for( int i = 0; i < nums.size(); i++){
            for(int j = 0; j < SIZEOFLIST; j++){
                if(table[j] == nums.at(i)){
                    btable[j] = true;
                    int row = j/SIZE;
                    int col = j%SIZE;
                    bool hbingo = true;
                    bool vbingo = true;
                    for(int k = 0; k < SIZE; k++){
                        if(!btable[k+row*SIZE]){
                            hbingo = false;
                            break;
                        }
                    }
                    for(int k = 0; k < SIZE; k++){
                        if(!btable[col+k*SIZE]){
                            vbingo = false;
                            break;
                        }
                    }

                    if((hbingo || vbingo) && champ < i){
                        //flush old value
                        winningsum = 0;
                        for(int k = 0; k < SIZEOFLIST; k++){
                             if(!btable[k]) winningsum += table[k];
                        }
                        champ = i;
                        found = true;
                    }
                    if(hbingo || vbingo) found = true;

                    break;
                }
            }
            if(found) break;
        }
    }
    
    cout << champ << endl;
    cout << winningsum * nums.at(champ)<< endl;

   
    
    //cout << "champ index: " << champ << endl;
    

    

    return 0;
}
