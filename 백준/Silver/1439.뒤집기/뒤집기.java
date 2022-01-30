import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] num = br.readLine().toCharArray();
		int zero = 0, one = 0;
		char type = '2';
		for(int i=0; i<num.length; i++) {
			if(num[i]!=type) {
				type = num[i];
				if(type == '1') one++;
				else if(type == '0') zero++;
			}
		}
		System.out.println(Math.min(one, zero));
	}
}
