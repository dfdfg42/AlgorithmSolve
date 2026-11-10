#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main() {
    cin >> n;
    cin >> str;

    int ans = 0;
    
    for(int i=0; i<n; i++){

        if(str[i] == 'C')
        for(int j= i+1; j<n; j++){

            if(str[j]=='O')
            for(int k=j+1; k<n; k++){

                if(str[k] == 'W') ans++;
            }
        }
    }

    cout << ans <<'\n';

    return 0;
}