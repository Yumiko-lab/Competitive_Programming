# XCPC Environment

[Gerchart - XCPC线下比赛环境C++代码的编写与运行简述（ICPC、CCPC、省赛比赛环境） - Bilibili](https://www.bilibili.com/video/BV1Vzy5YUEZx/) 

[DOMJudge](https://www.domjudge.org/) 

[DOMjudge 中文文档](https://nwpu.gitbook.io/domjudge-doc) 




## VSCode 及 DOMJudge 命令整理

### VSCode

在当前文件夹打开 VSCode：
```
code .
```

打开 Terminal
```cpp
Ctrl + ~
Ctrl + j
```

编译：

```cpp
g++ -std=c++20 -O2 -Wall x.cpp
```

( 编译成功之后会在当前文件夹下生成 `x.out` )

运行：

```cpp
./x.out
```

通过外部 txt 文件输入数据：

```cpp
./x.out < in.txt
```

将输出结果放入 txt 文件：

```cpp
./x.out < in.txt > out.txt
```

Linux 脚本编译 + 运行：

```cpp
创建 run.sh，文件内输入：

#/bin/bash

g++ -std=c++20 -O2 -Wall $1.cpp -o main
./main < in.txt > out.txt
cat out.txt

编译即运行命令：

./run.sh x
```



### DOMJudge


提交：

```cpp
submit x.cpp
```

强制提交 (不用确认)：

```cpp
submit x.cpp -y
```


打印文件：

```cpp
printfile x.cpp
```