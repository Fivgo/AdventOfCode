#include <iostream>
#include <fstream>
#include <math.h>
#include <iterator>
#include <vector>

using namespace std;

/* PART 1
int main(){
    ifstream myfile("input.txt");
    if(myfile.is_open()){
        long long int num;
        int len = 0;
        int numArr[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int arrSize = sizeof(numArr)/sizeof(int);
        while(myfile >> num){
            len++;
            for(int i = arrSize-1; i >= 0; i--){
                if(num%2) numArr[i]++;
                num /= 10; 
            }
        }
        myfile.close();
        int gamma = 0;
        int epsilon = 0;
        for(int i = 0; i < arrSize; i++){
            if(numArr[i] > len/2) gamma += pow(2,arrSize-1-i);
            if(numArr[i] < len/2) epsilon += pow(2,arrSize-1-i);
        }
        //011 000 011 101
        cout << endl << gamma<<endl;
        cout << epsilon<<endl;


        cout << gamma * epsilon;
    }
    
    return 0;
}
*/

//No one will know how long this solution took to realise.
//Just goes to show that just because your working with one
//data type doesn't mean there isn't an easier way to interpret
//the data. Was trying to solve this with long long ints until
//I realized that strings were able to handle the data more
//effectively. When in doubt, go for the acorn.

string recSplit(vector<string> arr, int ind, bool ones){
    vector<string> arrOnes;
    vector<string> arrZeros;
    if(ind >= arr.front().length() || arr.size() == 1){
        return arr.front();
    }
    for(string i : arr){
        if(i.at(ind) == '1'){ 
            arrOnes.push_back(i);
        }else{
            arrZeros.push_back(i);
        }
    }
    if(ones){
        if(arrOnes.size() >= arrZeros.size()){
            return recSplit(arrOnes, ind+1, ones);
        }else{
            return recSplit(arrZeros, ind+1, ones);
        }
    }else{
        if(arrOnes.size() < arrZeros.size()){
            return recSplit(arrOnes, ind+1, ones);
        }else{
            return recSplit(arrZeros, ind+1, ones);
        }
    }
    

    
}


int main(){
    ifstream myfile("input.txt");
    if(myfile.is_open()){
        
        istream_iterator<string> start(myfile), end;

        vector<string> shame(start, end);

        cout << recSplit(shame, 0, true)<<endl;
        cout << recSplit(shame, 0, false)<<endl;

        myfile.close();
    }

    
    return 0;
}