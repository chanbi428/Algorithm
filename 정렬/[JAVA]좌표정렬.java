import java.util.*;

class Pair implements Comparable<Pair>{
	int x, y;
	Pair(int x, int y){
		this.x = x;
		this.y = y;
	}
	@Override
	public int compareTo(Pair p) {
		if(p.x==this.x) return this.y-p.y;
		return this.x-p.x;
	}
	
}

public class Main {	

	public static void main(String[] args) {
		//Main T = new Main();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Pair> arr = new ArrayList<>();
		for(int i=0; i<n; i++) {
			Pair tmp = new Pair(sc.nextInt(), sc.nextInt());
			arr.add(tmp);
		}
		sc.close();
		
		Collections.sort(arr);
		for(Pair x : arr) System.out.println(x.x+" "+x.y);
		
	}

}

// 설명

// N개의 평면상의 좌표(x, y)가 주어지면 모든 좌표를 오름차순으로 정렬하는 프로그램을 작성하세요.

// 정렬기준은 먼저 x값의 의해서 정렬하고, x값이 같을 경우 y값에 의해 정렬합니다.


// 입력
// 첫째 줄에 좌표의 개수인 N(3<=N<=100,000)이 주어집니다.

// 두 번째 줄부터 N개의 좌표가 x, y 순으로 주어집니다. x, y값은 양수만 입력됩니다.


// 출력
// N개의 좌표를 정렬하여 출력하세요.


