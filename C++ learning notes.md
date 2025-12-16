# C++ learning notes

[TOC]



## 常用操作

### cin.getline() 

读取整行数据，后传入两个参数，前一个为指向数组的指针，后一个为整型，表示最多读取的数据

```c++
char arr[100];
cin.getline(arr,100)
```

若读取的为一个string类型字符串

```c++
string str;
getline(cin,str);
```



### 数字和字母字符操作

一个字符类型的数字（‘0’--‘9’），减去一个字符类型‘0’，即可得到整型类型该数字

```c++
char a='1';
b=a-'0';
//b为1
```

一个大写字母+32可以得到对应小写字母，同理小写字母-32得到大写字母

```c++
'A' + 32 = 'a'
'a' - 32 = 'A'
```



### pair组合

可以用于两种数据类型的值组成一个新的二元组数据类型，包含在头文件**utility**，部分容器头文件如***vector***、***map***中也包含，须使用namespace std

#### pair的创建与初始化

**直接创建** 

```c++
pair<int, string> p1(1, "apple");
```

**make_pair()函数创建（在涉及赋值时需使用该方法创建）**

```c++
auto p = make_pair(2,"banana");
```

**容器创建定义**

```c++
vector<pair<int,string> > v //注意两个>需要隔开
```

#### pair的访问

通过***.first***和***.second***访问第一/第二个元素

```c++
pair<int, string> p;
p.first = 10;         
p.second = "modify";   
```

#### pair的比较

若不定义cmp，比较时默认**先比较firts再比较second**

#### pair的嵌套

pair的成员类型可以是另一个pair，用于封装更复杂的多元数据

```c++
pair<int, pair<string, int> > student (101, {"Alice", 95});
```



### tolower和toupper函数

将字母全部转化为小/大写，需包含头文件***cctype***

传入参数为**字符**

```c++
char a = 'A';
char lower = tolower(a); // lower = 'a'
char b = 'b'；
char upper = toupper(b); // upper = 'B'
```

对于string数据类型实现全部转化为小/大写操作

```c++
string text = "Hello C++ World!";
transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c) { return tolower(c)/toupper(c); });
```



### 字符串数字和数字的转换

遇到位数较多的数时，可以通过字符串储存来进行操作

#### 数字转字符串

通过***to_string()***函数实现（C++11）   需包含头文件***string***

```c++
int num = 123;
double d = 3.14159;

string s1 = to_string(num); // s1 = "123"
string s2 = to_string(d);   // s2 = "3.141590" (默认保留6位小数)
```

通过流操作***stringstream***实现  需包含头文件***sstream***

```c++
int num = 123;
stringstream ss;
ss << num;       // 将 int 输入流
string s = ss.str(); // 从流中导出 string
```

#### 字符串转数字

通过***sto_()***函数家族实现（C++11）   需包含头文件***string***

最后一位的对应法则相同：

**stoi()**对应 int      **stol()/stoll()**对应 long / long long      **stod()/stof()**对应 double / float

```c++
string s1 = "123";
string s2 = "3.14";

int i = stoi(s1);       // i = 123
double d = stod(s2);    // d = 3.14

// 进制转换功能 (stoi 第二个参数是起始位置，第三个是进制)
string s3 = "1010";
int binary = stoi(s3, 0, 2); // 将二进制 "1010" 转为 int (结果10)
```

通过流操作***stringstream***实现  需包含头文件***sstream***

```c++
string s = "456";
int i;
stringstream ss(s); // 初始化流
ss >> i;            // 输出到 int 变量
```



### C++类型转换

C++ 推荐使用特定的四种转换操作符来替代 C 风格的强制转换 `(int)a`，以提供更高的安全性和可读性。

#### static_cast (静态转换)

**用途**：最常用的转换，用于“良性”和“合理”的转换。**编译时检查**。

- 基本数据类型转换（如 `int` 转 `double`，`enum` 转 `int`）。
- 继承体系中子类指针转父类（向上转型，安全）。
- `void*` 与其他类型指针互转。

```c++
double pi = 3.14;
int num = static_cast<int>(pi); // num = 3

// 向上转型 (Safe)
Derived* d = new Derived();
Base* b = static_cast<Base*>(d);
```

#### dynamic_cast (动态转换)

**用途**：主要用于处理**多态**，即安全的**向下转型**（父类指针转子类指针）。**运行时检查**。

- **前提**：基类必须包含至少一个**虚函数**。
- **行为**：若转换成功返回指针；若失败返回 `nullptr` (对引用失败抛出 `bad_cast` 异常)。

```c++
class Base { virtual void dummy() {} }; 
class Derived : public Base {};

Base* b = new Base;
// 试图将指向父类的指针转为子类，dynamic_cast 会检测出不安全
Derived* d = dynamic_cast<Derived*>(b); 

if (d == nullptr) 
    cout << "转换失败，类型不匹配" << endl;

//正确写法
Base* b = new Derived; 
Derived* d = dynamic_cast<Derived*>(b);
```

#### const_cast (常量转换)

**用途**：用于**去除**指针或引用的 `const` 或 `volatile` 属性。

- 常用于将常量指针传递给只接受非常量参数的旧接口函数。
- **注意**：如果变量本身定义时就是常量，强制去除 const 并修改值会导致**未定义行为**。

```c++
void print(char* str) {} // 旧接口，未加const

const char* c_str = "Hello";
print(const_cast<char*>(c_str)); // 去除 const 属性以通过编译
```

#### reinterpret_cast (重解释转换)

**用途**：**最危险**的转换，直接对内存的二进制位进行重新解释。

- 任意指针之间的转换（如 `int*` 转 `char*`）。
- 指针和整数之间的转换。

```c++
int a = 65;
int* p = &a;
char* c = reinterpret_cast<char*>(p); // 将 int 指针强转为 char 指针
// 此时 *c 的值取决于机器的大小端模式（可能是 'A'）
```



### const关键字

用于定义常量，核心作用是**“承诺不改变”**，能提高代码安全性和编译优化。

#### 基础用法

