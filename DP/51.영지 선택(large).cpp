#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, j, k, h, w, sh, sw;
	int sum, max=-247000000;
	
	scanf("%d %d",&h, &w);
	
	vector<vector<int> > terri(h+1, vector<int>(w+1));
	
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			scanf("%d",&terri[i][j]);
			terri[i][j]=terri[i][j]+terri[i-1][j]+terri[i][j-1]-terri[i-1][j-1];
		}
	}
	
	scanf("%d %d",&sh,&sw);
	
	for(i=sh;i<=h;i++){
		for(j=sw;j<=w;j++){
			sum=terri[i][j]-terri[i-sh][j]-terri[i][j-sw]+terri[i-sh][j-sw];
			if(sum>max) max=sum;
		}
	}

	printf("%d",max);
	
	return 0;
}

