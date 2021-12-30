import java.util.*;

public class Main {
	public ArrayList<Integer> solution(int n, int[] num) {
		ArrayList<Integer> answer = new ArrayList<>();
		answer.add(num[0]);
		for(int i=1; i<n; i++) {
			if(num[i]>num[i-1]) answer.add(num[i]);
		}
		
		return answer;
	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] num = new int[n];
		for(int i=0; i<n; i++) {
			num[i]=sc.nextInt();
		}
		sc.close();
		
		for(int x : T.solution(n, num)) {
			System.out.print(x+" ");
		}
	}

}

// 설명

// N개의 정수를 입력받아, 자신의 바로 앞 수보다 큰 수만 출력하는 프로그램을 작성하세요.

// (첫 번째 수는 무조건 출력한다)


// 입력
// 첫 줄에 자연수 N(1<=N<=100)이 주어지고, 그 다음 줄에 N개의 정수가 입력된다.


// 출력
// 자신의 바로 앞 수보다 큰 수만 한 줄로 출력한다.


