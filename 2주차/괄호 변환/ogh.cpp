#include <string>
#include <vector>

using namespace std;

// 변환 2 와 동시에 3 판단
int get_balanced_strings(string &input) {
    int count = 0;
    bool right = true;
    for(int i = 0;i < input.size();i++) {
        if (input[i] == '(') {
            count++;
        } else {
            count--;
        }
        if (count < 0) {
            // 올바른 문자열인가.
            right = false;
        }
        if (count == 0) {
            // 균형이 잡힌 최소 문자열 찾은 경우
            // 올바른 문자열이면 양수, 아니면 음수 반환
            return (i + 1) * (right ? 1 : -1);
        }
    }
    // 균형 잡힌 문자열이 존재하지 않음. 
    // 이 문제 조건에서는 여기까지 올 수 없음
    return input.size() + 1;
}

// 변환 4-4 
string trim_and_revert(string s) {
    s = s.substr(1, s.size() - 2);
    for(int i =0 ;i < s.size();i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else {
            s[i] = '(';
        }
    }
    return s;
}

// 조건 자체가 균형잡힌 문자열 이므로, 그 외는 제외함. 
string solution(string p) {
    if (p.size() == 0) return "";
    string answer = "";
    int end = get_balanced_strings(p); 
    if (end > 0) {
        // 올바른 문자열인 경우 
        answer = p.substr(0, end) + solution(end == p.size() ? "" : p.substr(end));
    } else {
        // 올바른 문자열이 아닌 경우 
        end *= -1;
        answer = '(' + solution(end == p.size() ? "": p.substr(end)) + ')' + trim_and_revert(p.substr(0, end));
    }
    return answer;
}
