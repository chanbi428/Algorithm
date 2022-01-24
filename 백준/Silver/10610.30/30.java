import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		br.close();
		int sum = 0;
		int[] num = new int[10];
		for(int i=0; i<str.length(); i++) {
			int n = str.charAt(i)-'0';
			num[n]++;
			sum += n;
		}
		if(num[0]!=0 && sum%3==0) {
			StringBuilder sb = new StringBuilder();
			for(int i=9; i>=0; i--) {
				for(int j=0; j<num[i]; j++) sb.append(i);
			}
			System.out.println(sb);
		}
		else System.out.println("-1");
	}
}
