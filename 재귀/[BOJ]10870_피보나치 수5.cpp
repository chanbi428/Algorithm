#include <bits/stdc++.h>
using namespace std;

int n;

int nach(int num){
	if(num==0) return 0;
	if(num==1) return 1;
	return nach(num-1)+nach(num-2);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	cin>>n;
	cout<<nach(n);
		
	return 0;
}
