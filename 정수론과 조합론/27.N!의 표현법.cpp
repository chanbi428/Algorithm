#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, j, n, tmp;
	
	scanf("%d",&n);
	
	vector<int> ch(n+1);
	
	for(i=2;i<=n;i++){
		tmp=i;
		for(j=2;tmp!=1;j++){
			if(tmp%j==0){
				ch[j]++;
				tmp=tmp/j;
				j--;
			}
			
		}
	}
	printf("%d! = ",n);
	for(i=2;i<=n;i++){
		if(ch[i]!=0) printf("%d ",ch[i]);
	}
	
	return 0;
}

