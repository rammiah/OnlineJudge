package Leetcode;

import java.util.Stack;

/**
 * Created by yaning on 17-6-7.
 */
public class _020ValidParen {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.isValid("{}"));
    }

    static class Solution {
        char[] valid = new char[256];
        Solution() {
            valid['}'] = '{';
            valid[']'] = '[';
            valid[')'] = '(';
        }
        // 这个题使用栈的性质非常适合，赞！！
        public boolean isValid(String s) {
            Stack<Character>list = new Stack<>();
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) != '}' && s.charAt(i) != ']' && s.charAt(i) != ')'){
                    list.push(s.charAt(i));
                } else  {
                    if (!list.isEmpty()) {
                        if (list.pop() != valid[s.charAt(i)]) {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
            }

            return list.isEmpty();
        }
    }
}
