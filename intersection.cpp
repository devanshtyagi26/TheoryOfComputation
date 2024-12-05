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
    vector<string> States = {"q0r0", "q1r0", "q2r0", "q0r1", "q1r1", "q2r1"};
    string initState = States[0];
    vector<string> finalStates = {States[5]};
    string inputAlphabets = "ab";
    vector<vector<string>> TransitionTable = {
     {States[1], States[3]},
     {States[2], States[3]},
     {States[2], States[5]},
     {States[1], States[3]},
     {States[2], States[3]},
     {States[2], States[5]}
    };

    string CurrentState = initState;
    string InputSequence = "abaab";
    
    cout << "Intersection(L1^L2) of \nL1: Containing 'aa'\nL2: Ends with 'b'\n";
    
    for(int i = 0; i<InputSequence.length(); i++){
        string currentInput = InputSequence.substr(i,1);
        cout << "\nCurrent State: " << CurrentState << " - Current Input: " << currentInput << " ";
        CurrentState = returnNextState(CurrentState, currentInput, States, inputAlphabets, TransitionTable);
        cout << "Next State: " << CurrentState << " ";
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