修饰普通变量，定义时必须初始化，后续不可修改。

```c++
const int MAX_VAL = 100;
// MAX_VAL = 200; // 报错：表达式必须是可修改的左值
```

#### 指针与const (口诀：左定值，右定向)

根据 `const` 在 `*` 号的左边还是右边来区分锁定的是**内容**还是**地址**。

- **`const` 在 `\*` 左边**：**指针指向的内容**不可改 
- **`const` 在 `\*` 右边**：**指针本身**不可改

```c++
int a = 10, b = 20;

// 1. 常量指针 (底层 const)
const int* p1 = &a; 
// *p1 = 30;  // 错误：数据不可改
p1 = &b;      // 正确：指针指向可以改

// 2. 指针常量 (顶层 const)
int* const p2 = &a;
*p2 = 30;     // 正确：数据可以改
// p2 = &b;   // 错误：指针指向不可改

// 3. 双重锁定
const int* const p3 = &a; // 数据和指向都不能改
```

#### 函数参数 (const引用)

工程中最常用。用于防止函数内部修改参数，同时配合**引用**避免大对象拷贝。

- **传值**：`void func(const int i)` 保护局部变量不被修改。
- **传引用**：`void func(const string& s)` **高效且安全**。

```c++
struct Student { string name; int age; };

// 推荐写法：既省去了拷贝构造的开销，又保证了数据安全
void printStudent(const Student& s) {
    // s.age = 20; // 错误：只读引用
    cout << s.name << endl;
}
```

#### 类成员函数 (const修饰函数)

放在参数列表后，表示该函数**不修改成员变量**。

- **位置**：`void func() const {}`
- **原理**：此时 `this` 指针变为 `const ClassName* const`。
- **限制**：`const` 对象只能调用 `const` 成员函数。

```c++
class Circle {
    int r;
public:
    // 只读操作，必须加 const
    int getArea() const {
        return 3.14 * r * r;
    }
    
    // 修改操作，不能加 const
    void setR(int r) {
        this->r = r;
    }
};

const Circle c;
c.getArea(); // 正确
// c.setR(5); // 错误：常量对象不能调用非const成员函数
```



## STL库

### stl容器

#### STL 序列式容器通用知识点

##### 基础准备

- **命名空间**：均需使用 `using namespace std;` 或 `std::` 前缀。
- **头文件**：分别要包括对应头文件或使用 `bits/stdc++.h`。

##### 通用初始化方式

- **默认构造**：`Container<Type> c;` // 空容器
- **填充构造**：`Container<Type> c(n, k);` // 包含 n 个值为 k 的元素
- **列表初始化**：`Container<Type> c = {v1, v2, ...};` (C++11)
- **拷贝构造**：`Container<Type> c2(c1);`
- **迭代器范围构造**：`Container<Type> c2(iter_begin, iter_end);`

##### 通用迭代器（元素指针）

所有序列容器都支持随机访问迭代器（或至少双向迭代器），用法一致：

- `c.begin()` / `c.end()`：返回指向 第一个元素 / 最后一个元素后一位 的正向迭代器。
- `c.rbegin()` / `c.rend()`：返回指向 最后一个元素 / 第一个元素前一位 的反向迭代器（用于逆序遍历）。

##### 通用容器与大小操作

- `c.size()`：返回容器中元素个数（部分可使用`c.length()`）。
- `c.empty()`：判断容器是否为空 (空->true / 非空->false)。
- `c.resize(n, k)`：调整大小为 n。若变大，新增元素用 k 填充；若变小，多余元素被截断。
- `c.clear()`：清空所有元素（size 变为0）。

##### 通用元素访问

- `c[i]`：返回下标 i 处的元素（无越界检查，效率高）。
- `c.at(i)`：返回下标 i 处的元素（有越界检查，越界抛异常）。
- `c.front()`：返回第一个元素。
- `c.back()`：返回最后一个元素。

##### 通用尾部操作

- `c.push_back(k)`：在尾部添加元素 k。
- `c.pop_back()`：删除尾部元素。

##### 通用插入与删除 (基于迭代器)

- `c.insert(pos, k)`：在迭代器 `pos` 处插入元素 k，返回新元素的迭代器。
- `c.erase(pos)`：删除迭代器 `pos` 处的元素，返回下一个元素的迭代器。
- `c.erase(first, last)`：删除迭代器范围 `[first, last)` 内的元素。

------



#### vector动态数组

**核心特点**：内存连续，尾部增删高效，中间增删需要移动数据。

##### 定义与初始化

- **创建格式**：`vector<数据类型> 数组名` e.g. `vector<int> v;`

- **二维数组创建** (难点)：

  ```c++
  // 创建 n 行 n 列的二维数组
  vector<vector<int> > v(n, vector<int>(n));
  ```

##### 独有/特定注意事项

- **Capacity (容量)**：虽然 String 也有，但在 Vector 中更常考查。
  - `v.capacity()`：返回当前分配的内存能容纳多少元素（>= size）。
  - `v.shrink_to_fit()`：释放未使用的内存 (C++11)。
- **底层特性**：
  - Vector 保证元素在内存中是**连续存放**的（兼容 C 语言数组）。
  - 扩容机制通常是 1.5 倍或 2 倍增长，涉及“开辟新空间-复制-释放旧空间”。



#### string字符串

**核心特点**：本质是 `vector<char>` 的封装，但增加了专门处理文本的方法（拼接、查找、转换）。

##### 容器与大小操作

- `s.length()`：等同于 `s.size()`，专门用于字符串的语义。
- `s.capacity()` / `s.shrink_to_fit()`：管理字符缓冲区容量（不包含末尾隐式 '\0'）。

##### 独有元素操作 (文本处理)

**赋值操作**

- `=`：直接赋值字符串字面量。

- `.assign()`：灵活赋值。

  ```c++
  s2.assign("hello world", 5); // s2 = "hello"（取前5个字符）
  s3.assign(3, 'b');           // s3 = "bbb"
  ```

**拼接操作**

- `+` / `+=`：拼接字符串或字符。

