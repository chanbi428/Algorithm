import java.util.*;

public class Main {
	public String solution(String s, char t) {
		String answer = "";
		int index =s.indexOf(t);
		for(int i=0; i<=index; i++) {
			answer+=Integer.toString(index-i)+" ";
		}
		while(s.indexOf(t,index+1)!=-1) {
			int tmp = s.indexOf(t,index+1);
			for(int i=index+1; i<=index+((tmp-index)/2); i++) {
				answer+=Integer.toString(i-index)+" ";
			}
			for(int i=index+((tmp-index)/2)+1; i<=tmp; i++) {
				answer+=Integer.toString(tmp-i)+" ";
			}
			index=tmp;
		}
		for(int i=index+1;i<s.length();i++) {
			answer+=Integer.toString(i-index)+" ";
		}
		
		return answer;
	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char t = sc.next().charAt(0);
		sc.close();
		
		System.out.println(T.solution(s, t));
	}

}

// 설명

// 한 개의 문자열 s와 문자 t가 주어지면 문자열 s의 각 문자가 문자 t와 떨어진 최소거리를 출력하는 프로그램을 작성하세요.


// 입력
// 첫 번째 줄에 문자열 s와 문자 t가 주어진다. 문자열과 문자는 소문자로만 주어집니다.

// 문자열의 길이는 100을 넘지 않는다.


// 출력
// 첫 번째 줄에 각 문자열 s의 각 문자가 문자 t와 떨어진 거리를 순서대로 출력한다
