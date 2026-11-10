#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int a[1003];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=1; j<n; j++){


            int next = (i + j)%n;

            temp += a[next] * (j);

        }

        ans = min(temp,ans);

    }

    cout << ans << '\n';

    return 0;
}