import java.util.*;

public class Main {
	public ArrayList<String> solution(int n, String[] s) {
		ArrayList<String> answer = new ArrayList<>();
		for(String i : s) {
			String tmp = new StringBuilder(i).reverse().toString();
			answer.add(tmp);
		}
		return answer;
	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] s = new String[n];
		for(int i=0; i<n; i++) {
			s[i] = sc.next();
		}
		sc.close();
		
		for(String i : T.solution(n, s)) {
			System.out.println(i);
		}
	}

}
//StringBuilder -> String이 불변이기 때문에 문자열 연산을 많이 사용할 수록 메모리 할당과 해체로 성능이 저하
//StringBuilder를 사용하면 같은 메모리를 계속 사용하기 때문에 더욱 효율적