- `.append()`：

  ```c++
  s3.append(" world", 0, 5); // 追加下标0-5字符
  s3.append(2, '!');         // 追加2个'!'
  ```

**比较操作**

- 关系运算符 (`<`, `==`, `>`)：按字典序比较。
- `.compare()`：返回 0 (相等)、负数 (小)、正数 (大)。

**基于下标的插入与删除 (String 特有重载)**

不同于通用的迭代器操作，String 支持直接用下标操作：

- `s.insert(index, "str")`：在下标 index 插入字符串。
- `s.erase(index, count)`：从下标 index 开始删除 count 个字符。

**查找与替换**

- **返回值**：`size_t` 类型，若未找到返回 `string::npos`。
- **查找**：
  - `s.find(str, pos)` / `s.rfind(str, pos)`：正向/反向查找。
  - `s.find_first_of(str)` / `s.find_last_of(str)`：查找 str 中**任意字符**在s中出现的位置。
- **替换**：
  - `s.replace(pos, len, "str")`：替换 `[pos, pos+len)` 范围的内容。

**转换为 C 风格字符串**

- `s.c_str()`：返回 `const char*`，以 `\0` 结尾。
- `s.data()`：C++11 后与 `c_str()` 类似。



#### deque双端队列

**核心特点**：分段连续（中控器管理），**头尾**增删都极其高效。

##### 核心结构说明

- 底层采用**分段连续存储结构**（多个大小固定的缓冲区 + 一个中控器 map）。
- 兼顾了 vector 的随机访问和 list 的双端操作特性。

##### 独有/特定元素修改

**头部操作** (Vector 没有的操作)

- `dq.push_front(val)`：在头部插入元素。
- `dq.pop_front()`：删除头部元素。

**原地构造** (C++11 高效操作)

- `dq.emplace_front(args)` / `dq.emplace_back(args)`：直接在容器内构造元素，避免拷贝。

**交换元素**

- `dq.swap(dq2)`：交换两个 deque 的内容（仅交换控制指针，效率极高）。

##### 注意事项与适用场景

- **无 `capacity()`**：因为是分段存储，随时可以挂载新的内存块，不需要像 Vector 那样预留大块连续内存。
- **内存特性**：随机访问效率略低于 Vector（因为要经过中控器计算地址）。
- **迭代器失效**：
  - Deque 在**头/尾**插入时，迭代器**可能**失效（涉及到 map 扩容），但指针/引用通常有效。
  - Vector 在尾部插入若触发扩容，**所有**迭代器/指针/引用均失效。
- **适用场景**：
  - 需要双端进出（如滑动窗口、任务队列）。
  - 元素数量极其巨大，且需要随机访问（Vector 可能找不到那么大的连续内存，Deque 可以分散存储）。



#### list 双向链表

**核心特点**：内存不连续（节点通过指针相连），**任意位置**插入删除极快（$O(1)$），但不支持随机访问（不能用 `[]` 或 `.at()`）。

##### 独有/特定注意事项

- **不支持随机访问**：只能通过迭代器 `it++` 或 `it--` 移动，不能写 `it + 5`。

- 成员函数 sort()：

  list 无法使用全局的 sort（随机访问迭代器设计），必须使用 list 自身的成员函数。

  ```c++
  list<int> L = {4, 1, 3, 9};
  L.sort();             // 默认升序
  L.sort(greater<int>()); // 降序
  ```

- 接合操作 splice()：

  可以将一个 list 的元素直接“剪切”并“接合”到另一个 list 中，不涉及元素拷贝，效率极高。

  ```c++
  list<int> list1 = {1, 2, 3};
  list<int> list2 = {10, 20};
  
  // 将 list2 所有元素移动到 list1 的头部
  list1.splice(list1.begin(), list2); 
  // 此时 list1: {10, 20, 1, 2, 3}, list2 为空
  ```



#### map字典

**核心特点**：底层为**红黑树**，所有元素自动按 **Key** 升序排序。存储 `pair<Key, Value>` 类型。

##### 数据的插入与访问

插入数据

主要有两种方式：使用 pair 插入或使用 []。

```c++
map<string, int> m;
// 1. insert 插入 pair
m.insert(make_pair("Alice", 100));

// 2. 数组下标方式插入 (若 Key 不存在则创建，若存在则修改)
m["Bob"] = 90; 
```

**访问数据与陷阱**

- operator[]：

  `cout << m["Tom"];`

  如果 "Tom" 不存在，map 会自动创建一个 Key 为 "Tom"，Value 为 0 (默认值) 的元素。如果只是想查找，千万不要用 []。

- at()：

  m.at("Tom")：如果不存在会抛出异常。

##### 查找操作

使用 `find(key)` 代替全局算法，效率为 $O(\log N)$。

```c++
auto it = m.find("Alice");
if (it != m.end()) 
    cout << "Found: " << it->first << " Score: " << it->second << endl;
else 
    cout << "Not Found" << endl;
```



#### set集合

**核心特点**：底层为**红黑树**，自动排序，只存 Key（Key 即 Value）。常用于**去重**和**自动排序**。

##### 核心操作

**去重技巧**

将 vector 扔进 set，再倒回来，即可实现去重+排序。

```c++
vector<int> v = {1, 3, 1, 2, 5};
set<int> s(v.begin(), v.end()); // 此时 s: {1, 2, 3, 5}
```

**自定义排序**

默认是从小到大，若需从大到小，需在定义时指定仿函数。

```c++
set<int, greater<int> > s; // 从大到小排序
```

**查找元素**

`s.count(key)`：查找是否有元素key，若有，返回1，没有返回0



### stl算法(头文件*algorithm*)

#### 排序函数sort()

整体升序排序： **sort(起始迭代器,终止迭代器)** （可以实现部分排序，第n个元素为v.begin（）+n）

整体降序排序（需包含头文件***functional***）：**sort(v.begin(), v.end(), greater<int>());**

自定义比较函数排序：**sort(v.begin(), v.end(), cmp);**   cmp为自定义比较函数

