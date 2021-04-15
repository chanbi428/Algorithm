#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, k, cnt=0;
int arr[10];

void DFS(int L, int sum){
	if(L==n){
		if(sum==k) cnt++;
		return;
	}
	else{
		DFS(L+1, sum+arr[L]);
		DFS(L+1, sum-arr[L]);
		DFS(L+1, sum);
	}
}

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	int i;
	scanf("%d %d",&n, &k);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	DFS(0, 0);
	if(cnt==0) printf("-1");
	printf("%d",cnt);
	
	return 0;
}

