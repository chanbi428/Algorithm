import java.io.*;
import java.util.*;

public class Main{
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int w = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		int[][] arr = new int[h][w];
		
		for(int i=0; i<h; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<w; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int[] mx = {-1, 1, 0, 0};
		int[] my = {0, 0, -1, 1};
		int[] hx = {-1, -2, -2, -1, 1, 2, 2, 1};
		int[] hy = {-2, -1, 1, 2, 2, 1, -1, -2};
		
		Queue<int[]> Q = new ArrayDeque<>();
		boolean[][][] visited = new boolean[h][w][k+1];
		Q.offer(new int[] {0, 0, 0, 0});
		visited[0][0][0] = true;
		while(!Q.isEmpty()) {
			int[] t = Q.poll();
			if(t[0]==h-1 && t[1]==w-1) {
				System.out.println(t[3]);
				return;
			}
			for(int i=0; i<4; i++) {
				int x = t[0]+mx[i];
				int y = t[1]+my[i];
				if(x<0 || x>=h || y<0 || y>=w || arr[x][y]==1 || visited[x][y][t[2]]) continue;
				Q.offer(new int[] {x, y, t[2], t[3]+1});
				visited[x][y][t[2]] = true;
			}
			if(t[2]<k) {
				for(int i=0; i<8; i++) {
					int x = t[0]+hx[i];
					int y = t[1]+hy[i];
					if(x<0 || x>=h || y<0 || y>=w || arr[x][y]==1 || visited[x][y][t[2]+1]) continue;
					Q.offer(new int[] {x, y, t[2]+1, t[3]+1});
					visited[x][y][t[2]+1] = true;
				}
			}
		}
		System.out.println("-1");
	}

}
