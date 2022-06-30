import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        
        Set<String> cars = new TreeSet<>();
        Map<String, int[]> inout = new HashMap<>();
        Map<String, Integer> times = new HashMap<>();
        
        for(int i=0; i<records.length; i++){
            StringTokenizer st = new StringTokenizer(records[i]);
            String time = st.nextToken();
            String carNum = st.nextToken();
            String io = st.nextToken();
            
            if(io.equals("IN")){
                cars.add(carNum);
                inout.put(carNum, new int[]{minutes(time), 0});
            } else{
                int inTime = inout.get(carNum)[0];
                int outTime = minutes(time);
                
                int t = outTime - inTime;
                
                if(times.containsKey(carNum)){
                    times.put(carNum, times.get(carNum)+t);
                } else{
                    times.put(carNum, t);
                }
                
                inout.put(carNum, new int[]{outTime, 1});
            }
        }
        
        int[] answer = new int[cars.size()];
        
        int i = 0;
        Iterator<String> it = cars.iterator();
        while(it.hasNext()){
            String carNum = it.next();
            if(inout.get(carNum)[1]==0){
                int inTime = inout.get(carNum)[0];
                int outTime = 1439;
                
                int t = outTime - inTime;
                
                if(times.containsKey(carNum)) times.put(carNum, times.get(carNum)+t);
                else times.put(carNum, t);
            }
            
            int t = times.get(carNum);
            int money = fees[1];
            if(t>fees[0]){  // 기본요금아닐 때 추가 
                t = t-fees[0];
                if(t%fees[2]==0){
                    money += fees[3]*(t/fees[2]);
                } else{
                    money += fees[3]*(t/fees[2]+1);
                }
            }
            answer[i++] = money;
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