import java.io.*;
import java.util.*;

public class Main{
	
	static int n, m;
	static char[][] miro;
	static boolean[][][] visited;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		miro = new char[n][m];
		visited = new boolean[n][m][1<<6+1];
		int x = 0, y = 0;
		for(int i=0; i<n; i++) {
			miro[i] = br.readLine().toCharArray();
			for(int j=0; j<m; j++) {
				if(miro[i][j]=='0') {
					x = i; y = j;
				}
			}
		}
		
		System.out.println(bfs(x, y));
	}
	
	static int bfs(int x, int y) {
		Queue<int[]> Q = new ArrayDeque<>();
		Q.offer(new int[] {x, y, 0, 0});
		visited[x][y][0] = true;
		
		while(!Q.isEmpty()) {
			int[] t = Q.poll();
			if(miro[t[0]][t[1]]=='1') return t[3];
			for(int i=0; i<4; i++) {
				int xx = t[0] + dx[i];
				int yy = t[1] + dy[i];
				if(xx<0 || xx>=n || yy<0 || yy>=m || miro[xx][yy] == '#' || visited[xx][yy][t[2]]) continue;
				if(miro[xx][yy]>='a' && miro[xx][yy]<='f') {
					int t2 = t[2] | 1<<(miro[xx][yy]-'a'+1);
					Q.offer(new int[] {xx, yy, t2, t[3]+1});
					visited[xx][yy][t2] = true;
				} 
				else if(miro[xx][yy]>='A' && miro[xx][yy]<='F') {
					if((t[2] & 1<<(miro[xx][yy]-'A'+1)) != 0) {
						Q.offer(new int[] {xx, yy, t[2], t[3]+1});
						visited[xx][yy][t[2]] = true;
					}
				}
				else {
					Q.offer(new int[] {xx, yy, t[2], t[3]+1});
					visited[xx][yy][t[2]] = true;
				}
			}
		}
		
		return -1;
	}
}
