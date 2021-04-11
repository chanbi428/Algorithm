#include <bits/stdc++.h>
using namespace std;

vector<vector<long long> > arr={{1,1},{1,0}};
long long n;

vector<vector<long long> > mul(vector<vector<long long> > arr1, vector<vector<long long> > arr2){
	vector<vector<long long> >res(2, vector<long long>(2));
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int a=0; a<2; a++){
				res[i][j]=(res[i][j]+arr1[i][a]*arr2[a][j])%1000000007;
			}
		}
	}
	return res;
}

vector<vector<long long> > power(vector<vector<long long> > arr, long long b){
	vector<vector<long long> > tmp(2, vector<long long>(2));
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
	
	vector<vector<long long> > tmp(2, vector<long long>(2));
	long long i, j;
	cin>>n;
	tmp=power(arr,n);
	cout<<tmp[0][1]%1000000007;
	
	return 0;
}
