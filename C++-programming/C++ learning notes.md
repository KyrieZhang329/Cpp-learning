# C++ learning notes

[TOC]



## 常用操作

### cin.getline() 

读取整行数据，后传入两个参数，前一个为指向数组的指针，后一个为整型，表示最多读取的数据

```c++
char arr[100];
cin.getline(arr,100)
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



### tolower函数

将字母全部转化为小写，需包含头文件***cctype***

传入参数为**字符**

```c++
char a = 'A';
char lower = tolower(a); // lower = 'a'
```

对于string数据类型实现全部转化为小写操作

```c++
string text = "Hello C++ World!";
transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c) { return std::tolower(c); });
```







## STL库

### stl容器

#### vector动态数组

##### 基础准备

使用vector时要包含头文件***vector***，并使用namespace std；

##### 定义与初始化

创建格式：**vector<数据类型> 数组名**    e.g. vector<int> v;

初始化：**vector<int> v(n,k)**  创建一个长度为n的vector，每个元素值为k

同时vector也可以用类似arr的{}初始化（C++11），以及复制初始化（在v后的括号内输入一个vector数组名）

迭代器初始化：用另一个容器来初始化vector

```c++
int arr[] = {10,20,30,40};
vector<int> v16(arr, arr+4);
```

vector二维数组创建

```c++
vector<vector<int>> v(n, vector<int>(n));
```

##### 容器与大小操作

**v.size()**  返回v中元素个数

**v.empty()**  返回v是否为空 (空->true/非空->false) 

**v.resize(n,k)** 调整大小为n，有多余元素则截断，不足则以k补齐

##### 元素访问

**v[i]/v.at(i)** 均返回i处的元素，前一个无越界检查，后一个有越界检查

**v.front()/v.back()** 返回第一个/最后一个元素

##### 元素修改

**v.push_back(k)** 在尾部添加元素k

**v.pop_back()** 删除尾部元素

**v.erase(pos)** 删除迭代器pos处的元素，返回下一个元素迭代器，后面元素依次前移

##### 迭代器（元素指针）

**v.begin()** 返回指向第一个元素的迭代器

**v.end()**  返回指向最后一个元素后一位的迭代器

**v.rbegin()**  返回指向最后一个元素的反向迭代器（逆序遍历起点）

**v.rend()**  返回指向第一个元素前一位的反向迭代器（逆序遍历终点）



#### string字符串

**string本质**：**动态字符数组**的封装，储存了字符串长度、容量等信息，自动处理内存

##### 基础准备

使用vector时要包含头文件***string***，并使用namespace std；

##### 定义与初始化

创建格式：**string 字符串名** 

初始化：**string s("hello")**

string也可以使用vector类似的（n,k）初始化，也可以复制初始化

容器与大小操作

**s.size()/s.length()** 返回字符串的字符数

**s.empty()**  返回v是否为空 (空->true/非空->false) 

**s.resize(n,k)** 调整大小为n，有多余元素则截断，不足则以k补齐

**s.capacity()**  返回当前缓冲区的容量（可存储的字符数，不包括末尾的 '\0'）

**s.shrink_to_fit()**  释放多余容量，使 capacity () 等于 size ()

##### 元素访问

**s[i]/s.at(i)** 均返回i处的元素，前一个无越界检查，后一个有越界检查

##### 迭代器（元素指针）

**s.begin()** 返回指向第一个元素的迭代器

**s.end()**  返回指向最后一个元素后一位的迭代器

**s.rbegin()**  返回指向最后一个元素的反向迭代器（逆序遍历起点）

**s.rend()**  返回指向第一个元素前一位的反向迭代器（逆序遍历终点）

##### 元素操作

赋值操作：**=** 或 ***.assign()***   等号直接赋值，.assign()方法灵活赋值

```c++
string s1; 
s1 = "hello"; //s1 = "hello"
string s2,s3;
s2.assign("hello world", 5); // s2 = "hello"（取前5个字符）
s3.assign(3, 'b');           // s3 = "bbb"（3个'b'）
```

拼接操作：**+** 或 **+=** 或 ***.append()***  +拼接两字符串为一个新字符串，+=操作后返回原本字符串 .append()灵活追加

```c++
string s1("hello"),s2("world"),s3("hello");
string s5 = s1 + " " + s2;//s5 = "hello world"
s1 += " world!" //s1 = "hello world!"
    
