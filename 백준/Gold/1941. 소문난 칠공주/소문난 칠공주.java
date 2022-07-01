import java.io.*;
import java.util.*;

public class Main {
	
	static char[][] arr;
	static char[] student = new char[25];
	static int[] princess = new int[7];
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static boolean[][] visited;
	static int answer;
	 
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		arr = new char[5][5];
		visited = new boolean[5][5];
		
		for(int i=0; i<5; i++) {
			arr[i] = br.readLine().toCharArray();
			for(int j=0; j<5; j++) {
				student[i*5+j] = arr[i][j];
			}
		}
		
		comb(0, 0, 0, 0);
		
		System.out.println(answer);
		
	}
	
	static void comb(int index, int cnt, int ycnt, int scnt) {
		if(ycnt>3) return;
		if(cnt==7) {
			if(isPoss()) answer++;
			return;
		}
		for(int i=index; i<25; i++) {
			visited[i/5][i%5] = true;
			princess[cnt] = i;
			if(student[i]=='Y') comb(i+1, cnt+1, ycnt+1, scnt);
			else comb(i+1, cnt+1, ycnt, scnt);
			visited[i/5][i%5] = false;
		}
	}
	
	static boolean isPoss() {
		Queue<int[]> Q = new ArrayDeque<>();
		Q.offer(new int[] {princess[0]/5, princess[0]%5});
		boolean[][] visited2 = new boolean[5][5];
		visited2[princess[0]/5][princess[0]%5] = true;
		
		int cnt = 1;
		while(!Q.isEmpty()) {
			int[] t = Q.poll();
			for(int i=0; i<4; i++) {
				int xx = t[0]+dx[i];
				int yy = t[1]+dy[i];
				if(xx<0 || xx>=5 || yy<0 || yy>=5 || !visited[xx][yy] || visited2[xx][yy]) continue;
				visited2[xx][yy] = true;
				Q.offer(new int[] {xx, yy});
				cnt++;
			}
		}
		
		if(cnt==7) return true;
		else return false;
	}

}
