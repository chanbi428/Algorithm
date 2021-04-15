#include <bits/stdc++.h>
using namespace std;

queue<int> Q;
int visited[1001], cnt=0;

void BFS(vector<vector<int> >&node){
	while(!Q.empty()){
		int tmp=Q.front();
		Q.pop();
		for(int i=0; i<node[tmp].size(); i++){
			if(visited[node[tmp][i]]==0){
				visited[node[tmp][i]]=cnt;
				Q.push(node[tmp][i]);
			}
		}
	}
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n, m, a, b;
	cin>>n>>m;
	vector<vector<int> > node(n+1);
	for(int i=0; i<m; i++){
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	for(int i=1; i<=n; i++){
		if(visited[i]==0){
			cnt++;
			Q.push(i);
			visited[i]=cnt;
			BFS(node);
		}
	}
	cout<<cnt;
	
	return 0;
}