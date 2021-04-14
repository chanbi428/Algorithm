#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, j, n, cnt=0, tmp;
	
	scanf("%d",&n);
	
	for(i=2;i<=n;i++){
		if(i%5==0){
			cnt++;
			tmp=i;
			tmp=tmp/5;
			while(tmp>=5&&tmp%5==0){
				if(tmp%5==0){
					cnt++;
					tmp=tmp/5;
				}
			}
		}
	}
	printf("%d",cnt);
	
	return 0;
}

