import java.util.*;

public class Main {	
	public String solution(String str1, String str2) {
		HashMap<Character, Integer> map = new HashMap<>();
		
		if(str1.length()!=str2.length()) return "NO";
		
		for(char x : str1.toCharArray()) {
			map.put(x, map.getOrDefault(x, 0)+1);
		}
		for(char x : str2.toCharArray()) {
			if(map.containsKey(x)) map.put(x, map.get(x)-1);
			else return "NO";
		}
		for(char x : map.keySet()) {
			if(map.get(x)!=0) return "NO";
		}
		return "YES";

	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		String str1 = sc.next();
		String str2 = sc.next();
		sc.close();
		
		System.out.print(T.solution(str1, str2));
	}

}
