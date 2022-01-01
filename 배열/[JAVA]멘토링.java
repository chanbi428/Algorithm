import java.util.*;

public class Main {	
	public int solution(int n, int m, int[][] arr) {
		int answer=0;
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i==j) continue;
				int cnt = 0;
				for(int k=0; k<m; k++) {
					int a=0,b=0;
					for(int s=0; s<n; s++) {
						if(arr[k][s]==i) a=s;
						if(arr[k][s]==j) b=s;
					}
					if(a<b) cnt++;
				}
				if(cnt==m) answer++;
			}
		}
		
		return answer;
	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] arr = new int[m][n];
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		sc.close();
		
		System.out.print(T.solution(n, m, arr));
	}

}
