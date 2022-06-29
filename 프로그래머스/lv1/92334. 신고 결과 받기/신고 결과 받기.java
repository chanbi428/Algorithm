import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Map<String, Integer> num = new HashMap<>();
        List<String>[] list = new ArrayList[id_list.length];
        Set<String> check = new HashSet<>();
        
        for(int i=0; i<id_list.length; i++){
            num.put(id_list[i], i);
            list[i] = new ArrayList<>();
        }
        
        for(int i=0; i<report.length; i++){
            if(check.contains(report[i])) continue;
            check.add(report[i]);
            
            StringTokenizer st = new StringTokenizer(report[i]);
            String user1 = st.nextToken();
            String user2 = st.nextToken();
            
            list[num.get(user2)].add(user1);
        }
        
        for(int i=0; i<list.length; i++){
            if(list[i].size()>=k){
                for(int j=0; j<list[i].size(); j++){
                    answer[num.get(list[i].get(j))]++;
                }
            }
        }
        
        return answer;
    }
}