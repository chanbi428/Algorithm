package bj;
import java.io.*;
import java.util.*;

public class BJ_치킨배달_15686 {
	
	static int n, m, hcnt, ccnt, answer = Integer.MAX_VALUE;
	static ArrayList<Pos> chicken = new ArrayList<>();
	static ArrayList<Pos> house = new ArrayList<>();
	static int[][] dis;
	static int[] min;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				int type = Integer.parseInt(st.nextToken());
				if(type == 1) {
					hcnt++;
					house.add(new Pos(i, j));
				} else if(type == 2) {
					ccnt++;
					chicken.add(new Pos(i, j));
				}
			}
		}
		
		dis = new int[hcnt][ccnt];
		
		for(int i=0; i<hcnt; i++) {
			for(int j=0; j<ccnt; j++) {
				dis[i][j] = Math.abs(house.get(i).x-chicken.get(j).x)+Math.abs(house.get(i).y-chicken.get(j).y);
			}
		}
		
		min = new int[hcnt];
		Arrays.fill(min, Integer.MAX_VALUE);
		comb(0, 0);
		System.out.println(answer);
	}
	
	static void comb(int index, int cnt) {
		if(cnt==m) {
			int sum = 0;
			for(int i=0; i<hcnt; i++) {
				sum += min[i];
			}
			answer = Math.min(sum, answer);
			return;
		}
		for(int i=index; i<ccnt; i++) {
			int[] tmp = Arrays.copyOf(min, hcnt);
			for(int j=0; j<hcnt; j++) {
				min[j] = Math.min(min[j],dis[j][i]);
			}
			comb(i+1, cnt+1);
			min = tmp;
		}
	}
	
	static class Pos{
		int x, y;
		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
}
