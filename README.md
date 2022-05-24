# 实验三：多路归并算法的实现

![Memory-used](https://user-images.githubusercontent.com/23132866/169997993-061bfce3-51ac-4f6b-b8b9-f1253ef130ab.png)

## 目录

- [实验要求](#实验要求)
- [使用方法](#使用方法)
- [开发文档](#开发文档)

## 实验要求

选择任意高级语言，设计实现归并排序。

要求：

- 随机生成具有1,000,000条记录的二进制文件，每条记录的长度为16字节，结构如下：

| 属性A（4字节整数） | 属性B（12字节字符串） |
| ---------- | ------------ |

- 针对属性A进行多路归并排序；

- 用于外部归并排序的内存空间不大于1MB。

## 使用方法

打开ExternalSort.exe，程序将在同级目录下产生：

1. 随机生成的二进制记录文件`data.in`；

2. 划分后的各归并段`tmp0`~`tmp19`；

3. 升序的二进制文件`data.out`。

## 开发文档

### 打开、编译和测试

使用[Visual Studio](https://visualstudio.microsoft.com/)打开项目根目录下的 `ExternalSort.sln` 解决方案。解决方案中包括两个项目：`ExternalSort` 和 `ExternalSortTest`，前者实现外排序，后者用于单元测试。

项目可以在Debug和Release模式下编译。单击“生成解决方案”生成可执行程序，或者单击“本地Windows调试器”开始调试，无需配置。

打开“测试资源管理器”可以查看和执行 `ExternalSortTest` 项目中的单元测试。其中对 `ExternalSort` 的几个核心类进行了测试。

### 代码结构

代码的类图如下（源文件位于`docs/ClassDiagram.puml`）：

![ClassDiagram](https://user-images.githubusercontent.com/23132866/169987280-f219dbc5-4013-42d3-a72f-458f3339771a.png)

左侧Record类是对实验要求中记录的实现；中间含“Block”的几个类通过装饰器模式实现对内存块的各种操作；右侧的LoserTree类实现败者树，用于实现外排序中第二趟的多路归并。

`ExternalSort.cpp`中有程序的入口，同时它也控制外排序的各种参数：内存限制、总记录数、归并段个数等，通过他们可以调整内存占用和排序速度。这些配置均位于该文件的顶部，有注释给出。
