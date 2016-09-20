/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., 

maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from 

source and has to reach destination. The rat can move only in two directions: forward and down.In the maze 

matrix, 0 means the block is dead end and 1 means the block can be used in the path from source to 

destination. Note that this is a simple version of the typical Maze problem. For example, a more complex 

version can be that the rat can move in 4 directions and a more complex version can be with limited number of moves.

Following is binary matrix representation of a maze.
                {1, 0, 0, 0}
                {1, 1, 0, 1}
                {0, 1, 0, 0}
                {1, 1, 1, 1}

Following is the solution matrix (output of program) for the above input matrx.

                {1, 0, 0, 0}
                {1, 1, 0, 0}
                {0, 1, 0, 0}
                {0, 1, 1, 1}
 All enteries in solution path are marked as 1.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > & getPathOfRat() = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    Solution0(std::vector<std::vector<int> > & maze) : pMaze_(&maze){
      for (size_t i=0; i<maze.size(); ++i)
        solution_.push_back(std::vector<int>(maze[i].size(), 0));
    }

    std::vector<std::vector<int> > & getPathOfRat() {
      if (backtracking(0, 0))
        return solution_;
      else {
        std::cout << "Solution does not exist!\n";
        for (size_t i=0; i<solution_.size(); ++i)
          for (size_t j=0; j<solution_[i].size(); ++j)
            solution_[i][j] = 0;
        return solution_;
      }
    }

  private:
    bool backtracking(int x, int y) {
      if (x==solution_.size()-1 && y==solution_[x].size()-1) {
        solution_[x][y] = 1;
        return true;
      }

      if (isValid(x, y)) {
        solution_[x][y] = 1;
        if (backtracking(x+1, y))
          return true;
        else if (backtracking(x, y+1))
          return true;
        else {
          solution_[x][y] = 0;
          return false;
        }
      } else
        return false;
    }

    bool isValid(int x, int y) {
      if (x>=0&&x<solution_.size() && y>=0&&y<solution_[x].size() && (*pMaze_)[x][y]==1 && solution_[x][y]==0)
        return true;
      else
        return false;
    }

    std::vector<std::vector<int> > * pMaze_;
    std::vector<std::vector<int> > solution_;
};

class Solution1 : public Solution {
  public:
    
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<std::vector<int> > maze;
  maze.push_back(std::vector<int>({1, 0, 0, 0}));
  maze.push_back(std::vector<int>({1, 1, 0, 1}));
  maze.push_back(std::vector<int>({0, 1, 0, 0}));
  maze.push_back(std::vector<int>({1, 1, 1, 1}));
               
  std::vector<Solution*> solutions;
  Solution0 s0(maze); solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::vector<int> > & solution = solutions[si]->getPathOfRat();
    for (size_t i=0; i<solution.size(); ++i) {
      for (size_t j=0; j<solution[i].size(); ++j)
        std::cout << ' ' << solution[i][j];
      std::cout << std::endl;
    }
  }

  return 0;
}
