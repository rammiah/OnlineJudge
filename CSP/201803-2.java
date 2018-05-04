import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int ballCount, lineLength, time;
        ballCount = in.nextInt();
        lineLength = in.nextInt();
        time = in.nextInt();
        int[] ballIndexes = new int[ballCount];
        int[] ballDirections = new int[ballCount];
        for (int i = 0; i < ballCount; i++) {
            ballIndexes[i] = in.nextInt();
        }
        while (time-- > 0) {
            for (int i = 0; i < ballCount; i++) {
                if (ballDirections[i] == 0) {
                    if (ballIndexes[i] == lineLength) {
                        ballDirections[i] = 1;
                        --ballIndexes[i];
                    } else {
                        ++ballIndexes[i];
                    }
                } else {
                    if (ballIndexes[i] == 0) {
                        ballDirections[i] = 0;
                        ++ballIndexes[i];
                    } else {
                        --ballIndexes[i];
                    }
                }
            }

            for (int i = 0; i < ballCount; i++) {
                for (int j = i + 1; j < ballCount; j++) {
                    if (j != i) {
                        if (ballIndexes[i] == ballIndexes[j]) {
                            ballDirections[i] = 1 - ballDirections[i];
                            ballDirections[j] = 1 - ballDirections[j];
                        }
                    }
                }
            }
        }

        for (int i = 0; i < ballCount; i++) {
            System.out.print(ballIndexes[i] + " ");
        }
    }
}