s3.append(" world", 0, 5); // s = "hello world"（追加下标0-5字符）
s3.append(2, '!');         // s = "hello world!!"
```

比较操作：关系运算符 按**字典序**比较 或***.compare()*** 方法

```c++
string s1("apple"), s2("banana");
bool b1 = (s1 < s2);  // true（apple字典序小于banana）
bool b2 = (s1 == "apple"); // true

int res = s1.compare(s2)
//返回0： 相等；返回负数，当前字符串更小；返回正数，当前字符串更大
```

插入与删除  ***.insert()*** 与 ***.erase()***

```c++
string s1("hello");
s1.insert(5, " world"); // 在下标5插入 → s = "hello world"
s1.insert(0, 2, '!');   // 在开头插入2个'!' → s = "!!hello world"

string s("hello world");
s.erase(5);        // 删除从下标5开始的所有字符 → s = "hello"
s.erase(1, 2);     // 删除从下标1开始的2个字符 → s = "hlo"
```

查找与替换

```c++
//查找返回数据类型为“size_t”的下标
size_t p=s.find(str, pos);	//从 pos 开始查找 str 第一次出现的位置
size_t p=s.rfind(str, pos);	//从 pos 开始反向查找 str 最后一次出现的位置
size_t p=s.find_first_of(str);	//查找 str 中任意字符第一次出现的位置
size_t p=s.find_last_of(str);	//查找 str 中任意字符最后一次出现的位置

//返回是否找到
if (pos != string::npos) 
        cout << pos;
    else
        cout << -1;
```

```c++
s.replace(0, 5, "hi"); // 替换[0,5)范围为"hi" → s = "hi world"
```

**转换为C风格字符串**    ***c_str()*** 或 ***data()***

```c++
string s("hello");
const char* cstr = s.c_str(); // cstr = "hello\0"
const char* cstr1 = s.data()
printf("%s %s\n", cstr,cstr1); // 输出hello hello
```



#### deque双端队列

deque（Double-Ended Queue）是 C++ STL 中的**双端队列容器**，底层采用**分段连续存储结构**（由中控器管理多个大小固定的连续内存块），兼顾了`vector`的随机访问特性和`list`的双端高效增删特性。它支持在**头部和尾部**快速插入 / 删除元素，也支持**随机访问**，是一种灵活的序列容器。

##### 基础准备

使用 deque 需包含头文件`<deque>`，并使用`std`命名空间：

##### 定义与初始化

deque 的定义格式为`deque<数据类型> 容器名`，支持多种初始化方式：

| 初始化方式        | 示例                                    | 说明                                   |
| ----------------- | --------------------------------------- | -------------------------------------- |
| 空 deque          | `deque<int> dq;`                        | 创建空的 int 类型双端队列              |
| 指定长度 + 初始值 | `deque<int> dq(5, 10);`                 | 创建长度为 5 的 deque，每个元素值为 10 |
| 初始化列表初始化  | `deque<int> dq{1, 2, 3, 4, 5};`         | 用列表元素初始化（C++11 及以上）       |
| 迭代器范围初始化  | `deque<int> dq2(dq.begin(), dq.end());` | 用另一个 deque 的迭代器范围初始化      |

##### 容器与大小操作

| 函数              | 功能描述                                                     |
| ----------------- | ------------------------------------------------------------ |
| `size()`          | 返回 deque 中当前元素的个数                                  |
| `empty()`         | 判断 deque 是否为空（空返回`true`，非空返回`false`）         |
| `resize(n, val)`  | 调整大小为`n`，新增元素用`val`填充                           |
| `max_size()`      | 返回 deque 理论上可容纳的最大元素个数（受系统内存限制）      |
| `shrink_to_fit()` | 释放未使用的内存空间，使容器容量适配当前元素个数（C++11 及以上） |

##### 元素访问

deque 支持随机访问和两端元素直接访问，具体方式如下：

| 访问方式     | 功能描述                                                     |
| ------------ | ------------------------------------------------------------ |
| `dq[i]`      | 访问下标`i`的元素（无越界检查，越界行为未定义）              |
| `dq.at(i)`   | 访问下标`i`的元素（有越界检查，越界抛出`std::out_of_range`异常） |
| `dq.front()` | 返回第一个元素的引用（可修改，需非 const 容器）              |
| `dq.back()`  | 返回最后一个元素的引用（可修改，需非 const 容器）            |

##### 迭代器（元素指针）

deque 提供**随机访问迭代器**（与`vector`相同，支持`++`/`--`/`+n`/`-n`等操作），可用于遍历、插入、删除等操作：

| 迭代器类型                  | 功能描述                                   |
| --------------------------- | ------------------------------------------ |
| `dq.begin()`                | 返回指向第一个元素的正向迭代器             |
| `dq.end()`                  | 返回指向最后一个元素**后一位**的正向迭代器 |
| `dq.rbegin()`               | 返回指向最后一个元素的反向迭代器           |
| `dq.rend()`                 | 返回指向第一个元素**前一位**的反向迭代器   |
| `dq.cbegin()`/`dq.cend()`   | 常量正向迭代器（不可修改元素）             |
| `dq.crbegin()`/`dq.crend()` | 常量反向迭代器（不可修改元素）             |

##### 元素修改

deque 支持双端插入 / 删除、中间插入 / 删除等操作，具体如下：

**插入元素**

| 插入方式              | 功能描述                                               |
| --------------------- | ------------------------------------------------------ |
| `push_front(val)`     | 在 deque 头部插入元素`val`                             |
| `push_back(val)`      | 在 deque 尾部插入元素`val`                             |
| `emplace_front(args)` | 头部原地构造元素（避免拷贝，效率更高，C++11 及以上）   |
| `emplace_back(args)`  | 尾部原地构造元素（避免拷贝，效率更高，C++11 及以上）   |
| `insert(pos, val)`    | 在迭代器`pos`位置插入元素`val`，返回指向新元素的迭代器 |
| `insert(pos, n, val)` | 在`pos`位置插入`n`个`val`                              |

**删除元素**

| 删除方式             | 功能描述                                                     |
| -------------------- | ------------------------------------------------------------ |
| `pop_front()`        | 删除 deque 头部元素（无返回值）                              |
| `pop_back()`         | 删除 deque 尾部元素（无返回值）                              |
| `erase(pos)`         | 删除迭代器`pos`位置的元素，返回指向删除位置下一个元素的迭代器 |
| `erase(first, last)` | 删除迭代器范围`[first, last)`内的元素，返回指向最后一个删除元素下一位的迭代器 |
| `clear()`            | 清空 deque 所有元素，大小变为 0                              |

**交换元素**

`swap(dq)`：交换当前 deque 与另一个 deque`dq`的内容（底层仅交换中控器指针，效率极高）。

```cpp
#include <iostream>
#include <deque>

