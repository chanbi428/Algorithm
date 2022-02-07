import java.util.*;
import java.io.*;


public class Main {	
	static class Top{
		int h, index;
		Top(int h, int index){
			this.h = h;
			this.index = index;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		Stack<Top> stack = new Stack<>();
		int[] tops = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			tops[i] = Integer.parseInt(st.nextToken());
			while(!stack.empty()) {
				if(stack.peek().h<tops[i]) {
					stack.pop();
				} 
				else break;
			}
			if(!stack.empty()) sb.append(stack.peek().index+1+" ");
			else sb.append("0 ");
			stack.push(new Top(tops[i], i));
		}
		System.out.println(sb);
		
	}
}
