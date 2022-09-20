import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        Map<String, Integer> index = new HashMap<>();
        Map<String, List<String>> list = new HashMap<>();
        Set<String> check = new HashSet<>();
        
        for(int i=0; i<id_list.length; i++){
            index.put(id_list[i], i);
        }
        
        for(int i=0; i<report.length; i++){
            if(!check.contains(report[i])){
                check.add(report[i]);
                StringTokenizer st = new StringTokenizer(report[i]);
                String a = st.nextToken();
                String b = st.nextToken();
                
                if(list.containsKey(b)){
                    List<String> tmp = list.get(b);
                    tmp.add(a);
                    list.put(b, tmp);
                } else{
                    List<String> tmp = new ArrayList<>();
                    tmp.add(a);
                    list.put(b, tmp);
                }
            }
        }
        
        for(String s : list.keySet()){
            if(list.get(s).size()>=k){
                List<String> tmp = list.get(s);
                for(String name : tmp){
                    answer[index.get(name)]++;
                }
            }
        }
        
        return answer;
    }
}