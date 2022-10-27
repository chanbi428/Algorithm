import java.util.*;

class Solution {
    
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int n, m;
    
    public int solution(int[][] maps) {
        int answer = 0;
        
        n = maps.length;
        m = maps[0].length;
        answer = bfs(maps);
        
        return answer;
    }
    
    static int bfs(int[][] maps){
        
        boolean[][] visited = new boolean[n][m];
        Queue<int[]> Q = new ArrayDeque<>();
        Q.offer(new int[]{0, 0, 1});
        visited[0][0] = true;
        
        while(!Q.isEmpty()){
            int[] tmp = Q.poll();
            
            if(tmp[0]==n-1 && tmp[1]==m-1) return tmp[2];
            for(int i=0; i<4; i++){
                int x = tmp[0] + dx[i];
                int y = tmp[1] + dy[i];
                
                if(x<0 || x>=n || y<0 || y>=m || visited[x][y] || maps[x][y]==0) continue;
                Q.offer(new int[]{x, y, tmp[2]+1});
                visited[x][y] = true;
            }
        }
        
        return -1;
    }
}