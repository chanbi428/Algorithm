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
		
		int n = Integer.parseInt(br.readLine());
		int[] answer = new int[n];
		Stack<Top> stack = new Stack<>();
		int[] tops = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			tops[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=n-1; i>=0; i--) {
			while(!stack.empty()) {
				if(stack.peek().h<tops[i]) {
					answer[stack.peek().index] = i+1;
					stack.pop();
				} 
				else break;
			}
			stack.push(new Top(tops[i], i));
		}
		for(int i=0; i<n; i++) System.out.print(answer[i]+" ");
		
	}
}
