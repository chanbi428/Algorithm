#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, sum=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c;
		sum+=c-48;
	}
	cout<<sum;
		
	return 0;
}
