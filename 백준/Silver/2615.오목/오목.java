import java.util.*;
import java.io.*;

public class Main {
	static int[][] arr;
	static int[] dx = new int[] {-1, 0, 1, 1};
	static int[] dy = new int[] {1, 1, 1, 0};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		arr = new int[20][20];
		for(int i=1; i<20; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=1; j<20; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=1; i<20; i++) {
			for(int j=1; j<20; j++) {
				if(arr[i][j]!=0) {
					int color = arr[i][j];
					for(int k=0; k<4; k++) {
						if(poss(i, j, k, color)) {
							System.out.println(color);
							System.out.println(i + " " + j);
							return;
						}
					}
				}
			}
		}
		System.out.println("0");
	}
	static boolean poss(int i, int j, int num, int color) {
		for(int k=1; k<5; k++) {
			int x = i+dx[num]*k;
			int y = j+dy[num]*k;
			if(x<1 || x>=20 || y<1 || y>=20) return false;
			if(arr[x][y]!=color) return false;
		}
		//뒤 확인 
		int x = i+dx[num]*5;
		int y = j+dy[num]*5;
		if(x>0 && x<20 && y>0 && y<20 && arr[x][y]==color) return false;
		//앞 확인 
		x = i-dx[num];
		y = j-dy[num];
		if(x>0 && x<20 && y>0 && y<20 && arr[x][y]==color) return false;
		return true;
	}
}
