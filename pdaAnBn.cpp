#include <iostream>
#include <string>
#include <stack>

using namespace std;

class PDA {
private:
    stack<char> st;

    void pushToStack() {
        st.push('a');  
        cout << "Pushed 'a' to the stack\n";
    }

    void popFromStack() {
        if (!st.empty()) {
            st.pop();  
            cout << "Popped 'a' from the stack\n";
        }
    }

    void checkString(string &s, int index) {
        if (index == s.length()) {
            if (st.empty()) {
                cout << "\nString Accepted\n";
            } else {
                cout << "\nString Rejected (Stack not empty)\n";
            }
            return;
        }

        char ch = s[index];

        if (ch == 'a') {
            pushToStack();  
            checkString(s, index + 1);
        }
        else if (ch == 'b') {
            if (st.empty()) {
                cout << "\nString Rejected (No 'a' for 'b')\n";
                return;
            } else {
                popFromStack();  
                checkString(s, index + 1);
            }
        } else {
            cout << "\nString Rejected (Invalid character)\n";
            return;
        }
    }

public:
    void process(string s) {
        while (!st.empty()) {
            st.pop(); 
        }

        cout << "Checking string: " << s << endl;
        checkString(s, 0);
    }
};

int main() {
    string s;
    PDA pda;

    cout << "Enter a string of 'a' and 'b': ";
    cin >> s;

    pda.process(s);

    return 0;
}
