#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int job[2001];

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n, k, i, sum=0;

	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&job[i]);
		sum+=job[i];
	}
	
	scanf("%d",&k);
	
	if(sum<=k) printf("-1");
	else{
		while(k>=0){
			if(i==n+1) i=1;
			if(job[i]!=0){
				job[i]--;
				k--;
			}
			i++;
		}
		printf("%d",i-1);
	}
	
	return 0;
}

