#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, x, ai, start, end, cnt=0;
	cin>>n;
	vector<int>a(n);
	
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a.begin(), a.end());
	cin>>x;
	
	start=0;
	end=n-1;
	while(start<end){
		if(a[start]+a[end]==x){
			cnt++;
			start++;
			end--;
		}
		else if(a[start]+a[end]<x) start++;
		else end--;
	}
	
	cout<<cnt;
	
	return 0;
}
