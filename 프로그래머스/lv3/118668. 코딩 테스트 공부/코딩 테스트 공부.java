import java.util.*;

class Solution {
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;
        
        int max_alp = alp;
        int max_cop = cop;
        
        for(int i=0; i<problems.length; i++){
            max_alp = Math.max(max_alp, problems[i][0]);
            max_cop = Math.max(max_cop, problems[i][1]);
        }
        int[][] dp = new int[max_alp+2][max_cop+2];
        for(int i=alp; i<=max_alp; i++) Arrays.fill(dp[i], Integer.MAX_VALUE);
        dp[alp][cop] = 0;
        
        for(int i=alp; i<=max_alp; i++){
            for(int j=cop; j<=max_cop; j++){
                dp[i+1][j] = Math.min(dp[i+1][j], dp[i][j]+1);
                dp[i][j+1] = Math.min(dp[i][j+1], dp[i][j]+1);
                
                for(int k=0; k<problems.length; k++){
                    if(i>=problems[k][0] && j>=problems[k][1]){
                        int next_alp = Math.min(max_alp, i+problems[k][2]);
                        int next_cop = Math.min(max_cop, j+problems[k][3]);
                        dp[next_alp][next_cop] = Math.min(dp[next_alp][next_cop], dp[i][j]+problems[k][4]);
                    }
                }
            }
        }
        
        return dp[max_alp][max_cop];
    }
    
}