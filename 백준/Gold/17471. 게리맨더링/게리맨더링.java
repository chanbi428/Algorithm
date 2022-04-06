import java.io.*;
import java.util.*;

public class Main{
	
	static int n, total,  answer = Integer.MAX_VALUE;
	static int[] people;
	static int visited;
	static ArrayList<Integer>[] area;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		people = new int[n+1];
		area = new ArrayList[n+1];
		for(int i=1; i<=n; i++) {
			area[i] = new ArrayList<>();
		}

		total = 0;
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; i++) {
			people[i] = Integer.parseInt(st.nextToken());
			total += people[i];
		}
		
		for(int i=1; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			for(int j=0; j<m; j++) {
				int num = Integer.parseInt(st.nextToken());
				area[i].add(num);
			}
		}
		subset();
		if(answer == Integer.MAX_VALUE) System.out.println("-1");
		else System.out.println(answer);
	}
	
	static void subset() {
		int size = (1<<n)-1;
		for(int i = 1; i<size; i++) {
			visited = i;
			int diff = sum();
			if(diff != -1) answer = Math.min(answer, diff);
		}
	}
	
	static int sum() {
		ArrayList<Integer> A = new ArrayList<>();
		ArrayList<Integer> B = new ArrayList<>();
		for(int i=1; i<=n; i++) {
			if((visited & (1<<i)) != 0) A.add(i);
			else B.add(i);
		}
		
		if(A.size() == 0 || B.size() == 0) return -1;
		if(isConnect(A, 1) && isConnect(B, 0)) {
			int a = 0;
			for(int i=0; i<A.size(); i++) {
				a += people[A.get(i)];
			}
			int b = total - a;
			return Math.abs(a-b);
		}
		
		return -1;
	}
	
	static boolean isConnect(ArrayList<Integer> arr, int flag) {
		boolean[] visit = new boolean[n+1];
		Queue<Integer> Q = new ArrayDeque<>();
		Q.offer(arr.get(0));
		visit[arr.get(0)] = true;
		while(!Q.isEmpty()) {
			int num = Q.poll();
			for(int i=0; i<area[num].size(); i++) {
				int tmp = area[num].get(i);
				if(visit[tmp]) continue;
				if(flag == 1 && (visited & (1<<tmp))==0) continue;
				if(flag == 0 && (visited & (1<<tmp))!=0) continue;
				visit[tmp] = true;
				Q.offer(tmp);
			}
		}
		
		for(int i=0; i<arr.size(); i++) {
			if(!visit[arr.get(i)]) return false;
		}
		
		return true;
	}
	
}
