import java.io.*;

public class Main {
	
	static int[] nan = new int[9];
	static int[] answer = new int[7];
	static StringBuilder sb = new StringBuilder();
	static boolean flag;
	
	static void comb(int cnt, int index, int sum) {
		if(flag || sum>100) return;
		if(cnt == 7) {
			if(sum == 100) {
				for(int x: answer) sb.append(x+"\n");
				flag = true;
			}
			return;
		}
		for(int i=index; i<9; i++) {
			answer[cnt] = nan[i];
			comb(cnt+1, i+1, sum+nan[i]);
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=0; i<9; i++) {
			nan[i] = Integer.parseInt(br.readLine());
		}
		comb(0, 0, 0);
		System.out.println(sb.toString());
	}
}