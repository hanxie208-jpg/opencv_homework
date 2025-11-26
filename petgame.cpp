#include <iostream>
#include <string>
using namespace std;

// ============================================================
//    父类 Pet
//    封装：将属性 hp、mood、name 封装在类中（private / protected）
//    构造函数
//    多态接口：speak() / feed()（虚函数）
// ============================================================

class Pet 
{
protected:
    string name;   // 封装：名字
    int hp;        // 封装：生命值
    int mood;      // 封装：心情值

public:
    // 构造函数（体现 this 指针）
    Pet(string name)
        : name(name), hp(60), mood(50) 
        {
        // 使用 this 指针区分成员变量
        this->name = name;
    }

    // 虚函数：可供子类重写（多态）
    virtual void feed() 
    {
        hp += 5;
        mood += 3;
        cout << name << " 还要！你尔多隆吗？ HP +5, Mood +3\n";
    }

    // 虚函数：多态接口
    virtual void speak() 
    {
        cout << name << " 发出了一般的叫声……\n";
    }

    // 查看宠物状态
    void status() 
    {
        cout << "【" << name << " 状态】 HP=" << hp << ", Mood=" << mood << endl;
    }

    virtual ~Pet() {}
};

// ============================================================
//    子类 Cat（继承 Pet）
//    继承
//    重写 speak()（多态）
// ============================================================ 

class Cat : public Pet 
{
public:
    Cat(string name) : Pet(name) {}

    void speak() override 
    { // 重写（多态）
        cout << name << ": 阿米嘎蒂朵喵喵～\n";
    }
};

// ============================================================
//    子类 Hamster（继承 Pet）
//    继承
//    重写 speak()
// ============================================================ 

class Hamster : public Pet 
{
public:
    Hamster(string name) : Pet(name) {}

    void speak() override {
        cout << name << ": 过来～（超绝气泡音）\n";
    }
};

// ============================================================
//    子类 Goose（鹅妈妈）
//    重写 feed()
//    重写 speak()
//    特殊事件 angry()
// ============================================================ 

class Goose : public Pet 
{
public:
    Goose(string name) : Pet(name) {}

    // 重写 feed（多态 + 子类特殊规则）
    void feed() override 
    {
        hp += 2;
        mood += 10;
        cout << name << ": 校车！鼠我也要做你的鼠鬼！（吃得超开心）\n";
    }

    // 重写 speak
    void speak() override 
    {
        if (hp < 40) 
        {
            cout << name << "（愤怒）: 鹅mama你鼠啦！！！\n";
        } else 
        {
            cout << name << ": 咱们好事成双，刷一个比心兔兔～\n";
        }
    }

    // 特殊事件：被惹怒
    void angry() 
    {
        hp -= 20;
        cout << name << ": 鹅蛋你们都去鼠！HP -20！\n";

        if (hp < 40) 
        {
            cout << "警告：鹅妈妈 HP 过低！鹅mama你鼠啦！！\n";
        }
    }
};

// ============================================================
//    选择宠物（实例化对象）
// ============================================================ 

Pet* choosePet() 
{
    cout << "\n请选择你的宠物：\n";
    cout << "1. 猫猫\n";
    cout << "2. 仓鼠\n";
    cout << "3. 鹅老弟（鹅妈妈）\n";
    cout << "输入编号（1/2/3）：";

    int choice;
    cin >> choice;

    cout << "给你的宠物起一个名字：";
    string name;
    cin >> name;

    if (choice == 1) return new Cat(name);
    else if (choice == 2) return new Hamster(name);
    else return new Goose(name);
}

// ============================================================
//    游戏交互循环（展示多态 + 封装 + 行为逻辑）
// ============================================================ 

void gameLoop(Pet* pet) 
{
    cout << "\n开始与 " << "你的赛博宠物互动吧！\n";

    while (true) 
    {
        cout << "\n========== 菜单 ==========\n";
        cout << "1. 喂食\n";
        cout << "2. 让它叫\n";
        cout << "3. 查看状态\n";
        cout << "4. 惹它生气（仅鹅mama）\n";
        cout << "0. 退出\n";
        cout << "==========================\n";
        cout << "选择操作： ";

        int op;
        cin >> op;

        if (op == 1) 
        {
            pet->feed();
        }
        else if (op == 2) 
        {
            pet->speak();   // 这里体现多态：pet 指针可能指向 Cat/Hamster/Goose
        }
        else if (op == 3) 
        {
            pet->status();
        }
        else if (op == 4) 
        {
            // dynamic_cast 判断是不是 Goose 子类，这里执指针书写ai纠正
            Goose* g = dynamic_cast<Goose*>(pet);
            if (g) g->angry();
            else cout << "只有鹅老弟能被惹怒哦！\n";
        }
        else if (op == 0) 
        {
            cout << "感谢游玩！你的宠物会想你的～\n";
            break;
        }
        else 
        {
            cout << "无效输入，请重新选择。\n";
        }
    }
}

// ============================================================
//    主程序（程序入口）
// ============================================================ 

int main() 
{
    cout << "==== 赛博宠物系统（C++版） ====\n";

    Pet* pet = choosePet();
    gameLoop(pet);

    delete pet; //重新进入不存档
    return 0;
}