**cmp**：自定义元素间的比较规则的二元函数，满足严格弱续（返回值只能为<或>，不能有=）

常用于sort()排序，传入参数通常用const引用，返回值（bool）表示**第一个参数是否应该排在第二个参数前面**

**返回为true：a应该排在b前面；返回为false：a不应该排在b前面**

```c++
//普通函数实现
bool cmp(const int a,const int b) 
{
    return a > b; // 返回一个bool值，代表若a>b，则a排在b前面
}
//lambda表达式实现
sort(students.begin(), students.end(), [](const Student& a, const Student& b)
    {
    return a.score > b.score;
    });
```

也可以用于pair组合或struct的内部成员优先顺序不同的排序

```c++
bool cmp(const pair<string,int>& a,const pair<string,int>& b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    return a.first<b.first;
}//second为第一优先考虑，first为第二优先考虑
```



#### 累加函数accumulate()

需包含头文件***numeric***对容器内所有数据求和，后传入三个参数，第一个为起始元素迭代器，第二个为结束元素迭代器（不包含该元素），第三个为累计的初始值（即开始操作之前的值）

对于第三个参数：

- 传入 `0` $\rightarrow$ 返回 `int`
- 传入 `0LL` $\rightarrow$ 返回 `long long`
- 传入 `0.0` $\rightarrow$ 返回 `double`
- 传入 `string("")` $\rightarrow$ 返回 `string`

ps. 若在三个元素之后再传入一个二元操作函数（有返回值，返回值作为与下一个元素进行二元操作的参数），则可以用此二元操作函数代替默认的累加操作（将前面操作（累加）完成得到的数与下一个数进行的二元操作）

```c++
	vector<int> nums = {1, 2, 3, 4, 5};
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << "整数总和：" << sum << endl; 
```

```c++
struct Student {
    string name;
    int score;
};

int sumScore(int total, const Student& s) {
    return total + s.score; 
}

int main() {
    vector<Student> classA = {
        {"Alice", 80},
        {"Bob", 90},
        {"Tom", 100}
    };

    int totalScore = accumulate(classA.begin(), classA.end(), 0, sumScore);
    return 0;
}
```



#### 转换操作函数transform()

对容器内一定范围数据进行一定操作并储存到另一个位置，后传入四个参数，第一个为起始元素迭代器，第二个为结束元素迭代器，第三个为操作后的结果储存开始的位置的迭代器，第四个为操作函数

```c++
char toLowerChar(unsigned char c) 
{
    return static_cast<char>(tolower(c));
}

int main()
{
    string text = "Hello WORLD!";
    transform(text.begin(), text.end(), text.begin(), toLowerChar);
    cout << text << endl; // 输出: hello world!
    return 0;
}
```



#### 反转函数 reverse()

将容器指定范围内的元素倒序，会直接在原容器上操作。后传入两个参数，分别为操作范围的起始迭代器和终止迭代器。

```c++
string s = "abcdef";
reverse(s.begin(), s.end()); 
// s 变为 "fedcba"
```



#### 查找函数 find() / find_if()

查找容器内满足条件的第一个元素，返回值均为找到的元素的迭代器，若找不到则返回（`end()`），后传入三个参数，前两个都是查找范围的起始迭代器和终止迭代器，对于**find()**，第三个参数是需要查找的值，对于**find_if()**，第三个参数是满足的条件

- `find(begin, end, value)`：找到第一个值为***value***的元素。
- `find_if(begin, end, pred)`：找到第一个满足pred条件的元素。

```c++
vector<int> v = {10, 20, 30, 40};
auto it = find(v.begin(), v.end(), 30);

if (it != v.end()) 
    cout << "找到位置下标: " << it - v.begin() << endl; // 输出 2
else 
    cout << "未找到" << endl;
```

条件查找：提前声明一个bool函数作为条件传入

```c++
bool isGreaterThanFive(int val)
{
    return val > 5;
}

vector<int> v = {1, 3, 4, 6, 8};
auto it = find_if(v.begin(), v.end(), isGreaterThanFive)
```



#### 统计函数 count() / count_if()

统计容器内满足条件的元素个数，返回值均为统计个数，后传入三个参数，耆那两个均为查找范围的其实迭代器和终止迭代器，对于**count()**，第三个参数是需要统计的元素的值，对于**count_if()**，第三个参数是需要统计的元素需要满足的的条件

- `count(begin, end, value)`：统计等于 value 的元素个数。
- `count_if(begin, end, pred)`：统计满足条件 pred 的元素个数。

```c++
vector<int> v = {10, 20, 10, 30};
int n = count(v.begin(), v.end(), 10); // n = 2
```

条件统计：提前声明一个bool函数作为条件传入

```c++
bool isGreaterThanFive(int val)
{
    return val > 5;
}

vector<int> v = {1, 3, 4, 6, 8};
auto it = count_if(v.begin(), v.end(), isGreaterThanFive)
```





## 类和对象

### 类和对象定义和使用

类的本质是**绑定了函数的结构体（一种数据类型）**，它将数据（成员变量）和操作数据的函数（成员函数）封装在一起

通过定义的类来声明创建一个该种数据类型的变量叫做**对象**

定义和使用一个类：

```c++
class Fan
{
    char name[20];
    int age;
    char gender;
    
    /*成员函数会会隐含一个指针this，this指向该对象本身 */
    void setName(char*name)
    {
        /*前一个this->name是指定义的成员变量，后一个name是函数传入的参数*/
        strcpy_s(this->name,name);
    }
}; /*定义完类后面记得写分号*/

int main()
{
    Fan fan1;
    char name[20]="justin";
    fan1.setName(name);
}
```

通过类，实现属性和行为储存在一起



### 构造函数与析构函数

对象的“出生”与“离世”，由系统自动调用，主要负责数据的初始化和内存的清理工作。

#### 构造函数

对象创建时**自动调用**，用于初始化成员变量。

**语法特点**：

- 函数名与**类名相同**。
- **无返回值**（连 `void` 都不写）。
- **可以重载**（可以写多个构造函数，参数不同）。

