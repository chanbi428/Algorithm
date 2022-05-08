import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		while(true) {
			String str = br.readLine();
			if(str==null || str.isEmpty()) break;
			sb.append(str+"\n");
		}
		
		System.out.println(sb.toString());
		
	}

}
