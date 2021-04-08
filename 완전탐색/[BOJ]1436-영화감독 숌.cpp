#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, cnt=0;
	string str;
	
	cin>>n;
	for(i=666;;i++){
		str=to_string(i);
		if(str.find("666")!=-1) cnt++;
		if(cnt==n) break;
	}
	cout<<str;

		
	return 0;
}