**两种常用写法**：

1. **普通构造**：在函数体内赋值。
2. **初始化列表**（推荐）：在参数列表后用冒号 `:` 连接，效率更高，且是某些类型（如引用、常量）初始化的唯一方式。

```c++
class Person {
public:
    string name;
    int age;

    // 1. 无参构造（默认构造）
    Person() {
        name = "Unknown";
        age = 0;
    }

    // 2. 有参构造 + 初始化列表语法
    // 语法：构造函数(参数) : 属性1(值), 属性2(值) { ... }
    Person(string n, int a) : name(n), age(a) {
        cout << name << " 出生了！" << endl;
    }
};

int main() {
    Person p1;             // 调用无参构造
    Person p2("Tom", 18);  // 调用有参构造
}
```

#### 析构函数 

对象销毁前（如离开作用域、被 delete）**自动调用**，用于释放内存（堆区资源）、关闭文件等善后工作。

**语法特点**：

- 函数名为 `~类名` （前面加波浪号）。
- **无返回值**，**无参数**。
- 不能重载（一个类只能有一个析构函数）。

```c++
class Person {
public:
    int* data;

    Person() {
        data = new int(10); // 构造时申请堆区内存
    }

    // 析构函数
    ~Person() {
        if (data != nullptr) {
            delete data; // 析构时必须手动释放堆区内存，否则内存泄漏
            data = nullptr;
        }
        cout << "对象被销毁，内存已释放" << endl;
    }
};
```



### 类的三大特性：封装、多态、继承

#### 封装

类中的属性和函数 主要分为三种访问修饰：

- **public** 可以同时在类的内部和外部进行访问
- **private** 仅可以在类的内部进行访问
- **protected** 访问范围介于public和private之间，多用于类的继承

访问修饰的使用原则：**成员属性不对外暴露，成员函数能不暴露就不暴露**

1. 成员属性若要进行访问和修改，通过一个暴露的成员函数来实现
2. 成员函数当且仅当需要外部调用时使用修饰

类的书写规范：

**成员组织规范：先属性后方法，按访问严格程度排序，相同严格程度可以只写一个修饰符**

```c++
class example
{
    private:
    	char name[20];
    	int age;
    	char gender;
    
    protected:
    	char a;
    	int b;
    
    private:
    	void test1()
        {
            
        }
    
    public:
    	void test2()
        {
            
        }
};
```

**文件组织规范**

每创建一个类，都要创造一个与其同名的**头文件**（***.h***结尾）和一个与其同名的**源文件**（***.cpp***结尾）

**头文件**中用于存放类的定义（成员属性和成员函数的声明），并在头部添加相应预编译指令防止重复包含，并去掉所有成员函数的实现部分，以分号结尾

```c++
#pragma once（防止重复包含）

 class example
{
    private:
    	char name[20];
    	int age;
    	char gender;
    
    protected:
    	char a;
    	int b;
    
    private:
    	void test1();
    
    public:
    	void test2();
};
```

**源文件**中引入存放类定义的头文件（用双引号***""***引入），在源文件中声明类成员函数的实现部分，注意成员函数前指明函数所属类(**类名::函数名**)

```c++
#include"头文件名"

private:
	void example::test1
	{
    
	}

public:
	void example::test2
    {
        
    }
```

之后再别的文件中，只需调用**头文件**便可调用类中public函数

#### 继承

类的继承的基本书写规范：**class 子类名（基类）:父类名（派生类）**

子类中便继承了父类所有的成员属性和成员函数，同时子类中可以额外再添加成员属性和成员函数

**类的三种继承方式**

类的继承时，在父类前要写上继承方式（不写默认为private）

**class 子类名（基类）: 继承方式 父类名（派生类）**

- 公有继承**public**：继承权限最高，不改变父类中成员的原有访问权限
- 保护性继承**protected**：父类中的public成员会被改变为protected成员，private成员不变
- 私有继承**private**：所有成员均会改变为private

继承后，父类中**原本的private**成员在子类中无法被访问，但被**改变成private**的成员可以被访问

子类也可以作为父类被继承，**一个子类可以有多个父类**，**各个父类前均要有写继承方式**，中间用逗号隔开

#### 多态

**虚函数**：在定义函数时 函数类型前加上**virtual**，即成为虚函数

在子类中，对该虚函数进行重写，在主函数中调用该函数均会调用子类该函数

若不是虚函数，则只有直接访问子类时才能调用子类该函数，用父类的指针和引用均会调用父类该成员函数

实现多态的条件：

- 父类的成员函数中有虚函数
- 子类是公有继承
- 子类中对虚函数进行了重写
- 主函数中使用父类指针或引用指向子类对象

```c++
class Polygon
{
    public:
    	virtual void state()
        {
            coot<<"多边形"<<endl;
        }
}

class Triangle:public Polygon
{
    public:
    	void draw() override  //override:关键字，明确表示在重写覆盖父类虚函数
        {
            cout<<"三角形"<<endl;
        }
}

class Rectangle:public Polygon
{
    public:
    	void draw() override
        {
            cout<<"长方形"<<endl;
        }
}

int main()
{
    Polygon* p1 = new Polygon();
    Polygon* p2 = new Triangle();
    Polygon* p3 = new Rectangle():
    
    p1->draw();
    p2->draw();
    p3->draw();
}
```

```c++
多边形
三角形
长方形
```

#### 虚析构函数 (配合多态使用)

**痛点**：当使用父类指针指向子类对象时（多态），如果父类析构函数不加 `virtual`，删除父类指针时**只会调用父类的析构函数，不会调用子类的析构函数**，导致子类内存泄漏。

**原则**：**若类可能作为父类被继承，务必将析构函数声明为 `virtual`。**

```c++
class Base {
public:
    // 加上 virtual，确保子类析构函数也会被调用
    virtual ~Base() {
        cout << "Base 析构" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived 析构" << endl;
    }
};

int main() {
    Base* p = new Derived();
    delete p; 
    // 若 Base 析构无 virtual：只输出 "Base 析构" (子类泄漏)
    // 若 Base 析构有 virtual：先输出 "Derived 析构" 再输出 "Base 析构" (安全)
}
```



