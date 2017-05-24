/**
 * Created by yaning on 17-5-23.
 */
public class _8Atoi {
    public static int myAtoi(String str) {
        if (str == null || str.isEmpty()){
            return 0;
        }
        str = str.replace(" ", "");
        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i))){
                res = str.charAt(i) - '0' + res * 10;
            }
            else if (str.charAt(i) == '+' && i == 0){
                continue;
            }
            else if (str.charAt(i) == '-' && i == 0){
                continue;
            }
            else{
                return 0;
            }
        }

        if (str.charAt(0) == '-'){
            return -res;
        }
        return res;
    }

    public static void main(String[] args){
        System.out.println(myAtoi("123"));
    }
}
