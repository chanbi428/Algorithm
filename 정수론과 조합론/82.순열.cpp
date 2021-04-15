#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, r, cnt=0;
int num[15], ch[15];
vector<int> res;

void DFS(int x){
	if(x==r){
		cnt++;
		for(int i=0;i<r;i++){
			printf("%d ",res[i]);
		}
		puts("");
	}
	else{
		for(int i=0;i<n;i++){
			if(ch[i]==0){
				ch[i]=1;
				res.push_back(num[i]);
				DFS(x+1);
				ch[i]=0;
				res.pop_back();
			}
		}
	}
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	scanf("%d %d",&n, &r);
	
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	DFS(0);
	
	printf("%d",cnt);

	return 0;
}

