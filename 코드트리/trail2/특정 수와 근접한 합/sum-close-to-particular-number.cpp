#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, S;
int arr[100];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for(int i=0; i<N; i++){
        sum += arr[i];
    }

    int findS=0;
    int T = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){

            int temp = sum - arr[i] - arr[j];

            if(abs(S-findS) > abs(S-temp)){
                findS = temp;
                T = temp;
            }

        }
    }
    

    cout << abs(findS - S) << '\n';

    return 0;
}