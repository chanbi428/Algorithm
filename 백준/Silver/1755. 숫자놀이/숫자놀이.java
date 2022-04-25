import java.io.*;
import java.util.*;

public class Main {
	
	static String[] eng = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};  // 0~9까지 영어 

	static class Num{  // 번호와 영어로 변환한 값 저장하는 자료구조 
		int num;
		String engnum;
		public Num(int num, String engnum) {
			this.num = num;
			this.engnum = engnum;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		
		ArrayList<Num> nlist = new ArrayList<>(); // 번호랑 영어로 변환한 값을 저장할 list
		
		int ma = m/10;  // m의 앞자리 
		int na = n/10;  // n의 앞자리 
		if(ma == na) {  // m~n까지의 앞자리가 모두 같으면 뒷자리만 고려해 주면된다. (11~18이면 1~8의 순서만 고려)
			int mb = m%10;
			int nb = n%10;
			for(int i=mb; i<=nb; i++) {
				nlist.add(new Num(ma*10+i, eng[i]));
			}
		} 
		else {  // 앞자리가 같지 않으면 (예를 들어 18~48)
			int mb = m%10;  // 뒷자리 
			if(ma == 0) { // 앞자리가 0일 때 zero를 붙이면 안되기 때문에 따로 고려
				for(int i=mb; i<=9; i++) {
					nlist.add(new Num(ma*10+i, eng[i]));
				}
			} else {  // 0이 아닐 때 m부터 앞자리+9 (18~19)
				for(int i=mb; i<=9; i++) {
					nlist.add(new Num(ma*10+i, eng[ma]+eng[i]));
				}
			}
			
			for(int i=ma+1; i<na; i++) {  // 뒷자리 0~9까지 다 들어 가는 수들 (20~39)
				for(int j=0; j<=9; j++) {
					nlist.add(new Num (i*10+j, eng[i]+eng[j]));
				}
			}
			
			int nb = n%10;
			for(int i=0; i<=nb; i++) {  // 가장 뒤에 n까지 고려 (40~48)
				nlist.add(new Num (na*10+i, eng[na]+eng[i]));
			}
		}
		
		Collections.sort(nlist, (e1, e2)->e1.engnum.compareTo(e2.engnum));  // 영어를 기준으로 정렬
		int cnt = 0;  // 10개씩 끊어줄 변수 
		for(Num l : nlist) {
			sb.append(l.num+" ");
			if(++cnt==10) {
				cnt = 0;
				sb.append("\n");
			}
		}

		System.out.println(sb.toString());
	}

}
