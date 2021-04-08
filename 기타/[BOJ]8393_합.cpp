#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	
	int n, s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		s+=i;
	}
	cout<<s;
	 
	return 0;
}
