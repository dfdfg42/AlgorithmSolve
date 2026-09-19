#include <string>
#include <vector>

using namespace std;

vector<char> sys = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};

string convert(int input,int base){
    if(input == 0) return "0";
    
    string out = "";
    
    
    while(input > 0){
        
        out += sys[input%base]; 
        
        input /= base;
    }
    
    return out;
    
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int count = 0;
    int target = 0;
    int seq = 0;
    
    while(answer.size() < t){
        
        
        string convStr = convert(target, n);
            
        for(int i=0; i<convStr.length(); i++){

            if(seq%m == p-1){
                answer += convStr[convStr.length() - i -1];
                
                if(answer.size() == t)
                return answer;
            }
            seq++;

        }
        
        target++;
        
        
    }
    
    
    return answer;
}