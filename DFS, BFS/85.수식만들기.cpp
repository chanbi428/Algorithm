#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, mmax=-2147000000, mmin=2147000000;
int seq[10];
int sign[4];

void DFS(int s, int sum){
	int i;
	if(s==n-1){
		if(sum>mmax) mmax=sum;
		if(sum<mmin) mmin=sum;
	}
	else{
		for(i=0;i<4;i++){
			if(sign[i]!=0){
				sign[i]--;
				if(i==0) DFS(s+1,sum+seq[s+1]);
				else if(i==1) DFS(s+1,sum-seq[s+1]);
				else if(i==2) DFS(s+1,sum*seq[s+1]);
				else DFS(s+1,sum/seq[s+1]);
				sign[i]++;
			}
		}
	}
}

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int i;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&seq[i]);
	}
	for(i=0;i<4;i++){
		scanf("%d",&sign[i]);
	}
	DFS(0,seq[0]);
	
	printf("%d\n%d",mmax,mmin);

	return 0;
}

