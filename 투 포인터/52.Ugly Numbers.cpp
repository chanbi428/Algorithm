#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int a[1501];

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, n, min=2147000000;
	int p2=1,p3=1,p5=1;
	
	a[1]=1;
	
	scanf("%d",&n);
	
	for(i=2;i<=n;i++){
		if(a[p2]*2<a[p3]*3) min=a[p2]*2;
		else min=a[p3]*3;
		if(a[p5]*5<min) min=a[p5]*5;
		if(a[p2]*2==min) p2++;
		if(a[p3]*3==min) p3++;
		if(a[p5]*5==min) p5++;
		a[i]=min;
	}
	
	printf("%d",a[n]);
	
	return 0;
}

