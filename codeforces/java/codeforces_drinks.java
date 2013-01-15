/*****************************
 * Codeforces 200B - Drinks
 *****************************/

import java.util.Scanner;

public class codeforces_drinks {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		int numDrinks = scanner.nextInt();
		double total = 0.0;
		
		for(int i = 0; i < numDrinks; i++){
			double x = scanner.nextInt();
			total += (x / numDrinks);
		}		
		System.out.println(total);
	}
}
