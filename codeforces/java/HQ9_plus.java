/*************************
 * Codeforces 133A - HQ9+
 *************************/

import java.util.Scanner;

public class HQ9_plus {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		String program = scan.nextLine();	
		if(program.contains("H") || program.contains("Q") || program.contains("9"))
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}
