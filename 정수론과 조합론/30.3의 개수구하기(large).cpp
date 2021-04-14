#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n;
	long long int cnt=0;
	long long int ten=10;
	
	scanf("%d",&n);
	
	while(n>=ten/10){
		cnt+=n/ten*(ten/10);
		if(n%ten>=4*(ten/10)){
			cnt+=(ten/10);
		}
		else if(n%ten>=3*(ten/10)){
			cnt+=n%(ten/10)+1;
		}
		ten*=10;
	}

	printf("%d",cnt);
	
	return 0;
}

