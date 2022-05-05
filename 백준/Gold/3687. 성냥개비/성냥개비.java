import java.util.*;
import java.io.*;

public class Main {
	
	static String[] max = new String[101];
	static String[] min = new String[101];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		maxNum();
		minNum();
		for(int i=0; i<n; i++) {
			int m = Integer.parseInt(br.readLine());
			sb.append(min[m]+" "+max[m]+"\n");
		}
//		for(int i=2; i<=100; i++) {
//			System.out.println(i+" "+min[i]+" "+max[i]);
//		}
		
		System.out.println(sb.toString());
	}
	
	static void maxNum() {
		max[2] = "1";
		max[3] = "7";
		for(int i=4; i<=100; i++) max[i] = max[i-2]+"1";
	}
	
	static void minNum() {
		String tmp[] = {"1", "7", "4", "2", "6", "8", "10", "18", "22", "20", "28", "68", "88", "108", "188", "200"};
		for(int i=0; i<16; i++) min[i+2] = tmp[i];
		for(int i=18; i<=100; i++) min[i] = min[i-7] + "8";
	}
}
