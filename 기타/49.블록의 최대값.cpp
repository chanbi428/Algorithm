#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, j, n, front, right, sum=0;
	
	scanf("%d",&n);
	
	vector<vector<int> > block(n, vector<int>(n));
	
	for(i=0;i<n;i++){
		scanf("%d",&front);
		for(j=0;j<n;j++){
			block[j][i]=front;
		}
	}
	
	for(i=n-1;i>=0;i--){
		scanf("%d",&right);
		for(j=n-1;j>=0;j--){
			if(block[i][j]>right) block[i][j]=right;
			sum+=block[i][j];
		}
	}
	
	printf("%d",sum);
	
	return 0;
}

