#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long long n, k, start, end, res=0, i, j;
	cin>>n>>k;

	start=1;
	end=n*n;
	
	while(start<=end){
		long long mid=(start+end)/2;
		long long cnt=0, imax;
		for(i=1; i<=n; i++){
			if(mid>=i*n) cnt+=n;
			else cnt+=mid/i;
		}
		if(cnt>=k){
			res=mid;
			end=mid-1;
		}
		else start=mid+1;
	}
	cout<<res;
	
	return 0;
}
