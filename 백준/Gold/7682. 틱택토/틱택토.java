import java.io.*;
import java.util.*;

public class Main {
	
	static char[][] arr;
	 
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		
		while(true) {
			String str = br.readLine();
			if(str.equals("end")) break;
			
			arr = new char[3][3];
			int o = 0;
			int x = 0;
			
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					arr[i][j] = str.charAt(i*3+j);
					if(arr[i][j] == 'O') o++;
					else if(arr[i][j] == 'X') x++;
				}
			}
			
			if(x==o || x-1==o) {
				int owin = 0;
				int xwin = 0;
				
				for(int i=0; i<3; i++) {
					if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
						if(arr[i][0] == 'O') owin++;
						else if(arr[i][0] == 'X') xwin++;
					}
					if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
						if(arr[0][i] == 'O') owin++;
						else if(arr[0][i] == 'X') xwin++;
					}
				}
				if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
					if(arr[0][0] == 'O') owin++;
					else if(arr[0][0] == 'X') xwin++;
				}
				if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
					if(arr[0][2] == 'O') owin++;
					else if(arr[0][2] == 'X') xwin++;
				}
				
				if(x==o) {
					if(xwin==0 && owin>0) answer.append("valid\n");
					else answer.append("invalid\n");
				} else {
					if((owin+xwin==0 && o+x==9) || (owin==0 && xwin>0)) answer.append("valid\n");
					else answer.append("invalid\n");
				}
			
			} else {
				answer.append("invalid\n");
			}
		}
		
		System.out.print(answer.toString());
	}


}
