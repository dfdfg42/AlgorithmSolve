#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int n;
int x[100];
int y[100];



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = INT_MAX;
    for(int i=1; i<n-1; i++){

        int distSum = 0;
        for(int j=1; j<n; j++){
            
            if(i==j){
                continue;
            }
            else if(j-1 != i){
                distSum += abs(x[j] - x[j-1]) + abs(y[j]- y[j-1]);
            }else{
                distSum += abs(x[j] - x[j-2]) + abs(y[j]- y[j-2]);
            }

            //cout << distSum << ' ';

        }   
        //cout <<'\n';
        ans = min(distSum,ans);

    }

    cout << ans <<'\n';

    return 0;
}