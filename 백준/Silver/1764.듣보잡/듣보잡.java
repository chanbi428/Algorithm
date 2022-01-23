import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		Set<String> set = new HashSet<>();
		ArrayList<String> answer = new ArrayList<>();
		
		for(int i=0; i<n; i++) {
			String str = br.readLine();
			set.add(str);
		}
		for(int i=0; i<m; i++) {
			String str = br.readLine();
			if(set.contains(str)) answer.add(str);
		}
		br.close();
		Collections.sort(answer);
		System.out.println(answer.size());
		for(String x: answer) System.out.println(x);
	}
}
