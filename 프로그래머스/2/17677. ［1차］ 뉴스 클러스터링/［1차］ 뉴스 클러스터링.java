import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        
        
        Map<String,Integer>  m1 = new HashMap<>();
        Map<String,Integer> m2 = new HashMap<>();
        
        int interSize = 0;
        int sumSize = 0;
        
    
        for(int i=0; i+1<str1.length(); i++){

            
            String temp = str1.substring(i,i+2);
            temp = temp.toLowerCase();
            
            boolean f = true;
            for(int j=0; j<temp.length(); j++){
                if(!Character.isLetter(temp.charAt(j)))  f = false;
            }
            
            if(!f) continue;
            m1.put(temp,m1.getOrDefault(temp,0)+1);
            
        }
        
        for(int i=0; i+1<str2.length(); i++){
            
            String temp = str2.substring(i,i+2);
            temp = temp.toLowerCase();
            boolean f = true;
            for(int j=0; j<temp.length(); j++){
                if(!Character.isLetter(temp.charAt(j)))  f = false;
            }
            
            if(!f) continue;
            m2.put(temp,m2.getOrDefault(temp,0)+1);
            
        }
        
        for(Map.Entry<String,Integer> entry : m1.entrySet()){
            String key = entry.getKey();
            int val = entry.getValue();
            
            if(!m2.containsKey(key)){
                sumSize += val;
            }
            else{
                int val2 = m2.get(key);
                
                interSize += Math.min(val , val2);
                sumSize += Math.max(val , val2);
                
                
            }
        }
        for(Map.Entry<String,Integer> entry : m2.entrySet()){
            String key = entry.getKey();
            int val = entry.getValue();
            
            if(!m1.containsKey(key)){
                sumSize += val;
            }
            
        }
        
        if(sumSize == 0) return 65536;

        answer = (int)((double)interSize / sumSize * 65536);
        
        
        
        return answer;
    }
}