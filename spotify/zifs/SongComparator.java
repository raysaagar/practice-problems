import java.util.Comparator;

public class SongComparator implements Comparator<Song>{

	@Override
	public int compare(Song o1, Song o2) {
		if (o1.zif() < o2.zif()){
			return -1;
		}
		else if (o1.zif() > o2.zif()){
			return 1;
		}
		return 0;
	}
}