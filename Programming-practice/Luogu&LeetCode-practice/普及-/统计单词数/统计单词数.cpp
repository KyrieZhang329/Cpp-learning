#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
    string target;
    cin >> target;
    string target_lower = target;
    transform(target_lower.begin(), target_lower.end(), target_lower.begin(), [](unsigned char c) { return tolower(c); });
    cin.ignore();
    string article;
    getline(cin, article);
    
    int count = 0;          
    int first_pos = -1;     
    int n = article.size();
    int i = 0;
    
    while (i < n) 
    {
        while (i < n && article[i] == ' ') 
            i++;
        if (i >= n) break;  
        int start = i;     
        while (i < n && article[i] != ' ') 
            i++;
        string word = article.substr(start, i - start);
        string word_lower = word;
        transform(word_lower.begin(), word_lower.end(), word_lower.begin(), [](unsigned char c) { return tolower(c); });
        
        if (word_lower == target_lower)
        {
            count++;
            if (first_pos == -1) 
                first_pos = start;
        }
    }
    
    if (first_pos == -1) 
        cout << -1 << endl;
    else 
        cout << count << " " << first_pos << endl;
    return 0;
}