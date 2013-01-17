/**************************************************************************
 * Calculate edit distance between two strings using dynamic programming
 * http://www.cs.berkeley.edu/~vazirani/algorithms/chap6.pdf
 **************************************************************************/

import java.util.Scanner;

public class edit_distance {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);

		// this example has edit distance of 6
//		String str1 = "exponential";
//		String str2 = "polynomial";
		
		String str1 = scanner.nextLine();
		String str2 = scanner.nextLine();
		
		int[][] subdists = new int[str1.length()][str2.length()];
		
		for(int i = 0; i < str1.length(); i++){
			subdists[i][0] = i;
		}
		for(int i = 1; i < str2.length(); i++){
			subdists[0][i] = i;
		}
		
		for(int i = 1; i < str1.length(); i++ ){
			for(int j = 1; j < str2.length();j++){
				subdists[i][j] = Math.min(Math.min(subdists[i-1][j]+1, subdists[i][j-1]+1),subdists[i-1][j-1]+((str1.charAt(i) == str2.charAt(j)) ? 0 : 1));
			}
		}
		
		// print the array to see all calculations
		for(int i = 0; i < str1.length(); i++ ){
			for(int j = 0; j < str2.length();j++){
				System.out.printf("%2d ", subdists[i][j]);
			}
			System.out.println();
		}
		
		System.out.println("Edit Distance: " + subdists[str1.length()-1][str2.length()-1]);
	}
}
