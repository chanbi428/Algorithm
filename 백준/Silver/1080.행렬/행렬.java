import java.io.*;
import java.util.*;

public class Main {
	
	static int n, m, answer;
	static char[][] a, b;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		a = new char[n][m];
		b = new char[n][m];
		
		for(int i=0; i<n; i++) a[i] = br.readLine().toCharArray();
		for(int i=0; i<n; i++) b[i] = br.readLine().toCharArray();
		
		if(n<3 || m<3) {
			if(equalArr()) System.out.println("0");
			else System.out.println("-1");
			return;
		}
		
		for(int i=0; i<n-2; i++) {
			for(int j=0; j<m-2; j++) {
				if(a[i][j]!=b[i][j]) {
					change(i, j);
					answer++;
				}
			}
		}
		if(!equalArr()) answer = -1;
		
		System.out.println(answer);
		
	}
	
	static void change(int x, int y) {
		for(int i=x; i<x+3; i++) {
			for(int j=y; j<y+3; j++) {
				if(a[i][j]=='0') a[i][j] = '1';
				else a[i][j] = '0';
			}
		}
	}
	
	static boolean equalArr() {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]!=b[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
}