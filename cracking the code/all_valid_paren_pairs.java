/************************************
 * Cracking the Coding Interview 8.5
 ************************************/

import java.util.ArrayList;

public class all_valid_paren_pairs {

	static ArrayList<String> combos = new ArrayList<String>();
	
	public static void main(String[] args) {
		int pairs = 3;
		parens(pairs,pairs,"");
		// print it out!
		for(String x:combos){
			System.out.println(x);
		}		
	}
	
	static void parens(int left, int right, String s){
		if (left == 0 && right == 0){ // no more parens to add
			combos.add(s);
			return;
		}
		// push a ( into the string
		if (left >= right || left > 0){
			parens(left-1,right,s+"(");
		}
		// push a closing ) into the string
		if (left < right){
			parens(left,right-1,s+")");
		}
		return;
	}
}
