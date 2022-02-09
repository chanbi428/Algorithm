import java.util.*;
import java.io.*;


public class Main {
	static int[] num;
	static int[] answer = new int[6];
	static StringBuilder sb = new StringBuilder();
	static int k;
	
	static void lotto(int cnt, int index) {
		if(cnt==6) {
			for(int x : answer) sb.append(x).append(" ");
			sb.append("\n");
			return;
		}
		for(int i=index; i<k; i++) {
			answer[cnt] = num[i];
			lotto(cnt+1, i+1);
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		while(true) {
			st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			if(k==0) break;
			
			num = new int[k];
			for(int i=0; i<k; i++) {
				num[i] = Integer.parseInt(st.nextToken());
			}
			lotto(0, 0);
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}