### 运算符重载

赋予C++标准运算符（如 `+`, `==`, `<<`, `->` 等）对自定义数据类型（类/结构体）进行操作的能力。

**基本语法**：`返回值类型 operator运算符(参数列表) { ... }`

#### 仿指针重载（* / ->）

常用于**智能指针**或**代理模式**，让类对象模仿裸指针的行为。

- **operator\***：返回被管理对象的引用（`Type&`）。
- **operator->**：返回被管理对象的指针（`Type*`）。

```c++
class MySmartPtr {
private:
    Student* ptr;
public:
    MySmartPtr(Student* p) : ptr(p) {}
    ~MySmartPtr() { if(ptr) delete ptr; }

    // 重载 *：解引用，为了能使用 *p
    Student& operator*() {
        return *ptr;
    }

    // 重载 ->：指针指向，为了能使用 p->score
    Student* operator->() {
        return ptr;
    }
};

// 使用
MySmartPtr p(new Student("Alice", 90));
cout << p->name;  // 等价于 p.operator->()->name
cout << (*p).score;
```





## 内存管理

### 堆区内存操作 (new / delete)

C++ 中使用 `new` 和 `delete` 操作符在**堆区** 动态申请和释放内存。相比栈区，堆区空间大，但需要手动管理。

#### 基本语法

**单个对象**

```c++
// 1. 申请内存：在堆区创建一个 Person 对象，调用有参构造
Person* p = new Person("Tom", 18);

// 2. 使用对象：指针访问成员需用 ->
cout << p->name << endl;

// 3. 释放内存：先调用析构函数，再释放堆区空间
delete p; 
// 建议释放后置空，防止野指针
p = nullptr;
```

**数组对象**

```c++
// 申请：创建 10 个 int 数据的数组
int* arr = new int[10];

// 释放：数组释放必须加 []，否则未定义行为
delete[] arr;
```

#### new/delete 与 malloc/free 的区别

| **特性**     | **new / delete**          | **malloc / free**           |
| ------------ | ------------------------- | --------------------------- |
| **属性**     | C++ 关键字/操作符         | C 语言库函数                |
| **核心区别** | **自动调用构造/析构函数** | **不调用**，仅分配/释放内存 |
| **返回值**   | 具体类型指针 (如 `int*`)  | `void*` (需强制转换)        |
| **安全性**   | 失败抛出异常              | 失败返回 NULL               |

#### 常见误区与注意事项

- **内存泄漏**：`new` 出的对象如果没有 `delete`，在程序运行期间会一直占用内存。
- **配对使用**：`new` 对应 `delete`，`new[]` 对应 `delete[]`。
- **不要混用**：不要用 `malloc` 创建对象再用 `delete` 释放，因为构造函数未执行，但析构函数被强制执行，逻辑会出错。



### 深拷贝与浅拷贝

**核心场景**：当类中有成员变量是**指针**，且在构造函数中使用了 `new` 申请堆区内存时，必须手动处理拷贝逻辑。

#### 浅拷贝
这是编译器的**默认行为**。编译器提供的默认拷贝构造函数，只会进行简单的**值拷贝**。
- 对于指针成员，它只复制指针的**地址值**。
- **致命后果**：两个对象的指针指向了堆区的**同一块内存**。当其中一个对象析构释放内存后，另一个对象再析构时会尝试释放已经被释放的内存，导致程序崩溃（Double Free）。

#### 深拷贝
需要程序员**自定义拷贝构造函数**。
- 在拷贝时，不只复制地址，而是**重新 `new` 一块内存**，并将原有数据复制到新内存中。
- **结果**：两个对象的指针指向不同的内存地址，但存储的数据相同。各自析构，互不影响。

#### 代码对比

```c++
class Person {
public:
    int* age; // 指针成员变量

    // 构造函数
    Person(int a) {
        age = new int(a); // 堆区申请内存
    }

    // 析构函数
    ~Person() {
        if (age != nullptr) {
            delete age;
            age = nullptr;
        }
    }

    // 【关键】自定义拷贝构造函数（实现深拷贝）
    Person(const Person& p) {
        // 1. 错误写法（浅拷贝）：
        // age = p.age; 
        // 这样会导致两个对象指向同一块堆区内存

        // 2. 正确写法（深拷贝）：
        age = new int(*p.age); // 重新申请一块内存
        // *p.age 是解引用，获取原本的数据值
    }
};

int main() {
    Person p1(18);
    Person p2(p1); // 调用拷贝构造函数
    
    // 如果是浅拷贝：p1析构释放一次，p2析构又释放同一块内存 -> 崩溃
    // 如果是深拷贝：p1释放地址A，p2释放地址B -> 安全
    return 0;
}
```

#### The Rule of Three (三法则)

如果你需要显式定义一个**析构函数**（通常是因为需要释放内存），那么你几乎肯定也需要显式定义**拷贝构造函数**和**拷贝赋值运算符**（operator=）。





## C++11 以后的核心特性

### auto 关键字

**核心特点**：让编译器在编译期根据初始值自动推导变量类型。主要用于简化长类型名（如迭代器）的书写。

#### 基础用法

必须初始化，否则无法推导。

```c++
auto a = 10;        // a 为 int
auto b = 3.14;      // b 为 double
auto ptr = &a;      // ptr 为 int*
```

#### 简化迭代器书写

这是 `auto` 最常用的场景，替代冗长的 STL 迭代器类型。

```c++
vector<string> v;
// 原写法：vector<string>::iterator it = v.begin();
auto it = v.begin(); 
```

#### 范围 for 循环 (Range-based for loop)

配合 `auto` 遍历容器更加便捷。

```c++
vector<int> nums = {1, 2, 3};

// 拷贝遍历（无法修改原容器）
for(auto n : nums) {
    cout << n << endl;
}

// 引用遍历（推荐，可修改原容器，避免拷贝）
for(auto& n : nums) {
    n++; 
}
```

