import java.io.*;
import java.util.*;

public class Main {
	
	static long n, p, q;
	static Map<Long, Long> dp = new HashMap<>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Long.parseLong(st.nextToken());
		p = Long.parseLong(st.nextToken());
		q = Long.parseLong(st.nextToken());
		
		dp.put(0L, 1L);
		find(n);
		
		System.out.println(dp.get(n));
		
	}
	
	static long find(long num) {
		if(dp.containsKey(num)) return dp.get(num);
		dp.put(num, find(num/p) + find(num/q));
		return dp.get(num);
	}

}
