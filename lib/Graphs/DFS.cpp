#include <bits/stdc++.h>
using namespace std;

int grid[1000][1000];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool visitados[1000][1000];

void dfs(int x, int y){
    visitados[x][y] = true;

    for(int i = 0; i < 4; i++){
        int ax = x + dx[i];
        int ay = y + dy[i];

        if(!visitados[ax][ay]) dfs(ax,ay);
    }
}
