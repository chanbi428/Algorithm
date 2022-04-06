import java.io.*;
import java.util.*;

public class Main{
	
	static int r, c, t;
	static char[][] miro;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static boolean[][] visited;
	static Queue<int[]> FQ = new ArrayDeque<>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		miro = new char[r][c];
		visited = new boolean[r][c];
		
		int x = 0, y = 0; // 지훈이 처음 위치 
		for(int i=0; i<r; i++) {
			miro[i] = br.readLine().toCharArray();
			for(int j=0; j<c; j++) {
				if(miro[i][j]=='J') { // 지훈이 위치 
					x = i; y = j;
				} else if(miro[i][j]=='F') {
					FQ.offer(new int[] {i, j, 0});
				}
			}
		}
		
		int answer = bfs(x, y);
		if(answer == -1) System.out.println("IMPOSSIBLE");
		else System.out.println(answer+1);
	}
	
	static int bfs(int x, int y) {

		Queue<int[]> Q = new ArrayDeque<>();
		Q.offer(new int[] {x, y, 0});
		visited[x][y] = true;
		
		while(!Q.isEmpty()) {
			int[] tmp = Q.poll();
			if(tmp[2]!=t) t++;
			if(!FQ.isEmpty() && FQ.peek()[2]== t) fire();
			for(int i=0; i<4; i++) {
				int xx = tmp[0] + dx[i];
				int yy = tmp[1] + dy[i];
				if(xx<0 || xx>=r || yy<0 || yy>=c) return tmp[2];
				if((xx==0 || xx==r-1 || yy==0 || yy==c-1) && miro[xx][yy]=='.') return tmp[2]+1;
				if(visited[xx][yy] || miro[xx][yy]!='.') continue;
				visited[xx][yy] = true;
				Q.offer(new int[] {xx, yy, tmp[2]+1});
			}
		}
		
		return -1;
	}
	
	static void fire() {
		while(true) {
			if(FQ.isEmpty() || FQ.peek()[2]!=t) return;
			int[] tmp = FQ.poll();
			for(int i=0; i<4; i++) {
				int xx = tmp[0] + dx[i];
				int yy = tmp[1] + dy[i];
				if(xx<0 || xx>=r || yy<0 || yy>=c || miro[xx][yy]=='#' || miro[xx][yy]=='F') continue;;
				miro[xx][yy] = 'F';
				FQ.offer(new int[] {xx, yy, tmp[2]+1});
			}
		}
	}
}
