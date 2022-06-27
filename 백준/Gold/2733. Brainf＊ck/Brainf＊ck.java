import java.io.*;
import java.util.*;

public class Main {
	 
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {

			StringBuilder lang = new StringBuilder();
			Stack<Integer> stack = new Stack<>();
			Map<Integer, Integer> map = new HashMap<>();
			int[] brain = new int[32768];
			boolean flag = false;
			bw.write("PROGRAM #"+t+":\n");
			
			while(true) {
				String str = br.readLine();
				str.replaceAll(" ", "");
				int remark = str.indexOf("%");
				if(remark!=-1) str = str.substring(0, remark);
				lang.append(str);
				
				if(str.equals("end")) break;
			}
		
			for(int i=0; i<lang.length(); i++) {
				if(lang.charAt(i)=='[') {
					stack.add(i);
				} else if(lang.charAt(i)==']') {
					if(!stack.isEmpty()) {
						int index = stack.pop();
						map.put(index, i);
						map.put(i, index);
					}
					else {
						bw.write("COMPILE ERROR\n");
						flag = true;
						break;
					}
				}
			}
			
			if(flag) continue;
			if(!stack.isEmpty()) {
				bw.write("COMPILE ERROR\n");
				continue;
			}
				int index = 0;
				for(int i=0; i<lang.length(); i++) {
					if(lang.charAt(i)=='+') {
						brain[index]++;
						if(brain[index]==256) brain[index] = 0;
					} else if(lang.charAt(i)=='-') {
						brain[index]--;
						if(brain[index]==-1) brain[index] = 255;
					} else if(lang.charAt(i)=='>') {
						index++;
						if(index==32768) index=0;
					} else if(lang.charAt(i)=='<') {
						index--;
						if(index==-1) index = 32767;
					} else if(lang.charAt(i)=='.') {
						bw.write((char)brain[index]);
					} else if(lang.charAt(i)=='[') {
						if(brain[index]==0) {
							i = map.get(i)-1;
						}
					} else if(lang.charAt(i)==']') {
						if(brain[index]!=0) {
							i = map.get(i)-1;
						}
					}
				}
		
			bw.write("\n");
		}
		
		bw.flush();
		
	}

}