int main() {
    deque<int> dq1{1,2,3}, dq2{4,5,6};
    dq1.swap(dq2);
    return 0;
}
```

##### 注意事项

1. **内存结构特性**：deque 的分段存储导致其**随机访问效率略低于 vector**（需通过中控器定位内存块），但**双端增删效率远高于 vector**（无需移动大量元素）；
2. **迭代器稳定性**：deque 在头部 / 尾部插入元素时，原有迭代器**可能失效**（因内存块扩容），而`vector`仅在尾部插入时迭代器可能失效；
3. **无容量概念**：deque 没有`capacity()`函数（分段存储无需预分配连续内存），`shrink_to_fit()`仅用于释放未使用的内存块；
4. **不能替代 vector/list**：需频繁随机访问选`vector`，需频繁中间插入 / 删除选`list`，需双端操作 + 偶尔随机访问选`deque`。

##### 适用场景

- 需要**双端快速增删**的场景（如滑动窗口算法、双端队列模拟、任务队列的头尾操作）；
- 需要**随机访问**且偶尔在头部增删元素的场景（如实现循环队列）；
- 需避免`vector`头部插入时的高开销（`vector`头部插入需移动所有元素）





### stl算法

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

对容器内所有数据求和，使用时需包含头文件***numeric***和使用std namespace，后传入三个参数，第一个为起始元素迭代器，第二个为结束元素迭代器（不包含该元素），第三个为累计的初始值（即开始操作之前的值）

ps. 若在三个元素之后再传入一个二元操作函数，则可以用此二元操作函数代替默认的累加操作（将前面操作（累加）完成得到的数与下一个数进行二元操作）

```c++
	vector<int> nums = {1, 2, 3, 4, 5};
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << "整数总和：" << sum << endl; 
```

```c++
	vector<int> nums = {1, 2, 3, 4};
    int product = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
    cout << "乘积：" << product << endl; // 1*2*3*4 = 24
```



#### 转换操作函数transform()

对容器内一定范围数据进行一定操作并储存到另一个位置，使用时需包含头文件***algorithm***和使用std namespace，后传入四个参数，第一个为起始元素迭代器，第二个为结束元素迭代器，第三个为操作后的结果储存开始的位置的迭代器，第四个为操作函数

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
#pragma once

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
    	void draw()
        {
            cout<<"三角形"<<endl;
        }
}

class Rectangle:public Polygon
{
    public:
    	void draw()
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



