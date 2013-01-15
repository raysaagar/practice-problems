/************************************
 * Cracking the Coding Interview 8.2
 ************************************/

public class possible_paths {

	public static void main(String[] args) {

		final int WIDTH = 4;
		final int HEIGHT = 5;
		
		// this array represents WIDTH by HEIGHT squares, so WIDTH+1 by HEIGHT+1 points 
		// ex - when 2 x 2, there are 9 points and  possible paths. 
		int[][] points = new int[WIDTH+1][HEIGHT+1];
		
		
		for(int i = 0; i < points.length; i++){
			for(int j = 0; j < points[0].length; j++){
				points[i][j] = 0;
			}
		}
		
		int combos = 1;
		for(int i = 1; i <= (WIDTH + HEIGHT); i++){
			combos *= i;
		}
		for(int i = 1; i <= WIDTH; i++){
			combos /= i;
		}
		for(int i = 1; i <= HEIGHT; i++){
			combos /= i;
		}
		
		int paths = countpaths(points,0,0);
		
		for(int i = 0; i < points.length; i++){
			for(int j = 0; j < points[0].length; j++){
				System.out.printf("%3d ", points[i][j]);
			}
			System.out.println();
		}
		
		if (combos != paths)
			System.out.println("ERROR!");
		System.out.println("Combinatorics:\t" + combos + "\nRecursive:\t" + paths);
		
		return;
	}
	
	static int countpaths(int[][] pts, int x, int y){
		
//		if(x == pts.length && y == pts[0].length)
//			return 1;
//		
//		int xpath = 0;
//		if(x < pts.length){
//			xpath = countpaths(pts,x+1,y);
//		}
//		
//		int ypath = 0;
//		if(y < pts[0].length){
//			ypath = countpaths(pts,x,y+1);
//		}
//		
//		return xpath + ypath;
		
		if (x == pts.length-1 || y == pts[0].length-1){
			return (pts[x][y] = 1);
		}
		return (pts[x][y] = countpaths(pts,x+1,y) + countpaths(pts,x,y+1)); 
	}

}
