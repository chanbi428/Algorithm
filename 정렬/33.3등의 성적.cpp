#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n, i, j, max, tmp, cnt=1;
	int a[100];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<n-1;i++){
		max=i;
		for(j=i+1;j<n;j++){
			if(a[j]>a[max]) max=j;
		}
		tmp=a[i];
		a[i]=a[max];
		a[max]=tmp;
		if(i!=0&&a[i]!=a[i-1]) cnt++;
		if(cnt==3) break;
	}
	
	printf("%d",a[i]);
	
	return 0;
}

