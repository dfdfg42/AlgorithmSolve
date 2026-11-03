#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> grid[i][j];

    
    int ans =0 ;
    for(int i=0; i<N; i++){
        for(int j=0; j<N-2; j++){

            int temp = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            ans = max(temp,ans);



        }
    }

    cout << ans <<'\n';

    return 0;
}