import java.util.ArrayList;
import java.util.List;

// boring problem
public class _412FizzBuzz {

    private static final String THREE = "Fizz", FIVE = "Buzz";

    public List<String> fizzBuzz(int n) {
        List<String> result = new ArrayList<>();
        String s = "";
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                if (i % 5 == 0) {
                    result.add(THREE + FIVE);
                } else {
                    result.add(THREE);
                }
            } else if (i % 5 == 0) {
                result.add(FIVE);
            } else {
                result.add("" + i);
            }
        }
        return result;
    }

    public static void main(String[] args) {

    }
}
