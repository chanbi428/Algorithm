#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ch[10001];

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int i, s, e, x, pos;
	int bang[3]={1,-1,5};
	queue<int> Q;
	
	scanf("%d %d", &s, &e);

	Q.push(s);
	ch[s]=1;
	
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=0;i<3;i++){
			pos=x+bang[i];
			if(pos<=0||pos>10000) continue;
			if(pos==e){
				printf("%d",ch[x]);
				exit(0);
			}
			if(ch[pos]==0){
				ch[pos]=ch[x]+1;
				Q.push(pos);
			}
		}
		
	}
	printf("%d",pos);

	return 0;
}

