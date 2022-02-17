import java.io.*;
import java.util.*;

public class Main {
	
	static int r, c, answer;
	static char[][] street;
	static int[] dx = {-1, 0, 1};
	
	static boolean steal(int x, int y) {
		if(y==c-1) {
			return true;
		}
		for(int k=0; k<3; k++) {
			if(x+dx[k]<0 || x+dx[k]>=r || street[x+dx[k]][y]=='x') continue;
			street[x+dx[k]][y] = 'x';
			if(steal(x+dx[k], y+1)) return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		street = new char[r][c];
		for(int i=0; i<r; i++) street[i] = br.readLine().toCharArray();

		for(int i=0; i<r; i++) {
			if(steal(i, 1)) answer++;
		}
		System.out.println(answer);
	}
	
}