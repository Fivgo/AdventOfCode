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
    vector<string> field;
    while(!myfile.eof()){
        string inp;
        myfile >> inp;
        field.push_back(inp);
    }

    int missingCounter[] = {0,0,0,0};

    vector<char> charStack = {};
    vector<string> incomplete = {};

    for(string line : field){
        char suspect = 'z';
        for(char brack : line){
            if(brack == '(' || brack == '[' || brack == '{' || brack == '<'){
                charStack.push_back(brack);
            }else if((brack == ')' && charStack.back() == '(') || 
                (brack == ']' && charStack.back() == '[')  ||
                (brack == '}' && charStack.back() == '{')  ||
                (brack == '>' && charStack.back() == '<') ){
                    charStack.pop_back();
            }else{
                suspect = brack;
                break;
            }
        }
        switch (suspect)
        {
        case ')':
            missingCounter[0]++;
            break;
        case ']':
            missingCounter[1]++;
            break;
        case '}':
            missingCounter[2]++;
            break;
        case '>':
            missingCounter[3]++;
            break;
        default:
            incomplete.push_back(line);
            break;
        }
        charStack.clear();
    }
    
    vector<long long int> scoreArr = {};
    for(string line : incomplete){
        long long int score = 0;
        for(char brack : line){
            if(brack == '(' || brack == '[' || brack == '{' || brack == '<'){
                charStack.push_back(brack);
            }else{
                charStack.pop_back();
            }
        }
        for(int i = charStack.size()-1; i >= 0; i--){
            score *= 5;
            switch (charStack.at(i))
            {
            case '(':
                score++;
                break;
            case '[':
                score += 2;
                break;
            case '{':
                score += 3;
                break;
            case '<':
                score += 4;
                break;
            default:
                break;
            }
        }
        scoreArr.push_back(score);
        charStack.clear();
    }
    sort(scoreArr.begin(), scoreArr.end());


    cout << missingCounter[0] * 3 + missingCounter[1] * 57 + missingCounter[2] * 1197 + missingCounter[3] * 25137 <<endl;
    cout << scoreArr.at(scoreArr.size()/2) << endl;



    
    return 0;
}
