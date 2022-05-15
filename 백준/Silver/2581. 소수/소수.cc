#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int i, j, n, m, a, sum=0, mmin=0, flag=0;
	cin>>m>>n;
	for(i=m;i<=n;i++){
		if(i==1) continue;
		flag=0;
		for(j=2;j<i;j++){
			if(i%j==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			if(mmin==0) mmin=i;
			sum+=i;
		}
	}
	if(sum==0) cout<<"-1";
	else cout<<sum<<"\n"<<mmin;
		
	return 0;
}
