#include <bits/stdc++.h>
using namespace std;

struct Brick{
	int s, h, w;
	Brick(int a, int b, int c){
		s=a, h=b, w=c;
	}
	const operator<(const Brick &rr){
		return s>rr.s;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, i, j, a, b, c, res=0;
	cin>>n;
	vector<int> dy(n);
	vector<Brick> Bricks;

	for(i=0;i<n;i++){
		cin>>a>>b>>c;
		Bricks.push_back(Brick(a, b, c));
	}
	sort(Bricks.begin(), Bricks.end());
	dy[0]=Bricks[0].h;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(Bricks[i].w<Bricks[j].w && dy[i]<dy[j]+Bricks[i].h) dy[i]=dy[j]+Bricks[i].h;
		}
		if(dy[i]==0) dy[i]=Bricks[i].h;
		if(res<dy[i]) res=dy[i];
	}
	cout<<res;
	 
	return 0;
}

