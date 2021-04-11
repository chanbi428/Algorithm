#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, x, start, end, res1, res2, val=2147000000;
	cin>>n;
	vector<int>a(n);
	
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	start=0;
	end=n-1;
	while(start<end){
		if(abs(a[start]+a[end])<abs(val)){
			val=a[start]+a[end];
			res1=a[start];
			res2=a[end];
		}
		if(abs(a[start])>abs(a[end])) start++;
		else end--;
	}
	
	cout<<res1<<" "<<res2;
	
	return 0;
}
