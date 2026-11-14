#include <iostream>
#include <string>

using namespace std;

int N, M;
string arr[50];

int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }


    int ans =0 ;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){

            if(arr[i][j] == 'L'){

                for(int d=0; d<8; d++){

                    bool lee = true;
                    for(int dt=1; dt<=2; dt++){
                        int ny = i+dy[d]*dt;
                        int nx = j+dx[d]*dt;
                        if(0>ny || ny>=N || 0>nx || nx>=M  || arr[ny][nx] != 'E'){
                            lee = false;
                            break;
                        }


                    }
                    if(lee){

                        ans ++;
                    }
                    

                }

            }


        }
    }

    cout << ans <<'\n';

    return 0;
}