#include <stdio.h>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n, i;
	int a[100], b[100];
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	
	for(i=0;i<n;i++){
		if((a[i]==1&&b[i]==3)||(a[i]==2&&b[i]==1)||(a[i]==3&&b[i]==2)){
			printf("A\n");
		}
		else if(a[i]-b[i]==0) printf("D\n");
		else printf("B\n");
	}
	
	return 0;
}

