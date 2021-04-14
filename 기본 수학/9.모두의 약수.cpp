#include <stdio.h>
using namespace std;

int res[50001];

int main(int argc, char** argv) {
//	freopen("input.txt", "rt", stdin);
	int num;
	int i, j;
		
	scanf("%d",&num);
	
	for(i=1;i<=num;i++){
		for(j=i;j<=num;j=j+i){
			res[j]++;
		}
	}
	for(i=1;i<=num;i++) printf("%d ",res[i]);
	
	return 0;
}
