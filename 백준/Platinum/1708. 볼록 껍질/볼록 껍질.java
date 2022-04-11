import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static long sy, sx;
	static long[][] point;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long[][] point = new long[n][2];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			point[i][0] = Integer.parseInt(st.nextToken());
			point[i][1] = Integer.parseInt(st.nextToken());
		}
		
		sx = point[0][0];
		sy = point[0][1];
		
		for(int i=1; i<n; i++) {
			if(sy>point[i][1]) {
				sx = point[i][0];
				sy = point[i][1];
			} else if( sy == point[i][1] && sx>point[i][0]) {
				sx = point[i][0];
				sy = point[i][1];
			}
		}
		
		Arrays.sort(point, (p1, p2) -> {
			int ret = ccw(sx, sy, p1[0], p1[1], p2[0], p2[1]);
			if(ret>0) return -1;
			else if(ret<0) return 1;
			else {
				long diff = distance(sx, sy, p1[0], p1[1]) - distance(sx, sy, p2[0], p2[1]);
				return diff > 0 ? 1 : -1;
			}
		});
		
		Stack<long[]> stack = new Stack<>();
		stack.add(new long[] {sx, sy});
		
		int length = point.length;
		for(int i=1; i<length; i++) {
			long[] next = point[i];
			while( stack.size() > 1) {
				long[] first = stack.get(stack.size()-2);
				long[] second = stack.get(stack.size()-1);
				int ret = ccw(first[0], first[1], second[0], second[1], next[0], next[1]);
				if( ret <= 0 ) stack.pop();
				else break;
			}
			stack.add(next);
		}
		
		System.out.println(stack.size());
	}
	
	static int ccw(long x1, long y1, long x2, long y2, long x3, long y3) {
		long ret = (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
		if(ret>0) return 1;
		else if(ret<0) return -1;
		else return 0;
	}
	
	static long distance(long x1, long y1, long x2, long y2) {
		return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
	}
	
}