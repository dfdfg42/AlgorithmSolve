class Solution {
    public long[] solution(long[] numbers) {
        int n = numbers.length;
        long[] answer = new long[n];
        
        for(int i=0; i<n; i++){
            long num = numbers[i];
            if(num % 2 == 0){
                answer[i]=  num +1;
                continue;
            }
            
            long bit = 1L;
            
            while((num & bit) != 0 ){
                bit <<= 1;
            }
            
            answer[i] = num + bit - (bit>>1);
        }
        
        return answer;
    }
}