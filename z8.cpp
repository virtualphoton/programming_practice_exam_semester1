#include <iostream>
#include <string>

using namespace std;
void recur_deeper(string output, int depth, int max_depth) {
    //border cases
    {
        if (depth == 0)
            output = "{";
        if (depth == max_depth) {
            output += "}";
            cout << output << '\n';
            return;
        }
    }
    //include current element
    {
        output = output.append(to_string(depth));
        cout << output;
    }
}

int main() {
    int n;
    cin >> n;
    recur_deeper("", 0, 10);
    return 0;
}