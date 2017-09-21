import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigDecimal number;;
        int e = 0;
        while (in.hasNext()) {
            number = in.nextBigDecimal();
            e = in.nextInt();
            number = number.pow(e);
            char[] num = number.toPlainString().toCharArray(); // 直接toString会有科学计数法
            int start = 0, end = num.length - 1;
            while (num[start] == '0') ++start;
            while (num[end] == '0') --end;
            if (num[end] == '.') --end;
            for (int i = start; i <= end; i++) {
                System.out.print(num[i]);
            }
            System.out.println();
        }
        System.exit(0);
    }
}

