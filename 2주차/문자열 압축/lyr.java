import java.util.ArrayList;
import java.util.Collections;

class Solution1 {
    public static void main(String[] args) {
        solution("xababcdcdababcdcd");
    }

    public static int solution(String s) {
        int answer = 0;
        ArrayList<Integer> arrayList = new ArrayList<>();

        for (int i = 1; i <= s.length(); i++) {
            String str = "";
            String sub = "";
            int num = 1;
            String result = "";

            for (int j = 0; j < s.length(); j += i) {

                if (j + i > s.length()) {
                    sub = s.substring(j);
                } else {
                    sub = s.substring(j, j + i);
                }

                if (str.equals(sub)) {
                    num += 1;
                } else {
                    if (num > 1) {
                        result += num + str;
                        str = sub;
                        num = 1;
                    } else if (j == 0) {
                        str = sub;
                    } else {
                        result += str;
                        str = sub;
                    }

                }

            }
            if (num > 1) {
                result += num + str;
            } else {
                result += str;
            }
            System.out.println(result);
            arrayList.add(result.length());

        }
        answer = Collections.min(arrayList);
        return answer;
    }


}