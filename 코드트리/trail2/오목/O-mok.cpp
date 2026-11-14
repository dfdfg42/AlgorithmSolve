#include <iostream>

using namespace std;

int board[19][19];

int dy[4] = {0,1,1,1};
int dx[4] = {1,0,1,-1};

bool isFive(int target,int y, int x){
    
    int oriY = y;
    int oriX = x;

    for(int d=0; d<4; d++){
        bool isWin = true;
        for(int i=0; i<4; i++){

            int ny = y + dy[d];
            int nx = x + dx[d];

            if(0>ny || ny >=19 || 0> nx || nx>=19) {
                isWin = false;
                break;
            } 

            if(board[ny][nx] !=target){
                isWin = false;
                break;
            };

            y = ny;
            x = nx;

        }
        if(isWin){
            cout << target <<'\n';
            cout << (oriY + y +2)/2 <<' ' << (oriX+x+2)/2 << '\n';
            return true;
        }
        y = oriY;
        x = oriX;
    }

    return false;
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];

    

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){

            if(board[i][j] != 0){
                if(isFive(board[i][j],i,j)){
                    return 0;
                }
            }


        }
    }

    cout << 0 << '\n';

    return 0;
}