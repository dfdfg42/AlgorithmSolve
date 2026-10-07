import java.util.*;

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        int n = skill_trees.length;
        
        HashMap<Character,Integer> sHash = new HashMap<>();
        
        for(int i=0; i<skill.length(); i++){
            sHash.put(skill.charAt(i),i+1);
        }
        
        for(int st = 0; st <n; st++){
            
            String pSkill = skill_trees[st];
            
            int learnSkill = 0;
            
            for(int i=0; i<pSkill.length(); i++){
                
                if(sHash.get(pSkill.charAt(i)) != null){
                    if(learnSkill == sHash.get(pSkill.charAt(i)) -1 ){
                        learnSkill++;
                    }else{
                        break;
                    }
                    
                }
                
                if( i == pSkill.length()-1) answer++;
            }
            
            
        }
        
        return answer;
    }
}