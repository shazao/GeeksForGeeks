/*
Below are the permutations of string ABC.
ABC, ACB, BAC, BCA, CAB, CBA
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::string> permutationsOfString(std::string & string) = 0; // Pure virtual, or Solutionx may not have data members.
};

// No duplicates allowed.
class Solution0 : public Solution {
  public:
    std::vector<std::string> permutationsOfString(std::string & string) {
      std::vector<std::string> permutations;
      backtracking(permutations, string, 0);
      return permutations;
    }
  private:
    void backtracking(std::vector<std::string> & permutations, std::string & string, int idx) {
      if (idx == string.size()) {
        permutations.push_back(string);
        return ;
      }
      
      for (size_t i=idx; i<string.size(); ++i) {
        std::swap(string[i], string[idx]);
        backtracking(permutations, string, idx+1);    // Note: idx+1, not i+1.
        std::swap(string[i], string[idx]);
      }
    }
};

class Solution1 : public Solution {
  public:
    
};


int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::string string = argv[1];

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::string> permutations = solutions[si]->permutationsOfString(string);
    for (size_t i=0; i<permutations.size(); ++i)
      std::cout << permutations[i] << std::endl;
  }

  return 0;
}
