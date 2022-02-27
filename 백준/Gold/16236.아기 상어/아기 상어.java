import java.io.*;
import java.util.*;

public class Main {

	static int n, sx, sy, ssize, seat, answer, smallFish;
	static int[][] sea;
	static int[] fish = new int[7];
	static int[] dx = {-1, 0, 0, 1};
	static int[] dy = {0, -1, 1, 0};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		sea = new int[n][n];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				sea[i][j] = Integer.parseInt(st.nextToken());
				if(sea[i][j] == 0) continue;
				else if(sea[i][j] == 9) {
					sx = i;
					sy = j;
					ssize = 2;
					sea[i][j] = 0;
				} else fish[sea[i][j]]++;
			}
		}
		
		smallFish = fish[1];
		while(smallFish!=0) {
			int time = find();
			if(time==0) break;
			answer += time;
		}
		
		System.out.println(answer);
	}
	
	static int find() {
		boolean[][] visited = new boolean[n][n];
		PriorityQueue<Pos> Q = new PriorityQueue<>((e1, e2)->e1.cnt==e2.cnt?(e1.x==e2.x?e1.y-e2.y:e1.x-e2.x):e1.cnt-e2.cnt);
		Q.offer(new Pos(sx, sy, 0));
		visited[sx][sy] = true;
		
		while(!Q.isEmpty()) {
			Pos tmp = Q.poll();
			if(sea[tmp.x][tmp.y]!=0 && sea[tmp.x][tmp.y]!=ssize) {
				eat(tmp.x, tmp.y);
				return tmp.cnt;
			}
			
			for(int i=0; i<4; i++) {
				int xx = tmp.x+dx[i];
				int yy = tmp.y+dy[i];
				if(xx<0 || xx>=n || yy<0 || yy>=n || visited[xx][yy] || sea[xx][yy]>ssize) continue;
				visited[xx][yy] = true;
				Q.offer(new Pos(xx, yy, tmp.cnt+1));
			}
		}
		
		return 0;
	}
	
	static void eat(int x, int y) {
		sea[x][y] = 0;
		smallFish--;
		seat++;
		sx = x;
		sy = y;
		if(seat==ssize) {
			seat=0;
			if(ssize<7) smallFish += fish[ssize];
			ssize++;
		}
	}
	
	static class Pos{
		int x, y, cnt;
		Pos(int x, int y, int cnt){
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
	}
}
