#include <stdio.h>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, n, j, cnt=0, max=-247000000, pre=0, now;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&now);
		if(pre<=now){
			cnt++;
		}
		else{
			if(max<cnt) max=cnt;
			cnt=1;
		}
		pre=now;
		
	}
	if(max<cnt) max=cnt;
	
	printf("%d",max);

	
	return 0;
}

