# 4.复合类型
## 4.1 数组Array
### 数组创建
+ 数组类型
+ 数组名
+ 元素个数
```cpp
 short months[12];      //数组的声明
 int array[3];          //数组声明与初始化
 array[0] = 2;
 array[1] = 3;
 array[2] = 4;
//int array[3] = {2,3,4};   //声明数组时，直接初始化或单独初始化;而不能声明与初始化分开，如下：
//int array[3];
//array[3] = {2,3,4}
 ```
 ### 数组的访问
 + 通过数组的下标或索引来访问数组中元素   
 + 下标从0开始
 + 下标最大值为数组长度（即元素个数）-1
 + 编译器不会检查下标是否有效，如`months[101]`,这些错误需要程序员在编写时，检查有效性。

### 数组的赋值
 - 声明时，直接初始化；`int array[2] = {1,2}`
 - 声明后，每个元素分开赋值
 - 可以不写元素个数，也可以不完全写完元素值,未赋值的元素将默认赋值为0 ；`int array[] = {1,2}；int array[2] = {1,}`
 - 禁止列表初始化禁止缩窄转化；`int array[2] = {1,2.0}；//double类型被赋值给int类型，将被禁止`

 ## 4.2  字符串
 ### 字符串操作方式
 + C语言中**数组**操作方式，C风格字符串；以空字符作为字符串的结尾；     
`char dog[4] = {'d','o','g','p'} //未以空字符结尾，为字符数组；
 char dog[4] = {'d','o','g','\0'} //字符串`
 + string类库

 ### 字符串的初始化 
 - 单引号初始化;    `char dog[4] = {'d','o','g','\0'}`
 - 双引号初始化;    `char dog[] = "dog"`
 - 数组空间开辟大小要比输入的字符串数多1，空字符考虑进去

### 字符常量、字符串常量
- 字符常量，用单引号,字符常量是字符串编码的简写表示。如`char a ='S'`,'S'是83的另一种写法，将83赋值给a。
- 字符串常量，用双引号，如`char a = "S"`,`"S"`表示字符S和\0组合；且`"S"`表示字符串在内存中的地址，所以语句不被允许。

### sizeof与strlen
- `sizeof`包括字符串数组中所有字符个数，包括空字符
- `strlen`只输出有效字符个数

### cin、getline、get
- `cin`使用空白字符来结束输入结束；空白字符包括空格、回车、制表符。
- `getline`函数读取整行，它使用通过回车键输入的换行符来确定输入的确定。并将丢弃换行符。字符串长度回车作为结束且不超过个数-1；如`cin.getline(name,20)`最多19个字符。
- get也看读取整行，但会将换行符保留到输入序列中。 
- `cin.clear()`

## 4.3   string类
### string类的使用
+ 需要添加`string`类头文件；
+ `string`类位于名称空间`std`中需要提供`using`编译指令；
+ `string`声明/赋值、拼接/附加
```cpp
    string str1;    //不需要指定字符个数，会自动调整大小
    string str2 = "hello world";
    string str4 ={"panter is a boy"};
    string str5 {"panter is a boy"};

    string str3 = str1 + str2;
    str3 += "good morning";
```
+ 确定字符串中字符个数的方法
```cpp
    int len1 = strlen(charr1);      //对于字符数组，可以使用strlen
    int len2 = str1.size();         //size（）为string类的一个方法
```
+ `string`类I/O
    + 将一行输入读取到字符数组；`cin.getline(charr,20)`
    + 将一行输入读取到string对象中；`getline(cin,str)`

## 4.4 结构体 Struct
### Struct声明
 ```cpp
    struct students
    {
        char name[20];      //可以使用string name;
        double point;
    };
```
### struct使用（初始化）
```cpp
    students stu1 =
    {
        "xiaoming",
        65.12
    };
    students stu2;
    stu2 = stu1;        //结构体对拷
    cout << stu2.name << stu2.point << endl;       //访问结构体成员
```
### 结构数组     
数组中每个元素都是结构体
+ 初始化规则
  + 外层花括号为*数组*,数组元素之间用",";
  + 内层花括号为*结构体*,结构体之间用",";
```cpp
    students stu[2]
    {
        {"xiaoming",65.12},
        {"xiaoli",52.12}
    };
    cout << stu[0].name <<" and " << stu[1].name << "totel points:" 
         << stu[0].point + stu[1].point <<endl;
```
## 4.5 共用体/联合体 Union ##
共用体为一种数据格式，用于储存不同类型的数据，但只能同时储存其中的一种类型。
 + 共用体的用途：当数据项选择两种或多种格式时，可节省空间；如书的ID，有的是id，有的是字符串。
 + 共用体的长度为其最大成员的长度；
 ```cpp
    union one2all
    {
        char ch;
        int n;
    };
    one2all num;
    num.ch = 'A';
    cout << num.ch << ":" << sizeof(num) << endl;
    cout << num.n << endl;
    ----------------------------------------------
    //结构体与共用体集合
    struct widget
    {
        char brand[20];
        int type;
        union id
        {
            long id_num;
            char id_char[20];
        }id_val;
    };
    widget prize;
    ......
    if (prize.type == 1)
        cin >>prize.id_val.id_num;
    else
        cin >> prize.id_val.id_char;
    ----------------------------------------------
    //结构体与共用体(匿名共用体)集合
    struct widget
    {
        char brand[20];
        int type;
        union
        {
            long id_num;
            char id_char[20];
        };
    };
    widget prize;
    ......
    if (prize.type == 1)
        cin >>prize.id_num;
    else
        cin >> prize.id_char;
```

## 4.6 枚举
### 枚举类型:主要定义符号常量，可以用const代替。
```cpp
enum WeekDay{Mon, Tues, Wed, Thur, Fri, Sat, Sun};
          //枚举量，默认值从0开始，然后1；若某个被赋值，之后的+1.
    WeekDay today;
    today1 = Mon;
    today2 = today(2);  
```
### 枚举的取值范围
 + 上限：找到最大值，它的最小的2的幂，再减去1；如最大值100，比它大的最小的2的幂为128，上限为128 - 1 = 127。
 + 下限：找到最小值，若为0，则下限为0；若不为0，采用上限的方式寻找下限。如最小值-10，比它小的最大的2的幂为-16，上限为-16 + 1 = -15。

## 4.7 指针和自由储存空间
### 指针为地址
 + 地址运算符`&` : 应用于变量，来取出变量的地址
 + 解除引用运算符`*` ：应用于指针，来取出指针储存的值
### 声明、初始化
指针声明必须指定指针指向的数据类型。
```cpp
int a = 5;        
int *p_a;       //对指针应用解除引用运算符之前，需将指针指向一个确定、适当的地址。
p_a = &a;
```
### 指针和数字
指针为地址，对其进行加减乘除无意义。
### new/delate运算符
使用规则        
+ 不能使用delete来释放不是new分配的内存[成对使用]
+ 不能使用delete释放同一个内存两次
+ 如果用new[]为数组分配内存，则应使用delete [] 来释放
+ 如果用new为一个实体分配的内存，则应用delete来释放
+ 对空指针使用delete是安全的

### 
+ 数组名、指针数组表示都是地址；其中数组名表示数组的首地址，指针表示指针的首地址
+ 当`sizeof(数组名)`表示整个数组作用的字节数
+ 当`sizeof(指针)`表示指针数组的第一个元素的作用字节数
+ 
