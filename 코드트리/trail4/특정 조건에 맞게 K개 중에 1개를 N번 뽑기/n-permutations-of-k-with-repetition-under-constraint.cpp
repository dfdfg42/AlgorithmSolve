#include <iostream>
#include <vector>

using namespace std;

int K, N;

vector<int> vec;
int ans ;
void dfs(int index){

    if(index == N){
        ans++;
        for(int i=0; i<vec.size(); i++){
            cout << vec[i] << ' '; 
        }
        cout <<'\n';
        return;
    }

    for(int i=1; i<=K; i++){

        if(index >= 2 && vec[index-1] == i && vec[index-2] == i) continue;

        vec.push_back(i);
        dfs(index+1);
        vec.pop_back();
    }
    
}

int main() {
    cin >> K >> N;
    ans = 0;
    // Please write your code here.
    dfs(0);


    return 0;
}
