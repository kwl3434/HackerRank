#include <iostream>
#include<algorithm>
#include<fstream>
#include<string>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int result = 0;
    for (int i = 1; i < s.size(); i++) { //개수
        for (int j = 0; j < s.size() - 1; j++) { //기준점
            if (s.size() - j <= i) {
                continue;
            }
            for (int k = j + 1; k < s.size(); k++) { //도는아이
                if (s.size() - k < i) {
                    break;
                }
                string a = s.substr(j, i);
                string b = s.substr(k, i);
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                if (!a.compare(b)) {
                    result++;
                }
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout("TEST.txt");

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
