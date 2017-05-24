/**
 * Created by yaning on 17-5-21.
 */
public class Leet166CalcuRecurringDecimal {
    public class Solution {
        public String fractionToDecimal(int numerator, int denominator) {
            String result = "";
            result += String.valueOf(numerator / denominator);
            result += ".";

            return result;
        }
    }
}
