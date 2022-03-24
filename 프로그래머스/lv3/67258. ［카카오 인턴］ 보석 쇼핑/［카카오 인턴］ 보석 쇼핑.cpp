#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map<string, int> kind;
    unordered_map<string, int> dis;
    int num=0, cnt=0, dis_answer=gems.size()+1;
    string front=gems[0], end=gems[0];
    
    for(int i=0; i<gems.size(); i++){
        if(!kind[gems[i]]){
            kind[gems[i]]=i+1;
            num++;
        }
    }
    
    for(int i=0; i<gems.size(); i++){
        if(!dis[gems[i]]) cnt++;
        dis[gems[i]]=i+1;
        if(front==gems[i]){
            int s=dis.begin()->second;
            for(auto j=dis.begin(); j!=dis.end(); j++){
                if(j->second<=s){
                    front=j->first;
                    s=j->second;
                }
            }
        }
        end=gems[i];
        if(cnt==num){
            if(dis_answer>(dis[end]-dis[front])){
                answer[0]=dis[front];
                answer[1]=dis[end];
                dis_answer=dis[end]-dis[front];
            }
        }
    }
    
    return answer;
}