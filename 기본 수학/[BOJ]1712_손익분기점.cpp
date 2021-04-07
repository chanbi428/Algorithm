#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	int a, b, c, res;
	cin>>a>>b>>c;
	if(b>=c) cout<<"-1";
	else cout<<a/(c-b)+1;
		
	return 0;
}
