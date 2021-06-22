#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<bool> visited(n+1);
    vector<vector<int>> node(n+1);
    queue<pair<int, int>> Q;
    int num=1;

    for(int i=0; i<edge.size(); i++){
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    visited[1]=true;
    Q.push({1,1});

    while(!Q.empty()){
        int n=Q.front().first;
        int m=Q.front().second;
        //cout<<"("<<n<<","<<m<<")\n";
        if(m>num){
            num=m;
            answer=1;
        }
        else if(m==num) answer++;
        //cout<<num<<" "<<answer<<"\n";
        Q.pop();

        for(int i=0; i<node[n].size(); i++){
            if(visited[node[n][i]]==false){
                Q.push({node[n][i], m+1});
                visited[node[n][i]]=true;
            }
        }
    }

    return answer;
}