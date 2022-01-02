import java.util.*;

public class Main {	
	public char solution(int n, char[] arr) {
		HashMap<Character, Integer> map = new HashMap<>();
		char answer = 'a';
		for(int i=0; i<n; i++) {
			map.put(arr[i], map.getOrDefault(arr[i], 0)+1);
		}
		for(Character x: map.keySet()) {
			if(map.get(x)>map.getOrDefault(answer, 0)) {
				answer = x;
			}
		}
		
		return answer;
	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] arr = sc.next().toCharArray();
		sc.close();
		
		System.out.print(T.solution(n, arr));
	}

}
