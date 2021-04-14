#include <stdio.h>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n, m, i, j, num, cnt=0, max=0;
	
	scanf("%d %d", &n, &m);
	
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(num>m){
			cnt=1;
			for(j=1;j<n-i;j++){
				scanf("%d",&num);
				if(num>m) cnt++;
				else break;
			}
			if(max<cnt) max=cnt;
			i=i+j;
		}
	}
	if(max==0) printf("-1");
	else printf("%d",max);
	
	return 0;
}

