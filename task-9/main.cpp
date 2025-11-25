#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "Vector2.h"

using namespace std;
constexpr float PI = 3.14159265358979323846f;

bool ParseVector(const string& input, Vector2& out)
{
    string s = input;

    if (s.size() < 5) return false;
    if (s.front() != '[' || s.back() != ']') return false;

    s = s.substr(1, s.size() - 2);

    float x, y;
    char comma;

    stringstream ss(s);
    if (!(ss >> x)) return false;
    if (!(ss >> comma) || comma != ',') return false;
    if (!(ss >> y)) return false;

    out = Vector2(x, y);
    return true;
}

int main(int argc, char* argv[])
{
    while (true)
    {
        cout << ">> What mode would you like to use?\n";
        cout << ">> - 1. Distance between two points.\n";
        cout << ">> - 2. Check if one point is within view cone of another.\n";
        cout << "- Enter your choice : ";

        int choice;
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice != 1 && choice != 2)
        {
            cout << "[!] ERROR: Invalid choice.\n";
            continue;
        }

        if (choice == 1)
        {
            cout << ">> Mode 1 selected.\n";

            Vector2 a, b;
            string input;

            while (true)
            {
                cout << "- Enter vector #1: ";
                getline(cin, input);
                if (ParseVector(input, a)) break;
                cout << "[!] ERROR: Invalid format, please use [x, y].\n";
            }

            while (true)
            {
                cout << "- Enter vector #2: ";
                getline(cin, input);
                if (ParseVector(input, b)) break;
                cout << "[!] ERROR: Invalid format, please use [x, y].\n";
            }

            float d = Vector2::Distance(a, b);
            cout << ">> Distance between [" << a.x << ", " << a.y << "] and ["
                << b.x << ", " << b.y << "] is " << d << ".\n\n";
        }

        else if (choice == 2)
        {
            cout << ">> Mode 2 selected.\n";

            Vector2 p1, dir, p2;
            string input;

            while (true)
            {
                cout << "- Enter player #1 pos : ";
                getline(cin, input);
                if (ParseVector(input, p1)) break;
                cout << "[!] ERROR: Invalid format.\n";
            }

            while (true)
            {
                cout << "- Enter player #1's view direction : ";
                getline(cin, input);
                if (ParseVector(input, dir)) break;
                cout << "[!] ERROR: Invalid format.\n";
            }

            dir.Normalize();

            while (true)
            {
                cout << "- Enter player #2 pos : ";
                getline(cin, input);
                if (ParseVector(input, p2)) break;
                cout << "[!] ERROR: Invalid format.\n";
            }

            Vector2 toTarget = (p2 - p1).Normalized();

            float dot = Vector2::Dot(dir, toTarget);
            float cutoff = std::cos(45.0f * PI / 180.0f);

            if (dot >= cutoff)
                cout << ">> Player 2 is within Player 1's FoV.\n\n";
            else
                cout << ">> Player 2 is NOT within Player 1's FoV.\n\n";
        }
    }

    return 0;
}
