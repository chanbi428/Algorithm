import java.util.*;
import java.io.*;


public class Main {	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		Stack<int[]> stack = new Stack<>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; i++) {
			int height = Integer.parseInt(st.nextToken());
			while(!stack.empty()) {
				if(stack.peek()[1]>=height) {
					sb.append(stack.peek()[0]).append(" ");
					break;
				} 
				stack.pop();
			}
			if(stack.empty()) sb.append("0 ");
			stack.push(new int[] {i, height});
		}
		System.out.println(sb);
		
	}
}
