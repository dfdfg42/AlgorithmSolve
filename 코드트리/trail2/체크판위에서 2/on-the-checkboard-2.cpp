#include <iostream>

using namespace std;

int R, C;
char grid[15][15];
int ans;

void dfs(int depth, int row , int col, char before){

    if(depth == 2 && before != grid[R-1][C-1]){

        ans++;
        
        return;
    }


    for(int i = row + 1; i < R-1; i++){
        for(int j= col + 1; j<C-1; j++){
            if(grid[i][j] != before){
               //cout << i<< ' ' << j << "! \n";
                dfs(depth+1, i,j,grid[i][j]);
            }
        }
    }

}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    ans = 0;


    dfs(0,0,0,grid[0][0]);

    cout << ans <<'\n';

    return 0;
}