#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, n, pre, now;
	
	scanf("%d",&n);
	
	vector<int> a(n);
	
	scanf("%d",&pre);
	
	for(i=1;i<n;i++){
		scanf("%d",&now);
		if(abs(now-pre)<n&&a[abs(now-pre)]==0){
			a[abs(now-pre)]=1;
			pre=now;
		}
		else{
			printf("NO");
			break;
		}
	}
	if(i==n) printf("YES");

	
	return 0;
}

