#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int cnt=0, n;
int ch[21];

void DFS(int begin, vector<vector<int> > arr){
	int i;
	if(begin==n){
		cnt++;
		return;
	}
	ch[begin]=1;
	for(i=0;i<arr[begin].size();i++){
		if(ch[arr[begin][i]]==0) DFS(arr[begin][i],arr);
	}
	ch[begin]=0;
}
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int m, i, v1, v2;
	
	scanf("%d %d",&n, &m);
	
	vector<vector<int> >arr(n+1);
	
	for(i=0;i<m;i++){
		scanf("%d %d",&v1, &v2);
		arr[v1].push_back(v2);
	}
	DFS(1, arr);
	printf("%d",cnt);

	return 0;
}

