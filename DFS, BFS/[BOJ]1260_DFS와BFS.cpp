#include <bits/stdc++.h>
using namespace std;

int ch[1001], ch2[1001];

void DFS(int v, vector<vector<int> >node){
	ch[v]=1;
	cout<<v<<" ";
	for(int i=0;i<node[v].size();i++){
		if(ch[node[v][i]]==0){
			DFS(node[v][i], node);
		}
	}
}
void BFS(int v, vector<vector<int> >node){
	queue<int>Q;
	Q.push(v);
	ch2[v]=1;
	while(!Q.empty()){
		int tmp=Q.front();
		Q.pop();
		cout<<tmp<<" ";
		for(int i=0;i<node[tmp].size();i++){
			if(ch2[node[tmp][i]]==0){
				Q.push(node[tmp][i]);
				ch2[node[tmp][i]]=1;
			}
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, v, i, a, b;
	cin>>n>>m>>v;
	vector<vector<int> >node(n+1);
	for(i=0;i<m;i++){
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for(i=0;i<n;i++) sort(node[i].begin(), node[i].end());
	DFS(v, node);
	cout<<"\n";
	BFS(v, node);
	
	return 0;
}