#### 注意事项

- **引用和 const 的丢失**：`auto` 默认推导的是值类型，会忽略顶层 `const` 和引用 `&`。
  - 若需要引用：`auto&`
  - 若需要不可改引用：`const auto&`

```c++
int x = 0;
int& y = x;

auto z = y; // z 是 int (引用被忽略，发生了拷贝)
z = 10;     // 修改 z 不影响 x

auto& w = y; // w 是 int& (保留引用)
w = 10;      // 修改 w 同时修改了 x
```

------

### 智能指针 (Smart Pointers)

**核心特点**：RAII（资源获取即初始化）思想的体现。封装了原始指针，**自动管理内存释放**，杜绝内存泄漏。需包含头文件 ***memory\***。

#### unique_ptr (独占指针)

**特点**：同一时刻只能有一个指针指向该对象，**禁止拷贝**，只允许移动（move）。

```c++
// 创建：推荐使用 make_unique (C++14)
unique_ptr<int> p1 = make_unique<int>(10);

// unique_ptr<int> p2 = p1; // 报错：禁止拷贝
unique_ptr<int> p2 = move(p1); // 正确：所有权转移，p1 变为空
```

#### shared_ptr (共享指针)

**特点**：多个指针可以指向同一个对象。内部维护一个**引用计数**，每多一个指针指向计数+1，析构一次计数-1，计数为0时释放内存。

```c++
// 创建：推荐使用 make_shared
shared_ptr<int> p1 = make_shared<int>(100);
cout << p1.use_count(); // 计数: 1

{
    shared_ptr<int> p2 = p1; // 共享所有权
    cout << p1.use_count(); // 计数: 2
} // 离开作用域，p2 析构，计数-1

cout << p1.use_count(); // 计数: 1
```

#### weak_ptr (弱指针)

**特点**：辅助 `shared_ptr` 工作，只观测不拥有，**不增加引用计数**。

**用途**：主要用于解决 `shared_ptr` 的**循环引用**（Circular Reference）导致内存无法释放的问题（即 A 指向 B，B 指向 A，计数永不为 0）。

```c++
shared_ptr<int> sp = make_shared<int>(10);
weak_ptr<int> wp = sp; // 不增加计数

// 使用时需先检查是否有效，并转化为 shared_ptr
if (auto locked_sp = wp.lock()) { // lock() 返回一个 shared_ptr
    cout << *locked_sp << endl;
}
```

------

### Lambda 表达式

**核心特点**：匿名函数对象，常用于编写临时的、局部的回调函数，特别是在 STL 算法（如 `sort`, `for_each`）中。

#### 语法格式

```
[捕获列表](参数列表) -> 返回值类型 { 函数体 }
```

- **参数列表**、**返回值类型** 可以省略（若编译器能推导）。

#### 捕获列表 (Capture List)

决定了 Lambda 内部如何访问外部的局部变量。

- `[]`：不捕获任何外部变量。
- `[=]`：**按值捕获**所有外部变量（只读，无法修改）。
- `[&]`：**按引用捕获**所有外部变量（可读写，需注意生命周期）。
- `[this]`：捕获当前类对象的 `this` 指针。
- `[x, &y]`：混合模式，x 按值，y 按引用。

#### 实战演练

**配合 sort 使用**

```c++
struct Student { string name; int score; };
vector<Student> classA = { {"Tom", 60}, {"Jerry", 90} };

// 按成绩降序排序
sort(classA.begin(), classA.end(), [](const Student& a, const Student& b) {
    return a.score > b.score;
});
```

**按值捕获 vs 按引用捕获**

```c++
int a = 10;
// 按值捕获 (mutable 允许在 lambda 内部修改拷贝的值，不影响外部)
auto f1 = [a]() mutable { 
    a++; 
    cout << a; // 输出 11
};
f1();
cout << a; // 输出 10 (外部未变)

// 按引用捕获
auto f2 = [&a]() {
    a++;
};
f2();
cout << a; // 输出 11 (外部被修改)
```

------

### 函数包装器 (std::function)

**核心特点**：通用多态函数封装器。它可以存储、复制和调用任何**可调用对象**（普通函数、Lambda、函数指针、仿函数）。需包含头文件 ***functional\***。

#### 定义语法

```c++
function<返回值类型(参数类型1, 参数类型2...)> 变量名
```

#### 基础用法

统一不同类型的可调用对象，常用于**回调函数**的设计。

```c++
#include <functional>

// 1. 普通函数
int add(int a, int b) { return a + b; }

// 2. 函数对象 (仿函数)
struct Minus 
{
    int operator()(int a, int b) { return a - b; }
};

int main() 
{
    // 包装普通函数
    function<int(int, int)> func1 = add;
    
    // 包装 Lambda
    function<int(int, int)> func2 = [](int a, int b) { return a * b; };
    
    // 包装仿函数
    function<int(int, int)> func3 = Minus();

    cout << func1(10, 5) << endl; // 15
    cout << func2(10, 5) << endl; // 50
    cout << func3(10, 5) << endl; // 5
}
```



## 常见头文件

### 头文件***cstring*** (操作C风格字符串)

**strlen()** 计算字符串有效长度，后传入一个字符串

```c++
char str[] = "hello";
cout << strlen(str);  // 输出 5（'h'到'o'共5个字符）
```

**strcpy()** 字符串复制，后传入两个字符串，前一个为接受，后一个为被复制（注意接受字符串足够长）

```c++
char dest[20];
char src[] = "world";
strcpy(dest, src);  // dest 变为 "world"（包含'\0'）
```

**strncpy()** 字符串指定长度复制，后传入两个字符串和一个int长度n，前一个为被接受，后一个为被复制，复制前n个字符

```c++
char dest[5];
char src[] = "hello";
strncpy(dest, src, 4);  // 复制前4个字符：'h','e','l','l'
dest[4] = '\0';  // 手动补'\0'，否则可能不是有效字符串
```

**strcat()** 连接字符串，后传入两个字符串，将后一个合并到前一个中，新字符串为前一个

