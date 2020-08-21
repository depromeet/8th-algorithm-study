public class Solution2 {
    public static void main(String[] args) {
        System.out.println(solution("()))((()"));
    }

    public static String solution(String p) {
        String answer = "";
        if (p.isEmpty()) return p;

        int idx = split(p);
        String u = p.substring(0, idx);
        String v = p.substring(idx);

        if (check(u)) {
            return u + solution(v);
        } else {
            String temp = '(' + solution(v) + ')';
            u = u.substring(1, u.length()-1);

            System.out.println(temp);
            for(int i = 0; i < u.length(); i++){
                if(u.charAt(i) == '(') answer += ')';
                else if(u.charAt(i) == ')') answer += '(';
            }

            return temp + answer;
        }

    }

    static int split(String p) {
        int idx = 0;
        int i;
        for (i = 0; i < p.length(); i++) {
            if (p.charAt(i) == '(') {
                idx++;
            } else if (p.charAt(i) == ')') {
                idx--;
            }
            if (idx == 0) return i + 1;
        }
        return i;
    }

    static boolean check(String str) {
        int right = 0;
        int i;
        for (i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                right++;
            } else if (str.charAt(i) == ')') {
                right--;
            }
            if (right < 0) return false;
        }
        return true;
    }
}
