#include <iostream>
#include <cassert>
#include "../include/matrix.h"

void testMatrixInitialization() {
  try {
    // Тест пустой матрицы
    matrix::Matrix m1;
    assert(m1.getRows() == 0);
    assert(m1.getCols() == 0);

    // Тест матрицы с заданными размерами
    matrix::Matrix m2(3, 3, 1.0);
    assert(m2.getRows() == 3);
    assert(m2.getCols() == 3);
    assert(m2(0, 0) == 1.0);

    // Тест матрицы с initializer_list
    matrix::Matrix m3{{1, 2}, {3, 4}};
    assert(m3.getRows() == 2);
    assert(m3.getCols() == 2);
    assert(m3(0, 0) == 1);
    assert(m3(1, 1) == 4);

    std::cout << "Тест инициализации матрицы выполнен успешно!" << std::endl;
  } catch (...) {
    std::cout << "Тест инициализации матрицы провален!" << std::endl;
  }
}

void testMatrixAddition() {
  try {
    matrix::Matrix m1{{1, 2}, {3, 4}};
    matrix::Matrix m2{{5, 6}, {7, 8}};
    matrix::Matrix result = m1 + m2;

    assert(result.getRows() == 2);
    assert(result.getCols() == 2);
    assert(result(0, 0) == 6);
    assert(result(1, 1) == 12);

    std::cout << "Тест сложения матриц выполнен успешно!" << std::endl;
  } catch (...) {
    std::cout << "Тест сложения матриц провален!" << std::endl;
  }
}

void testMatrixMultiplication() {
  try {
    matrix::Matrix m1{{1, 2}, {3, 4}};
    matrix::Matrix m2{{5, 6}, {7, 8}};
    matrix::Matrix result = m1 * m2;

    assert(result.getRows() == 2);
    assert(result.getCols() == 2);
    assert(result(0, 0) == 19);
    assert(result(1, 1) == 50);

    std::cout << "Тест умножения матриц выполнен успешно!" << std::endl;
  } catch (...) {
    std::cout << "Тест умножения матриц провален!" << std::endl;
  }
}

void testTranspose() {
  try {
    matrix::Matrix m{{1, 2}, {3, 4}};
    matrix::Matrix transposed = m.transpose();

    assert(transposed.getRows() == 2);
    assert(transposed.getCols() == 2);
    assert(transposed(0, 1) == 3);
    assert(transposed(1, 0) == 2);

    std::cout << "Тест транспонирования матрицы выполнен успешно!" << std::endl;
  } catch (...) {
    std::cout << "Тест транспонирования матрицы провален!" << std::endl;
  }
}

void testDeterminant() {
  try {
    matrix::Matrix m{{1, 2}, {3, 4}};
    double det = m.determinant();
    assert(det == -2);
    std::cout << "Тест вычисления определителя выполнен успешно!" << std::endl;
  } catch (...) {
    std::cout << "Тест вычисления определителя провален!" << std::endl;
  }
}

void testMinor() {
  try {
    matrix::Matrix m{{1, 2}, {3, 4}};
    matrix::Matrix minor = m.minor(0, 0);

    assert(minor.getRows() == 1);
    assert(minor.getCols() == 1);
    assert(minor(0, 0) == 4);

    std::cout << "Тест вычисления минора выполнен успешно!" << std::endl;
  } catch (...) {
    std::cout << "Тест вычисления минора провален!" << std::endl;
  }
}

void testExceptions() {
  try {
    matrix::Matrix m{{1, 2}, {3, 4}};

    try {
      m(3, 3); // Неверный индекс
      assert(false); // Если исключение не выброшено, тест провален
    } catch (const std::out_of_range&) {
      assert(true); // Исключение выброшено, тест пройден
    }

    try {
      matrix::Matrix m1{{1, 2}, {3, 4}};
      matrix::Matrix m2{{1, 2, 3}, {4, 5, 6}};
      matrix::Matrix result = m1 + m2; // Сложение матриц разных размеров
      assert(false); // Если исключение не выброшено, тест провален
    } catch (const std::invalid_argument&) {
      assert(true); // Исключение выброшено, тест пройден
    }

    std::cout << "Тесты на выброс исключений выполнены успешно!" << std::endl;
  } catch (...) {
    std::cout << "Тесты на выброс исключений провалены!" << std::endl;
  }
}

int main() {
  testMatrixInitialization();
  testMatrixAddition();
  testMatrixMultiplication();
  testTranspose();
  testDeterminant();
  testMinor();
  testExceptions();

  std::cout << "Все тесты завершены!" << std::endl;
  return 0;
}