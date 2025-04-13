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
    return Matrix();
  }
  Matrix Matrix::operator*(const Matrix &other) const
  {
    return Matrix();
  }
  Matrix Matrix::transpose() const
  {
    return Matrix();
  }
  double Matrix::determinant() const
  {
    return 0.0;
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
}