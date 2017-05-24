/**
 * Created by yaning on 17-5-22.
 */
public class _292NimGame {
    public static boolean canWinNim(int n) {
        return IWin(n);
    }

    static int isGood(int left){
        if (left <= 3){
            return left;
        }
        for (int i = 1; i <= 3; ++i){
            if (canWinNim(left - i)){
                return i;
            }
        }
        return 1;
    }

    static boolean IWin(int left){
        if (left == 0){
            return false;
        }
        else if (left <= 3) {
            return true;
        }

        return !YWin(left - isGood(left));
    }

    static boolean YWin(int left){
        if (left == 0){
            return false;
        }
        else if (left <= 3){
            return true;
        }

        return !IWin(left - isGood(left));
    }


    public static void main(String[] args){
        System.out.println(canWinNim(5));
    }
}
