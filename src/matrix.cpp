#include "matrix.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <cmath>

namespace matrix {
  Matrix::Matrix() : rows(0), cols(0), data()
  {

  }

  Matrix::Matrix(size_t rows, size_t cols, double initialValue) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<double>(cols, initialValue));
  }

  Matrix::Matrix(std::initializer_list<std::initializer_list<double>> initList) {
    rows = initList.size();
    cols = initList.begin()->size();
    data.resize(rows);

    size_t i = 0;
    for (const auto& row : initList) {
      if (row.size() != cols) {
        throw std::invalid_argument("All rows must have the same number of columns.");
      }
      data[i++] = row;
    }
  }

  size_t Matrix::getRows() {
    return rows;
  }

  size_t Matrix::getCols() {
    return cols;
  }

  double& Matrix::operator()(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
      throw std::out_of_range("Index out of range.");
    }
    return data[row][col];
  }

  double Matrix::operator()(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
      throw std::out_of_range("Index out of range.");
    }
    return data[row][col];
  }

  std::vector<double>& Matrix::operator[](size_t row) {
    if (row >= rows) {
      throw std::out_of_range("Index out of range.");
    }
    return data[row];
  }

  const std::vector<double>& Matrix::operator[](size_t row) const {
    if (row >= rows) {
      throw std::out_of_range("Index out of range.");
    }
    return data[row];
  }

  Matrix Matrix::operator+(const Matrix &other) const
  {
    if (rows != other.rows || cols != other.cols) {
      throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    Matrix results(rows, cols);

    for (size_t i = 0; i < rows; ++i) {
      for(size_t j = 0; j < cols; ++j) {
        results(i,j) = (*this)(i,j) + other(i,j);
      }
    }
    return results;
  }

  Matrix Matrix::operator*(const Matrix &other) const
  {
    if (cols != other.rows) {
      throw std::invalid_argument("Matrix dimensions must match for multiplication.");
    }

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < other.cols; ++j) {
        for (size_t k = 0; k < cols; ++k) {
          result(i, j) += (*this)(i, k) * other(k, j);
        }
      }
    }

    return result;
  }

  Matrix Matrix::transpose() const
  {
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < cols; ++j) {
        result(j, i) = (*this)(i, j);
      }
    }
    return result;
  }

  double Matrix::determinant() const
  {
    if (rows != cols) {
      throw std::invalid_argument("Matrix must be square to calculate determinant.");
    }

    if (rows == 1) {
      return data[0][0];
    }

    if (rows == 2) {
      return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    double det = 0.0;
    for (size_t j = 0; j < cols; ++j) {
      det += (j % 2 == 0 ? 1 : -1) * data[0][j] * minor(0, j).determinant();
    }
    return det;
  }

  Matrix Matrix::minor(size_t row, size_t col) const
  {
    return Matrix();
  }

  Matrix Matrix::toScalar(double scalar) const
  {
    return Matrix();
  }

  Matrix Matrix::toDiagonalForm() const
  {
    return Matrix();
  }

  void Matrix::print() const {
    for (const auto& row : data) {
      for (const auto& elem : row) {
        std::cout << elem << " ";
      }
      std::cout << std::endl;
    }
  }
}