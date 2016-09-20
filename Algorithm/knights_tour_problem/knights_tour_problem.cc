/*
The knight is placed on the first block of an empty board and, moving according to 

the rules of chess, must visit each square exactly once.

Existence(From WikiPedia): 

Conrad et al. proved that on any rectangular board whose smaller dimension is at least 5, 

there is a (possibly open) knight's tour.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "..\..\Profiler.h"

class Solution {
  public:
    virtual void solveKnightTour() = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    Solution0(size_t n) : n_(n) { solution_.resize(n*n, -1); }
    void solveKnightTour() {
      if (n_ < 3) std::cout << "Solution does not exest!" << std::endl;

      solution_[0] = 0;
      if (backtracking(1, 0, 0, 1, 2))
        printSolution();
      else if (backtracking(1, 0, 0, 2, 1))
        printSolution();
      else
        std::cout << "Solution does not exest!" << std::endl;

      validateSolution();
    }

  private:
    bool backtracking(size_t move_idx, int x, int y, int move_x, int move_y) {
      if (move_idx == n_*n_)
        return true;

      x += move_x;
      y += move_y;
      if (isValid(x, y)) {
        solution_[x*n_ + y] = move_idx;
        for (size_t i=0; i<8; ++i)
          if (backtracking(move_idx+1, x, y, move_x_[i], move_y_[i]))
            return true;
        solution_[x*n_ + y] = -1;
        return false;
      } else
        return false;
    }

    bool isValid(int x, int y) {
      if (x>=0&&x<n_ && y>=0&&y<n_ && solution_[x*n_+y]==-1)
        return true;
      else 
        return false;
    }

    void printSolution() {
      for (size_t i=0; i<solution_.size(); ++i) {
        if (i%n_ == 0) std::cout << std::endl;
        std::cout << ' ' << solution_[i];
      }
      std::cout << std::endl;
    }

    bool validateSolution() {
      auto it = min_element(solution_.begin(), solution_.end());
      size_t idx = it - solution_.begin();
      size_t move_idx = *it;
      int x = idx/n_;
      int y = idx%n_;
      int last_move = n_*n_-1;
      while (move_idx < last_move) {
        int i = 0;
        int x_ = 0;
        int y_ = 0;
        for (; i<8; ++i) {
          x_ = x + move_x_[i];
          y_ = y + move_y_[i];
          if (x_>=0&&x_<n_ && y_>=0&&y_<n_)
            if (solution_[x_*n_ + y_] == move_idx+1)
              break;
        }
        if (i == 8) {
          std::cout << "Invalid move at " << move_idx << "th move." << std::endl;
          return false;
        }
        x = x_;
        y = y_;
        ++ move_idx;
      }
      return true;
    }

    std::vector<int> move_x_ = {-2, -1, 1, 2, 2, 1, -1, -1};
    std::vector<int> move_y_ = {1, 2, 2, 1, -1, -2, -2, -1};
    size_t n_;
    std::vector<int> solution_;
};

class Solution1 : public Solution {
  public:
    
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "\nPlease input the N: ";
  int n = 0;
  std::cin >> n;

  std::vector<Solution*> solutions;
  Solution0 s0(n); solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    solutions[si]->solveKnightTour();
  }

  return 0;
}
