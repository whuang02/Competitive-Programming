import java.util.Scanner;

/**
 *
 * @author whuang Problem 10235 - Simply Emirp
 */
public class Main {

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) {
      Integer num, reverse;

      Scanner in = new Scanner(System.in);
      while (in.hasNext()) {
         num = in.nextInt();

         if (!isPrimeNumber(num) || num == 1) {
            System.out.println(num + " is not prime.");
         } else {
            reverse = reverseInt(num);
            if(num.equals(reverse) || !isPrimeNumber(reverse)){
               System.out.println(num + " is prime.");
            }
            else {
               System.out.println(num + " is emirp.");
            }
           
         }
      }
   }

   public static boolean isPrimeNumber(int number) {
      if (number == 2 || number == 3) {
         return true;
      }
      if (number % 2 == 0) {
         return false;
      }
      int sqrt = (int) Math.sqrt(number) + 1;
      for (int i = 3; i < sqrt; i += 2) {
         if (number % i == 0) {
            return false;
         }
      }
      return true;
   }

   public static int reverseInt(Integer num) {
      int r = 0;
      while (num > 0) {
         r *= 10;
         r += num % 10;
         num /= 10;
      }
      return r;
   }
}
