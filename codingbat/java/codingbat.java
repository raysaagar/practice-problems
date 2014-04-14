/* Coding Bat Java Problems */

public class codingbat {

	// Coding Bat Array-3 Problems
	public static int maxSpan(int[] nums) {
	
		int largestSpan = 0;
		
		for (int i = 0; i < nums.length; i++) {
			for (int j = i; j < nums.length; j++) {
				if (nums[i] == nums[j]) {
					int count = j - i + 1;
					if (count > largestSpan) {
						largestSpan = count;
					}
				}
			}
		}
		
		return largestSpan;
	}
	
	public static boolean canBalance(int[] nums) {
		int len = nums.length;
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum += nums[i];
			int rollingSum = 0;
			for (int j = i+1; j < len; j++) {
				rollingSum += nums[j];
			}
			if (sum == rollingSum)
			{
				System.out.println("true");
				return true;
			}
		}
		System.out.println("false");
		return false;
	}

	
	public static boolean linearIn(int[] outer, int[] inner) {
		int outersize = outer.length;
		int innersize = inner.length;
		
		if (innersize == 0)
			return true;
		
		int innerpos = 0;
		
		for (int i = 0; i < outersize; i++) {
			if (outer[i] == inner[innerpos]) {
				innerpos++;
			}
			if (innerpos == innersize)
				break;
		}
		
		if (innerpos == innersize) {
			System.out.println("true");
			return true;
		}
		
		System.out.println("false");
		return false;
	}
	
	public static int[] squareUp(int n) {
		if (n == 0)
			return new int[0];
		int[] nums = new int[n*n];
		
		int count = 0;
		for (int i = 1; i <= n; i++) {
			int nt = n;
			
			while (nt > 0) {
				if (i < nt) {
					nums[count] = 0;
				}
				else {
					nums[count] = nt;
				}
				count++;
				nt--;
			}
			
		}
		
		for (int i = 0; i < nums.length; i++)
			System.out.print(nums[i] + " ");
		System.out.println();
		
		return nums;
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

//		maxSpan(new int[] {1, 2, 1, 1, 3});
//		maxSpan(new int[] {1, 4, 2, 1, 4, 1, 4});
//		maxSpan(new int[] {1, 4, 2, 1, 4, 4, 4});
//		maxSpan(new int[] {1});
		
//		canBalance(new int[] {1, 1, 1, 2, 1});
//		canBalance(new int[] {2, 1, 1, 2, 1});
//		canBalance(new int[] {10, 10});
		
//		linearIn(new int[]{1, 2, 4, 6}, new int[]{2, 4});
//		linearIn(new int[]{1, 2, 4, 6}, new int[]{2, 3, 4});
//		linearIn(new int[]{1, 2, 4, 4, 6}, new int[]{2, 4});
		
		squareUp(3);
		squareUp(2);
		squareUp(4);
	}
	

}
