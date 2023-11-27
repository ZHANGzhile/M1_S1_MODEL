# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall -Wextra -std=c99

# 目标文件
TEST_TARGET = test
COMPARE = compare

# 源文件
SRCS_TEST = test.c utils.c fastFourierTrans.c multPoly.c
SRCS = comparison.c utils.c fastFourierTrans.c multPoly.c

# 生成目标文件列表
OBJS_TEST = $(SRCS_TEST:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(TEST_TARGET) $(COMPARE)

# 链接目标文件生成可执行文件
$(TEST_TARGET): $(OBJS_TEST)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(OBJS_TEST)

$(COMPARE): $(OBJS)
	$(CC) $(CFLAGS) -o $(COMPARE) $(OBJS)

# 生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# 清理生成的文件
clean:
	rm -f $(TARGET) $(OBJS)

# 检查内存泄漏
leak: 
	leaks -atExit -- ./$(TARGET)
