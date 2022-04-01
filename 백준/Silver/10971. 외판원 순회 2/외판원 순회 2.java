import java.io.*;
import java.util.*;

public class Main{
	
	static int n, answer = Integer.MAX_VALUE;
	static int[][] arr;
	static boolean[] visited;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		visited = new boolean[n];
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		visited[0] = true;
		dfs(0, 1, 0);
		System.out.println(answer);
		
	}
	
	static void dfs(int num, int cnt, int sum) {
		if(cnt==n) {
			if(arr[num][0]==0) return;
			answer = Math.min(answer, sum+arr[num][0]);
			return;
		}
		if(sum>answer) return;
		for(int i=1; i<n; i++) {
			if(!visited[i] && arr[num][i]!=0) {
				visited[i] = true;
				dfs(i, cnt+1, sum+arr[num][i]);
				visited[i] = false;
			}
		}
	}
}
