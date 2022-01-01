import java.util.*;

public class Main {	
	public int solution(int n, int[][] arr) {
		int answer = 0;
		int tmp1, tmp2;
		
		for(int i=0; i<n; i++) {
			tmp1 = 0; tmp2 = 0;
			for(int j=0; j<n; j++) {
				tmp1 += arr[i][j];
				tmp2 += arr[j][i];
			}
			answer = Math.max(answer, tmp1);
			answer = Math.max(answer, tmp2);
		}
		tmp1 = 0; tmp2 = 0;
		for(int i=0; i<n; i++) {
			tmp1 += arr[i][i];
			tmp2 += arr[i][n-i-1];
		}
		answer = Math.max(answer, tmp1);
		answer = Math.max(answer, tmp2);
		
		return answer;
	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] arr = new int[n][n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		sc.close();
		
		System.out.print(T.solution(n, arr));
	}

}

// 설명

// 5*5 격자판에 아래롸 같이 숫자가 적혀있습니다.

// N*N의 격자판이 주어지면 각 행의 합, 각 열의 합, 두 대각선의 합 중 가 장 큰 합을 출력합니다.


// 입력
// 첫 줄에 자연수 N이 주어진다.(2<=N<=50)

// 두 번째 줄부터 N줄에 걸쳐 각 줄에 N개의 자연수가 주어진다. 각 자연수는 100을 넘지 않는다.


// 출력
// 최대합을 출력합니다.
