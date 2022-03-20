#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   int n, m, per1, per2, p, c;
   bool flag=false;
   
   cin>>n>>per1>>per2>>m;
   
   vector<int> parent(n+1);
   vector<vector<int> > child(n+1);
   vector<bool> visited(n+1);
   queue<pair<int, int> >Q;
   
   for(int i=0; i<m; i++){
   		cin>>p>>c;
   		parent[c]=p;
   		child[p].push_back(c);
   }
   
   visited[per1]=true;
   Q.push({per1, 0});
   
   while(!Q.empty()){
   		int num=Q.front().first;
   		int cnt=Q.front().second;
   		Q.pop();
   		
   		if(num==per2){
   			cout<<cnt;
   			flag=true;
   			break;
		}
   		
   		for(int i=0; i<child[num].size(); i++){
   			if(!visited[child[num][i]]){
   				visited[child[num][i]]=true;
   				Q.push({child[num][i], cnt+1});
			   }
		   }
		if(!visited[parent[num]]){
			visited[parent[num]]=true;
			Q.push({parent[num], cnt+1});
		}
   }
   
   if(!flag) cout<<"-1";
   
   return 0;
}