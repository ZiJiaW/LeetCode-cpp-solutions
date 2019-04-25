#include "all.h"
using namespace std;
/**
return "Possible" if initial can change into target, otherwise return "Impossible";
change methods:
    1. append an "A" to initial;
    2. reverse initial and append a "B" to it;
suppose:
    target is longer than initial and they all consist of character 'A' and 'B';
*/
class ABBA {
public:
    string canObtain(string initial, string target) {
        bool reversed = false;
        int start = 0, end = target.length() - 1;
        while (end - start + 1 != initial.length()) {
            char endChar = reversed ? target[start++] : target[end--];
            if (endChar == 'B') reversed = !reversed;
        }
        for (int i = 0; i < initial.length(); ++i) {
            if (reversed && initial[i] != target[end--] || !reversed && initial[i] != target[start++]) return "Impossible";
        }
        return "Possible";
    }
};
//int main()
//{
//    string a("BBAB"), b("ABABABABB");
//    cout << ABBA().canObtain(a, b) << endl;
//    return 0;
//}