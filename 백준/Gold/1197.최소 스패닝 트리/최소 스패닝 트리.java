import java.io.*;
import java.util.*;

public class Main {
	
	static int[] parents;
	static Info[] infos;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		//int T = Integer.parseInt(br.readLine());
		
		//for(int t = 1; t<=T; t++) {
			//answer.append("#"+t+" ");
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			int v = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			parents = new int[v+1];
			infos = new Info[e];
			makeSet(v);
			
			for(int i=0; i<e; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				
				infos[i] = new Info(a, b, c);
			}
			Arrays.sort(infos, (i1, i2)->i1.c-i2.c);
			
			int cnt = 0;
			long sum = 0L;
			for(int i=0; i<e; i++) {
				int a = infos[i].a;
				int b = infos[i].b;
				if(union(a,b)) {
					sum += infos[i].c;
					cnt++;
				}
				if(cnt==v-1) break;
			}
			
			answer.append(sum+"\n");
		//}
		System.out.println(answer.toString());
	}
	
	static void makeSet(int n) {
		for(int i=1; i<=n; i++) {
			parents[i] = i;
		}
	}
	
	static int find(int a) {
		if(parents[a]==a) return a;
		return parents[a] = find(parents[a]);
	} 
	
	static boolean union(int a, int b) {
		int aP = find(a);
		int bP = find(b);
		if(aP==bP) return false;

		parents[aP] = bP;
		return true;
	}
	
	static class Info{
		int a, b, c;
		Info(int a, int b, int c){
			this.a = a;
			this.b = b;
			this.c = c;
		}
	}

}
