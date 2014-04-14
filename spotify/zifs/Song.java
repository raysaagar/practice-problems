public class Song{

		int quality;
		String name;
		double zif;

		public Song(int val, String n){
			quality = val;
			name = n;
			zif = val;
		}

		public int quality(){
			return this.quality;
		}

		public String name(){
			return this.name;
		}

		public double zif(){
			return this.zif;
		}

		public void setZif(int z){
			this.zif = z;
		}

		public int compareTo(Object obj){
			Song tmp = (Song) obj;

			if (this.zif < tmp.zif()){
				return -1;
			}
			else if (this.zif > tmp.zif()){
				return 1;
			}
			return 0;
		}
	}
