import java.io.*;
import java.util.*;

public class Main{
	
	static int[] parent;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int sum = 0;
		int[] arr = new int[n];
		Map<Integer, Integer> map = new HashMap<>();
		
		for(int i=0; i<n; i++) {
			int num = Integer.parseInt(br.readLine());
			sum += num;
			arr[i] = num;
			if(map.containsKey(num)) {
				map.put(num, map.get(num)+1);
			}else map.put(num, 1);
		}
		Arrays.sort(arr);
		
		PriorityQueue<int[]> pq = new PriorityQueue<>((e1, e2)->e2[0]==e1[0]?e1[1]-e2[1]:e2[0]-e1[0]);
		for(int m : map.keySet()) {
			pq.add(new int[] {map.get(m), m});
		}
		int[] first = pq.poll();
		int[] second = pq.isEmpty()?new int[] {0, 0} : pq.poll();
		
		System.out.println(Math.round((double)sum/n));
		System.out.println(arr[n/2]);
		if(first[0]==second[0]) System.out.println(second[1]);
		else System.out.println(first[1]);
		System.out.println(arr[n-1]-arr[0]);
	}
	
}
