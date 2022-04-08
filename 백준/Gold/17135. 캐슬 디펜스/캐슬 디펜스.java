import java.io.*;
import java.util.*;

public class Main {
	
	static int n, m, d, max;
	static int[][] map;
	static int[] archer = new int[3];
	static ArrayList<Enemy> enemy = new ArrayList<>();
	static ArrayList<Enemy> enemyCopy = new ArrayList<>();
	static PriorityQueue<Enemy> pq = new PriorityQueue<>( (e1, e2) -> {
		return e1.d == e2.d ? e1.y - e2.y : e1.d - e2.d;
	} );
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j]==1) {
					enemyCopy.add(new Enemy(i, j));
				}
			}
		}
		
		comb(0, 0);
		System.out.println(max);
		
	}
	
	static void check() {
		// 적군 자료구조 정리 
		enemy.clear();
		for(Enemy e : enemyCopy) {
			enemy.add(new Enemy(e.x, e.y));
		}
		int dead = 0; // 죽는 적군의 수 
		while(true) {
			
			for(int i=0; i<3; i++) {
				int ac = archer[i]; // 궁사 1명을 꺼내서
				
				// 사정거리안에 드는 적군을 pq에 담는다.
				pq.clear();
				for(int j=0; j<enemy.size(); j++) {
					Enemy e = enemy.get(j);
					e.d = Math.abs(ac - e.y) + Math.abs(n - e.x);
					if(e.d<=d) pq.offer(e);
				}
				
				if(!pq.isEmpty()) pq.poll().dead = true;
			}
			
			// 죽은 적국 제거, 적군 이동 
			Iterator<Enemy> iter = enemy.iterator();
			while( iter.hasNext() ) {
				Enemy e = iter.next();
				
				if( e.dead ) {
					iter.remove();
					dead++;
				} else if( e.x == n-1 ) {
					iter.remove();
				} else {
					e.x++;
				}
			}
			
			if(enemy.size() == 0) break;
		}
		
		max = Math.max(max, dead);
	}
	
	static void comb(int index, int cnt) {
		if(cnt==3) {
			check();
			return;
		}
		
		for(int i=index; i<m; i++) {
			archer[cnt] = i;
			comb(i+1, cnt+1);
		}
	}
	
	static class Enemy{
		int x, y, d;
		boolean dead;
		
		Enemy(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
}