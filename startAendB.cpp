#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string returnNextState(string State, string input, vector<string> &States, string &inputAlphabets, vector<vector<string>>  &TransitionTable){
    auto it = find(States.begin(), States.end(), State);
    return TransitionTable[it- States.begin()][inputAlphabets.find(input)];
}


int main(){
    vector<string> States = {"q0", "q1", "q2", "q3"};
    string initState = States[0];
    string deadState = States[3];
    vector<string> finalStates = {States[2]};
    string inputAlphabets = "ab";
    vector<vector<string>> TransitionTable = {
     {States[1], States[3]},
     {States[1], States[2]},
     {States[1], States[2]},
     {States[3], States[3]}
     };

    string CurrentState = initState;
    string InputSequence = "ababababbbbaababba";
    
    
    for(int i = 0; i<InputSequence.length(); i++){
        string currentInput = InputSequence.substr(i,1);
        cout << "\nCurrent State: " << CurrentState << " - Current Input: " << currentInput << " ";
        CurrentState = returnNextState(CurrentState, currentInput, States, inputAlphabets, TransitionTable);
        cout << "Next State: " << CurrentState << " ";
        if(CurrentState == deadState){
            cout << " (Dead State)";
            break;
        }
        int cnt = count(finalStates.begin(), finalStates.end(), CurrentState);
        if(cnt>0){
            cout << " (Accepting State)";
        }
    }
    cout << "\nEnding State: " << CurrentState << endl;
    int cnt = count(finalStates.begin(), finalStates.end(), CurrentState);
        if(cnt>0){
            cout << "(Accepting State)";
        }
        else{
            cout << "(Not Accepting State)";
        }
    
    return 0;
}