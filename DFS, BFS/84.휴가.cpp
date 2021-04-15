#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, cost=-2147000000;
vector<int>T(1,1), P(1);
void DFS(int d, int sum){
	int i;
	if(d==n+1){
		if(sum>cost) cost=sum;
	}
	else{
		for(i=d+T[d];i<=n+1;i++){
			DFS(i,sum+P[d]);
		}
	}
}

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int t, p, i;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&t, &p);
		T.push_back(t);
		P.push_back(p);
	}
	DFS(0,0);
	
	printf("%d",cost);

	return 0;
}

