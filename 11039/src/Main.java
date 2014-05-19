import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;

/**
 *
 * @author whuang Problem 11039 - Building Designing
 */
public class Main {

   public static void main(String[] args) {
      int numCases, curCase = 0, numFloors, input, maxB = 0, maxR = 0;
      List<Integer> redFloors = new ArrayList<>();
      List<Integer> blueFloors = new ArrayList<>();
      Scanner in = new Scanner(System.in);
      numCases = in.nextInt();

      class lessThanComparator implements Comparator<Integer> {

         @Override
         public int compare(Integer left, Integer right) {
            return left.compareTo(right);
         }
      }

      class greaterThanComparator implements Comparator<Integer> {

         @Override
         public int compare(Integer left, Integer right) {
            return -1 * left.compareTo(right);
         }
      }

      while (curCase < numCases) {
         redFloors.clear();
         blueFloors.clear();
         numFloors = in.nextInt();

         for (int i = 0; i < numFloors; i++) {
            input = in.nextInt();
            if (input > 0) {
               blueFloors.add(input);
            } else {
               redFloors.add(input);
            }
         }
         redFloors.sort(new lessThanComparator());
         blueFloors.sort(new greaterThanComparator());
         maxB = maxFloorBuilding(redFloors, blueFloors, false);
         maxR = maxFloorBuilding(redFloors, blueFloors, true);
         if (maxB < maxR) {
            System.out.println(maxR);
         } else {
            System.out.println(maxB);
         }
         curCase++;
      }
   }

   //ArrayLists passed in must be already sorted.
   public static int maxFloorBuilding(List<Integer> redFloors, List<Integer> blueFloors, boolean isRedFl) {
      int maxFloor = 0, currFloorSize = Integer.MAX_VALUE, testedFloor;
      Iterator redIter = redFloors.iterator(), blueIter = blueFloors.iterator();
      boolean end = false, found = false;
      while (end == false) {
         if (isRedFl == true) {
            while (redIter.hasNext()) {
               testedFloor = (Integer) redIter.next();
               if (Math.abs(testedFloor) < currFloorSize) {
                  currFloorSize = Math.abs(testedFloor);
                  maxFloor++;
                  found = true;
                  break;
               }
            }
            if (found == false) {
               end = true;
            }
         } else {
            while (blueIter.hasNext()) {
               testedFloor = (Integer) blueIter.next();
               if (Math.abs(testedFloor) < currFloorSize) {
                  currFloorSize = Math.abs(testedFloor);
                  maxFloor++;
                  found = true;
                  break;
               }
            }
            if (found == false) {
               end = true;
            }
         }
         isRedFl = !isRedFl;
         found = false;
      }
      return maxFloor;
   }
}
