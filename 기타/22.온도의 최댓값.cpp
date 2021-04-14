#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int i, n, k, j, sum=0, max=-247000000;
	
	scanf("%d %d",&n,&k);
	vector<int> a(n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i<k) sum+=a[i];
	}
	max=sum;
	
	for(i=0;i<n-k;i++){
		sum=sum-a[i]+a[i+k];
		if(max<sum) max=sum;
	}
	
	printf("%d",max);

	
	return 0;
}

