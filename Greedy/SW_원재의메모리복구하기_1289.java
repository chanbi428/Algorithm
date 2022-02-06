package sw;

import java.io.*;

public class SW_원재의메모리복구하기_1289 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			int count = 0;
			int pre = 0;
			
			char[] str = br.readLine().toCharArray();
			for(int i=0; i<str.length; i++) {
				if(pre != str[i]-'0') {
					count++;
					if(pre == 0) pre=1;
					else pre=0;
				}
			}
			
			System.out.println("#"+t+" "+count);
		}
		
		br.close();
	}

}
