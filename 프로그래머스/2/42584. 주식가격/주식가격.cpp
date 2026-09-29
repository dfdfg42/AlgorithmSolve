#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    
    vector<int> st;
    for(int i=0; i<n; i++){
        
        while(!st.empty() && prices[st.back()] > prices[i]){
            
            int prev = st.back();
            st.pop_back();
            
            answer[prev] = i - prev;
            
            
        }
        st.push_back(i);
        
    }
    
    while(!st.empty()){
        int now = st.back();
        st.pop_back();
        answer[now] = n-now-1;
    }
    
    return answer;
}