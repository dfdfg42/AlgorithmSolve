#include <iostream>
#include <vector>
using namespace std;

int main() {
    

    int N;
    cin >> N;
    vector<int> cows(N);

    for(int i=0; i<N; i++){
        cin >> cows[i];
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j= i+1; j<N; j++){
            if(cows[j] < cows[i]) continue;

            for(int k = j+1; k<N; k++){
                if(cows[k] < cows[j]) continue;

                ans++;
            }
        }
    }
    
    cout << ans <<'\n';

    return 0;
}