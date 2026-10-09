import java.util.*;
class Solution {
    
    static int n;
    static int answer;
    static String g_numbers;
    static boolean[] primes ;
    static HashSet<Integer> nums;
    
    public void dfs(int index , String choosen , boolean[] visited , int len){
        
        if( choosen.length() == len){
            
            if(nums.contains(Integer.parseInt(choosen))) return;
            
            if(!primes[Integer.parseInt(choosen)])  answer++;
            
            nums.add(Integer.parseInt(choosen));
            return;
        }
        
        for(int i=0; i<n; i++){
            
            if(visited[i] == false){
                visited[i] = true;
                dfs(index+1,choosen + g_numbers.charAt(i),visited,len);
                visited[i] = false;
            }
            
        }
        
    }
    
    public int solution(String numbers) {
        
        int range = 100_000_000;
        answer = 0;
        g_numbers = numbers;
        n = numbers.length();
        primes = new boolean[range+1];
        nums = new HashSet<>();
        
        primes[0] = true;
        primes[1] = true;
        for(int i=2; i<=range; i++){
            if(primes[i] == false){
                for(int j = i + i; j<=range; j+=i){
                    primes[j] = true;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            dfs(0,"",new boolean[n], i);
        }
        
        return answer;
    }
}