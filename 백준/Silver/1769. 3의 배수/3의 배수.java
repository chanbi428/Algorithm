import java.util.*;
import java.io.*;

public class Main {	
	static void three(int cnt, String num) {
		if(num.length()<2) {
			System.out.println(cnt);
			if(Integer.parseInt(num)%3==0) System.out.println("YES");
			else System.out.println("NO");
			return;
		}
		int sum = 0;
		for(int i=0; i<num.length(); i++) {
			sum+=num.charAt(i)-'0';
		}
		three(cnt+1, String.valueOf(sum));
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String n = br.readLine();
		three(0, n);
	}
}
