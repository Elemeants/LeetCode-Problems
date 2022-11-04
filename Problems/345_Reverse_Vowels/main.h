//
// 345. Reverse Vowels of a String
//
#pragma once

#include <string>
#include <vector>

class Solution
{
private:
  bool isvowel(char c) {
    const char _c = tolower(c);
    return (_c == 'a' || _c == 'e' || _c == 'i' || _c == 'o' || _c == 'u');
  }

  void swap (char* head, char* tail) {
    char aux = *head;
    *head = *tail;
    *tail = aux;
  }
public:
  std::string reverseVowels(std::string s)
  {
    char* tail = (char*)s.c_str();
    char* head = tail + (s.size() - 1);

    while (tail < head) {
      if (isvowel(*tail)) {
        while (!isvowel(*head)) {
          head--;
        }
        swap(head, tail);
        head--;
      }
      tail ++;
    }

    return s;
  }
};
