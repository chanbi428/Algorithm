#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int ten=10, n, cnt=0;
	
	scanf("%d",&n);
	
	while(n>=(ten/10)){
		if(n>=3*(ten/10)){
			cnt+=n/ten*(ten/10);
			if(n%ten>=3*(ten/10)){
				if(ten==10) cnt+=1;
				else{
					if(n%ten>3*(ten/10)) cnt+=ten/10;
					else cnt+=n%(ten/10)+1;
				}
			}
		}
		ten*=10;
	}
	

	printf("%d",cnt);
	
	return 0;
}

