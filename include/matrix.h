// #ifdef MATRIX_H
// #define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>

namespace matrix {
  /// @brief 
  class Matrix {
    private:
      std::vector<std::vector<double>> data;
      size_t rows;
      size_t cols;

    public:
      /// @brief 
      /// @param rows 
      /// @param cols 
      Matrix(size_t rows, size_t cols);
      /// @brief 
      /// @param rows 
      /// @param cols 
      /// @param initialValue 
      Matrix(size_t rows, size_t cols, double initialValue = 0.0);
      /// @brief 
      /// @param  
      Matrix(std::initializer_list<std::initializer_list<double>>);

      /// @brief 
      /// @return 
      size_t getRows();
      /// @brief 
      /// @return 
      size_t getCols();
      /// @brief 
      /// @param row 
      /// @param col 
      /// @return 
      double getElement(size_t row, size_t col) const;
      /// @brief 
      /// @param row 
      /// @param col 
      /// @return 
      double& getElement(size_t row, size_t col);
      /// @brief 
      /// @param row 
      /// @param col 
      /// @param value 
      void setElement(size_t row, size_t col, double value);
  };


};

// #endif