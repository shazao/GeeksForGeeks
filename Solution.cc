class Solution {
  public:
    virtual  = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
};

class Solution1 : public Solution {
  public:
};

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
  }
