import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
			int n = Integer.parseInt(st.nextToken());
			int[][] tall = new int[n+1][n+1];
			int m = Integer.parseInt(st.nextToken());
			for(int i=0; i<m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				tall[a][b] = 1;
				tall[b][a] = -1;
			}
			
			for(int k=1; k<=n; k++) {
				for(int i=1; i<=n; i++) {
					if(k==i) continue;
					for(int j=1; j<=n; j++) {
						if(i==j || j==k) continue;
						if(tall[i][j]==0) {
							if(tall[i][k]==1 && tall[k][j]==1) {
								tall[i][j] = 1;
								tall[j][i] = -1;
							} else if(tall[i][k]==-1 && tall[k][j]==-1) {
								tall[i][j] = -1;
								tall[j][i] = 1;
							}
						}
					}
				}
			}
			
			int answer = 0;
			for(int i=1; i<=n; i++) {
				int tmp = 1;
				for(int j=1; j<=n; j++) {
					if(tall[i][j]!=0) tmp++;
				}
				if(tmp == n) answer++;
			}
		
		
		System.out.println(answer);
	}
	
}
