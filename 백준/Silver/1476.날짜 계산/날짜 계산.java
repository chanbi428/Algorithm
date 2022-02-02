import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int e = Integer.parseInt(st.nextToken());  //15
		int s = Integer.parseInt(st.nextToken());  //28
		int m = Integer.parseInt(st.nextToken());  //19
		int answer = s;
		while(true) {
			int ee = answer%15==0?15:answer%15;
			int mm = answer%19==0?19:answer%19;
			if(e == ee && m == mm) {
				System.out.println(answer);
				break;
			}
			answer += 28;
		}
	}
}
