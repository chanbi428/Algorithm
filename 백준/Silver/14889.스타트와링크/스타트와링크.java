import java.util.*;
import java.io.*;

public class Main {
	static int n, min = Integer.MAX_VALUE;
	static int[][] arr;
	static boolean[] visited;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		visited = new boolean[n];
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		visited = new boolean[n];
		DFS(0, 0);
		System.out.println(min);
	}
	static void DFS(int index, int cnt) {
		if(cnt==n/2) {
			min = Math.min(diff(), min);
			return;
		}
		for(int i=index; i<n; i++) {
			visited[i] = true;
			DFS(i+1, cnt+1);
			visited[i] = false;
		}
	}
	static int diff() {
		int start = 0, link = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(visited[i] && visited[j]) {
					start += arr[i][j];
				}
				if(!visited[i] && !visited[j]) {
					link += arr[i][j];
				}
			}
		}
		return Math.abs(start-link);
	}

}
