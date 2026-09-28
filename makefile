编译工具 := g++
编译参数 := -std=c++17 -Wall -Wextra -finput-charset=UTF-8 -fexec-charset=UTF-8 -I定义

源码目录 := 源码
构建目录 := 构建

运行软件 := $(构建目录)/运行软件

源码路径 := $(wildcard $(源码目录)/*.cpp)

目标文件 := $(patsubst $(源码目录)/%.cpp, $(构建目录)/%.o, $(源码路径))

头文件 := $(wildcard $(源码目录)/*.hpp)

all: $(运行软件)

$(运行软件): $(目标文件)
	$(编译工具) $(目标文件) -o $@

$(构建目录)/%.o: $(源码目录)/%.cpp $(头文件)
	@mkdir -p $(构建目录)
	$(编译工具) $(编译参数) -c $< -o $@

run: $(运行软件)
	./$(运行软件) 测试/测试

clean:
	rm -f $(目标文件) $(运行软件)

.PHONY: all run clean