import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<String, Integer> map = new HashMap<>();
		int n = Integer.parseInt(br.readLine());
		for(int i=0; i<n; i++) {
			String str = br.readLine();
			if(map.containsKey(str)) {
				map.replace(str, map.get(str)+1);
			} else {
				map.put(str, 1);
			}
		}
		List<Map.Entry<String, Integer>> entryList = new LinkedList<>(map.entrySet());
		entryList.sort((e1, e2) -> e1.getValue()==e2.getValue()?e1.getKey().compareTo(e2.getKey()):e2.getValue()-e1.getValue());
		System.out.println(entryList.get(0).getKey());
		
	}
}
