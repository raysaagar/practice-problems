/*******************************************
 * Codeforces 245A - System Administrator
 *******************************************/

import java.util.Scanner;

public class sysadmin {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		
		int numCmds = scan.nextInt();
		
		int aPass = 0;
		int aTotal = 0;
		int bPass = 0;
		int bTotal = 0;
		
		for(int i = 0; i < numCmds; i++){
			
			if(scan.nextInt() == 1){
				aPass += scan.nextInt();
				scan.nextInt(); // get failed pings
				aTotal += 10;
			}
			else{
				bPass += scan.nextInt();
				scan.nextInt(); // get failed pings
				bTotal += 10;
			}
		}

		
		if((double) aPass / aTotal >= 0.5){
			System.out.println("LIVE");
		}
		else{
			System.out.println("DEAD");
		}
		if((double) bPass / bTotal >= 0.5){
			System.out.println("LIVE");
		}
		else{
			System.out.println("DEAD");
		}
	}
}
