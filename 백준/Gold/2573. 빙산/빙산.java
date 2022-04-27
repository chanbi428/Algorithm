import java.util.*;
import java.io.*;

public class Main {
	
	static int n, m;
	static int[][] arr;
	static Queue<int[]> Q = new ArrayDeque<>();
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j]!=0) Q.offer(new int[] {i, j});
			}
		}
		
		int answer = 1;
		while(!Q.isEmpty()) {
			melt();
			if(!bfs()) break;
			answer++;
		}
		
		if(Q.size()==0) System.out.println("0");
		else System.out.println(answer);
	}
	
	static void melt() {
		Queue<int[]> tmp = new ArrayDeque<>();
		int[][] arr2 = new int[n][m];
		
		while(!Q.isEmpty()) {
			int[] t = Q.poll();
			int cnt = 0;
			for(int i=0; i<4; i++) {
				int x = t[0] + dx[i];
				int y = t[1] + dy[i];
				if(x<0 || x>=n || y<0 || y>=m) continue;
				if(arr[x][y] == 0 && arr2[x][y] == 0) cnt++;
			}
			arr2[t[0]][t[1]] = arr[t[0]][t[1]];
			if(arr[t[0]][t[1]]-cnt<=0) {
				arr[t[0]][t[1]] = 0;
			} else {
				tmp.offer(t);
				arr[t[0]][t[1]] -= cnt;
			}
		}
		
		Q = tmp;
	}
	
	static boolean bfs() {
		if(Q.isEmpty()) return true;
		
		Queue<int[]> tmp = new ArrayDeque<>();
		boolean[][] visited = new boolean[n][m];
		int[] s = Q.peek();
		tmp.offer(s);
		int cnt = 1;
		visited[s[0]][s[1]] = true;
		
		while(!tmp.isEmpty()) {
			int[] t = tmp.poll();
			for(int i=0; i<4; i++) {
				int x = t[0] + dx[i];
				int y = t[1] + dy[i];
				if(x<0 || x>=n || y<0 || y>=m || arr[x][y]==0 || visited[x][y]) continue;
				cnt++;
				visited[x][y] = true;
				tmp.offer(new int[] {x,y});
			}
		}
		
		if(cnt==Q.size()) return true;
		else return false;
	}

}
