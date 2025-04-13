#include <iostream>
#include <matrix.h>

int main() {
  matrix::Matrix mat {{1.0,2.0,3.0}};
  std::cout << mat(0,4) << std::endl;
  // std::cout << mat[0][3] << std::endl;
  return 0;
}