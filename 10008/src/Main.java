
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

/**
 *
 * @author whuang Problem 10008 - What's Cryptanalysis?
 */
public class Main {

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) {
      int numLines;
      Integer count;
      Character c;
      String str;
      Scanner in = new Scanner(System.in);
      Map<Character, Integer> charMap = new HashMap<>();
      ValueComparator vc = new ValueComparator(charMap);
      SortedMap<Character, Integer> sortedCharMap = new TreeMap<>(vc);

      numLines = in.nextInt();

      while (numLines >= 0) {
         str = in.nextLine();
         for (int i = 0; i < str.length(); i++) {
            c = str.charAt(i);
            if (Character.isLetter(c)) {
               c = Character.toUpperCase(c);
               count = charMap.get(c);
               if (count == null) {
                  charMap.put(c, 1);
               } else {
                  charMap.put(c, ++count);
               }
            }
         }
         numLines--;
      }
      sortedCharMap.putAll(charMap);
      for(Map.Entry<Character,Integer> entry : sortedCharMap.entrySet()) {
         Character key = entry.getKey();
         Integer value = entry.getValue();

         System.out.println(key + " " + value);
      }
   }
}

class ValueComparator implements Comparator<Character> {

   Map<Character, Integer> base;

   public ValueComparator(Map<Character, Integer> base) {
      this.base = base;
   }

   // Note: this comparator imposes orderings that are inconsistent with equals.    
   @Override
   public int compare(Character a, Character b) {
      if (base.get(a) > base.get(b)) {
         return -1;
      } else if (base.get(a).equals(base.get(b))) {
         if (a.compareTo(b) > 0) {
            return 1;
         } else {
            return -1;
         }
      } else {
         return 1;
      }
   }
}
