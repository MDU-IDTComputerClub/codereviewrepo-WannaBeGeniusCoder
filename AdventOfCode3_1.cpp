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
    static int c = 0;

    // char *alpha_l[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // char *alpha_u[] = {'A', 'B', 'C', ' D ', ' E ', ' F ', ' G ', ' H ', ' I ', ' J ', ' K ', ' L', ' M ', ' N ', ' O ', ' P ', ' Q ', ' R ', ' S ', ' T ', ' U', ' V ', ' W ', ' X ', ' Y ', ' Z'};

    static int sum = 0;
    if (inFil.is_open())
    {
        
        std::vector<std::string> strVec;
        std::string str;

        while (std::getline(inFil, str))
        {
            strVec.push_back(str);
            std::string half = str.substr(0, str.length() / 2);

            std::string otherHalf = str.substr(str.length() / 2);
           // cout << otherHalf << endl;
            // cout << half << endl;

            std::set<char> set1, set2;
            for (int j = 0; j < half.length(); j++)
            {
                set1.insert(half[j]);      // remove repeat occurrences
                set2.insert(otherHalf[j]); // remove repeat occurrences
            }

            for (int i = 0; i < half.length(); ++i)
            {
                char letter = half[i];
               // cout << "chosen letter from 1st half:  " << letter << endl;

                std::set<char>::iterator itr1;

                itr1 = set2.find(letter);
                if (itr1 != set2.end())
                {
                    
                    set2.erase(letter);
                    sum+= getNumber(letter);
                   
                    break;
                }

            }
              
            }
        }
    
    cout << "SUM is: " << sum << endl;
    return 0;
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