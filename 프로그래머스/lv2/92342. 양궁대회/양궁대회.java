class Solution {
    
    static int max = -1;
    static int[] arr = new int[11];
    static int[] tmp = new int[11];
    
    public int[] solution(int n, int[] info) {
        int[] answer = {};
        
        arch(0, 0, 0, n, info);
        
        if(max == -1) {
            answer = new int[1];
            answer[0] = -1;
        }
        else answer = arr;
        
        return answer;
    }
    
    static void arch(int index, int ryan, int apeach, int cnt, int[] info){
        if(index == 11){
            tmp[10] += cnt;
            if(ryan>apeach){
                
                if(ryan-apeach>max){
                   // System.out.println(ryan + " " + apeach);
                    max = ryan-apeach;
                    for(int i=0; i<11; i++) arr[i] = tmp[i];
                } else if(ryan-apeach==max){
                    for(int i=10; i>=0; i--){
                        if(arr[i]>tmp[i]) break;
                        else if(arr[i]<tmp[i]){
                            for(int j=0; j<11; j++) arr[j] = tmp[j];
                            break;
                        }
                    }
                }
            }
            tmp[10] -= cnt;
            return;
        }
        if((info[index]+1)<=cnt){
            tmp[index] = info[index]+1;
            arch(index+1, ryan+(10-index), apeach, cnt-(info[index]+1), info);
            tmp[index] = 0;
        }
        if(info[index]==0) arch(index+1, ryan, apeach, cnt, info);
        else arch(index+1, ryan, apeach+(10-index), cnt, info);
    }
}