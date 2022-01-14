#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Ball{
	int bx, by, rx, ry, cnt;
};

char arr[10][10];
int n, m;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
queue<Ball>Q;
bool visited[10][10][10][10];

bool possible(int num, int x, int y){
	if(x+dx[num]<0 || x+dx[num]>=n || y+dy[num]<0 || y+dy[num]>=m || arr[x+dx[num]][y+dy[num]]=='#') return false;
	return true;
}

bool gored(int num, int rx, int ry, int bx, int by, int cnt){
	int x1=rx, y1=ry, x2=bx, y2=by;
	bool flag=false;
	while(possible(num, x1, y1)){
		x1+=dx[num];
		y1+=dy[num];
		if(arr[x1][y1]=='O'){
			flag=true;
			break;
		}
	}
	while(possible(num, x2, y2)){
		x2+=dx[num];
		y2+=dy[num];
		if(arr[x2][y2]=='O'){
			return false;
		}
		if(x2==x1 && y2==y1){
			x2-=dx[num];
			y2-=dy[num];
			break;
		}
	}
	if(flag) return true;
	if((x1==rx && y1==ry && x2==bx && y2==by) || cnt==10 || visited[x2][y2][x1][y1]==true) return false;
	Q.push({x2, y2, x1, y1, cnt+1});
	visited[x2][y2][x1][y1]=true;
	return false;
}

bool goblue(int num, int rx, int ry, int bx, int by, int cnt){
	int x1=bx, y1=by, x2=rx, y2=ry;
	while(possible(num, x1, y1)){
		x1+=dx[num];
		y1+=dy[num];
		if(arr[x1][y1]=='O'){
			return false;
		}
	}
	while(possible(num, x2, y2)){
		x2+=dx[num];
		y2+=dy[num];
		if(arr[x2][y2]=='O') return true;
		if(x2==x1 && y2==y1){
			x2-=dx[num];
			y2-=dy[num];
			break;
		}
	}
	if((x2==rx && y2==ry && x1==bx && y1==by) || cnt==10 || visited[x1][y1][x2][y2]==true || (x1==10 && y1==10)) return false;
	Q.push({x1, y1, x2, y2, cnt+1});
	visited[x1][y1][x2][y2]=true;
	return false;
}

bool go(int num, int rx, int ry, int bx, int by, int cnt){
	int x1=bx, y1=by, x2=rx, y2=ry;
	while(possible(num, x1, y1)){
		x1+=dx[num];
		y1+=dy[num];
		if(arr[x1][y1]=='O'){
			return false;
		}
	}
	while(possible(num, x2, y2)){
		x2+=dx[num];
		y2+=dy[num];
		if(arr[x2][y2]=='O') return true;
	}
	if((x2==rx && y2==ry && x1==bx && y1==by) || cnt==10 || visited[x1][y1][x2][y2]==true || (x1==10 && y1==10)) return false;
	Q.push({x1, y1, x2, y2, cnt+1});
	visited[x1][y1][x2][y2]=true;
	return false;
}

int bfs(pair<int, int> blue, pair<int, int> red){
	Q.push({blue.first, blue.second, red.first, red.second, 0});
   visited[blue.first][blue.second][red.first][red.second]=true;
   while(!Q.empty()){
   	Ball tmp =Q.front();
   	Q.pop();
   	if(tmp.by==tmp.ry){  //위, 아래 이동시에 같은 열에 있다면 
		if(tmp.rx<tmp.bx){
			if(gored(0, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
			if(goblue(1, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
		}
		else{
			if(gored(1, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
			if(goblue(0, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
		}
			for(int i=2; i<4; i++){
			if(go(i, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
		}
	}
	else if(tmp.bx==tmp.rx){
		if(tmp.ry<tmp.by){
			if(gored(2, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
			if(goblue(3, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1; 
		}
		else{
			if(gored(3, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
			if(goblue(2, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
		}
		for(int i=0; i<2; i++){
			if(go(i, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
		}
	}
	else{
		for(int i=0; i<4; i++){
			if(go(i, tmp.rx, tmp.ry, tmp.bx, tmp.by, tmp.cnt)) return tmp.cnt+1;
		}
	}	
   }
   return -1;
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   int i, j;
   pair<int, int> blue, red;
   
   cin>>n>>m;
   
   for(i=0; i<n; i++){
   	for(j=0; j<m; j++){
   		cin>>arr[i][j];
   		if(arr[i][j]=='B'){
   			blue={i, j};
   			arr[i][j]='.';
		}
		else if(arr[i][j]=='R'){
   			red={i, j};
   			arr[i][j]='.';
		}
	   }
   }
   
    int answer=bfs(blue, red);
   if(answer>10) cout<<"-1";
   else cout<<answer;

   return 0;
}