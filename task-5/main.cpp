#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool containsAlpha(const string& s) {
    for (char c : s) {
        if (isalpha(c)) return true;
    }
    return false;
}

string toLowercase(const string& src) {
    string dst = src;
    for (char& c : dst)
        c = tolower(c);
    return dst;
}

string toUppercase(const string& src) {
    string dst = src;
    for (char& c : dst)
        c = toupper(c);
    return dst;
}

string toSentenceCase(const string& src) {
    string dst = src;
    bool start = true;

    for (int i = 0; i < (int)dst.length(); i++) {
        char c = dst[i];

        if (start && isalnum(c)) {
            dst[i] = toupper(c);
            start = false;
        }
        else {
            dst[i] = tolower(c);
        }

        if (c == '.' || c == '!' || c == '?')
            start = true;
    }

    return dst;
}

string toAlternatingCase(const string& src) {
    string dst = src;
    int toggle = 0;

    for (int i = 0; i < (int)dst.length(); i++) {
        char c = dst[i];

        if (isalpha(c)) {
            if (toggle == 0)
                dst[i] = tolower(c);
            else
                dst[i] = toupper(c);

            toggle = !toggle;
        }
    }

    return dst;
}

int main() {
    string input;

    cout << "Enter some text: ";
    getline(cin, input);

    if (!containsAlpha(input)) {
        cout << "[!] ERROR: Can't run text casing, there is no alphabetical characters in input string.\n";
        return 0;
    }

    cout << "Uppercase => " << toUppercase(input) << "\n";
    cout << "Lowercase => " << toLowercase(input) << "\n";
    cout << "Sentence casing => " << toSentenceCase(input) << "\n";
    cout << "Alternate casing => " << toAlternatingCase(input) << "\n";

    return 0;
}