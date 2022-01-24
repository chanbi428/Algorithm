import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder str = new StringBuilder(br.readLine());
		br.close();
		int len = str.length();
		String[] arr = new String[len];
		for(int i=0; i<len; i++) {
			arr[i] = str.substring(i);
		}
		Arrays.sort(arr);
		for(int i=0; i<len; i++) {
			System.out.println(arr[i]);
		}
	}
}
