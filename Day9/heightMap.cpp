#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visX = {};
vector<int> visY = {};

int search(vector<string> map, int x, int y, int xMax, int yMax){
    if(x < xMax-1 && map.at(y).at(x+1) != '9' && map.at(y).at(x) < map.at(y).at(x+1)){
        bool visited = false;
        for(int i = 0; i < visX.size(); i++){
            if(x+1 == visX.at(i) && y == visY.at(i)){
                visited = true;
                break;
            }
        }
        if(!visited){
            visX.push_back(x+1);
            visY.push_back(y);
            search(map, x+1, y, xMax, yMax);
        }
    }
    if(y < yMax-1 && map.at(y+1).at(x) != '9' &&  map.at(y).at(x) < map.at(y+1).at(x)){
        bool visited = false;
        for(int i = 0; i < visX.size(); i++){
            if(x == visX.at(i) && y+1 == visY.at(i)){
                visited = true;
                break;
            }
        }
        if(!visited){
            visX.push_back(x);
            visY.push_back(y+1);
            search(map, x, y+1, xMax, yMax);
        }
    }
    if(y > 0 && map.at(y-1).at(x) != '9' &&  map.at(y).at(x) < map.at(y-1).at(x)){
        bool visited = false;
        for(int i = 0; i < visX.size(); i++){
            if(x == visX.at(i) && y-1 == visY.at(i)){
                visited = true;
                break;
            }
        }
        if(!visited){
            visX.push_back(x);
            visY.push_back(y-1);
            search(map, x, y-1, xMax, yMax);
        }
    }
    if(x > 0 && map.at(y).at(x-1) != '9' &&  map.at(y).at(x) < map.at(y).at(x-1)){
        bool visited = false;
        for(int i = 0; i < visX.size(); i++){
            if(x-1 == visX.at(i) && y == visY.at(i)){
                visited = true;
                break;
            }
        }
        if(!visited){
            visX.push_back(x-1);
            visY.push_back(y);
            search(map, x-1, y, xMax, yMax);
        }
    }
    return 0;
}


int startSearch(vector<string> map, int x, int y, int xM, int yM, int* arr){
    visX.push_back(x);
    visY.push_back(y);
    search(map,x,y,xM,yM);
    
    
    int smallest = min(arr[0],arr[1]);
    smallest = min(smallest,arr[2]);
    if(smallest < visX.size()){
        for(int i = 0; i < 3; i++){
            if(arr[i] == smallest){
                arr[i] = visX.size();
                break;
            }
        }
    }
    
    visX.clear();
    visY.clear();
}




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

    int x = field.at(0).length();
    int y = field.size();
    int champArr[] = {0,0,0};
    int sum = 0;

    for(int i = 1; i < x-1; i++){
        for(int j = 1; j < y-1; j++){
            char point = field.at(j).at(i);
            if(point < field.at(j-1).at(i) &&
                point < field.at(j+1).at(i) && 
                point < field.at(j).at(i-1) && 
                point < field.at(j).at(i+1)){   
                startSearch(field, i, j, x, y, champArr);   
                sum += 1 + point - '0';
            }
        }
    }

    for(int i = 1; i < y-1; i++){
        char point = field.at(i).at(0);
        if(point < field.at(i-1).at(0) && 
            point < field.at(i+1).at(0) && 
            point < field.at(i).at(1)){
            sum += 1 + point - '0';
            startSearch(field, 0, i, x, y, champArr);
        }
        point = field.at(i).at(x-1);
        if(point < field.at(i-1).at(x-1) && 
            point < field.at(i+1).at(x-1) && 
            point < field.at(i).at(x-2)){
            sum += 1 + point - '0';
            startSearch(field, x-1, i, x, y, champArr);
        }
    }

    for(int i = 1; i < x-1; i++){
        char point = field.at(0).at(i);
        if(point < field.at(0).at(i-1) 
            && point < field.at(0).at(i+1) 
            && point < field.at(1).at(i)){
            sum += 1 + point - '0';
            startSearch(field, i, 0, x, y, champArr);
        }
        point = field.at(y-1).at(i);
        if(point < field.at(y-1).at(i-1) 
            && point < field.at(y-1).at(i+1) 
            && point < field.at(y-2).at(i)){ 
            sum += 1 + point - '0';
            startSearch(field, i, y-1, x, y, champArr);
        }
    }

    if(field.at(0).at(0) < field.at(0).at(1) && field.at(0).at(0) < field.at(1).at(0)){
        sum += 1 + field.at(0).at(0) - '0';
        startSearch(field, 0, 0, x, y, champArr);
    }
    
    if(field.at(y-1).at(0) < field.at(y-1).at(1) && field.at(y-1).at(0) < field.at(y-2).at(0)){
        sum += 1 + field.at(y-1).at(0) - '0';
        startSearch(field, 0, y-1, x, y, champArr);
    }
    
    if(field.at(0).at(x-1) < field.at(0).at(x-2) && field.at(0).at(x-1) < field.at(1).at(x-1)){
        sum += 1 + field.at(0).at(x-1) - '0';
        startSearch(field, x-1, 0, x, y, champArr);
    }
        
    if(field.at(y-1).at(x-1) < field.at(y-1).at(x-2) && field.at(y-1).at(x-1) < field.at(y-2).at(x-1)){
        sum += 1 + field.at(y-1).at(x-1) - '0';
        startSearch(field, x-1, y-1, x, y, champArr);
    }
    
    cout << sum <<endl;
    for(int i : champArr)
        cout << i << " ";
    cout << endl;

    return 0;
}