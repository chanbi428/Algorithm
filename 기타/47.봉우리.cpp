#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n, i, j, cnt=0;

	scanf("%d",&n);
	
	vector<vector<int> > bong(n+2,vector<int>(n+2));
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		scanf("%d",&bong[i][j]);
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		if(bong[i][j]>bong[i-1][j]&&bong[i][j]>bong[i+1][j]&&
		bong[i][j]>bong[i][j-1]&&bong[i][j]>bong[i][j+1])
		cnt++;
	}
	
	printf("%d",cnt);
	
	return 0;
}

