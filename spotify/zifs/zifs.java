import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


public class zifs {

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		int numSongs = scan.nextInt();
		int numChoose = scan.nextInt();
		
		int firstQuality = 0; 
		
//		System.out.println(numSongs);
//		System.out.println(numChoose);
		
        Comparator<Song> comparator = new SongComparator();
		PriorityQueue<Song> album = new PriorityQueue<Song>(numSongs, comparator);
		
		for (int i = 0; i < numSongs; i++){
			int qual = scan.nextInt();
			String n = scan.next();
			Song s;
			if (i == 0){
				firstQuality = qual;
			}
			s = new Song(qual, n);
			s.setZif(-1*qual/(firstQuality/(i+1)));
			album.add(s);
		}
		
		for (int i = 0; i < numChoose; i++){
			//System.out.println(album.peek().zif());
			System.out.println(album.poll().name());
		}
	}	
}

