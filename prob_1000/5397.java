import java.util.LinkedList;
import java.io.*;

class Main {
	public static void main (String[] args) throws IOException {
		LinkedList<Character> list = new LinkedList<Character>();
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int index, n= Integer.parseInt(bf.readLine());;
		String pw = "";
		
		for (int i=0;i<n;i++) {
			pw = bf.readLine();
			index = 0;
			for (int j=0;j<pw.length();j++) {
				switch (pw.charAt(j)) {
					case '-' :
						if (index!=0) list.remove(--index);
						break;
					case '<' :
						if (index>0) index--;
                        break;
					case '>' :
						if (index<list.size()) index++;
                        break;
					default :
						list.add(index++, pw.charAt(j));
                        break;
				}
			}
			for (Character c : list)
                bw.write(c);
            bw.write("\n");
			list.clear();
        }
        bw.close();
	}
}
