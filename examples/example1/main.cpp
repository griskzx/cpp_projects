#include <print>

/*
 * 学习lambda表达式
 *
*/

int main(){
  std::println("learn lambda...");
  auto add = [](int a, int b){
    return a+b;
  };

  std::println("{}",add(3, 5));

  int offset =10; 
  auto add_offset =[offset](int value){
    return offset+value;
  };
  
  std::println("{}",add_offset(5));
  
}
