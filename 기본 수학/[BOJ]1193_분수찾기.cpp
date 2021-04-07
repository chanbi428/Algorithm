#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int n, cnt=1, tmp=1, mo, ja;
	cin>>n;
	while(tmp<n){
		cnt++;
		tmp=tmp+cnt;
	}
	if(cnt%2==0){
		ja=cnt-(tmp-n);
		mo=cnt-ja+1;
	}
	else{
		mo=cnt-(tmp-n);
		ja=cnt-mo+1;
	}
	cout<<ja<<"/"<<mo;
		
	return 0;
}
