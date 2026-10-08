class Solution {
    
    public static char[][] Board;
    public static boolean[][] checkBoard;
    public static int g_m;
    public static int g_n;
    int answer;
    
    public boolean check(){
        
        boolean can = false;
        checkBoard = new boolean[g_m][g_n];
        
        for(int i = 0; i<g_m-1; i++){
            for(int j=0; j<g_n-1; j++){
                if(Board[i][j] == 'X') continue;
                if(Board[i][j] == Board[i+1][j] && Board[i][j] == Board[i][j+1] && Board[i][j] == Board[i+1][j+1]){
                checkBoard[i][j] = true;
                checkBoard[i][j+1] = true;
                checkBoard[i+1][j] = true;
                checkBoard[i+1][j+1] = true;
                can = true; 
                }
                    
                
                
            }
        }
        return can;
    }
    
    public void removeAndCount(){
        
        for(int i=0; i<g_m; i++){
            for(int j=0; j<g_n; j++){
                if(checkBoard[i][j] == true){
                    answer++;
                    Board[i][j] = 'X';
                }
            }
        }
        
    }
    
    public void fall(){
        
        for(int col=0; col<g_n; col++){
            int floor = g_m-1;
            for(int row = g_m-1; row>=0; row--){
                if(Board[row][col]!='X'){
                    char temp = Board[row][col];
                    Board[row][col] = 'X';
                    Board[floor][col] = temp;
                    floor--;
                    
                }
            }
        }
        
    }
    
    public int solution(int m, int n, String[] board) {
        
        g_m = m;
        g_n = n;
        Board =  new char[m][n];
        answer = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                Board[i][j] = board[i].charAt(j);
            }
        }
        
        // m x n <= 300
        // 4개 뭉치 확인 후 표시 = 3364
        // 4개 뭉치 삭제 + 카운팅
        // 중력효과 300 
        // (3364 + 300  ) *5
        
        while(check()){
            removeAndCount();
            fall();
        }
        
        return answer;
    }
}