import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		char[] ppap = {'P', 'P', 'A', 'P'};
		
		if(str.equals("p")) {
			System.out.println("PPAP");
			return;
		}
		
		Stack<Integer> stack = new Stack<>();
		int index = 0;
		
		for(int i=0; i<str.length(); i++) {
			if(str.charAt(i)==ppap[index]) {
				index++;
				if(index==4) {
					if(stack.empty()) index=1;
					else index = stack.pop();
				}
			} else {
				if(str.charAt(i)=='P') {
					if(index==2) {
						stack.push(2);
						index=2;
					} else {
						stack.push(index);
						index=1;
					}
				} else {
					System.out.println("NP");
					return;
				}
			}
		}
		
		if(index==1) System.out.println("PPAP");
		else System.out.println("NP");
		
	}

}
