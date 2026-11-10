#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    int ans = 0;
    int n = A.length();
    for(int i=0; i<n-1; i++){

        if(A[i] == '(' && A[i+1] == '('){

            for(int j=i+1; j<n-1; j++){
                if(A[j] == ')' && A[j+1] == ')'){
                    ans++;
                }
            }

        }

    }
    cout << ans <<'\n';

    return 0;
}