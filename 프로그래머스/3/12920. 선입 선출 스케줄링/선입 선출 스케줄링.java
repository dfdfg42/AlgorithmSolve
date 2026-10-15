import java.util.*;

class Solution {
    public int solution(int n, int[] cores) {
        int answer = 0;
        
        if (n <= cores.length) {
            return n;
        }
        
        int l = 0, r = 500000000;
        
        while(l<r){
            int mid = (l+r)/2;
            
            long totalComplete =  cores.length;
            for(int c : cores){
                totalComplete += mid/c;
            }
            
            if(totalComplete >= n ){
                r = mid;
            }
            else{
                
                l = mid+1;
                
            }
            
        }
        
        
        
        int time = l;

        
        long count = cores.length;
        for (int c : cores) {
            count += (time - 1) / c;
        }

        
        for (int i = 0; i < cores.length; i++) {
            if (time % cores[i] == 0) {
                count++;

                if (count == n) {
                    return i + 1;
                }
            }
        }

        return -1;
    }
}