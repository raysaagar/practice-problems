/*******************************************
 * Codeforces 276A - Lunch Rush
 *******************************************/

import java.util.Scanner;

public class lunchrush {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int joy = Integer.MAX_VALUE * -1;
		
		int numRest = scanner.nextInt();
		int maxTime = scanner.nextInt();
		int f, t;
		
		for(int i = 0; i < numRest; i++){
			f = scanner.nextInt();
			t = scanner.nextInt();
			if (t > maxTime){
				int tmp = f - (t - maxTime);
				joy = tmp > joy ? tmp : joy;
			}
			else{
				joy = f > joy ? f : joy;
			}
		}
		
		System.out.println(joy);

	}

}
