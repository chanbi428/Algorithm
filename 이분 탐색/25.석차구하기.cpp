#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int i, n, j;
	
	scanf("%d",&n);
	
	vector<int> a(n);
	vector<int> grade(n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(a[i]<a[j]) grade[i]++;
			else if(a[i]>a[j]) grade[j]++;
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d ",grade[i]+1);
	}

	
	return 0;
}

