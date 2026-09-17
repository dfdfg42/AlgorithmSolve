#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef long long ll;

int solution(vector<int> scoville, int K) {
    
    ll count = 0;
    priority_queue<ll,vector<ll>,greater<>> pq;
    for(auto a : scoville){
        pq.push(a);
    }
    
    
    while(pq.top() < K && pq.size() >=2 ){
        
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        
        pq.push(a + (b*2));
        
        count++;
    }
    
    if(pq.top() < K ) return -1;
    
    
    return count;
}