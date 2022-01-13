#include <iostream>
#include <algorithm>

using namespace std;

int map[33]={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,13,16,19,22,24,28,27,26,25,30,35,40,0};
bool visited[33];
int point[4]={0,0,0,0};
int dice[10], answer;

void move(int n, int sum){
	if(n==10){
		answer=max(answer, sum);
		return;
	}
	for(int i=0; i<4; i++){
		int next=point[i]+dice[n], pre=point[i];
		if(pre==32) continue;
		
		if(pre==5 || (pre>=20 && pre<=22 && next>22)){
			if(pre==5) next+=14;
			if(next>22) next+=5;
		}
		else if(pre==10 || (pre>=23 && pre<=24 && next>24)){
			if(pre==10) next+=12;
			if(next>24) next+=3;
		}
		else if(pre==15){
			next+=9;
		}
		else if(pre>=16 && pre<=19 && next>19){
			next+=11;
		}
		if(next>32) next=32;
		
		if(next!=32 && visited[next]) continue;
		visited[pre]=false;
		visited[next]=true;
		point[i]=next;
		move(n+1, sum+map[next]);
		visited[next]=false;
		visited[pre]=true;
		point[i]=pre;
	}
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   for(int i=0; i<10; i++) cin>>dice[i];
   move(0, 0);
   
   cout<<answer;
   
   return 0;
}
