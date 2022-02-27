import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] map;
	static int n;
	static int[] dx = {0, 0, -1, 1};
	static int[] dy = {-1, 1, 0, 0};
	static PriorityQueue<Info> Q = new PriorityQueue<>((e1, e2)->e1.sum-e2.sum);

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t = 1;
		
		while(true) {
			n = Integer.parseInt(br.readLine());
			
			if(n==0) break;
			map = new int[n][n];
			
			for(int i=0; i<n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j=0; j<n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int answer = BFS();
			sb.append("Problem "+(t++)+": "+answer+"\n");
		}
		System.out.println(sb.toString());
	}
	
	static int BFS() {
		boolean[][] visited = new boolean[n][n];
		int[][] min = new int[n][n];
		for(int i=0; i<n; i++) Arrays.fill(min[i], Integer.MAX_VALUE);
		Q.clear();
	
		Q.offer(new Info(0, 0, map[0][0]));
		min[0][0] = map[0][0];
		
		while(!Q.isEmpty()) {
			Info info = Q.poll();
			int x = info.x;
			int y = info.y;
			if(min[x][y]<info.sum) continue;
			if(x==n-1 && y==n-1) break;
			visited[x][y] = true;
			
			for(int i=0; i<4; i++) {
				int xx = x+dx[i];
				int yy = y+dy[i];
				if(xx<0 || xx>=n || yy<0 || yy>=n || visited[xx][yy] || info.sum+map[xx][yy]>min[xx][yy]) continue;
				min[xx][yy] = info.sum+map[xx][yy];
				Q.offer(new Info(xx, yy, min[xx][yy]));
			}
		}
		
		return min[n-1][n-1];
	}
	
	static class Info{
		int x, y, sum;
		public Info(int x, int y, int sum) {
			this.x = x;
			this.y = y;
			this.sum = sum;
		}
	}
	
}
