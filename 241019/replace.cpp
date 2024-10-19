#include <iostream>
#include <string>

std::string replace(const std::string& s, const std::string& t, const std::string& v) {
    std::string result = s;
    size_t pos = 0;

    // 查找t在s中的位置
    while ((pos = result.find(t, pos)) != std::string::npos) {
        // 替换t为v
        result.replace(pos, t.length(), v);
        pos += v.length(); // 更新位置
    }

    return result;
}

int main() {
    std::string s = "aabbabcbaabaaacbab";
    std::string t = "bab";
    std::string v = "abdc";

    std::string result = replace(s, t, v);
    std::cout << "替换后的字符串: " << result << std::endl;

    // 暂停
    std::cin.get();

    return 0;
}
