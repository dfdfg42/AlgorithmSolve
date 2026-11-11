#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int nums[12];

vector<int> points;
int ans;

void dfs(int index){

    if(index == n){
        int temp = 0;
        for(int i=0;i<k; i++){
            if(points[i]>=m) temp++;
        }
        ans = max(ans,temp);
        return;
    }

    for(int i=0; i<k; i++){

        points[i] += nums[index];
        dfs(index+1);
        points[i] -= nums[index];

    }

}

int main() {
    cin >> n >> m >> k;
    ans = 0;

    points.resize(k,1);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    dfs(0);
    
    cout << ans <<'\n';

    return 0;
}
