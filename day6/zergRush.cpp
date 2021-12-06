#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


//PART1
/*
int main(){
    
    ifstream myfile("input.txt");
    //Checks if we have anything
    if(!myfile.is_open()){
        cout << "no file found"<<endl;
        return -1;
    }

    const int NUMBEROFDAYS = 80;
    string inp;
    vector<int> creeps;

    while(!myfile.eof()){
        getline(myfile, inp, ',');
        creeps.push_back(stoi(inp));
    }

    cout << creeps.size() << endl;
    for(int i = 0; i < NUMBEROFDAYS; i++){
        int size = creeps.size();
        for(int j = 0; j < size; j++){
            if(creeps.at(j)-- == 0){
                creeps.at(j) = 6;
                creeps.push_back(8);
            }
        }
        cout << i << endl;
    }
    cout << creeps.size() << endl;
}
*/ 

//Part 2
//My special thanks goes out mattmorgan6 who was able to see
//the importance of the problem rather than holding onto
//all of the fish in an array
int main(){
    
    ifstream myfile("input.txt");
    //Checks if we have anything
    if(!myfile.is_open()){
        cout << "no file found"<<endl;
        return -1;
    }

    const int NUMBEROFDAYS = 256;
    string inp;
    vector<long long int> creeps;
    for(int i = 0; i < 9; i++){
        creeps.push_back(0);
    }

    while(!myfile.eof()){
        getline(myfile, inp, ',');
        creeps.at(stoi(inp))++;
    }

    for(int i = 0; i < NUMBEROFDAYS; i++){
        long long int temp = creeps.at(0);
        
        //Revolving door
        for(int j = 0; j < creeps.size()-1; j++){
            creeps.at(j) = creeps.at(j+1);
        }

        //BABIES
        creeps.at(8) = temp;
        //ADULTS
        creeps.at(6) += temp;
        
    }
    long long int total = 0;
    for(int i = 0; i < creeps.size(); i++){
        total += creeps.at(i);
    }

    cout << total << endl;

}