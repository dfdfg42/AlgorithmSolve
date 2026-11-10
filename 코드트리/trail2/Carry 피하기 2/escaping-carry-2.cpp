#include <iostream>

using namespace std;

int n;
int arr[20];

bool isCarry(int a, int b , int c){

    int carry = 0;
    while(a>0 || b>0 || c >0 ){

        if(a%10 + b%10 + c%10 + carry >= 10){
            return false;
        }

        carry = (a%10+b%10+c%10)/10;
        a /= 10;
        b /= 10;
        c /= 10;

    }

    return true;

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans =-1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(isCarry(arr[i],arr[j] ,arr[k])) {
                    ans = max(arr[i] + arr[j] + arr[k] , ans);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}