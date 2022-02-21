#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visited1[1001], visited2[1001];
queue<int> Q;

void DFS(int s, vector<vector<int> >&arr){
	cout<<s<<" ";
	for(int i=0; i<arr[s].size(); i++){
		if(visited1[arr[s][i]]==0){
			visited1[arr[s][i]]=1;
			DFS(arr[s][i], arr);
		}
	}	
}
void BFS(int s, vector<vector<int> >&arr){
	Q.push(s);
	cout<<"\n"<<s<<" ";
	while(!Q.empty()){
		int tmp=Q.front();
		Q.pop();
		for(int i=0; i<arr[tmp].size(); i++){
			if(visited2[arr[tmp][i]]==0){
				visited2[arr[tmp][i]]=1;
				cout<<arr[tmp][i]<<" ";
				Q.push(arr[tmp][i]);
			}
		}
	}	
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, s, v1, v2;
	cin>>n>>m>>s;
	
	vector<vector<int> > arr(n+1);
	
	for(int i=0; i<m; i++){
		cin>>v1>>v2;
		arr[v1].push_back(v2);
		arr[v2].push_back(v1);
	}
	for(int i=1; i<=n; i++) sort(arr[i].begin(), arr[i].end());
	
	visited1[s]=1;
	visited2[s]=1;
	DFS(s, arr);
	BFS(s, arr);
	
	return 0;
}