import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author whuang Problem 10370 - Above Average
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int cases, numStudents, sum, numAbove, grade;
        float percentAboveAvg, average;
        ArrayList<Integer> grades = new ArrayList<>();
        Scanner in =  new Scanner(System.in);
        
        cases = in.nextInt();
        for(int i = 0; i < cases; i++){
           grades.clear();
           sum = 0;
           numAbove = 0;
           numStudents = in.nextInt();
           for(int j = 0; j < numStudents; j++){
              grade = in.nextInt();
              grades.add(grade);
              sum += grade;
           }
           average = sum/numStudents;
           for (Integer grade1 : grades) {
              if (grade1 > average) {
                 numAbove++;
              }
           }
           percentAboveAvg = (float)numAbove/numStudents * 100;
           System.out.println(String.format("%.3f",percentAboveAvg)+"%");
        }
    }
}
