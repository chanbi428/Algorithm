import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = -1;
        
        Queue<Integer> Q1 = new ArrayDeque<>();
        Queue<Integer> Q2 = new ArrayDeque<>();
        Queue<Integer> Q3 = new ArrayDeque<>();
        Queue<Integer> Q4 = new ArrayDeque<>();
        
        Queue<Integer> originQ1 = new ArrayDeque<>();
        Queue<Integer> originQ2 = new ArrayDeque<>();
        
        long total = 0;
        long sum1 = 0;
        long sum2 = 0;
        for(int i : queue1){
            total += i;
            sum1 += i;
            Q1.offer(i);
            Q3.offer(i);
            originQ1.offer(i);
        }
        for(int i : queue2){
            total += i;
            sum2 += i;
            Q2.offer(i);
            Q4.offer(i);
            originQ2.offer(i);
        }
        
        long middle = total/2;
        int cnt1 = 0;
        int cnt2 = 0;
        while(cnt1<queue1.length*3){
            if(sum1==middle) break;
            else if(sum1<middle){
                sum1 += Q2.peek();
                Q1.offer(Q2.poll());
            } else{
                sum1 -= Q1.peek();
                Q2.offer(Q1.poll());
            }
            cnt1++;
        }
        
         while(cnt2<queue1.length*3){
            if(sum2==middle) break;
            else if(sum2<middle){
                sum2 += Q3.peek();
                Q4.offer(Q3.poll());
            } else{
                sum2 -= Q4.peek();
                Q3.offer(Q4.poll());
            }
            cnt2++;
        }
        
        //System.out.println(cnt1+" "+cnt2);
        if(cnt1!=queue1.length*3 && cnt2!=queue1.length*3) answer = Math.min(cnt1, cnt2);
        else if(cnt1!=queue1.length*3) answer = cnt1;
        else if(cnt2!=queue1.length*3) answer = cnt2;
        
        return answer;
    }
}