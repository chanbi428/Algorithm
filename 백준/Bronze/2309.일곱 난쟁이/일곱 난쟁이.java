import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] nan = new int[9];
		int sum = 0;
		for(int i=0; i<9; i++) {
			nan[i] = Integer.parseInt(br.readLine());
			sum += nan[i];
		}
		sum -= 100;
		boolean flag = false;
		int[] answer = new int[7];
		for(int i=0; i<9; i++) {
			for(int j=i+1; j<9; j++) {
				if(nan[i] + nan[j] == sum) {
					int cnt = 0;
					for(int k=0; k<9; k++) {
						if(k==i || k==j) continue;
						answer[cnt++] = nan[k];
						flag = true;
					}
					break;
				}
				if(flag) break;
			}
		}
		Arrays.sort(answer);
		for(int i=0; i<7; i++) {
			System.out.println(answer[i]);
		}
		
	}
}
