/*

Ananth interested in creating the acronyms for any word.
The definition of acronym is another word with a concatenation of its first letter,
 the number of letters between the first and last letter, and its last letter. 
 
 If a word has only two characters, then it is an acronym of itself.
 
 Examples:
	- Acronym of 'dog' is 'd1g'.
	- Acronym of 'another' is 'a5r'.
	- Acronym of 'ab' is 'ab'.

You are given a list of vocabulary, and another list of words.
Your task is to check is word with the vocabulary and
return "true" if atleast one of the following rules satisfied:
	1. acronym of the word should not match with any of the acronyms of vocabulary
	2. if acronym of the word matches with any of the acronyms of vocabulary
	'the word' and matching words in vocabulary should be same.
Otherwise, return 'false'.

Input Format:
-------------
Line-1: Space separated strings, vocabulary[] 
Line-2: Space separated strings, words[] 

Output Format:
--------------
Print N boolean values, where N = words.length. 


Sample Input-1:
---------------
cool bell cool coir move more mike
cool char move 

Sample Output-1:
----------------
true false false


*/

#include<bits/stdc++.h>
using namespace std;

vector<string> split(string str)
{
    string curr;
    vector<string> words;
    for(char c: str) {
        if(c == ' ') {
            if(curr != "") {
                words.push_back(curr);
                curr = "";
            }
        }
        else {
            curr += c;
        }
    }
    if(curr != "") {
        words.push_back(curr);
    }
    return words;
}

int main()
{
    string s1;
    getline(cin, s1);
    vector<string> vocab = split(s1);
    getline(cin, s1);
    vector<string> words = split(s1);
    
    
    
    
    unordered_map<string, unordered_set<string>> mp;
    
    for(string s: vocab) {
        if(s.length() == 2) {
            mp[s].insert(s);
            continue;
        }
        string ack = s[0] + to_string(s.length()-2) + s.back();
        mp[ack].insert(s);
    }
    
    
    for(string word: words) {
        string ack = "";
        if(word.length() == 2) {
            ack = word;
        }
        else 
            ack = word[0] + to_string(word.length() - 2) + word.back();
            
        if(mp.count(ack) == 0) {
            cout << "true ";
        }
        else if (mp[ack].size() == 1) {
            auto w = mp[ack].begin();
            if(*w == word) {
                cout << "true "; 
            }
            else {
                cout << "false ";
            }
        }
        else {
            cout << "false ";
        }
    }
    cout << endl;
    
    return 0;
}