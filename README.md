# compiler_lab


> 序号最大的实验 **完善程度** 最高，根据 **情况复杂程度** 修复了前面实验的bug

## Usage
```shell
$ git clone git@github.com:Zhlee0311/compiler_lab.git
$ cd lab...
$ mkdir build && cd build
$ make -j4
$ ./${target_name}
```

### 1. 编译器使用
- gcc
- clang
### 2. 词法分析
- 2.1 正规表达式转NFA
- 2.2 NFA转DFA
- 2.3 DFA的最小化
### 3. 语法分析
- 3.1 消除左递归
- 3.2 提取左公因子
- 3.3 求first和follow集
- 3.4 LL(1)文法预测分析器