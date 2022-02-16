import java.io.*;
import java.util.*;

public class Main {
	
	static int n, answer = Integer.MAX_VALUE;
	static int[][] ingre;
	
	static void comb(int index, int sour, int bitter) {
		if(index != 0) answer = Math.min(answer, Math.abs(sour-bitter));
		if(index == n) return;
		for(int i=index; i<n; i++) {
			comb(i+1, sour*ingre[i][0], bitter+ingre[i][1]);
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
		
		comb(0, 1, 0);
		System.out.println(answer);
	}	
}