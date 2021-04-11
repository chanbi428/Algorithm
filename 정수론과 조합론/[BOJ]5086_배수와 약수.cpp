#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, b;
	while(true){
		cin>>a>>b;
		if(a==0 && b==0) break;
		else if(b%a==0) cout<<"factor\n";
		else if(a%b==0) cout<<"multiple\n";
		else cout<<"neither\n";
	}
		
	return 0;
}
