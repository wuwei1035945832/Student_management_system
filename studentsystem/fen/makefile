# Makefile：学生成绩管理系统

CC = gcc
CFLAGS = -Wall -Wextra

# 目标文件和依赖项
OBJS = main.o student.o
DEPS = student.h

# 目标可执行文件名
TARGET = grade_management_system

# 构建目标可执行文件的规则
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# 编译 main.o 的规则
main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c main.c

# 编译 student.o 的规则
student.o: student.c $(DEPS)
	$(CC) $(CFLAGS) -c student.c

# 清除规则，用于删除生成的目标文件和可执行文件
clean:
	rm -f $(OBJS) $(TARGET)
