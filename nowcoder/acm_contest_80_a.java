import java.util.HashMap;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        int mod = 1000000007;
        Scanner in = new Scanner(System.in);
        HashMap<Character, Integer> charCounts = new HashMap<>();
        for (char i = 'a'; i <= 'z'; i++) {
            charCounts.put(i, 2);
        }
        for (char i = '0'; i <= '9'; i++) {
            charCounts.put(i, 1);
        }
        charCounts.put('i', 4);
        charCounts.put('l', 4);
        charCounts.put('o', 3);
        charCounts.put('0', 3);
        String str = in.nextLine().toLowerCase();

        long result = 1;

        char[] chs = str.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            result *= charCounts.get(chs[i]);
            result %= mod;
        }
        System.out.println(result);

        in.close();
    }
}

