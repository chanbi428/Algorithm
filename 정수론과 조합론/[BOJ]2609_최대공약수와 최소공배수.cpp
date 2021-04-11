#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int a, b, small, i;
	cin>>a>>b;
	small=min(a, b);
	for(i=small;i>=1;i--){
		if(a%i==0 && b%i==0){
			cout<<i<<"\n";
			break;
		}
	}
    for(i=1;;i++){
    	if((a*i)%b==0){
    		cout<<a*i<<"\n";
    		break;
		}
	}
		
	return 0;
}
