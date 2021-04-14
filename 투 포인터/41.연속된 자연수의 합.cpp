#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int num, i, cnt=0;
	int a, n=2;

	scanf("%d",&num);
	
	while((num-n*(n-1)/2)/n>0){
		if((num-n*(n-1)/2)%n==0){
			a=(num-n*(n-1)/2)/n;
			cnt++;
			printf("%d ", a);
			for(i=1;i<n;i++){
				printf("+ %d ",a+i);
			}
			printf("= %d\n",num);
		}
		n++;
	}
	printf("%d",cnt);
	
	return 0;
}

