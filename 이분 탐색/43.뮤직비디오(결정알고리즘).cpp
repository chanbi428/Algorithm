#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
	
int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int n, m, i, length;
	int lt=1, rt=0, mid, cnt=0, sum=0, min=0, max=-247000000;
	vector<int> dvd;

	scanf("%d %d",&n, &m);
	
	for(i=0;i<n;i++){
		scanf("%d",&length);
		dvd.push_back(length);
		rt+=length;
		if(dvd[i]>max) max=dvd[i];
	}
	
	while(lt<=rt){
		cnt=0;
		mid=(lt+rt)/2;
		if(mid<max){
			lt=mid+1;
			continue;
		}
		for(i=0;i<n;i++){
			if(sum+dvd[i]>mid){
				cnt++;
				sum=0;
			}
			sum+=dvd[i];
		}
		cnt++;
		sum=0;
		if(cnt<=m){
			min=mid;
			rt=mid-1;		
		}
		else{
			lt=mid+1;
		}
	}
	printf("%d",min);
	
	return 0;
}

