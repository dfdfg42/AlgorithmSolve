#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a;

int main() {
    cin >> a;
    int ans = 0;
    for(int i=0; i<a.length(); i++){

        string temp = a;

        if(temp[i] =='0'){
            temp[i] = '1';
        }else{
            temp[i] = '0';
        }

        int val = 0;
        int len = temp.length();
        for(int j = len -1; j>=0; j--){
            if(temp[j] == '1'){
                val += 1 << (len - j -1);
            }
           
        }
        
        ans = max(val,ans);
    }
    
    cout << ans <<'\n';

    return 0;
}