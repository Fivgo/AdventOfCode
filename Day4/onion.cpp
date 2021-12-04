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
    //Checks if we have anything
    if(!myfile.is_open()){
        return -1;
    }
    //bingo string
    vector<int> nums;
    string snumbers;
    myfile >> snumbers;
    stringstream ss(snumbers);

    //convert bingo string into vector int
    for(int i; ss>>i;){
        nums.push_back(i);
        if (ss.peek() == ',') ss.ignore();
    }

    //Create an array for to represent two tables:
    //one for the actual ints, and one for the bools
    int table[SIZEOFLIST];
    bool btable [SIZEOFLIST];

    //mfw they have been asking for the sum of the unpicked numbers
    //instead of the sum of winning bingo numbers. Too bad!
    int winningsum;
    
    //PART 1
    int champ = nums.size();
    //PART 2
    //int champ = 0;
    
    
    while(!myfile.eof()){

        for(int i = 0; i < SIZEOFLIST; i++){
            myfile >> table[i];
            btable[i] = false;
        }
        bool found = false;

        //ENABLE FOR PART 1
        
        for( int i = 0; i < champ; i++){
            for(int j = 0; j < SIZEOFLIST; j++){
                if(table[j] == nums.at(i)){
                    btable[j] = true;
                    int row = j/SIZE;
                    int col = j%SIZE;
                    
                    //Check for row bingo
                    bool hbingo = true;
                    for(int k = 0; k < SIZE; k++){
                        if(!btable[k+row*SIZE]){
                            hbingo = false;
                            break;
                        }
                    }
                    //check for column bingo
                    bool vbingo = true;
                    for(int k = 0; k < SIZE; k++){
                        if(!btable[col+k*SIZE]){
                            vbingo = false;
                            break;
                        }
                    }
                    if(hbingo || vbingo){
                        //flush old value
                        winningsum = 0;
                        for(int k = 0; k < SIZEOFLIST; k++) if(!btable[k]) winningsum += table[k];
                        champ = i;
                        found = true;
                    }
                    break;
                }
            }
            if(found) break;
        }
        
        
        //basically the same comments
        //ENABLE FOR PART 2
        /*
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
        }*/
    }
    
    cout << winningsum * nums.at(champ)<< endl;
    return 0;
}
