#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    string sub = "";
    int count = 0;
    int zipped_len = 0;
    
    for(int i = 1 ;i < s.size();i++) {
        sub = "";
        count = 0;
        zipped_len = 0;
        for(int j = 0 ;j < s.size();j += i) {
            string temp = s.substr(j, i);
            if (sub == temp) {
                count++;
            } else {
                if (sub.size()) {
                    zipped_len += i;
                    if (count > 1) {
                        zipped_len += to_string(count).size();
                    }
                }
                sub = temp;
                count = 1;
            }
        }
        zipped_len += sub.size();
        if (count > 1) {
            zipped_len += to_string(count).size();
        }
        answer = min(answer, zipped_len);
    }
    return answer;
}
