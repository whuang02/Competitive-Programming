import java.util.Scanner;

/**
 *
 * @author whuang Problem 11636 - Hello World!
 */
public class Main {

   public static void main(String[] args) {
      int numLines = 0, currLines, numCopies, iter = 0;

      Scanner in = new Scanner(System.in);

      while (true) {
         numLines = in.nextInt();
         if(numLines < 0) break;
         
         iter++;
         currLines = 1;
         numCopies = 0;

         while (currLines < numLines) {
            currLines += currLines;
            numCopies++;
         }

         System.out.println("Case " + iter + ": " + numCopies);

      }
   }
}