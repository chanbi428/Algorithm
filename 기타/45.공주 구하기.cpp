#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int prince[1001];

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int n, k, i, cnt=0, sum=0, res=0;

	scanf("%d %d",&n, &k);
	
	while(true){
		for(i=1;i<=n;i++){
			cnt++;
			if(prince[i]!=0) cnt--;
			else if(cnt==k&&prince[i]==0){
				cnt=0;
				prince[i]=1;
				sum++;
			}
			if(sum==n-1&&prince[i]==0){
				res=i;
				break;
			}
		}
		if(res!=0) break;
	}
	
	printf("%d",res);
	
	return 0;
}

