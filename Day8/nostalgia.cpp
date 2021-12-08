#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    const int DELIMITER = 10;
    ifstream myfile("input.txt");
    //Checks if we have anything
    if(!myfile.is_open()){
        cout << "no file found"<<endl;
        return -1;
    }
    vector<vector<string>> sevSeg;
    string inp;
    while(!myfile.eof()){
        vector<string> line;
        for(int i = 0; i < 10; i++){
            myfile >> inp;
            line.push_back(inp);
        }
        myfile >> inp;
        for(int i = 0; i < 4; i++){
            myfile >> inp;
            line.push_back(inp);
        }
        sevSeg.push_back(line);
    }

    cout << sevSeg.size() << endl;
    int count = 0;
    //PART 1
    /*
    for(vector<string> line : sevSeg){
        bool numPresent[] = {0,0,0,0,0,0,0,0,0,0};
        for(int i = 0; i < DELIMITER; i++){
            switch (line.at(i).length())
            {
            case 2:
                numPresent[1] = true;
                break;
            case 3:
                numPresent[7] = true;
                break;
            case 4:
                numPresent[4] = true;
                break;
            case 7:
                numPresent[8] = true;
                break;
            default:
                break;
            }
        }
        for(int i = DELIMITER; i < line.size(); i++){
            switch (line.at(i).length())
            {
            case 2:
                if(numPresent[1]) count++;
                break;
            case 3:
                if(numPresent[7]) count++;
                break;
            case 4:
                if(numPresent[4]) count++;
                break;
            case 7:
                if(numPresent[8]) count++;
                break;
            default:
                break;
            }
        }
    }
    */
    //PART 2
    int sumTot = 0;
    for(vector<string> line : sevSeg){
        //It's late so I apologize for the madness
        //                         1  7   4    8   5   5   5   6   6   6
        vector<string> decoder = {"", "", "", "", "", "", "", "", "", ""};
        int fiveBlock = 4;
        int sixBlock = 7;
        //Sort inputs into usable formats
        for(int i = 0; i < DELIMITER; i++){
            switch (line.at(i).length())
            {
            case 2:
                decoder[0] = line.at(i);
                break;
            case 3:
                decoder[1] = line.at(i);
                break;
            case 4:
                decoder[2] = line.at(i);
                break;
            case 5:
                decoder[fiveBlock++] = line.at(i);
                break;
            case 6:
                decoder[sixBlock++] = line.at(i);
                break;
            case 7:
                decoder[3] = line.at(i);
                break;
            default:
                break;
            }
        }
        

        //              a    b    c    d    e    f    g
        char code[] = {'z', 'z', 'z', 'z', 'z', 'z', 'z'};
        //Discover key characters
        int c = 0;
        int counter[] = {0,0,0,0,0,0,0};
        //realized this is better than what I concocted yesterday
        //look for build array:
        //      5
        //  2       6
        //      4
        //  1       6
        //      3
        //                       1              7              7                4              2/3/5        2/3/5           2/3/5
        for(string word : {decoder.at(0), decoder.at(1), decoder.at(1), decoder.at(2), decoder.at(4), decoder.at(5), decoder.at(6)}){
            for(char l: word){
                switch (l)
                {
                case 'a':
                    counter[0]++;
                    break;
                case 'b':
                    counter[1]++;
                    break;
                case 'c':
                    counter[2]++;
                    break;
                case 'd':
                    counter[3]++;
                    break;
                case 'e':
                    counter[4]++;
                    break;
                case 'f':
                    counter[5]++;
                    break;
                case 'g':
                    counter[6]++;
                    break;
                default:
                    break;
                }
            }
        }
        for(int i = 0; i < 7; i++){
            switch (counter[i])
            {
            case 1:
                code[4] = "abcdefg"[i];
                break;
            case 2:
                code[1] = "abcdefg"[i];
                break;
            case 3:
                code[6] = "abcdefg"[i];
                break;
            case 4:
                code[3] = "abcdefg"[i];
                break;
            case 5:
                code[0] = "abcdefg"[i];
                break;
            default:
                break;
            }

        }

        int sum = 0;
        for(int i = DELIMITER; i < line.size(); i++){
            sum *= 10;
            switch (line.at(i).length())
            {  
            case 2:
                sum += 1;
                break;
            case 3:
                sum += 7;
                break;
            case 4:
                sum += 4;
                break;
            case 5:
                if(line.at(i).find(code[4]) != -1){
                    sum += 2;
                }else if(line.at(i).find(code[1]) != -1){
                    sum += 5;
                }else{
                    sum += 3;
                }
                break;
            case 6:
                if(line.at(i).find(code[3]) == -1){
                    sum += 0;
                }else if (line.at(i).find(code[4]) == -1){
                    sum += 9;
                }else{
                    sum += 6;
                }     
                break;
            case 7:
                sum += 8;
                break;  
            default:
                break;
            }
        }
        sumTot += sum;

    }
    /**/

    
    //cout << count << endl;
    cout << sumTot << endl;
}