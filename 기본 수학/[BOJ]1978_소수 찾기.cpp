#include <bits/stdc++.h>
using namespace std;

int num[1001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int i, n, a, j, cnt=0;
	num[1]=1;
	for(i=2;i<1001;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				num[i]=1;
				break;
			}
			
		}
	}
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		if(num[a]==0) cnt++;
	}
	cout<<cnt;
		
	return 0;
}
