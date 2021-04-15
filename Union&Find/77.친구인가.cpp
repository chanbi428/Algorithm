#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int freind[1001], cnt=0, n;

void check(int a, int b){
	int tmp;
	if(freind[a]==0&&freind[b]==0){
		cnt++;
		freind[a]=cnt;
		freind[b]=cnt;
	}
	else if(freind[a]==0) freind[a]=freind[b];
	else if(freind[b]==0) freind[b]=freind[a];
	else if(freind[a]!=freind[b]){
		tmp=freind[a];
		for(int i=1;i<=n;i++){
			if(tmp==freind[i]) freind[i]=freind[b];
		}
	}
}

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int m, i, a, b;
	
	scanf("%d %d",&n, &m);
	for(i=0;i<m;i++){
		scanf("%d %d",&a, &b);
		check(a, b);
	}
	
	scanf("%d %d", &a, &b);
	
	if(freind[a]==freind[b]&&freind[a]!=0) printf("YES");
	else printf("NO");

	return 0;
}

