import java.util.*;
import java.io.*;

public class Main {
	static int n, k;
	static String[] card;
	static boolean[] visited;
	static Set<String> set = new HashSet<>();
	static void num(int cnt, String str) {
		if(cnt==k) {
			set.add(str);
			return;
		}
		for(int i=0; i<n; i++) {
			if(!visited[i]) {
				visited[i] = true;
				num(cnt+1, str+card[i]);
				visited[i] = false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		k = Integer.parseInt(br.readLine());
		card = new String[n];
		visited = new boolean[n];
		for(int i=0; i<n; i++) {
			card[i] = br.readLine();
		}
		num(0, "");
		System.out.println(set.size());
	}
}
