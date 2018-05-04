import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int sum = 0;
        int num, oldScore = 0;
        int cnt = 0;
        while ((num = in.nextInt()) != 0) {
            if (num == 1) {
                oldScore = 1;
                sum += 1;
            } else if(num == 2) {
                if (cnt == 0 || oldScore == 1) {
                    oldScore = 2;
                    sum += 2;
                } else {
                    oldScore += 2;
                    sum += oldScore;
                }
            }
            cnt++;
        }
        System.out.println(sum);
    }
}
