#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct coord{
    int x,y;
};

//Drake meme:
//Nah: Hydrothermal Venture
//Yah: HydroHarmal Venture

int main(){
    
    ifstream myfile("input.txt");
    //Checks if we have anything
    if(!myfile.is_open()){
        cout << "no file found"<<endl;
        return -1;
    }
    string inp;
    const int SIZE = 1000;
    vector<vector<int>> map;
    for(int x = 0; x < SIZE; x++){
        vector<int> newrow = {};
        map.push_back(newrow);
        for(int y = 0; y < SIZE; y++){
            map.at(x).push_back(0);
        }
    }
    coord start, end;

    while(!myfile.eof()){
        //...there is a single newline character throwing off my code
        if(myfile.peek() == '\n') break;
        
        getline(myfile, inp, ',');
        start.x = stoi(inp);
        getline(myfile, inp, ' ');
        start.y = stoi(inp);
        myfile >> inp;
        getline(myfile, inp, ',');
        end.x = stoi(inp);
        getline(myfile, inp);
        end.y = stoi(inp);

        int minx = min(start.x,end.x);
        int miny = min(start.y,end.y);

        int maxx = max(start.x,end.x);
        int maxy = max(start.y,end.y);

        if(start.x == end.x){
            for(int y = miny; y <= maxy; y++)
                map.at(start.x).at(y)++;

        }else if(start.y == end.y){
            for(int x = minx; x <= maxx; x++)
                map.at(x).at(start.y)++;

        //Remember, diagnols are a two-way road
        }else if((start.x < end.x && start.y < end.y) || (start.x > end.x && start.y > end.y)){
            for(int j = 0; j <= maxx-minx; j++)
                map.at(minx+j).at(miny+j)++;
        }else{
            for(int j = 0; j <= maxx-minx; j++)
                map.at(minx+j).at(maxy-j)++;
        }


    }

    int counter = 0;
    for(vector<int> x : map){
        for(int y: x){
            if(y >= 2) counter++;
        }
    }
    cout << counter;



    return 0;
}
