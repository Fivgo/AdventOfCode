#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int main(){
    
    ifstream myfile("input.txt");
    //Checks if we have anything
    if(!myfile.is_open()){
        cout << "no file found"<<endl;
        return -1;
    }
    //Read in and put into intArr
    vector<int> intArr;
    string inp;
    while(!myfile.eof()){
        getline(myfile,inp,',');
        intArr.push_back(stoi(inp));
    }
    sort(intArr.begin(),intArr.end());
    
    //PART 1
    cout << intArr.at(intArr.size()/2) << endl;
    //It was at this point the term median had a whole new meaning
    int midPoint = intArr.at(intArr.size()/2);
    int total = 0;
    for ( int i : intArr){
        total += max(midPoint, i) - min(midPoint,i);
    }
    cout << total << endl;


    //PART 2
    //Looking for the cheapest amount of movement. Everyone must
    //share the load.
    int arrTotal = 0;
    for(int i : intArr){
        arrTotal += i;
    }
    int arrAvg = arrTotal/intArr.size();
    cout << arrAvg << endl;
    total = 0;
    for(int i : intArr){
        for(int j = 1; j <= max(arrAvg, i) - min(arrAvg,i); j++){
            total += j;
        }
    }
    cout << total << endl;
    return 0;
}