#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, b, i, j, n;
	cin>>n;
	
	for(j=0;j<n;j++){
		cin>>a>>b;
		for(i=1;;i++){
    		if((a*i)%b==0){
    			cout<<a*i<<"\n";
    			break;
			}
		}
	}
		
	return 0;
}
