#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void init(vector<int> &tree, vector<int> &h, int start, int end, int node){
	if(start==end) tree[node]=start;
	else{
		int mid=(start+end)/2;
		init(tree, h, start, mid, node*2);
		init(tree, h, mid+1, end, node*2+1);
		if(h[tree[node*2]]<=h[tree[node*2+1]]) tree[node]=tree[node*2];
		else tree[node]=tree[node*2+1];
	}
}

int query(vector<int> &tree, vector<int> &h, int start, int end, int node, int left, int right){
	if(left>end || right<start) return -1;
	if(left<=start && end<=right) return tree[node];
	int mid=(start+end)/2;
	int tmp1=query(tree, h, start, mid, node*2, left, right);
	int tmp2=query(tree, h, mid+1, end, node*2+1, left, right);
	if(tmp1==-1) return tmp2;
	else if(tmp2==-1) return tmp1;
	else{
		if(h[tmp1]<=h[tmp2]) return tmp1;
		else return tmp2;
	}
}

long long histo(vector<int> &tree, vector<int> &h, int start, int end){
	int n=h.size();
	int h_min=query(tree, h, 0, n-1, 1, start, end);
	long long area=(long long)h[h_min]*(long long)(end-start+1);
	if(h_min>start){
		long long tmp=histo(tree, h, start, h_min-1);
		area=max(area, tmp);
	}
	if(h_min<end){
		long long tmp=histo(tree, h, h_min+1, end);
		area=max(area, tmp);
	}
	return area;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n;
	while(true){
		cin>>n;
		if(n==0) break;
		vector<int>h(n);
		for(int i=0; i<n; i++){
			cin>>h[i];
		}
		//int t = (int)(ceil(log2(t))+1e-9);
        //int tree_size = (1 << (t+1));
        vector<int> tree(n*4);
		init(tree, h, 0, n-1, 1);
		cout<<histo(tree, h, 0, n-1)<<"\n";
	}
	
	return 0;
}
