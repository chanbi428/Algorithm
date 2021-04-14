#include <stdio.h>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n,i,num, res;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&num,&res);
		if(num*(num+1)/2==res) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}

