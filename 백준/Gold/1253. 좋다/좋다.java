import java.util.*;
import java.io.*;

public class Main {


	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[] num = new int[n];
		Map<Integer, Integer> cnt = new HashMap<>();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			num[i] = Integer.parseInt(st.nextToken());
			if(cnt.containsKey(num[i])) cnt.replace(num[i], cnt.get(num[i])+1);
			else cnt.put(num[i], 1);
		}
		Arrays.sort(num);
		
		int answer = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n ; j++) {
				if(i==j) continue;
				int tmp = num[i] - num[j];
				if(tmp == num[j] && tmp==num[i]) {
					if(cnt.get(tmp)>2) {
						answer++;
						break;
					}
				} else if(tmp == num[i] || tmp == num[j]){
					if(cnt.get(tmp)>1) {
						answer++;
						break;
					}
				}else {
					if(cnt.containsKey(tmp)) {
						answer++;
						break;
					}
				}
			}
		}
		
		System.out.println(answer);
		
	}
	
}
