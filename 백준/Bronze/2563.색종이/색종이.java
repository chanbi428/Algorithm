import java.io.*;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int answer = 0;
		int n = Integer.parseInt(br.readLine());
		int[][] paper = new int[100][100];
		for(int t=0; t<n; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			for(int i=x; i<x+10; i++) {
				for(int j=y; j<y+10; j++) {
					if(paper[i][j]==0) {
						answer++;
						paper[i][j] = 1;
					}
				}
			}
		}
		System.out.println(answer);
	}
}
