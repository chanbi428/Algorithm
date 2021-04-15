#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, flag=0;
int ch[10],arr[10];

void DFS(int L){
	int i, sum=0;
	if(L==n){
		for(i=0;i<n;i++){
 			if(ch[i]==1) sum+=arr[i];
 			else sum-=arr[i];
		}
		if(sum==0) flag=1;
	}
	else{
		ch[L]=1;
		DFS(L+1);
		ch[L]=0;
		DFS(L+1);
	}
}

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	DFS(0);
	if(flag==1) printf("YES");
	else printf("NO");
	
	return 0;
}

