#include <bits/stdc++.h>
using namespace std;

int n, c;

bool poss(long long dis, vector<long long>house){
	long long cnt=1, tmp=house[0];
	for(int i=1; i<n; i++){
		if(house[i]-tmp>=dis){
			cnt++;
			tmp=house[i];
		}
	}
	if(cnt>=c) return true;
	else return false;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long long start, end, res=0;
	cin>>n>>c;
	vector<long long>house(n);
	for(int i=0; i<n; i++){
		cin>>house[i];
	}
	sort(house.begin(), house.end());
	start=1;
	end=house[n-1]-house[0];
	
	while(start<=end){
		long long mid=(start+end)/2;
		if(poss(mid, house)){
			start=mid+1;
			if(mid>res) res=mid;
		}
		else end=mid-1;
	}
	cout<<res;
	
	return 0;
}
