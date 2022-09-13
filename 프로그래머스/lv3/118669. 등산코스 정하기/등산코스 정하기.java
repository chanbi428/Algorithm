import java.util.*;

class Solution {
    static List<int[]>[] list;
    static int[] mountain;
    static boolean[] visited;
    static int[] intensity;
    static PriorityQueue<int[]> Q = new PriorityQueue<>((e1, e2) -> e1[1]-e2[1]);
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        mountain = new int[n+1];
        visited = new boolean[n+1];
        intensity = new int[n+1];
        list = new ArrayList[n+1];
        for(int i=0; i<=n; i++) {
            list[i] = new ArrayList<int[]>();
        }
        Arrays.fill(intensity, Integer.MAX_VALUE);
        
        
        for(int gate : gates) mountain[gate] = 1;  // 출입구
        for(int summit : summits) mountain[summit] = 2; // 산봉우리
        
        for(int[] path : paths){
            if(mountain[path[1]]!=1 && mountain[path[0]]!=2) list[path[0]].add(new int[]{path[1], path[2]});
            if(mountain[path[0]]!=1 && mountain[path[1]]!=2) list[path[1]].add(new int[]{path[0], path[2]});
        }
        
        for(int gate : gates){
            intensity[gate] = 0;
        }
        for(int i=1; i<=n; i++) Q.offer(new int[]{i, intensity[i]});
        climb(n);
        
        int[] answer = new int[]{0, Integer.MAX_VALUE};
        for(int summit : summits){
            if(answer[1] == intensity[summit]){
                if(summit<answer[0]) answer[0] = summit;
            } else if(answer[1] > intensity[summit]){
                answer[1] = intensity[summit];
                answer[0] = summit;
            }
        }
        //for(int i=1; i<=n; i++) System.out.print(intensity[i]+" ");
        
        return answer;
    }
    
    static void climb(int n){
        int cnt = 0;
        while(true){
            if(cnt==n) break;
            int index = Q.poll()[0];
            
            //System.out.println(index);
            if(index == 0) break;
            visited[index] = true;
            cnt++;
            
            for(int i=0; i<list[index].size(); i++){
                int[] next = list[index].get(i);
                if(!visited[next[0]]){
                    if(intensity[next[0]] > Math.max(intensity[index], next[1])){
                        intensity[next[0]] = Math.max(intensity[index], next[1]);
                        Q.offer(new int[]{next[0], intensity[next[0]]});
                    }
                }
            }
        }
    }
}