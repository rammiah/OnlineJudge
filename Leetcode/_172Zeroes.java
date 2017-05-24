import java.util.Scanner;

/**
 * Created by yaning on 17-5-21.
 */
public class _172Zeroes {
    public static int trailingZeroes(int n) {
        int result = 0;
        while (n > 0){
            n /= 5;
            result += n;
        }
        return result;
    }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(trailingZeroes(n));
        in.close();
    }
}
