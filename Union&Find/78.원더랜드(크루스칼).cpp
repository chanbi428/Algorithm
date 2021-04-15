#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int unf[101], sum=0;

struct Data{
	int v1;
	int v2;
	int e;
	Data(int a, int b, int c){
		v1=a;
		v2=b;
		e=c;
	}
	bool operator<(Data &c){
		return e<c.e;
	}
};

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b, int c){
	a=Find(a);
	b=Find(b);
	if(a!=b){
		unf[a]=b;
		sum+=c;
	}
}

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int n, m, i, a, b, c;
	vector<Data> k;
	
	scanf("%d %d",&n, &m);
	for(i=1;i<=n;i++){
		unf[i]=i;
	}
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a, &b, &c);
		k.push_back(Data(a,b,c));
	}
	sort(k.begin(),k.end());
	for(i=0;i<m;i++){
		Union(k[i].v1,k[i].v2,k[i].e);
	}
	
	printf("%d", sum);


	return 0;
}

