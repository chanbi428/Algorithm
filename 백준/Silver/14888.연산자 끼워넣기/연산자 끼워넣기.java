import java.util.*;
import java.io.*;

public class Main {
	static int n, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
	static int[] num, sign;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		num = new int[n];
		sign = new int[4];
		for(int i=0; i<n; i++) num[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<4; i++) sign[i] = Integer.parseInt(st.nextToken());
		br.close();
		
		DFS(1, num[0]);
		System.out.println(max);
		System.out.println(min);
		
	}
	static void DFS(int index, int sum) {
		if(index == n) {
			min = Math.min(sum, min);
			max = Math.max(sum, max);
			return;
		}
		for(int i=0; i<4; i++) {
			if(sign[i]!=0) {
				sign[i]--;
				if(i==0) DFS(index+1, sum+num[index]);
				else if(i==1) DFS(index+1, sum-num[index]);
				else if(i==2) DFS(index+1, sum*num[index]);
				else DFS(index+1, sum/num[index]);
				sign[i]++;
			}
		}
	}

}
