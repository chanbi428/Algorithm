class Solution {
    public String solution(String new_id) {
        String answer = new_id;
        
        answer = answer.toLowerCase();
        
        String tmp = "";
        for(int i=0; i<answer.length(); i++){
            char c = answer.charAt(i);
            if((c>='a'&&c<='z') || (c>='0'&&c<='9') || c=='-' || c=='_' || c=='.'){
                tmp+=c;
            } 
        }
        answer = tmp;
        
        tmp = "";
        for(int i=0; i<answer.length(); i++){
            if(answer.charAt(i)=='.'){
                if(i+1<answer.length() && answer.charAt(i+1)=='.') continue;
            }
            tmp+=answer.charAt(i);
        }
        answer = tmp;
        
        if(answer.charAt(0)=='.') answer = answer.substring(1);
        if(answer.length()!=0 && answer.charAt(answer.length()-1)=='.') answer = answer.substring(0, answer.length()-1);
        
        if(answer.length()==0) answer = "a";
        
        if(answer.length()>=16){
            answer = answer.substring(0, 15);
            if(answer.charAt(14)=='.') answer = answer.substring(0, 14);
        }
        
        if(answer.length()<=2){
            char c = answer.charAt(answer.length()-1);
            if(answer.length()==1) answer = answer+c+c;
            else answer += c;
        }
        
        
        return answer;
    }
}