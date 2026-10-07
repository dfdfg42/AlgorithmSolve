#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    vector<int> stack;
    int n = order.size();
    int seq = 0;
    for(int i=0; i<n; i++){
        
        stack.push_back(i+1);
        while(!stack.empty() && stack.back() == order[seq]){
            seq++;
            stack.pop_back();
        }
        
        
    }
    
    return seq;
}