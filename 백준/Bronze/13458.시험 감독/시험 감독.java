import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		br.close();
		
		int b = Integer.parseInt(st2.nextToken());
		int c = Integer.parseInt(st2.nextToken());
		long answer = n;
		
		for(int i=0; i<n; i++) {
			int tmp = Integer.parseInt(st1.nextToken())-b;
			if(tmp>0) {
				answer += tmp/c;
				if((tmp)%c!=0) answer++;
			}
		}
		System.out.println(answer);
	}

}