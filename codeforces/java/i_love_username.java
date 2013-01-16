/***************************************
 * Codeforces 155A - I_love_%username%
 ***************************************/

import java.util.Scanner;

public class i_love_username {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int numContests = scanner.nextInt();
		int tmp = scanner.nextInt();
		int low = tmp;
		int high = tmp;
		int amazing = 0;
		
		for(int i = 1; i < numContests; i++){
			tmp = scanner.nextInt();
			if (tmp > high){
				high = tmp;
				amazing++;
			}
			if (tmp < low){
				low = tmp;
				amazing++;
			}
		}
		
		System.out.println(amazing);
		return;
	}

}
