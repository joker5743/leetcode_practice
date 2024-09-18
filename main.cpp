#include"CountQuadruplets.cpp"
#include<iostream>
#include<vector>


int main(){
  CountQuadruplets ques = CountQuadruplets();
  std::vector input = {1, 3, 2 , 4, 5};
  int ans = ques.countQuadruplets(input);
  std::cout << "the program is finished here !" << std::endl;
  return 0;
}