#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[10001];

struct Node{
	int v1, v2, cost;
	Node(int a, int b, int c){
		v1=a; v2=b; cost=c;
	}
};

bool cmp(Node&a, Node&b){
	return a.cost<b.cost;
}

int find(int v){
	if(root[v]==v) return v;
	else return find(root[v]);
}

bool unio(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y) return false;
	root[x]=y;
	return true;
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int v, e, a, b, c, i, cnt=0;
	long long sum=0;
	
	cin>>v>>e;
	vector<Node> gragh;
	
	for(i=1; i<v+1; i++) root[i]=i;
	
	for(i=0; i<e; i++){
		cin>>a>>b>>c;
		gragh.push_back(Node(a, b, c));
	}
	sort(gragh.begin(), gragh.end(), cmp);
	
	for(i=0; i<gragh.size(); i++){
		if(unio(gragh[i].v1, gragh[i].v2)){
			sum+=gragh[i].cost;
			cnt++;
		}
		if(cnt==v-1){
			cout<<sum;
			break;
		}
	}
	
	return 0;
}
