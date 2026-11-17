#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;

int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int ans;

void dfs(int steps , int y, int x){

    ans = max(steps,ans);

    int oriY = y;
    int oriX = x;

    while(true){

        int ny = y + dy[move_dir[oriY][oriX]-1];
        int nx = x + dx[move_dir[oriY][oriX]-1];

        if(0>ny || ny>=n || 0>nx || nx>= n) break;

        y = ny;
        x = nx;

        if(num[ny][nx] <= num[oriY][oriX]) continue;

        dfs(steps+1, ny,nx);



    }

    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    ans =0 ;
dfs(0,r-1,c-1);

    cout << ans <<'\n';

    return 0;
}
