import java.io.*;
import java.util.*;

public class Main {

	static int answer, r, c;
	static boolean flag;
	
	static void visit(int n, int x, int y) {
		if(flag) return;
		if(n==0) {
			flag = true;
			return;
		}
		int tmp = 1<<(n-1);
		if(r>=x && r<x+tmp && c>=y && c<y+tmp) {
			visit(n-1, x, y);
			return;
		}
		else answer += tmp*tmp;
		if(r>=x && r<x+tmp && c>=y+tmp && c<y+tmp*2) {
			visit(n-1, x, y+tmp);
			return;
		}
		else answer += tmp*tmp;
		if(r>=x+tmp && r<x+tmp*2 && c>=y && c<y+tmp) {
			visit(n-1, x+tmp, y);
			return;
		}
		else answer += tmp*tmp;
		if(r>=x+tmp && r<x+tmp*2 && c>=y+tmp && c<y+tmp*2) {
			visit(n-1, x+tmp, y+tmp);
			return;
		}
		else answer += tmp*tmp;
	
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