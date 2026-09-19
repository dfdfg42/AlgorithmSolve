#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    //dp[i][j] i행 j열을 밟았을 때의 최대값

    vector<vector<int>> dp(n,vector<int>(m,0));
    
    for(int i=0; i<m; i++){
        dp[0][i] = land[0][i];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            
            
            for(int k=0; k<m; k++){
                if(j == k ) continue;
                dp[i][j] = max(dp[i-1][k] + land[i][j] , dp[i][j]);
            }
            
        }
    }
    
    for(int col = 0; col<m; col++){
        answer = max(dp[n-1][col] ,answer);
    }
    

    return answer;
}