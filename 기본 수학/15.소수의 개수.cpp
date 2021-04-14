#include <stdio.h>
using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);

	int n, i, j, res=0, flag;
	
	scanf("%d",&n);
	
	for(i=2;i<=n;i++){
		flag=1;
		for(j=2;j*j<=i;j++){
			if(i%j==0){
				flag=0;
				break;
			}
		}
		if(flag==1) res++;
	}
	
	printf("%d",res);
	
	return 0;
}

