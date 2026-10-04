import java.util.*;
import java.io.*;

class Solution {
    
    public boolean isPrime(long value){
        if(value <2) return false;
        
        for(long i=2; i*i <=value; i++){
            if(value % i ==0 ) return false;
         }
        
        return true;
    }
    
    public int solution(int n, int k) {
        int answer = 0;
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
    
        
        //1 n을 k 진수로 바꾸고
        String conv =  Integer.toString(n,k);
        String[] numbers = conv.split("0");
        
        for(String num: numbers){
            if (num.isEmpty()) continue;
            long value = Long.parseLong(num);
            if(isPrime(value)){
                answer++;
            }
            
        }
        
        
        
        return answer;
    }
}