#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int n, m, i, x;
	queue<int> Q;
	
	scanf("%d %d", &n, &m);
	
	for(i=0;i<n;i++){
		Q.push(i+1);
	}
	
	i=0;
	while(!Q.empty()){
		i++;
		x=Q.front();
		Q.pop();
		if(i==m) i=0;
		else Q.push(x);
	}
	printf("%d",x);

	return 0;
}

