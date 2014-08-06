import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
/**
 *
 * @author whuang Problem 1339 - Ancient Cipher
 */
public class Main {

   /**
    * @param args the command line arguments
    */
   static Map<Character, Integer> msgHMap = new HashMap<>();
   static Map<Character, Integer> cipherHMap = new HashMap<>();
   
   public static void main(String[] args) {
      Boolean decodable;

      String msg, code;
      Scanner in = new Scanner(System.in);

      while (in.hasNext()) {
         msg = in.next();
         code = in.next();

         decodable = canBeDecoded(msg, code);
         if(decodable == true){
            System.out.println("YES");
         }else{
            System.out.println("NO");
         }
         System.out.println(in.hasNext());
      }
     
   }

   public static Boolean canBeDecoded(String msg, String code) {
      Integer countM, countC;
      Character charM, charC;
      if (msg.length() != code.length()) {
         return false;
      }
      msgHMap.clear();
      cipherHMap.clear();
      for (int i = 0; i < msg.length(); i++) {
         charM = msg.charAt(i);
         countM = msgHMap.get(charM);
         if (null == countM) {
            msgHMap.put(charM, 1);
         } else {
            msgHMap.put(charM, countM++);
         }
         
         charC = code.charAt(i);
         countC = cipherHMap.get(charC);
         if (null == countC) {
            cipherHMap.put(charC, 1);
         } else {
            cipherHMap.put(charC, countC++);
         }
      }
      if(msgHMap.size() != cipherHMap.size()){
         return false;
      }else{
         Collection<Integer> arr = msgHMap.values();
         Collection<Integer> arr2 = cipherHMap.values();
         for(Integer i : arr){
            if(arr2.contains(i)){
               arr2.remove(i);
            }else{
               return false;
            }
         }
         return arr2.isEmpty();
      }
   }
}
