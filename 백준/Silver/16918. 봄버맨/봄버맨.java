import java.io.*;
import java.util.*;

public class Main {
	
	static int r, c, n;
	static char[][] arr;
	static int[] dx = {0, 0, -1, 1};
	static int[] dy = {-1, 1, 0, 0};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		arr = new char[r][c];
		
		Queue<int[]> bomb = new ArrayDeque<>();  // 폭탄 있는 위치들 
		Queue<int[]> empty = new ArrayDeque<>(); // 빈칸들 
		
		for(int i=0; i<r; i++) {
			arr[i] = br.readLine().toCharArray();
			for(int j=0; j<c; j++) {
				if(arr[i][j]=='O') bomb.add(new int[] {i, j, 3});
				else empty.add(new int[] {i, j});
			}
		}
		
		for(int sec=2; sec<=n; sec++) {
			while(!empty.isEmpty()) {
				int[] tmp = empty.poll();
				arr[tmp[0]][tmp[1]] = 'O';
				bomb.offer(new int[] {tmp[0], tmp[1], sec+3});
			}
			sec++;
			if(sec>n) break;
			
			Queue<int[]> bomb2 = new ArrayDeque<>();
			boolean[][] visited = new boolean[r][c];
			while(!bomb.isEmpty()) {
				int[] tmp = bomb.poll();
				if(tmp[2]!=sec) {
					if(!visited[tmp[0]][tmp[1]]) bomb2.add(tmp);
					continue;
				}
				if(!visited[tmp[0]][tmp[1]]) {
					arr[tmp[0]][tmp[1]] = '.';
					empty.add(new int[] {tmp[0], tmp[1]});
					visited[tmp[0]][tmp[1]] = true;
				}
				for(int i=0; i<4; i++) {
					int x = tmp[0]+dx[i];
					int y = tmp[1]+dy[i];
					if(x<0 || x>=r || y<0 || y>=c || visited[x][y]==true) continue;
					arr[x][y] = '.';
					empty.add(new int[] {x, y});
					visited[x][y] = true;
				}
			}
			bomb = bomb2;
		}
		
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
				System.out.print(arr[i][j]);
			}
			System.out.println();
		}
		
	}
}
