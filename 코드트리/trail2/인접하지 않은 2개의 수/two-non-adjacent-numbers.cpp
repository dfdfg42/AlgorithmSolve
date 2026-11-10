#include <iostream>
#include <algorithm>

using namespace std;

int n;
int numbers[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int ans =0;

    for(int i=0; i<n; i++){
        for(int j=i+2; j<n; j++){
            ans = max(ans, numbers[i] + numbers[j]);
        }
    }

    cout << ans <<'\n';

    return 0;
}