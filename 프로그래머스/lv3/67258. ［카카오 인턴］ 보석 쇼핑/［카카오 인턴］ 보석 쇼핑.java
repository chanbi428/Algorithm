import java.util.*;
class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        Map<String, Integer> kind = new HashMap<>();
        for(int i=0; i<gems.length; i++){
            kind.put(gems[i], 0);
        }
        int s = 0, e = 0, n = kind.size(), as= -1, ae = -1;
        int cnt = 0;
        int len = Integer.MAX_VALUE;
        int t = 1;
        while(s<=e){
            if(cnt==n){
                if(len>e-s){
                    len = e-s;
                    as = s;
                    ae = e-1;
                }
                String st = gems[s];
                kind.replace(st, kind.get(st)-1);
                if(kind.get(st)==0) cnt--;
                s++;
            }
            else{
                if(e==gems.length) break;
                String gem = gems[e];
                if(kind.get(gem)==0){
                    kind.replace(gem, 1);
                    cnt++;
                } else{
                    kind.replace(gem, kind.get(gem)+1);
                }
                e++;
            }
        }
        
        answer[0] = as+1;
        answer[1] = ae+1;
        return answer;
    }
}