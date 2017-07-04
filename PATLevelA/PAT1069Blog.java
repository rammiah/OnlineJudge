import java.util.*;

public class PAT1069Blog {
    static void Award(String[] peoples, int start, int step){
        Set<String>awarded = new HashSet<String >();
        for (int i = start; i <= peoples.length;){
            if (awarded.contains(peoples[i - 1])){
                i += 1;
            }
            else {
                System.out.println(peoples[i - 1]);
                awarded.add(peoples[i - 1]);
                i += step;
            }
        }
        if (awarded.isEmpty()){
            System.out.println("Keep going...");
        }
    }

    public static void main(String[]args){
        Scanner in = new Scanner(System.in);
        int sum = 0;
        int start = 0;
        int step = 0;
        sum = in.nextInt();
        step = in.nextInt();
        start = in.nextInt();
        in.nextLine();
        String[] peoples = new String[sum];

        for (int i = 0; i < sum; i++) {
            peoples[i] = in.nextLine();
        }

        Award(peoples, start,step);

        in.close();
    }
}
