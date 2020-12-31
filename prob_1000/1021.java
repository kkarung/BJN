import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class Main {
	public static void main (String[] args) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt(), m, a=0, b, count=0;
		// a는 현재 index, b는 찾으려는 수의 index
		
		for (int i=1;i<=n;i++)
			list.add(i);
		
		m = scan.nextInt();
		for (int i=0;i<m;i++) {
			b = list.indexOf(scan.nextInt());
			if (b>a) 
				count += (b-a < n-(b-a)) ? b-a : n-(b-a);
			else
				count += (a-b < n-(a-b)) ? a-b : n-(a-b);
			list.remove(b);
			a = b++;
			n--;
		}
		System.out.println(count);
	}
}
