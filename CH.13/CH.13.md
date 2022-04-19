# 类继承
## 13.1 基类
### 创建类继承
```cpp
    //class 继承类类名： public 基类类名
    class RatedPlayer: public TableTennisPlayer
    {

    };
```
### 类的定义
```cpp
    //类名::方法名(参数列表):基类(参数列表)
    RatedPlayer::RatedPlayer(const int r, const TableTennisPlayer &tp): TableTennisPlayer(tp)
    {
        rating = r;
    }
```
### 访问基类成员