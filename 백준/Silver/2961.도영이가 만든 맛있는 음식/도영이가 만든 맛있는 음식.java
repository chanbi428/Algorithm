import java.io.*;
import java.util.*;

public class Main {
	
	static int n, answer = Integer.MAX_VALUE;
	static int[][] ingre;
	
	static void bitsubset() {
		int s = 1<<n;
		
		for(int i=1; i<s; i++) {
			
			int sour = 1;
			int bitter = 0;
			
			for(int j=0; j<n; j++) {
				if((i&(1<<j))!=0) {
					sour *= ingre[j][0];
					bitter += ingre[j][1];
				}
			}
			answer = Math.min(answer, Math.abs(sour-bitter));
		}

	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		ingre = new int[n][2];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			ingre[i][0] = Integer.parseInt(st.nextToken());
			ingre[i][1] = Integer.parseInt(st.nextToken());
		}
		
		bitsubset();
		System.out.println(answer);
	}	
}