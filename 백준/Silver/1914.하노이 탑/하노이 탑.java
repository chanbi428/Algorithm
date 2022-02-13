import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

	static StringBuilder answer = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger bi = new BigInteger("1");
		int n = Integer.parseInt(br.readLine());
		
		if(n<=20) {
			answer.append((int)(Math.pow(2, n)-1)+"\n");
			hanoi(n, 1, 2, 3);
		}
		else {
			for(int i=0; i<n; ++i) {
                bi = bi.multiply(new BigInteger("2"));
            }
            bi = bi.subtract(new BigInteger("1"));
            answer.append(bi);
		}
		System.out.println(answer);
	}
	static void hanoi(int n, int from, int temp, int to) {
		if(n==1) {
			answer.append(from+" "+to+"\n");
			return;
		}
		hanoi(n-1, from, to, temp);
		answer.append(from+" "+to+"\n");
		hanoi(n-1, temp, from, to);
	}

}