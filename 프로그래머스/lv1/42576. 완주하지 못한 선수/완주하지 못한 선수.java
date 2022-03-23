import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> people = new HashMap<>();
        
        for(int i=0; i<completion.length; i++){
            int cnt = 1;
            if(people.containsKey(completion[i])) cnt = people.get(completion[i])+1;
            people.put(completion[i], cnt);
        }
        for(int i=0; i<participant.length; i++){
            if(!people.containsKey(participant[i])){
                answer = participant[i];
                break;
            } else {
                people.replace(participant[i], people.get(participant[i])-1);
                if(people.get(participant[i])==0) people.remove(participant[i]);
            }

        }
        
        if(answer=="") {
            for(String str : people.keySet()) answer = str;
        }
        return answer;
    }
}