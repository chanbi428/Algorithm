import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		String a = st.nextToken();
		String b = st.nextToken();
		int alen = a.length();
		int blen = b.length();
		int answer = blen;
		if(b.contains(a)) answer = 0;
		else {
			for(int i=0; i<=blen-alen; i++) {
				int cnt = 0;
				for(int j=0; j<alen; j++) {
					if(a.charAt(j)!=b.charAt(i+j)) cnt++;
				}
				answer = Math.min(answer, cnt);
			}
		}
		System.out.println(answer);
	}
}
