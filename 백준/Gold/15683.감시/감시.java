import java.io.*;
import java.util.*;

public class Main {
	
	static int n, m, answer = Integer.MAX_VALUE;
	static int[][] room;
	static ArrayList<CCTV> cctvs;
	static int[] dx = {0, 0, -1, 1};
	static int[] dy = {1, -1, 0, 0};

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		room = new int[n][m];
		cctvs = new ArrayList<>();
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				room[i][j] = Integer.parseInt(st.nextToken());
				if(room[i][j]>=1 && room[i][j]<=5) {
					cctvs.add(new CCTV(room[i][j], i, j));
				}
			}
		}
		
		look(0);
		
		System.out.println(answer);
	}
	
	static void look(int cnt) {
		if(cnt == cctvs.size()) {
			int area = 0;
			for(int i=0; i<n; i++) {
				for(int j=0; j<m ;j++) {
					if(room[i][j]==0) area++;
				}
			}
			answer = Math.min(area, answer);
			return;
		}
		int ver = cctvs.get(cnt).ver;
		int x = cctvs.get(cnt).x;
		int y = cctvs.get(cnt).y;
		
		if(ver==1) {
			for(int i=0; i<4; i++) {
				on(x, y, i, -(cnt+1));
				look(cnt+1);
				off(x, y, i, (cnt+1));
			}
		} else if(ver==2) {
			for(int i=0; i<4; i+=2) {
				on(x, y, i, -(cnt+1));
				on(x, y, i+1, -(cnt+1));
				look(cnt+1);
				off(x, y, i, (cnt+1));
				off(x, y, i+1, (cnt+1));
			}
		} else if(ver==3) {
			for(int i=0; i<2; i++) {
				for(int j=2; j<4; j++) {
					on(x, y, i, -(cnt+1));
					on(x, y, j, -(cnt+1));
					look(cnt+1);
					off(x, y, i, (cnt+1));
					off(x, y, j, (cnt+1));
				}
			}
		} else if(ver==4) {
			for(int i=0; i<4; i++) {
				if(i!=0) on(x, y, 0, -(cnt+1));
				if(i!=1) on(x, y, 1, -(cnt+1));
				if(i!=2) on(x, y, 2, -(cnt+1));
				if(i!=3) on(x, y, 3, -(cnt+1));
				look(cnt+1);
				if(i!=0) off(x, y, 0, (cnt+1));
				if(i!=1) off(x, y, 1, (cnt+1));
				if(i!=2) off(x, y, 2, (cnt+1));
				if(i!=3) off(x, y, 3, (cnt+1));
			}
		} else {
			for(int i=0; i<4; i++) on(x, y, i, -(cnt+1));
			look(cnt+1);
			for(int i=0; i<4; i++) off(x, y, i, (cnt+1));
		}
	}
	
	static void on(int x, int y, int d, int num) {
		x += dx[d];
		y += dy[d];
		while(true) {
			if(x<0 || x>=n || y<0 || y>=m || room[x][y]==6) break;
			if(room[x][y]==0) {
				room[x][y] = num;
			}
			x += dx[d];
			y += dy[d];
		}
	}
	static void off(int x, int y, int d, int num) {
		x += dx[d];
		y += dy[d];
		while(true) {
			if(x<0 || x>=n || y<0 || y>=m || room[x][y]==6) break;
			if(room[x][y]==-num) {
				room[x][y] = 0;
			}
			x += dx[d];
			y += dy[d];
		}
	}
	
	static class CCTV{
		int ver, x, y;
		public CCTV(int ver, int x, int y) {
			this.ver = ver;
			this.x = x;
			this.y = y;
		}
	}

}
