import java.io.*;
import java.util.*;

public class Main{
	
	static int n, m, sec, cnt;
	static int[][] cheese;
	//static boolean[][] visited;
	//static Queue<int[]> Q = new ArrayDeque<>();
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		cheese = new int[n][m];
		//visited = new boolean[n][m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				cheese[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int tmp = 0;
		while(true) {
			sec++;
			tmp = air();
			if(tmp==0) break;
			cnt = tmp;
		}
		//melt();
		System.out.println((sec-1)+"\n"+cnt);
	}
	
	static int air() {
		boolean[][] visited = new boolean[n][m];
		visited[0][0] = true;
		Queue<int[]> a = new ArrayDeque<>();
		int tmp = 0;
		a.offer(new int[] {0, 0});
		while(!a.isEmpty()) {
			int[] t = a.poll();
			for(int i=0; i<4; i++) {
				int x = t[0]+dx[i];
				int y = t[1]+dy[i];
				if(x<0 || x>=n || y<0 || y>=m || visited[x][y]) continue;
				if(cheese[x][y]==0) a.offer(new int[] {x, y});
				else {
					tmp++;
					cheese[x][y] = 0;
				}
				visited[x][y] = true;
			}
		}
		return tmp;
	}

}
