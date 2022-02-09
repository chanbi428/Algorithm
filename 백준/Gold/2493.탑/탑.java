import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	public static int N;
	public static ArrayDeque<top> stack = new ArrayDeque<>();
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			int n = Integer.parseInt(st.nextToken());
			while(!stack.isEmpty()) {
				if(stack.peek().num < n){
					stack.pop();
				}else {
					sb.append(stack.peek().count).append(" ");
					break;
				}
			}
			if(stack.isEmpty()) {
				sb.append(0).append(" ");
			}
			stack.push(new top(n,i+1));
		}
		System.out.println(sb);
	}
	
}
class top{
	int num;
	int count;
	
	public top(int num, int count) {
		this.num = num;
		this.count = count;
	}

}