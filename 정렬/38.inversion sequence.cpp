#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j;

	scanf("%d",&n);
	
	vector<int> ivs(n);
	vector<int> seq(n);	
	
	for(i=0;i<n;i++){
		scanf("%d", &ivs[i]);
	}
	for(i=n-1;i>=0;i--){
		for(j=n-1;j>=ivs[i];j--){
			seq[j]=seq[j-1];
		}
		seq[ivs[i]]=i+1;
	}
	
	for(i=0;i<n;i++){
		printf("%d ",seq[i]);
	}
	
	return 0;
}

