// CellAuto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Automata {
private:
    int compareThree(int zero, int one, int two);
    vector<int> binaryRule;
public:
    vector<int> Rule(int decimal, int size);
    vector<int> NextState(vector<int> current, int size);
};

vector<int> Automata::Rule(int decimal, int size) {
    // Convert the rule number to a binary string
    vector<int> bckwrds;
    vector<int> starterStr;
    int OneOrZero;

    for (int i = 0; i < size; i++) {
        if (i != (size / 2 - 1)) {
            starterStr.push_back(0);
        }
        else {
            starterStr.push_back(1);
        }
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        bckwrds.push_back(decimal % 2);
        decimal = decimal / 2;
    }

    for (int i = 8; i > -1; i--) {
        binaryRule.push_back(bckwrds.at(i));
    }

    for (int i = 0; i < 8; i++)
        cout << binaryRule.at(i);
    cout << endl;

    return starterStr;
}

vector<int> Automata::NextState(vector<int> current, int size) {
    vector<int> newState;

    for (int i = 0; i < size; i++) {
        if ((i != 0) && (i != size - 1)) {
            newState.push_back(compareThree(current.at(i - 1), current.at(i), current.at(i + 1)));
        }
        else if (i == 0) {
            newState.push_back(compareThree(current.at(size - 1), current.at(i), current.at(i + 1)));
        }
        else {
            newState.push_back(compareThree(current.at(i - 1), current.at(i), current.at(0)));
        }
    }

    return newState;
}

int Automata::compareThree(int two, int one, int zero) {
    int octalNum;
    int newBinaryOut;

    octalNum = 1 * zero + 2 * one + 2 * 2 * two;

    return binaryRule.at(7 - octalNum);
    
    /*switch (octalNum)
    {
    case 0:
        return binaryRule.at(7);
        ;
    case 1:
        return binaryRule.at(6);
        ;
    case 2:
        return binaryRule.at(5);
        ;
    case 3:
        return binaryRule.at(4);
        ;
    case 4:
        return binaryRule.at(3);
        ;
    case 5:
        return binaryRule.at(2);
        ;
    case 6:
        return binaryRule.at(1);
        ;
    case 7:
        return binaryRule.at(0);
        ;
    }
    */
    return 0;
}

int main()
{
    Automata x;
    int size, state, rule, iterate;
    cout << "Automata width: ";
    cin >> size;
    cout << "Rule: ";
    cin >> rule;
    cout << "Iterations: ";
    cin >> iterate;

    vector<int> current = x.Rule(rule, size);

    for (int i = 0; i < iterate; i++) {
        for (int j = 0; j < size; j++) {
            if (current.at(j) == 1) {
                cout << "X";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
        current = x.NextState(current, size);
    }
    
    system("pause>0");
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
