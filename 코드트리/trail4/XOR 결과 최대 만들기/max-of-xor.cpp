#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int A[20];

vector<int> selected;
int ans;

void dfs(int index){

    if(selected.size()  == m){
        int temp = 0;

        for(int i=0; i<selected.size(); i++){

            temp ^= selected[i];

        }   
        ans = max(ans,temp);
        return;
    }

    for(int i=index; i<n; i++){
        selected.push_back(A[i]);
        dfs(i+1);
        selected.pop_back();
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ans =0;
    dfs(0);
    cout << ans <<'\n';

    return 0;
}