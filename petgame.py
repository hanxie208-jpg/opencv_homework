class Pet:
    #1.对象属性
    def __init__(self, name):
        # 封装（属性）
        self.name = name  #名字
        self.hp = 60  #生命值
        self.mood = 50  #心情值
    #2.行为
    def feed(self):  #（父类默认版本，可被子类重写）
        """你正在喂食哦～！"""
        self.hp += 5
        self.mood += 3
        print(f"{self.name} 还要!你尔多隆吗?HP +5,Mood +3")

    def speak(self): #为了让子类实现多态，这里只是占位
        
        print(f"{self.name} 发出了某种叫声……")

    def status(self):
        """查看状态"""
        print(f"【{self.name} 状态】HP={self.hp}, Mood={self.mood}")


# =======================================
#Cat 类（继承 Pet）
#继承 + 重写 speak（多态）
# =======================================

class Cat(Pet):
    def __init__(self, name):#初始化
        super().__init__(name)
        self.species = "猫猫"

    def speak(self):#行为
        print(f"{self.name}: 阿米嘎蒂朵喵喵～")


# =======================================
# Hamster 类（继承 Pet）
# =======================================

class Hamster(Pet):
    def __init__(self, name):
        super().__init__(name)
        self.species = "仓鼠"

    def speak(self):
        print(f"{self.name}: 过来～(超绝气泡音)")

2
# =======================================
# Goose（鹅妈妈）
# 重写 feed、重写 speak、特殊事件、动作影响属性
# =======================================

class Goose(Pet):
    def __init__(self, name):#初始化
        super().__init__(name)
        self.species = "鹅老第"

    def feed(self):#行为
        #"""鹅妈妈吃东西心情涨很多"""
        self.hp += 2
        self.mood += 10
        print(f"{self.name}: 校车，鼠我也要做你的鼠鬼!（吃得超开心）")

    def speak(self):
        print(f"{self.name}: 咱们好事成双，刷一个比心兔兔～～～")

    def angry(self):
        #"""鹅妈妈生气：HP 降低 + 特殊事件"""
        self.hp -= 20
        print(f"{self.name} 鹅蛋你们都去鼠！HP -20！")

        # 特殊事件：HP 过低报警（多态行为外追加独有功能）
        if self.hp < 40:
            print("鹅mama你鼠啦!(生命值太低，快喂食!)")


# =======================================
# 选择宠物（互动部分）
# =======================================

def choose_pet():
    print("\n请选择你的宠物对象：")
    print("1. 猫猫")
    print("2. 仓鼠")
    print("3. 鹅老弟")
    choice = input("输入序号（1/2/3）：")

    name = input("给你的宠物起一个名字：")

    if choice == "1":
        return Cat(name)
    elif choice == "2":
        return Hamster(name)
    elif choice == "3":
        return Goose(name)
    else:
        print("输入错误，默认选择鹅老弟")
        return Goose(name)


# =======================================
# 游戏循环（完整交互），部分ai矫正
# =======================================

def game_loop(pet):
    print(f"\n你选择了 {pet.species} —— {pet.name}！开始互动吧～")

    while True:
        print("\n============ 菜单 ============")
        print("1. 喂食")
        print("2. 让它叫")
        print("3. 查看状态")
        if isinstance(pet, Goose):   # 特殊功能：鹅妈妈专属，就是这么宠
            print("4. 惹鹅妈妈生气（特殊事件）")
        print("0. 退出互动")
        print("==============================")

        op = input("选择操作： ")

        if op == "1":
            pet.feed()
        elif op == "2":
            pet.speak()
        elif op == "3":
            pet.status()
        elif op == "4" and isinstance(pet, Goose):
            pet.angry()
        elif op == "0":
            print("期待你的下次到来，鹅妈妈永远欢迎你！")
            break
        else:
            print("无效输入，请重新输入。")


# =======================================
# 主程序
# =======================================

if __name__ == "__main__":
    print("===== 欢迎进入赛博宠物互动系统 =====")
    pet = choose_pet()   # 选择宠物对象（实例化）
    game_loop(pet)       # 启动交互系统