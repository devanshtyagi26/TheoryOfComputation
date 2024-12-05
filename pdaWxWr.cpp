#include <iostream>
#include <string>
#include <stack>

using namespace std;

class PDA {
private:
    stack<char> st;

    void pushToStack(char c) {
        st.push(c);
        cout << "Pushed '" << c << "' to the stack\n";
    }

    void popFromStack() {
        if (!st.empty()) {
            char popped = st.top();
            st.pop();  
            cout << "Popped '" << popped << "' from the stack\n";
        }
    }

    void processString(string &s, int index, bool isFirstPhase) {
        if (index == s.length()) {
            if (!isFirstPhase && st.empty()) {
                cout << "\nString Accepted\n";
            } else if (isFirstPhase) {
                cout << "First phase completed. Now, waiting for X.\n";
            } else {
                cout << "\nString Rejected (Mismatch or Stack is not empty)\n";
            }
            return;
        }

        char currentChar = s[index];

        if (isFirstPhase) {
            if (currentChar == 'X') {
                processString(s, index + 1, false);
            } else {
                pushToStack(currentChar);
                processString(s, index + 1, true);
            }
        } else {
            if (st.empty()) {
                cout << "\nString Rejected (More characters in w^r than w)\n";
                return;
            }

            char topChar = st.top();
            if (topChar == currentChar) {
                popFromStack();
                processString(s, index + 1, false);
            } else {
                cout << "\nString Rejected (Mismatch between w and w^r)\n";
                return;
            }
        }
    }

public:
    void process(string s) {
        while (!st.empty()) {
            st.pop();  
        }

        cout << "Checking string: " << s << endl;
        processString(s, 0, true);  
    }
};

int main() {
    string s;
    PDA pda;

    cout << "Enter a string of the form wXw^r (e.g., abXba): ";
    cin >> s;

    pda.process(s);

    return 0;
}


