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
      Matrix();
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

      double& operator()(size_t row, size_t col);
      double operator()(size_t row, size_t col) const;

      std::vector<double> &operator[](size_t row);
      const std::vector<double> &operator[](size_t row) const;

      Matrix operator+(const Matrix& other) const;
      Matrix operator*(const Matrix& other) const;

      /// @brief 
      /// @return 
      Matrix transpose() const;
      /// @brief 
      /// @return 
      double determinant() const;
      /// @brief 
      /// @param row 
      /// @param col 
      /// @return 
      Matrix minor(size_t row, size_t col) const;
      /// @brief 
      /// @param scalar 
      /// @return 
      Matrix toScalar(double scalar) const;
      /// @brief 
      /// @return 
      Matrix toDiagonalForm() const;
  };
};

// #endif