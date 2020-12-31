import java.io.*;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Point {
	int x, y;
	
	public Point(int x, int y) {
		this.x = x; this.y = y;
	}
}

class Direct {
	int time; String dir;
	public Direct (int t, String d) {
		time = t; dir = d;
	}
}

class Main {
	public static void main (String[] args) throws IOException {
		LinkedList<Point> list = new LinkedList<Point>();
		LinkedList<Point> apple = new LinkedList<Point>();
		HashMap<Integer, String> direct = new HashMap<Integer, String>();
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int time=0, n, k, l, x=1, y=1, dir=1, temp;
		
		n = Integer.parseInt(bf.readLine()); // 보드 크기
		k = Integer.parseInt(bf.readLine()); // 사과 개수
		for (int i=0;i<k;i++) { // 사과 위치 저장
			st = new StringTokenizer(bf.readLine());
			temp = Integer.parseInt(st.nextToken()); // y 값
			apple.add(new Point(Integer.parseInt(st.nextToken()), temp)); // x값
		}
		l = Integer.parseInt(bf.readLine()); // 방향 변환 횟수
		for (int i=0;i<l;i++) { // 방향 시간 저장
			st = new StringTokenizer(bf.readLine());
			direct.put(Integer.parseInt(st.nextToken()), st.nextToken());
		}
		
		list.add(new Point(1, 1));
		while (true) {
			time++;
			if(dir<0) dir+=4;
			switch(dir%4) {
				case 0 : y--; break;
				case 1 : x++; break;
				case 2 : y++; break;
				case 3 : x--; break;
				default : break;
			}
			
			if (x>n||x<1||y>n||y<1) // 벽 충돌 체크
				break;
			if (removeContainsPoint(list, new Point(x, y))) { // 몸 충돌 (값 삭제되어도 상관 없음)
				break;
			}
			list.add(new Point(x, y)); // 머리 한 칸 전진
			
			if (!removeContainsPoint(apple, new Point(x, y))) // 사과가 있으면 사과list에서 삭제 및 false return, 사과가 없으면
				list.remove(0); // 몸 삭제

			if (direct.containsKey(time)) { // 방향 변환 시간이면
				if (direct.get(time).equals("L")) dir--;
				else if (direct.get(time).equals("D")) dir++;
			}
		}
		bw.write(time+"\n");
		bw.close();
	}
	public static boolean removeContainsPoint(LinkedList<Point> l, Point p) {
		for (int i=0; i<l.size(); i++) {
			if (l.get(i).x==p.x && l.get(i).y==p.y) {
				l.remove(i);
				return true;
			}
		}
		return false;
	}
}
