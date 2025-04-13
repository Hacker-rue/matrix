# Makefile для компиляции и запуска проекта на C++

# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Директории
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Исходные файлы и объектные файлы
SRCS = $(SRC_DIR)/matrix.cpp main.cpp
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Исполняемый файл
TARGET = app

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для компиляции объектных файлов
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Запуск
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run