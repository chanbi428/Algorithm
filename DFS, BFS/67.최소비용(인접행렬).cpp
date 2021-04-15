#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int sum=0, n, mmin=2147000000;
int map[21][21], ch[21];

void DFS(int v){
	int i;
	if(v==n){
		if(sum<mmin) mmin=sum;
	}
	else{
		for(i=1;i<=n;i++){
			if(map[v][i]==0) continue;
			if(ch[i]==0){
				ch[i]=1;
				sum+=map[v][i];
				DFS(i);
				ch[i]=0;
				sum-=map[v][i];
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
		map[v1][v2]=num;
	}
	ch[1]=1;
	DFS(1);
	printf("%d",mmin);

	return 0;
}

