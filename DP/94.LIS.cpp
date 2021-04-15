#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, i, j, res=0;
	cin>>n;
	vector<int> arr(n);
	vector<int> dy(n,1);
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(arr[i]>arr[j]&&dy[i]<dy[j]+1) dy[i]=dy[j]+1;
		}
		if(res<dy[i]) res=dy[i];
	}
	cout<<res;
	 
	return 0;
}

