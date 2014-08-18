import java.util.Scanner;

/**
 *
 * @author whuang Problem 10346 - Peter's Smokes
 */
public class Main {

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) {
      int n, k;
      Scanner in = new Scanner(System.in);

      while (in.hasNext()) {
         n = in.nextInt();
         k = in.nextInt();

         System.out.println(n + (n - 1) / (k - 1));
      }
   }
}