/*
The N Queen is the problem of placing N chess queens on an N×N chessboard 

so that no two queens attack each other. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\..\Profiler.h"

class Solution {
  public:
    virtual void solveNQueen(int n = 8) = 0; // Pure virtual, or Solutionx may not have data members.
};

// The iterative method shows the "backtracking" clearly by "-- idx".
class Solution0 : public Solution {
  public:
    void solveNQueen(int n = 8) {
      solution_.resize(n, 0);
      int idx = 0;
      while (idx >= 0) {
        if (solution_[idx] == n) {
          solution_[idx] = 0;
          -- idx;
          if (idx >= 0)
            ++ solution_[idx];
          continue;
        }
        while (solution_[idx]<n-1 && !canPlace(idx, solution_[idx]))
          ++ solution_[idx];
        if (solution_[idx]==n-1 && !canPlace(idx, solution_[idx])) {
          solution_[idx] = 0;
          -- idx;
          ++ solution_[idx];
        } else if (idx == n-1) {
          solutions_.push_back(solution_);
          ++ solution_[idx];
        } else {
          ++ idx;
        }
      }

      printSolution();
    }

  private:
    // Can ith queen be placed at Column j(The ith queen is placed at Row i)?
    bool canPlace(int i, int j) {
      for (int idx=0; idx<i; ++idx)
        if (solution_[idx]==j || solution_[idx]-j==idx-i || solution_[idx]-j==i-idx)
          return false;
      return true;
    }

    // Print.
    void printSolution() {
      for (size_t i=0; i<solutions_.size(); ++i) {
        for (size_t j=0; j<solution_.size(); ++j) {
          for (size_t k=0; k<solution_.size(); ++k)
            if (k == solutions_[i][j])
              std::cout << ' ' << 'O';
            else
              std::cout << ' ' << 'X';
          std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
      }
      std::cout << "Total " << solutions_.size() << " solutions." << std::endl << std::endl;
    }

    std::vector<int> solution_;
    std::vector<std::vector<int> > solutions_;
};

// The recursive method shows the "backtracking" implicitly by return to the caller after the for loop.
class Solution1 : public Solution {
  public:
    void solveNQueen(int n = 8) {
      solution_.resize(n, 0);
      backtracking(0);
      printSolution();
    }
    
  private:
    void backtracking(int i) {
      if (i == solution_.size())
        return;
      for (int j=0; j<solution_.size(); ++j) {
        solution_[i] = j;
        if (canPlace(i, j)) {
          if (i == solution_.size()-1) {
            solutions_.push_back(solution_);
          } else
            backtracking(i+1);
        }
      }
    }

    // Can ith queen be placed at Column j(The ith queen is placed at Row i)?
    bool canPlace(int i, int j) {
      for (int idx=0; idx<i; ++idx)
        if (solution_[idx]==j || solution_[idx]-j==idx-i || solution_[idx]-j==i-idx)
          return false;
      return true;
    }

    // Print.
    void printSolution() {
      for (size_t i=0; i<solutions_.size(); ++i) {
        for (size_t j=0; j<solution_.size(); ++j) {
          for (size_t k=0; k<solution_.size(); ++k)
            if (k == solutions_[i][j])
              std::cout << ' ' << 'O';
            else
              std::cout << ' ' << 'X';
          std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
      }
      std::cout << "Total " << solutions_.size() << " solutions." << std::endl << std::endl;
    }

    std::vector<int> solution_;
    std::vector<std::vector<int> > solutions_;
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "\nPlease input the N: ";
  int n = 8;
  std::cin >> n;
  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    solutions[si]->solveNQueen(n);
  }

  return 0;
}

// Reference:
// A more neat iterative solution.
/* 
bool place(int x[], int k)//考察皇后k放置在x[k]列是否发生冲突
{
    int i;
    for(i=1;i<k;i++)
        if(x[k]==x[i] || k-i==x[k]-x[i] || k-i==x[i]-x[k])
            return false;
    return true;
}

void queen(int n)
{
    int x[100];
    int i,k;
    for(i=1;i<=n;i++)
        x[i]=0;
    k=1;
    while(k>=1)
    {
        x[k]=x[k]+1;   //在下一列放置第k个皇后
        while(x[k]<=n&&!place(x, k))
            x[k]=x[k]+1;//搜索下一列
        if(x[k]<=n&&k==n)//得到一个输出
        {
            ++ solution_count;
            std::cout << "Solution " << solution_count << ": ";
            for(i=1;i<=n;i++)
                printf("%d ",x[i]);
            printf("\n");
        //return;//若return则只求出其中一种解，若不return则可以继续回溯，求出全部的可能的解
        }
        else if(x[k]<=n&&k<n)
            k=k+1;//放置下一个皇后
        else
        {
            x[k]=0;//重置x[k],回溯
            k=k-1;
        }
    }
}
*/
