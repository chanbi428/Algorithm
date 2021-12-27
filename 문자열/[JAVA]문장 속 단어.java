import java.util.*;

public class Main {
	public String solution(String str) {
		String answer = "";
		int m = Integer.MIN_VALUE;
		String[] s = str.split(" ");
		for(String i : s) {
			if(i.length()>m) {
				m=i.length();
				answer=i;
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		sc.close();
		
		System.out.println(T.solution(str));
	}

}
