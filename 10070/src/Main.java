import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author whuang Problem 10070 - Leap Year or Not Leap Year and ...
 */
public class Main {

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) {
      BigInteger year;
      boolean specialYear, first = true, leapYear;
      Scanner in = new Scanner(System.in);

      while (in.hasNext()) {
         year = new BigInteger(in.nextLine());
         specialYear = false;
         leapYear = false;
         if (first) {
            first = false;
         } else {
            System.out.println("");
         }
         if (isLeapYear(year)) {
            specialYear = true;
            leapYear = true;
            System.out.println("This is leap year.");
         }
         if (isHuluculu(year)) {
            specialYear = true;
            System.out.println("This is huluculu festival year.");
         }
         if (leapYear && isBulukulu(year)) {
            specialYear = true;
            System.out.println("This is bulukulu festival year.");
         }
         if (!specialYear) {
            System.out.println("This is an ordinary year.");
         }
      }
   }

   public static boolean isLeapYear(BigInteger year) {
      return year.mod(BigInteger.valueOf(400)).equals(BigInteger.ZERO)
              || (year.mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO) && !year.mod(BigInteger.valueOf(100)).equals(BigInteger.ZERO));
   }

   public static boolean isHuluculu(BigInteger year) {
      return year.mod(BigInteger.valueOf(15)).equals(BigInteger.ZERO);
   }

   public static boolean isBulukulu(BigInteger year) {
      return year.mod(BigInteger.valueOf(55)).equals(BigInteger.ZERO);
   }
}
