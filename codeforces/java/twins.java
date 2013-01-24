/***************************
 * Codeforces 160A - Twins
 ***************************/

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class twins {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int numCoins = scan.nextInt();
		ArrayList<Integer> coins = new ArrayList<Integer>();
		
		int sum = 0;
		
		for(int i = 0; i < numCoins; i++){
			int tmp = scan.nextInt();
			sum += tmp;
			coins.add(tmp);
		}
		
		// easy sorting of arraylist
		Collections.sort(coins);

		int twinSum = 0;
		int twinCount = 0;
		
		for(int i = coins.size()-1; i >= 0; i--){
			twinSum += coins.get(i);
			twinCount++;
			if(twinSum > ((double)sum/2)){
				break;
			}
		}
		
		System.out.println(twinCount);
	}
}
