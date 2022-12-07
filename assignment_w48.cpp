#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include "Card.hpp"
#include "Card_def.cpp"

/*  create a deck of cards that may be sorted using either their
value (e.g., all aces, then all twos, then all threes ...) or suite-value combination.
Finally make it possible to shuffle the deck. */
std::string GetLongestCommonSubstring(std::string const &a, std::string const &b);
std::string find_common_part(std::string, std::string);
int getNumber(char);
int main()
{

    vector<Card> someDeck;
    std::vector<Card> newDeck1;
    for (int i = 80; i < 84; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            Card card1(i, j);
            someDeck.push_back(card1);
        }
    }
    Deck aDeck(someDeck);

    std::vector<std::string> selectedCard = aDeck.selectRandom();

    fstream inFil;
    inFil.open("/Users/ndi01/Downloads/assignment_AdventOfCode3.txt");
    static int c = 0;

    // char *alpha_l[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // char *alpha_u[] = {'A', 'B', 'C', ' D ', ' E ', ' F ', ' G ', ' H ', ' I ', ' J ', ' K ', ' L', ' M ', ' N ', ' O ', ' P ', ' Q ', ' R ', ' S ', ' T ', ' U', ' V ', ' W ', ' X ', ' Y ', ' Z'};

    static int sum = 0;
    if (inFil.is_open())
    {
        cout << "open " << endl;
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
                   // cout << "LETTER from 1st Half found in 2nd half : \n"
                    //     << letter << endl;
                   // cout << "number is :  " << getNumber(letter) << endl;
                   // cout << "SUM:  " << sum << endl;
                    break;
                }

            }

            //unused code below....
           /*  for (int i = 0; i < half.length(); ++i)
            {
                std::set<char>::iterator itr2;
                char letter1 = otherHalf[i];
                cout << "chosen letter from 2nd half:  " << letter1 << endl;
                itr2 = set1.find(letter1);
                if (itr2 != set1.end())
                {
                    cout << "LETTER: from 2nd Half found in 1st half: \n " << letter1 << endl;
                    set1.erase(letter1); 
                    break;
                }
            */
                

              
            }
        }
    
    cout << "SUM is: " << sum << "count is: " << c << endl;
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
/* std::string GetLongestCommonSubstring(std::string const& a, std::string const& b) {
    std::vector<std::string> substrings;
    for (auto beg = a.begin(); beg != std::prev(a.end()); ++beg)
        for (auto end = beg; end != a.end(); ++end)
            if (b.find(std::string(beg, std::next(end))) != std::string::npos)
                substrings.emplace_back(beg, std::next(end));
    return *std::max_element(substrings.begin(), substrings.end(),
           [](auto& elem1, auto& elem2) { return elem1.length() < elem2.length(); });
}
*/

/* ADVENT DAY 3 CODE NOT RELATED TO CARD, DECK
    char *s = "Hi Thiss Amasing";
    char *t = {"Hi this Amazing"};
    cout << s << endl; // prints the entire string "Hi Thiss Amasing"

    std::map<char, int> counters;
    int i ;
    while (*(s + i) != '\0'){
        ++counters[*(s+i)]; i++; }

    for (auto iter = counters.begin(); iter != counters.end(); iter++)
        cout << iter->first << " " << iter->second << endl;

*/

/*-------------- EXTRA-------
enum MyEnum
{
    VAL1,
    VAL2, Hearts
};
template <MyEnum n>
struct StrMyEnum
{
    static char const *name() { return "Unknown"; }
};

#define STRENUM(val, str)                         \
    template <>                                   \
    struct StrMyEnum<val>                         \
    {                                             \
        static char const *name() { return str; } \
    };

STRENUM(VAL1, "Value 1");
STRENUM(VAL2, "Value 2");
STRENUM(Hearts, "HEARTS");

std::cout << StrMyEnum<Hearts>::name();




// for ( itr = deck.begin(); itr < deck.end(), ++itr)
    //   {cout << itr->printFace().first << " " <<  itr->printFace().second << endl;}
    // cout << card2.printFace().first << " " << card2.printFace().second <<   std::endl;
    cout << card1.printFace().second << endl;
*/

 /*  if (set2.size() < set1.size()) // letter in first half
                {

                    cout << "size of set2: " << set2.size() << "\n";
                    cout << "size of set1: " << set1.size() << "\n";

                    cout << "The letter first loop is: " << letter << endl;
                    c++;
                    cout << "Number is: " << getNumber(letter) << "count: " << c << endl;
                    sum += getNumber(letter);
                    cout << sum << endl;
                    // break;
                }
                else if (set2.size() > set1.size()) // letter in otherHalf
                {
                    cout << "The letter second loop is: " << letter1 << endl;
                    c++;
                    cout << "Number is: " << getNumber(letter1) << "count: " << c << endl;
                    sum += getNumber(letter1);
                    cout << sum << endl;
                    // break;
                } */