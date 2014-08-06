
import java.util.Scanner;

/**
 *
 * @author whuang
 */
public class Main {

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) {
      int numIter = 0, testCases = 0;
      Long maxLong = Long.MAX_VALUE, num, reversed;

      Scanner in = new Scanner(System.in);
      testCases = in.nextInt();
      for (int i = 0; i < testCases; i++) {
         numIter = 0;
         num = in.nextLong();
         reversed = reverseNumber(num);
         num += reversed;
         while (numIter < 999 && num <= maxLong) {
            if (isPalindrome(num.toString())) {
               System.out.println(numIter + 1 + " " + num);
               break;
            } else {
               reversed = reverseNumber(num);
               num += reversed;
               numIter++;
            }
         }
      }
   }

   public static Long reverseNumber(Long l) {
      Long reversedNum = 0l;
      while (l > 0) {
         reversedNum *= 10;
         reversedNum += l % 10;
         l /= 10;
      }
      return reversedNum;
   }

   public static Boolean isPalindrome(String str) {
      int strLen = str.length();
      for (int i = 0; i < strLen / 2; i++) {
         if (str.charAt(i) != str.charAt(strLen - (i + 1))) {
            return false;
         }
      }
      return true;
   }
}
