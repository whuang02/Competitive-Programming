/*  Solution to Problem 10213
 * 	By: Wei Wei Huang & Mohammed Hossain
 * 	Language: Java * 
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner istream = new Scanner(System.in);
		int cases;	
		BigInteger n, lands;
		
		for(cases = istream.nextInt(); cases > 0; cases--){
			
			n = istream.nextBigInteger();
			//Formula = (n choose 2) + (n choose 4) + 1 
			//Converted to polynomial: (n^4 - 6n^3 + 23n^2 - 18n + 24)/24
			lands = n.pow(4); // n^4
			lands = lands.subtract(BigInteger.valueOf(6).multiply(n.pow(3))); // -6n^3
			lands = lands.add(BigInteger.valueOf(23).multiply(n.pow(2))); // +23n^2
			lands = lands.subtract(BigInteger.valueOf(18).multiply(n)); // -18n
			lands = lands.add(BigInteger.valueOf(24)); //+24
			lands = lands.divide(BigInteger.valueOf(24)); // lands/24
			System.out.println(lands);
		}
	}
}
