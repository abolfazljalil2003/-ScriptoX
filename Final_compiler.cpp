#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <cmath>

using namespace std;

unordered_map<string, int> varStore;
unordered_map<string, size_t> labelStore;

void display(int value) {
    cout << value << endl;
}

int addFunc(int x, int y) { return x + y; }
int multiplyFunc(int x, int y) { return x * y; }
void incrementVar(string var) { varStore[var]++; }
int subtractFunc(int x, int y) { return x - y; }
int divideFunc(int x, int y) {
    if (y == 0) throw runtime_error("Division by zero");
    return x / y;
}
int powerFunc(int x, int y) {
    if (y < 0) throw runtime_error("Negative exponent");
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}
int modFunc(int x, int y) {
    if (y == 0) throw runtime_error("Modulo by zero");
    return x % y;
}
bool isNumeric(const string& s) {
    if (s.empty()) return false;
    size_t start = (s[0] == '-') ? 1 : 0;
    // Reject "-" or strings like "--5"
    if (start == 1 && s.size() == 1) return false;
    for (size_t i = start; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

void gatherLabels(const vector<string>& lines) {
    for (size_t i = 0; i < lines.size(); i++) {
        string line = lines[i];
        stringstream ss(line);
        string token;
        while (ss >> token) {
            if (token[0] == '@') {
                labelStore[token] = i;
                break;
            }
        }
    }
}

int processCommand(const vector<string>& lines, size_t currentLine) {
    string line = lines[currentLine];
    string modifiedCommand = line;

    size_t pos;
    while ((pos = modifiedCommand.find("->")) != string::npos)
        modifiedCommand.replace(pos, 2, " ");
    while ((pos = modifiedCommand.find(',')) != string::npos)
        modifiedCommand.replace(pos, 1, " ");

    stringstream ss(modifiedCommand);
    string token;
    vector<string> tokens;

    while (ss >> token) {
        if (token.back() == ';') token.pop_back();
        tokens.push_back(token);
    }

    if (tokens.empty()) return currentLine + 1;

    try {
        // Skip lines that are label definitions (already processed)
        if (tokens.size() == 1 && tokens[0][0] == '@') {
            return currentLine + 1;
        }

        // Handle unconditional jumps
        if (tokens.size() >= 2 && tokens[1] == "jump") {
            if (labelStore.find(tokens[0]) == labelStore.end()) {
                throw runtime_error("Undefined label: " + tokens[0]);
            }
            return labelStore[tokens[0]];
        }

        // Handle conditional jumps
        if (tokens.size() >= 4 && (
            tokens[3] == "jump_if_equal" ||
            tokens[3] == "jump_if_greater" ||
            tokens[3] == "jump_if_less"
        )) {
            int a, b;
            string operand1 = tokens[1];
            string operand2 = tokens[2];

            a = (operand1[0] == '$') ? varStore[operand1] : stoi(operand1);
            b = (operand2[0] == '$') ? varStore[operand2] : stoi(operand2);

            bool conditionMet = false;
            if (tokens[3] == "jump_if_equal") conditionMet = (a == b);
            else if (tokens[3] == "jump_if_greater") conditionMet = (a > b);
            else if (tokens[3] == "jump_if_less") conditionMet = (a < b);
            if (labelStore.find(tokens[0]) == labelStore.end()) {
                throw runtime_error("Undefined label: " + tokens[0]);
            }
            return conditionMet ? labelStore[tokens[0]] : currentLine + 1;
        }

        // Handle variable assignments and operations
        if (tokens.size() == 2) {
            if (tokens[1] == "print") {
                if (tokens[0][0] == '$') display(varStore[tokens[0]]);
                else if (isNumeric(tokens[0])) display(stoi(tokens[0]));
            } else if (tokens[1] == "increase") {
                incrementVar(tokens[0]);
            } else if (tokens[1][0] == '$') {
                varStore[tokens[1]] = stoi(tokens[0]);
            }
        } else if (tokens.size() == 4) {
            string operation = tokens[2];
            string target = tokens[3];
            int a = (tokens[0][0] == '$') ? varStore[tokens[0]] : stoi(tokens[0]);
            int b = (tokens[1][0] == '$') ? varStore[tokens[1]] : stoi(tokens[1]);

            if (operation == "add") varStore[target] = addFunc(a, b);
            else if (operation == "multiply") varStore[target] = multiplyFunc(a, b);
            else if (operation == "subtract") varStore[target] = subtractFunc(a, b);
            else if (operation == "divide") varStore[target] = divideFunc(a, b);
            else if (operation == "power") varStore[target] = powerFunc(a, b);
            else if (operation == "modulo") varStore[target] = modFunc(a, b);
            else throw runtime_error("Unknown operation: " + operation);
        }

    } catch (const exception& e) {
        cerr << "Error in line " << currentLine + 1 << ": " << e.what() << endl;
    }

    return currentLine + 1;
}

int main() {
    ifstream inputFile("testCase.txt");
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) lines.push_back(line);
    inputFile.close();

    // First pass: collect all labels
    gatherLabels(lines);

    // Second pass: execute code
    for (size_t i = 0; i < lines.size();) {
        i = processCommand(lines, i);
    }

    return 0;
}
