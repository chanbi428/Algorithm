#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int n, m, i;
	int apoint=0, bpoint=0;

	scanf("%d",&n);
	vector<int> a(n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	
	scanf("%d",&m);
	vector<int> b(m);	
	for(i=0;i<m;i++){
		scanf("%d", &b[i]);
	}
	
	for(i=0;i<n+m;i++){
		if((a[apoint]<=b[bpoint]&&apoint!=n)||bpoint==m){
			printf("%d ",a[apoint]);
			apoint++;
		}
		else if((a[apoint]>b[bpoint]&&bpoint!=m)||apoint==n){
			printf("%d ",b[bpoint]);
			bpoint++;
		}
	}
	
	return 0;
}

