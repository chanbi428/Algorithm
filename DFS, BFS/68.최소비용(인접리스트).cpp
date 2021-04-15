#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, cost=2147000000;
int ch[21];
vector<pair<int,int> >map[21];


void DFS(int v, int sum){
	int i;
	if(v==n){
		if(sum<cost) cost=sum;
	}
	else{
		for(i=0;i<map[v].size();i++){
			if(ch[map[v][i].first]==0){
				ch[map[v][i].first]=1;
				DFS(map[v][i].first, sum+map[v][i].second);
				ch[map[v][i].first]=0;
			}
		}
	}
}
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int i, j, m, v1, v2, num;
	
	scanf("%d %d", &n, &m);
	
	for(i=0;i<m;i++){
		scanf("%d %d %d",&v1, &v2, &num);
		map[v1].push_back(pair<int,int>(v2,num));
	}
	ch[1]=1;
	DFS(1, 0);
	printf("%d",cost);

	return 0;
}

