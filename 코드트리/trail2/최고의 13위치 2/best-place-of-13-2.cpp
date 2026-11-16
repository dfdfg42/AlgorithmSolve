#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];


    int ans =0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N-2; j++){
            
            int temp = 0;
            temp = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            bool first = false;
            for(int k=i; k<N; k++){
                for(int t = 0; t<N-2; t++){

                    if(k==i && !first) {
                        t=j+3;
                        first = true;
                    }
                    if(t>= N-2) continue;

                    int temp2 = arr[k][t] + arr[k][t+1] +arr[k][t+2];
                    
                    ans = max(ans,temp2 + temp);

                }
            }

        }
    }

    cout << ans <<'\n';

    return 0;
}