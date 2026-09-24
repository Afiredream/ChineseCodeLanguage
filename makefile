CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -finput-charset=UTF-8 -fexec-charset=UTF-8

# ★ 源码子目录
SRCDIR   := 源码

TARGET   := 程序
SRCS     := 词法分析.cpp 运行软件.cpp
OBJS     := $(addprefix $(SRCDIR)/, $(SRCS:.cpp=.o))

all: $(TARGET)

# 链接：目标文件都在 源码/ 里
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# 编译：源文件、头文件、目标文件都在 源码/ 里
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/词法分析.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean