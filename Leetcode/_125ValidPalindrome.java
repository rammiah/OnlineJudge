/**
 * Created by yaning on 17-5-21.
 */
public class _125ValidPalindrome {
    public static boolean isPalindrome(String s) {
        s = filter(s);
        StringBuffer t = new StringBuffer(s);
        String str = t.reverse().toString();
        return s.equals(str);
    }

    public static String filter(String str){
        StringBuilder s = new StringBuilder();
        str = str.toLowerCase();
        for (int i = 0; i < str.length(); ++i){
            if (Character.isLetterOrDigit(str.charAt(i))){
                s.append(str.charAt(i));
            }
        }
        return s.toString();
    }


    public static void main(String[] args){
        String str = "A man, a plan, a canal: Panama";

        System.out.println(isPalindrome(str));
    }
}
