#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, a, i, j, tmp;
	
	cin>>n;
	vector<int>num(n);
	
	for(i=0;i<n;i++){
		cin>>a;
		num[i]=a;
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(num[i]>num[j]){
				tmp=num[i];
				num[i]=num[j];
				num[j]=tmp;
			}
		}
	}
	for(i=0;i<n;i++){
		cout<<num[i]<<"\n";
	}
	

		
	return 0;
}
