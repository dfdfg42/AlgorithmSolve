#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    //다리에 처음 올라간 뒤, 다리를 내려 올 때 까지 다리 길이만큼의 시간 걸림
    //초당 1개의 버스만 다리에 올라갈 수 있고, 초당 1개의 버스만 다리에서 빠져나올 수 있음
    
    int bridge_cap = 0;
    
    //나갈시각 , 무게
    queue<pair<int,int>> bridge;
    
    
    int time = 0;
    for(int truck : truck_weights){
        
        time++;
        
        while(!bridge.empty() && bridge.front().first <= time){
            bridge_cap -= bridge.front().second;
            bridge.pop();
        }
        
        while(bridge_cap + truck > weight){
            time = bridge.front().first;
            
            bridge_cap -= bridge.front().second;
            bridge.pop();
        }
        
        bridge.push({time + bridge_length, truck});
        bridge_cap += truck;
        
    }
    
    return bridge.back().first;
}