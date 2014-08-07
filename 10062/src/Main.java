import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

/**
 *
 * @author whuang Problem 10062 - Tell me the frequencies!
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String line;
        Integer freq, c;
        boolean first =  true;
        Scanner in = new Scanner(System.in);
        Map<Integer, Integer> freqMap = new HashMap<>();
        ValueComparator vc = new ValueComparator(freqMap);
        SortedMap<Integer, Integer> sortedFreqMap = new TreeMap<>(vc);
        
        while(in.hasNext()){
           freqMap.clear();
           sortedFreqMap.clear();
           line = in.nextLine();
           if(first){
              first = false;
           }else{
              System.out.println("");
           }
           for(int i = 0; i < line.length(); i++){
              c = (int)line.charAt(i);
              freq = freqMap.get(c);
              if(freq == null){
                 freqMap.put(c, 1);
              }else{
                 freqMap.put(c, ++freq);
              }
           }
           sortedFreqMap.putAll(freqMap);
           for(Map.Entry<Integer,Integer> entry: sortedFreqMap.entrySet()){
              System.out.println(entry.getKey() + " " + entry.getValue());
           }
        }      
    }
}
class ValueComparator implements Comparator<Integer> {

   Map<Integer, Integer> base;

   public ValueComparator(Map<Integer, Integer> base) {
      this.base = base;
   }

   // Note: this comparator imposes orderings that are inconsistent with equals.    
   @Override
   public int compare(Integer a, Integer b) {
      if (base.get(a) < base.get(b)) {
         return -1;
      }
      else if(base.get(a).equals(base.get(b))) {
         if(a < b){
            return 1;
         }
         else{
            return -1;
         }
      }
      else {
         return 1;
      }
   }
}