import java.util.*;

class Solution {
    public int[] solution(String msg) {
        
        int n = msg.length();
        int seq = 27;
        List<Integer> result = new ArrayList<>();
        
        HashMap<String,Integer> dic = new HashMap<>();
        
        for(int i=1; i<=26; i++){
            dic.put("" + (char)('A'+i -1), i);
        }
        
        //현재글자 + 다음글자 사전에 없으면 , 현재글자 출력,  현재글자 다음글자 사전추가
        for(int i=0; i<n; i++){
            
            int in = i;
            String temp = "" + msg.charAt(i);
            while(in < n){
                in++;
                if(in == n){
                    result.add(dic.get(temp));
                    i = in-1;
                    break;
                }
                String temp2 = temp + msg.charAt(in);
                if(dic.get(temp2) == null){
                    dic.put(temp2, seq++);
                    result.add(dic.get(temp));
                    i = in-1;
                    break;
                }
                temp = temp2;
                
            }
            
            
        }
        int[] answer = new int[result.size()];
        for(int i=0; i<result.size(); i++){
           answer[i] =result.get(i);
        }
        
        return answer;
    }
}