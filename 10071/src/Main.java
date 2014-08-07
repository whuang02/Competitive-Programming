import java.util.Scanner;

/**
 *
 * @author whuang Problem 10071 - Back to High School Physics
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int velocity, time;
        
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
           velocity = in.nextInt();
           time = in.nextInt();
           System.out.println(velocity*time*2);
        }
    }

}
