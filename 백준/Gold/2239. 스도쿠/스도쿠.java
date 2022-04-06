import java.io.*;
import java.util.*;

public class Main{
	
	static boolean[][] xv = new boolean[9][10];
	static boolean[][] yv = new boolean[9][10];
	static boolean[][] dv = new boolean[9][10];
	static int[][] dn = {{0,0,0,1,1,1,2,2,2},
						{0,0,0,1,1,1,2,2,2},
						{0,0,0,1,1,1,2,2,2},
						{3,3,3,4,4,4,5,5,5},
						{3,3,3,4,4,4,5,5,5},
						{3,3,3,4,4,4,5,5,5},
						{6,6,6,7,7,7,8,8,8},
						{6,6,6,7,7,7,8,8,8},
						{6,6,6,7,7,7,8,8,8}};
	static int[][] sdoku;
	static ArrayList<int[]> zero = new ArrayList<>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sdoku = new int[9][9];
		for(int i=0; i<9; i++) {
			String str = br.readLine();
			for(int j=0; j<9; j++) {
				sdoku[i][j] = str.charAt(j)-'0';
				if(sdoku[i][j]!=0) {
					xv[i][sdoku[i][j]] = true;
					yv[j][sdoku[i][j]] = true;
					dv[dn[i][j]][sdoku[i][j]] = true;
				} else zero.add(new int[] {i, j});
			}
		}
		
		if(!zero.isEmpty()) dfs(0);
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				sb.append(sdoku[i][j]);
			}
			sb.append("\n");
		}
		
		System.out.println(sb.toString());
	}
	
	static boolean dfs(int cnt) {
		if(cnt == zero.size()) {
			return true;
		}
		int x = zero.get(cnt)[0];
		int y = zero.get(cnt)[1];
		int d = dn[x][y];

		for(int i=1; i<=9; i++) {
			if(xv[x][i] || yv[y][i] || dv[d][i]) continue;

			sdoku[x][y] = i;
			xv[x][i] = true;
			yv[y][i] = true;
			dv[d][i] = true;
			
			if(dfs(cnt+1)) return true;
			
			sdoku[x][y] = 0;
			xv[x][i] = false;
			yv[y][i] = false;
			dv[d][i] = false;
		}
		return false;
	}
	
}
