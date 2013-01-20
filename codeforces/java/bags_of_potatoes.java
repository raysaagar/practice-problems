/******************************************
 * Codeforces 239A - Two Bags of Potatoes
 ******************************************/

import java.util.Scanner;

public class bags_of_potatoes {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int y = scan.nextInt();
		int k = scan.nextInt();
		int n = scan.nextInt();
		
		int count = 0;
		// get the first x
		int x = k - (y % k);
		
		if (x + y > n){
			System.out.println(-1);
			return;
		}
		else{
			// get all other x's by skipping k numbers at a time
			while(x+y <= n){
				System.out.print(x + " ");
				x += k;
			}
		}
	}
}
