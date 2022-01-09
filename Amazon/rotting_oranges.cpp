#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){
            return -1;
        }
        set<pair<int,int>> fresh;
        set<pair<int,int>> rotten;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    fresh.insert({i,j});
                }
                if(grid[i][j] == 2){
                    rotten.insert({i,j});
                }
            }
        }
        int move = 0;
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(fresh.size() > 0){
            set<pair<int,int>> temprot;
            for(auto v : rotten){
                int row = v.first;
                int col = v.second;
                //check
                
                for(auto d : directions){
                    int x = row + d[0];
                    int y = col + d[1];
                    if(fresh.find({x,y}) != fresh.end()){
                        fresh.erase({x,y});
                        temprot.insert({x,y});
                    }
                }
            }
            if(temprot.size() == 0){
                return -1;
            }
            for(auto v : temprot){
                rotten.insert(v);
            }
            move++;
        }
        return move;    
    }
};