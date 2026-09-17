#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int topEarn;
vector<pair<int,int>> jobs;

void dfs(int index, int earn){

    if(index >= n){
        topEarn = max(earn,topEarn);
        return;
    }

    if(index + jobs[index].first <= n){
        dfs(index + jobs[index].first , earn + jobs[index].second);
    }

    dfs(index+1,earn);

}

int main() {
    


    cin >> n;
    topEarn = 0;


    for(int i=0; i<n; i++){
        int t, p;
        cin >> t >> p;
        jobs.push_back({t,p});
    }

    dfs(0,0);
    cout << topEarn <<'\n';
    return 0;
}