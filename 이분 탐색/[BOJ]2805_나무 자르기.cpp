#include <bits/stdc++.h>
using namespace std;

int n, m;

bool poss(long long leng, vector<long long>wood){
	long long home=0;
	for(int i=0; i<n; i++){
		if(wood[i]>leng) home+=wood[i]-leng;
	}
	if(home>=m) return true;
	else return false;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long long start=0, end=0, res=0;
	cin>>n>>m;
	vector<long long>wood(n);
	for(int i=0; i<n; i++){
		cin>>wood[i];
		if(end<wood[i]) end=wood[i];
	}
	
	while(start<=end){
		long long mid=(start+end)/2;
		if(poss(mid, wood)){
			start=mid+1;
			if(mid>res) res=mid;
		}
		else end=mid-1;
	}
	cout<<res;
	
	return 0;
}
