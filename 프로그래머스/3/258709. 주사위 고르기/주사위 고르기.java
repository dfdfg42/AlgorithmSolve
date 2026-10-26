import java.util.*;


class Solution {
    
    public int n;
    public int[][] gDices;
    public ArrayList<Integer> aSums;
    public ArrayList<Integer> bSums;
    
    public int aWins;
    public int[] winDices;
    
    public int calWins(ArrayList<Integer> aSums,ArrayList<Integer> bSums){
        
        int win = 0;
        for(int i=0; i<aSums.size(); i++){
            
            int target = aSums.get(i);
            
            //이분탐색
            int l=0, r = bSums.size()-1;
            int mid = (l+r)/2;
            int temp = 0;
            while(l<=r){
                mid = (l+r)/2;
                
                if(bSums.get(mid) < target){
                    temp = mid+1;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            
            win += temp;
        }
        
        return win;
        
    }
    
    //주사위들의 합 종류 구하기 
    public void diceComb(int[] aDices,int[] bDices){
        
        aSums = new ArrayList<>();
        bSums = new ArrayList<>();
        
        makeSums(aDices,0,0,aSums);
        makeSums(bDices,0,0,bSums);
        
        Collections.sort(bSums);
        
        int win = calWins(aSums, bSums);
        
        if(win > aWins){
            aWins = win;
            winDices = aDices.clone();
        }
        
    }
    
    public void makeSums(int[] dice, int depth,int sum, ArrayList<Integer> sums){
        
        if(depth == dice.length){
            sums.add(sum);
            return;
        }
        
        int nowDice =  dice[depth];
        
        for(int i=0; i<6; i++){
            
            makeSums(dice, depth+1, sum + gDices[nowDice][i],sums);
            
        }
        
    }
    
    public void diceAlloc(int [] aDice,int[] bDice,int index, int aCount , int bCount){
        
        if(index == n){
            diceComb(aDice,bDice);
            return;
        }
        
        
        if(aCount < n/2){
            aDice[aCount] = index;
            diceAlloc(aDice,bDice,index+1,aCount+1,bCount); 
            
        }
        if(bCount < n/2){
            bDice[bCount] = index;
            diceAlloc(aDice,bDice,index+1,aCount,bCount+1); 
            
        }
        
        
    }
    
    public int[] solution(int[][] dice) {
        int[] answer = {};
        n = dice.length;
        gDices = dice;
        
        //주사위 n/2 개로 A와 B에게 할당
        aWins = -1;
        diceAlloc(new int[n/2], new int[n/2],0,0,0);
        
        //A 에서 나오는 합들 미리 구하기
        //B 에서 나오는 합들 미리 구하기
        
        //A합들 개별로  B의 합이 작은 것들의 개수 (이분탐색)
        
        //그걸로 승 개수를 고를 수 있음 -> 가장 승 많은 조합 추적해서 정답으로 기록
        
       for (int i = 0; i < winDices.length; i++) {
            winDices[i]++;
        }
        
        return winDices;
    }
}