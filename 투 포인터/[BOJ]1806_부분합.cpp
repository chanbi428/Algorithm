#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, s, start, end, sum=0, cnt;
	cin>>n>>s;
	vector<int>a(n);
	
	for(int i=0; i<n; i++) cin>>a[i];
	
	start=0;
	end=0;
	cnt=2147000000;
	while(start<=end){
		if(sum>=s){
			cnt=min(cnt, end-start);
			sum-=a[start];
			start++;
		}
		else if(end==n) break;
		else{
			sum+=a[end];
			end++;
		}
	}
	if(cnt==2147000000) cout<<"0";
	else cout<<cnt;
	
	return 0;
}
