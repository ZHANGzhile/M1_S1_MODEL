# Makefile for a simple C program

# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall -Wextra -std=c99

# 目标文件
TARGET = test

# 源文件
SRCS = test.c utils.c fastFourierTrans.c multPoly.c

# 生成目标文件列表
OBJS = $(SRCS:.c=.o)

# 默认构建规则
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# 清理生成的文件
clean:
	rm -f $(TARGET) $(OBJS)

# 检查内存泄漏
leak: 
	leaks -atExit -- ./$(TARGET)
