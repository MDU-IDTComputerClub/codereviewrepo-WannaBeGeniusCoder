#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <map>
#include <set>
using namespace std;

int main()
{

    fstream inFil;
    inFil.open("/Users/ndi01/Downloads/assignment_AdventOfCode6_1.txt");

    static int count_line = 0; // if its a multiple of 3, run some code
    std::vector<char> fileChar, windowChar;
    char readFile;

    // static std::vector<std::vector<std::string>> strVec;
    if (inFil.is_open())
    {

        while (inFil >> readFile)
        {
            fileChar.push_back(readFile);
            count_line++;
        }
    }

    /* for (auto ptr = fileChar.begin(); ptr != fileChar.end(); ++ptr)
    {
        auto ptr = fileChar.begin();
        advance(ptr, 2);
        cout << *ptr << endl;*/

    for (int i = 0; i < fileChar.size(); i++) // fileChar.size();
    {
        auto ptr = fileChar.begin();
        std::set<char> window;
        std::vector<char>::const_iterator window_ptr;
        advance(ptr, i);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        //  code for part 2
        /**********************/
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        advance(ptr, 1);
        windowChar.push_back(*ptr);
        for (window_ptr = windowChar.begin(); window_ptr != windowChar.end(); ++window_ptr)
        {
           // cout << *window_ptr << endl;

            window.insert(*window_ptr); // window contains 4 elements comprising a window.
        }
        if (window.size() == 14) // part 1 = 4; part 2 = 14
        {
            cout << "HURRRRAAHHHH    " << i + 14 << endl;  // part 1 = 4 ; part 2 = 14
            break;
        }

       // cout << "set length: " << window.size() << endl;
       // cout << " *********\n";
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        //  code for part 2
        /**********************/
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
        windowChar.pop_back();
    }

    // cross check
    /* auto ptr1 = fileChar.begin();
    int count = 0;
    for (ptr1; ptr1 != fileChar.end(); ++ptr1)
    {
        count++;
        if (count == 1962)
        {
            cout << " check " << *ptr1 << endl;
            advance(ptr1, 1);
            cout << *ptr1 << endl;
            advance(ptr1, 1);
            cout << *ptr1 << endl;
            advance(ptr1, 1);
            cout << *ptr1 << endl;
        }
    } */
}
