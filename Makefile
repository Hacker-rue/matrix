# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Папки
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BUILD_DIR = build
LIB_NAME = libmatrix.a

# Цели
LIB = $(BUILD_DIR)/$(LIB_NAME)
TEST_EXEC = $(BUILD_DIR)/test_matrix

# Список исходных файлов
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

# Задачи
all: build install

build: $(LIB) $(TEST_EXEC)

$(LIB): $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $^
	ar rcs $(LIB) *.o
	rm -f *.o

$(TEST_EXEC): $(TEST_FILES) $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

install:
ifeq ($(OS),Windows_NT)
	@echo Установка библиотеки в Windows...
	@mkdir -p C:\matrix_lib
	@copy $(LIB) C:\matrix_lib
	@copy $(INCLUDE_DIR)\matrix.h C:\matrix_lib
else
	@echo Установка библиотеки в Linux...
	@sudo mkdir -p /usr/local/include/matrix_lib
	@sudo cp $(LIB) /usr/local/lib
	@sudo cp $(INCLUDE_DIR)/matrix.h /usr/local/include/matrix_lib
endif

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR) *.o

uninstall:
ifeq ($(OS),Windows_NT)
	@echo Удаление библиотеки из Windows...
	@rmdir /S /Q C:\matrix_lib
else
	@echo Удаление библиотеки из Linux...
	@sudo rm -rf /usr/local/include/matrix_lib
	@sudo rm -f /usr/local/lib/$(LIB_NAME)
endif