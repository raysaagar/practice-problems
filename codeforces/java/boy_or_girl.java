/*********************************
 * Codeforces 158A - Boy or Girl
 *********************************/
import java.util.HashSet;
import java.util.Scanner;

public class boy_or_girl {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		HashSet<String> letters = new HashSet<String>(100);

		String user = scan.nextLine();

		for(int i = 0; i < user.length(); i++){
			letters.add(user.substring(i, i+1));
		}

		if(letters.size() % 2 == 0){
			System.out.println("CHAT WITH HER!");
		}
		else{
			System.out.println("IGNORE HIM!");
		}

	}

}
