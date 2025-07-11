#include <bits/stdc++.h>
using namespace std;

int grid[1000][1000];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool visitados[1000][1000];

void BFS(int x, int y){
    
    queue<pair<int,int>> q;
    q.push({x,y});

    visitados[x][y] = true;

    while(q.size()){
        auto [x1, y1] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ax = x1 + dx[i];
            int ay = y1 + dy[i];

            if(!visitados[ax][ay]){
                visitados[ax][ay] = true;
                q.push({ax, ay});
            }
        }
    }
}