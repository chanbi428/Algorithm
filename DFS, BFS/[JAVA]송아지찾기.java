import java.util.*;

public class Main {	
	class Pair{
		int x, y;
		Pair(int x, int y){
			this.x=x;
			this.y=y;
		}
	}

	public int solution(int s, int e) {
		int answer = 0;
		boolean visited[] = new boolean[10001];
		Queue<Pair> Q = new LinkedList<>();
		Q.offer(new Pair(s, 0));
		visited[s] = true;
		
		while(true) {
			int pos = Q.peek().x;
			int cnt = Q.poll().y;
			if(pos == e) {
				answer = cnt;
				break;
			}
			if(pos>0 && pos<=10000 && !visited[pos+1]) {
				Q.offer(new Pair(pos+1, cnt+1));
				visited[pos+1] = true;
			}
			if(pos>0 && pos<=10000 && !visited[pos-1]) {
				Q.offer(new Pair(pos-1, cnt+1));
				visited[pos-1] = true;
			}
			if(pos>0 && pos<=10000 && !visited[pos+5]) {
				Q.offer(new Pair(pos+5, cnt+1));
				visited[pos+5] = true;
			}
		}
		
		return answer;
	}
	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		int s = sc.nextInt();
		int e = sc.nextInt();
		sc.close();
		
		System.out.print(T.solution(s, e));
		
	}

}

// 설명

// 현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다.

// 현수의 위치와 송아지의 위치가 수직선상의 좌표 점으로 주어지면 현수는 현재 위치에서 송아지의 위치까지 다음과 같은 방법으로 이동한다.

// 송아지는 움직이지 않고 제자리에 있다.

// 현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수 있다.

// 최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성하세요.


// 입력
// 첫 번째 줄에 현수의 위치 S와 송아지의 위치 E가 주어진다. 직선의 좌표 점은 1부터 10,000까지이다.


// 출력
// 점프의 최소횟수를 구한다. 답은 1이상이며 반드시 존재합니다.


