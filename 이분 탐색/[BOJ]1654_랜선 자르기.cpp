#include <bits/stdc++.h>
using namespace std;

int n, k;
long long rof[10000];

bool poss(long long leng){
	long long cnt=0;
	for(int i=0;i<k;i++){
		cnt+=rof[i]/leng;
	}
	if(cnt>=n) return true;
	else return false;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long long leng=0, start, end, res=0;
	cin>>k>>n;
	for(int i=0;i<k;i++){
		cin>>rof[i];
		if(leng<rof[i]) leng=rof[i];
	}
	start=1;
	end=leng;
	while(start<=end){
		long long mid=(start+end)/2;
		if(poss(mid)){
			if(res<mid) res=mid;
			start=mid+1;
		}
		else end=mid-1;
	}
	cout<<res;
	
	return 0;
}
