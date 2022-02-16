import java.io.*;
import java.util.*;

public class Main {
	
	static int n, m, answer;
	static int[] cost;
	
	static boolean poss(int mid) {
		int sum = 0;
		for(int i=0; i<n; i++) {
			sum+= (cost[i]<=mid?cost[i]:mid);
		}
		if(sum<=m) return true;
		else return false;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int min = 0, max = 0;
		n = Integer.parseInt(br.readLine());
		cost = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			cost[i] = Integer.parseInt(st.nextToken());
			max = Math.max(max, cost[i]);
		}
		m = Integer.parseInt(br.readLine());
		
		min = m/n;
		while(min<=max) {
			int mid = (max+min)/2;
			if(poss(mid)) {
				answer = Math.max(answer, mid);
				min = mid+1;
			} else {
				max = mid-1;
			}
		}
		
		System.out.println(answer);
		
	}
	
}