#include <iostream>  
#include <time.h>  
  
int main()  
{  
  clock_t s, e;  
  
  s = clock() ;   
  for(int i=100000000; i>0; --i) ;   
  e = clock() ;   
  
  std::cout << "Number of clock ticks per second: " << CLOCKS_PER_SEC << '.' << std::endl;
  std::cout << e-s << " clock ticks elapsed!" << std::endl ;   
  std::cout << (e-s)*1000.0/CLOCKS_PER_SEC << " milliseconds elapsed(" << e-s << " clock ticks)!" << std::endl ;   
  
  return 0 ;  
}
