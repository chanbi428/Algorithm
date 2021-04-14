#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
	
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	
	int n, m, i;
	int ap=0, bp=0;

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
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	while(ap!=n&&bp!=m){
		if(a[ap]>b[bp]) bp++;
		else if(a[ap]<b[bp]) ap++;
		else{
			printf("%d ",a[ap]);
			ap++;
			bp++;
		}
	}
	
	return 0;
}

