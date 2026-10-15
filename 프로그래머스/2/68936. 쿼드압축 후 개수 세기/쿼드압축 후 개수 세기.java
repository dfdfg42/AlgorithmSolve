class Solution {
    
    static int[] answer;
    
    public void dfs(int r, int c, int size, int[][] arr){
        
        if(size == 1) {
            if(arr[r][c] == 1) answer[1]++;
            else answer[0]++;
            return;
        }
        
        boolean allSame = true;
        int base = arr[r][c];
        for(int row=r; row<r+size; row++){
            for(int col = c; col<c+size; col++){
                if(arr[row][col] != base) {
                    allSame = false;
                    break;
                }
            }
            if(!allSame)break;
        }
        
        if(allSame) {
            answer[arr[r][c] == 1 ? 1 : 0]++;
            return;
        }
        
        int n_size = size/2;
        
        dfs(r,c,n_size,arr);
        dfs(r,c+n_size,n_size,arr);
        dfs(r+n_size,c,n_size,arr);
        dfs(r+n_size,c+n_size,n_size,arr);
        
        return;
        
    }
    
    public int[] solution(int[][] arr) {
        answer = new int[2];
        
        dfs(0,0,arr.length,arr);
        
        return answer;
    }
}