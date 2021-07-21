#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, t, i, j, a, b;
	cin>>t;
	
	for(i=0; i<t; i++){
		cin>>n>>m;
		
		for(j=0; j<m; j++){
            cin>>a>>b;
        }
		
		cout<<n-1<<"\n";
	}
	
	return 0;
}
