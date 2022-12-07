#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <map>
#include <set>
using namespace std;

int getNumber(char);
int main()
{
    fstream inFil;
    inFil.open("/Users/ndi01/Downloads/assignment_AdventOfCode3.txt");

    static int count_line = 0; // if its a multiple of 3, run some code

    static int sum = 0;
    int numSets = 100;
    std::string str, str2;
    std::vector<std::string> temp;
   // static std::vector<std::vector<std::string>> strVec;
    if (inFil.is_open())
    {
        
        for (int i = 0; i < 3*numSets; i++)
        {
            std::getline(inFil, str);
            temp.push_back(str);
        }
    }

    std::vector<std::string>::iterator it;
    for (int i = 0; i < 3*numSets; i+=3)
    {
        
        it = temp.begin();
        advance(it, i);
        std::string string1 = *it;
        
        advance(it, 1);
        std::string string2 = *it; 
        advance(it, 1);
        std::string string3 = *it; 
        
    
        std::set<char> set1, set2, set3;
        std::set<char>::iterator itr1, itr2, itr3, itr1_find, itr2_find, itr3_find;

        // std::vector<std::vector<char>> commonLetters;

        for (int j = 0; j < string1.length(); j++)
        {
            set1.insert(string1[j]); // remove repeat occurrences
        }
        for (int j = 0; j < string2.length(); j++)
        {
            set2.insert(string2[j]); // remove repeat occurrences
        }
        for (int j = 0; j < string3.length(); j++)
        {
            set3.insert(string3[j]); // remove repeat occurrences
        }

        std::vector<char> common12, common23, common13;

        for (itr1 = set1.begin(); itr1 != set1.end(); ++itr1)
        {
            char alfabet1 = *itr1;

            itr1_find = set2.find(alfabet1);
            if (itr1_find != set2.end())
                {common12.push_back(*itr1_find);
                //cout << "Alfabets Line 1 & 2 :  " << *itr1_find << endl;
                }
        }

        cout << "\n";
        for (itr2 = set2.begin(); itr2 != set2.end(); ++itr2)
        {
            char alfabet2 = *itr2;
            itr2_find = set3.find(alfabet2);
            if (itr2_find != set3.end())
                common23.push_back(*itr2_find);{
               // cout << "Alfabets Line 2 & 3 :  " << *itr2_find << endl;
                 }
        }
        cout << "\n";
        for (itr3 = set3.begin(); itr3 != set3.end(); ++itr3)
        {
            char alfabet3 = *itr3;
            itr3_find = set1.find(alfabet3);
            if (itr3_find != set1.end()){
                common13.push_back(*itr3_find);
               // cout << "Alfabets Line 1 & 3 :  " << *itr3_find << endl;
                }
        }

        for (std::vector<char>::iterator ptr1 = common12.begin(); ptr1 != common12.end(); ++ptr1)
        {
            std::vector<char>::iterator ptr2 = std::find(common23.begin(), common23.end(), *ptr1);
            if (ptr2 != common23.end())
            {
                
                cout << "Common letter is : " << *ptr2 << endl;
                cout << "Value is : " << getNumber(*ptr2) << endl; 
                sum+= getNumber(*ptr2);
                cout << "Running sum: " <<  sum << endl;
            }
        }
    }
    cout << "SUM:  " << sum << endl;
}


    int getNumber(char val)
    {
        std::map<char, int> mapObject_u, mapObject_l;

        for (int i = 1; i < 27; i++)
        {
            mapObject_u.insert(pair<char, int>('A' + i - 1, 27 + i - 1));
            mapObject_l.insert(pair<char, int>('a' + i - 1, i));
        }
        std::map<char, int>::iterator itr_l, itr_u;
        bool upper, lower;
        if (int(val) >= 97 && int(val) <= 122)
        {
            lower = true;
        }
        else
        {
            upper = true;
        }
        if (lower)
        {
            itr_l = mapObject_l.find(val);
            return itr_l->second;
        }
        else
        {
            return mapObject_u.find(val)->second;
        }
    }
    