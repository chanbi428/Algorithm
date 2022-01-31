import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer stra = new StringTokenizer(br.readLine());
		StringTokenizer strb = new StringTokenizer(br.readLine());
		int[] a = new int[n]; 
		int[] b = new int[n]; 
		
		for(int i=0; i<n; i++) {
			a[i] = Integer.parseInt(stra.nextToken());
			b[i] = Integer.parseInt(strb.nextToken());
		}
		
		Arrays.sort(a);
		Arrays.sort(b);
		int answer = 0;
		
		for(int i=0; i<n; i++) {
			answer += a[i]*b[n-i-1];
		}
		System.out.println(answer);
	}
}
