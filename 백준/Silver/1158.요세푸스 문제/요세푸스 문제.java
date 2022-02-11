import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int cnt =0;
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		Queue<Integer> person = new LinkedList<>();
		
		answer.append("<");
		for(int i=1; i<=n; i++) person.offer(i);
		while(person.size()>1) {
			cnt++;
			if(cnt==k) {
				answer.append(person.poll()+", ");
				cnt=0;
			}
			else person.offer(person.poll());
		}
		answer.append(person.poll()+">");
		System.out.println(answer);
	}
}
