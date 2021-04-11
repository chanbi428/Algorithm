#include <bits/stdc++.h>
using namespace std;

int ch[101], cnt=0;

void BFS(int v, vector<vector<int> >node){
	queue<int>Q;
	Q.push(v);
	ch[v]=1;
	while(!Q.empty()){
		int tmp=Q.front();
		Q.pop();
		cnt++;
		for(int i=0;i<node[tmp].size();i++){
			if(ch[node[tmp][i]]==0){
				Q.push(node[tmp][i]);
				ch[node[tmp][i]]=1;
			}
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, i, a, b;
	cin>>n>>m;
	vector<vector<int> >node(n+1);
	for(i=0;i<m;i++){
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	BFS(1, node);
	cout<<cnt-1;
	
	return 0;
}
