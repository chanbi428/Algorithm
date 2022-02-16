import java.io.*;
import java.util.*;

public class Main {

	static int answer, r, c;
	static boolean flag;
	
	static void visit(int n, int x, int y) {
		if(flag) return;
		
		int tmp = 1<<n;
		if(r<x || r>=x+tmp || c<y || c>=y+tmp) {
			answer += tmp*tmp;
			return;
		}
		
		if(n==0) {
			flag = true;
			return;
		}
		visit(n-1, x, y);
		visit(n-1, x, y+tmp/2);
		visit(n-1, x+tmp/2, y);
		visit(n-1, x+tmp/2, y+tmp/2);
	
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		visit(n, 0, 0);
		System.out.println(answer);
	}	
}