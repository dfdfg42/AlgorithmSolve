import java.util.*;

class Solution {
    
    public class File implements Comparable<File>{
        
        String head;
        int number;
        int inputSeq;
        String original;
        
        public File(String file, int inputSeq){
            this.original = file;
            this.inputSeq = inputSeq;
            
            int idx = 0;
            
            while(idx < file.length() && !Character.isDigit(file.charAt(idx))){
                idx++;
            }
            this.head = file.substring(0, idx).toUpperCase();
            
            int start = idx;
            
            while(idx < file.length() && Character.isDigit(file.charAt(idx)) && idx-start <5){
                idx++;
            }
            
            this.number = Integer.parseInt(file.substring(start,idx));
            
        }
            
            
        
        @Override
        public int compareTo(File other){
            
            if(!this.head.equals(other.head)){
                return this.head.compareTo(other.head);
            }
            else if(this.number != other.number){
                return this.number - other.number;
            }
            return this.inputSeq - other.inputSeq;
            
            
            
        }
        
    }
    
    public String[] solution(String[] files) {
        String[] answer = new String[files.length];
        int n = files.length;
        
        ArrayList<File> Files = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            
            Files.add(new File(files[i],i));
            
        }
        
        Collections.sort(Files);
        
        for (int i = 0; i < n; i++) {
            answer[i] = Files.get(i).original;
        }
        
        return answer;
    }
}