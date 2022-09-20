import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        
        Map<String, Integer> times = new HashMap<>();
        Set<String> cars = new TreeSet<>();
        Map<String, String> state = new HashMap<>();
        Map<String, Integer> inTime = new HashMap<>();
        
        for(int i=0; i<records.length; i++){
            StringTokenizer st = new StringTokenizer(records[i]);
            int time = minutes(st.nextToken());
            String car = st.nextToken();
            String inout = st.nextToken();
            if(!times.containsKey(car)){
                times.put(car, 0);
            }
            
            if(inout.equals("IN")){
                cars.add(car);
                inTime.put(car, time);
            } else {
                times.put(car, times.get(car) + (time-inTime.get(car)));
            }
            state.put(car, inout);
        }
        
        for(String car : state.keySet()){
            if(state.get(car).equals("IN")){
                times.put(car, times.get(car) + (1439-inTime.get(car)));
            }
        }
        
        int[] answer = new int[cars.size()];
        Iterator<String> iterator = cars.iterator();
        int index = 0;
        while(iterator.hasNext()) {
            String car = iterator.next();
            int time = times.get(car);
            
            answer[index] = fees[1];
            if(time>fees[0]){
                time -= fees[0];
                if(time%fees[2]==0){
                    answer[index] += (time/fees[2])*fees[3];
                } else{
                    answer[index] += (time/fees[2]+1)*fees[3];
                }
            }
            
            index++;
        }
        
        return answer;
    }
    
    static int minutes(String str){
        int time = 0;
        
        int h = Integer.parseInt(str.substring(0, 2));
        int m = Integer.parseInt(str.substring(3, 5));
        time = h*60+m;
        
        return time;
    }
}