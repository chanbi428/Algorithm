import java.util.*;

class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        
        StringBuilder sb = new StringBuilder();
        while(true){
            if(n/k==0){
                sb.append(n);
                break;
            }
            sb.append(n%k);
            n = n/k;
        }
        String str = sb.reverse().toString();
        //System.out.println(str);
        
        String[] nums = str.split("0");
       // for(String num : nums) System.out.print(num+",");
        
        for(String num : nums){
            if(isPrime(num)) answer++;
        }
        
        return answer;
    }
    
    static boolean isPrime(String str){
        if(str.equals("")) return false;
        long num = Long.parseLong(str);
        
        if(num==1) return false;
        for(long i=2; i*i<=num; i++){
            if(num%i==0) return false;
        }
        
        return true;
    }
}