#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, j, res, dis;
	double sum;
	int arr[9][9], avg[9];
	
	for(i=0;i<9;i++){
		sum=0;
		for(j=0;j<9;j++){
			scanf("%d",&arr[i][j]);
			sum+=arr[i][j];
		}
		avg[i]=round(sum/9);
	}
	
	for(i=0;i<9;i++){
		dis=100;
		for(j=0;j<9;j++){
			if(dis>abs(avg[i]-arr[i][j])){
				dis=abs(avg[i]-arr[i][j]);
				res=arr[i][j];
			}
			else if(dis==abs(avg[i]-arr[i][j])){
				if(res<arr[i][j]) res=arr[i][j];
			} 
		}
		printf("%d %d\n",avg[i], res);
	}
	
	return 0;
}

