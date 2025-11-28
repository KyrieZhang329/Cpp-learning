#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

string process(const string& s) 
{
    stack<char> stk;
    for (char c : s) 
    {
        if (c == '<') 
        {
            if (!stk.empty()) 
                stk.pop();
        } 
        else 
            stk.push(c);
    }
    string result = "";
    while (!stk.empty()) 
    {
        result = stk.top() + result;
        stk.pop();
    }
    return result;
}

int main()
{
    vector<string> standard;
    string line;
    while (getline(cin, line) && line != "EOF") 
        standard.push_back(line);
    vector<string> input;
    while (getline(cin, line) && line != "EOF") 
        input.push_back(line);
    int time;
    cin >> time;
    int correctCount = 0;
    int maxLines = min(standard.size(), input.size());
    
    for (int i = 0; i < maxLines; i++) 
    {
        string processedStandard = process(standard[i]);
        string processedInput = process(input[i]);
        int len = min(processedStandard.size(), processedInput.size());
        for (int j = 0; j < len; j++) 
        {
            if (processedStandard[j] == processedInput[j]) 
                correctCount++;
        }
    }
    double kpm = (double)correctCount * 60.0 / (double)time;
    int result = (int)(kpm + 0.5); 
    cout << result;
    return 0;
}