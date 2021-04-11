#include <bits/stdc++.h>
using namespace std;

vector<vector<long long> > arr(5, vector<long long>(5));
long long n;

vector<vector<long long> > mul(vector<vector<long long> > arr1, vector<vector<long long> > arr2){
	vector<vector<long long> >res(5, vector<long long>(5));
	for(long long i=0; i<n; i++){
		for(long long j=0; j<n; j++){
			for(long long a=0; a<n; a++){
				res[i][j]=(res[i][j]+arr1[i][a]*arr2[a][j])%1000;
			}
		}
	}
	return res;
}

vector<vector<long long> > power(vector<vector<long long> > arr, long long b){
	vector<vector<long long> > tmp(5, vector<long long>(5));
	if(b==1) return arr;
	else if(b%2==0){
		tmp=power(arr,b/2);
		return mul(tmp, tmp);
	}
	else{
		tmp=power(arr,b-1);
		return mul(arr,tmp);
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	vector<vector<long long> > tmp(5, vector<long long>(5));
	long long i, j;
	long long b;
	cin>>n>>b;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	tmp=power(arr,b);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cout<<tmp[i][j]%1000<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
