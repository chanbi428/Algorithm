#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, j, k, h, w, fsum=0, bsum=0, max=-247000000;
	
	scanf("%d %d",&h, &w);
	
	vector<vector<int> > terri(h, vector<int>(w));
	
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf("%d",&terri[i][j]);
		}
	}
	
	scanf("%d %d",&h,&w);
	
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			fsum+=terri[i][j];
		}
	}
	bsum=fsum;
	max=bsum;
	
	for(i=0;i<=terri.size()-h;i++){
		for(j=0;j<terri[i].size()-w;j++){
			for(k=0;k<h;k++){
				bsum=bsum-terri[i+k][j]+terri[i+k][j+w];
			}
			if(max<bsum) max=bsum;
		}
		if(i==terri.size()-h) break;
		bsum=fsum;
		j=0;
		for(k=0;k<w;k++){
			bsum=bsum-terri[i][j+k]+terri[i+h][j+k];
		}
		if(max<bsum) max=bsum;
		fsum=bsum;
	}
	printf("%d",max);
	
	return 0;
}