```c++
char dest[20] = "hello";
char src[] = "world";
strcat(dest, src);  // dest 变为 "helloworld"
```

**strancat()** 字符串指定长度连接，后传入两个字符串和一个int长度n，将后一个的前n个字符合并到前一个中

```c++
char dest[20] = "hello";
char src[] = "world";
strncat(dest, src, 3);  // 追加前3个字符，dest变为"hellowor"
```

**strcmp()** 字符串比较，按ASCII码值逐一比较，直到遇到不同字符或 `'\0'`，后传入两个字符串，

**返回值**：

- 正数：`str1` 大于 `str2`（第一个不同字符的 ASCII 差）；
- 0：`str1` 与 `str2` 相等；
- 负数：`str1` 小于 `str2`。

```c++
cout << strcmp("apple", "banana");  // 负数（'a' < 'b'）
cout << strcmp("cat", "cat");       // 0（相等）
```

**strncmp()**指定长度字符串比较，后传入两个字符串和一个int长度n，比较前n个字符

```c++
strncmp("hello", "helloworld", 5);  // 0（前5个字符相同）
```

**strchr()** 字符查找，后传入一个字符串和一个字符，查找该字符在字符串中第一个出现的位置

**返回**：返回指向该字符的指针；若未找到，返回 `NULL`。

```c++
char str[] = "hello";
char* p = strchr(str, 'l');  // p 指向第一个 'l'（索引2）
```

**strrchr() ** 字符查找，后传入一个字符串和一个字符，查找该字符在字符串中最后一个出现的位置

```c++
char str[] = "hello";
char* p = strrchr(str, 'l');  // p 指向第二个 'l'（索引3）
```

**strstr()** 子串查找，后传入两个字符串，前一个为主串，后一个为子串，查找子串在字符串中第一次出现的位置

```c++
char str[] = "abcdeabc";
char* p = strstr(str, "bc");  // p 指向索引1（"bcdeabc"的起始）
```





### 头文件***cmath*** (常用数学函数)

tips：**cmath头文件中，输出基本均为浮点数，使用时需注意精度**

**sqrt()** 计算平方根

```c++
cout << sqrt(16);  // 输出 4.0
```

**pow()** 计算幂

```c++
cout << pow(2, 3);  // 输出 8.0（2的3次方）
```

**abs() / fabs()** 计算绝对值（整数/浮点数）

```c++
cout << abs(-10);   // 输出 10
cout << fabs(-3.5); // 输出 3.5
```

**round() / ceil() / floor()** 取整函数

```c++
cout << round(3.7); // 4.0（四舍五入）
cout << ceil(3.2);  // 4.0（向上取整）
cout << floor(3.9); // 3.0（向下取整）
```

**sin() / cos() / tan()** 三角函数（参数为弧度）

```c++
cout << sin(M_PI/2);  // 约1.0
cout << cos(M_PI/2); 
cout << tan(M_PI/2);
```

---





### 头文件***cstdlib*** (标准库函数)

**rand()** 生成随机数（0到RAND_MAX之间）
```c++
srand(time(0)); // 设置种子
cout << rand() % 100; // 生成0-99的随机数
```

**abs()** 整数绝对值

```c++
cout << abs(-42); // 输出42
```

**atoi() / atof()** 字符串转数值

```c++
cout << atoi("123");  // 输出123（字符串转整数）
cout << atof("3.14"); // 输出3.14（字符串转浮点数）
```

**exit()** 退出程序
```c++
exit(0); // 正常退出
exit(1); // 异常退出
```

**system()** 执行系统命令
```c++
system("cls"); // Windows清屏
system("clear"); // Linux/Mac清屏
```



## 工程构建 (CMake)

CMake 是一个跨平台的自动化构建系统，通过 `CMakeLists.txt` 文件生成标准的构建文件

### 基础构建流程 

为了保持源码目录整洁，推荐在独立的 build 文件夹中进行编译（**外部构建**）。

**操作步骤：**

1.  在项目根目录下新建 build 文件夹：`mkdir build`
2.  进入该文件夹：`cd build`
3.  生成构建文件（指向上级目录）：`cmake ..`
4.  编译可执行文件：`make` 

### CMakeLists.txt 核心指令

文件名必须严格区分大小写，且必须命名为 **CMakeLists.txt**。

#### 1. 基础三件套

一个最简项目的必备指令。

```cmake
# 1. 指定 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 2. 定义项目名称
project(MyProject)

# 3. 生成可执行文件
# 语法：add_executable(程序名 源文件1 源文件2 ...)
add_executable(App main.cpp)
```

#### 2. 配置 C++ 标准

指定编译器使用 C++11, C++17 等标准，通常写在 `project` 指令下方。

```cmake
# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
# 强制要求标准（非必须，但推荐）
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

### 多文件与自动化管理

当源文件较多时，手动罗列文件名效率太低，可使用变量和搜索指令。

#### 自动搜索源文件

使用 `aux_source_directory` 扫描指定目录下的所有源文件。

```cmake
# 语法：aux_source_directory(目录路径 变量名)
# 扫描当前目录(.)下的所有源文件，并将列表存储在变量 SRC_LIST 中
aux_source_directory(. SRC_LIST)

# 使用变量生成可执行文件 (取变量值需加 ${})
add_executable(App ${SRC_LIST})
```

### 库的操作

用于将代码封装为库文件，或链接第三方库。

#### 生成静态库

将源文件编译为 `.lib` (Windows) 或 `.a` (Linux) 静态库，而不是可执行程序。

```cmake
# 语法：add_library(库名 STATIC 源文件)
add_library(MathLib STATIC math_func.cpp)
```

#### 链接库文件

将库（Library）“挂载”到主程序（Executable）上。

```cmake
# 1. 生成库
add_library(MathLib STATIC math_func.cpp)

# 2. 生成主程序
add_executable(App main.cpp)

# 3. 链接：告诉 App 需要使用 MathLib
# 语法：target_link_libraries(目标 权限 库名)
target_link_libraries(App PUBLIC MathLib)
```
