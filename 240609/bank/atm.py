from user import User
from card import Card
import random

class ATM:
    def __init__(self, all_user):
        self.all_user = all_user

    # ---
    def random_card_id(self):
        while True:
            card_id = ''
            for i in range(6):
                card_id += str(random.randint(0, 9))
            if card_id not in self.all_user:
                return card_id
    
    def check_flexible_pwd(self, pwd):
        # 1. 长度6-8
        if len(pwd) < 6 or len(pwd) > 8:
            print('密码长度必须在6-8位之间')
            return -1
        # 2. 不能全是数字
        if pwd.isdigit():
            print('密码不能全是数字')
            return -1
        # 3. 不能全是字母
        if pwd.isalpha():
            print('密码不能全是字母')
            return -1
        # 4. 不能全是特殊字符
        notalnum = 0
        for x in pwd:
            if not x.isalnum():
                notalnum += 1
        if notalnum == len(pwd):
            print('密码不能全是特殊字符')
            return -1
        # 5. 不能有空格
        if ' ' in pwd:
            print('密码不能有空格')
            return -1
        # 6. 不能有中文
        for c in pwd:
            if '\u4e00' <= c <= '\u9fa5':
                print('密码不能有中文')
                return -1
        # 7. 不能连续，正序或者倒序
        for i in range(len(pwd) - 1):
            if ord(pwd[i]) + 1 == ord(pwd[i + 1]) or ord(pwd[i]) - 1 == ord(pwd[i + 1]):
                print('密码不能连续，正序或者倒序')
                return -1
        return 0
    
    # 1
    def create_user(self):
        name = input('请输入姓名：')
        id = input('请输入身份证号：')
        phone = input('请输入电话号码：')
        money = float(input('请输入预存金额：'))
        if money <= 0:
            print('预存金额必须大于0')
            return -1
        
        while True:
            once_pwd = input('请输入密码：')
            if self.check_flexible_pwd(once_pwd) == -1:
                print('密码不符合要求')
                continue
            break

        password = input('请再次输入密码：')
        if once_pwd != password:
            print('两次密码不一致')
            return -1
        print(f"密码设置成功，请牢记密码：{password}")
        card_id = self.random_card_id()

        card = Card(card_id, password, money)  # 创建卡对象
        user = User(name, id, phone, card)     # 创建用户对象
        self.all_user[card_id] = user          # 存储用户信息
        print(f'开户成功，您的卡号为：{card_id}')

    # ---
    def check_pwd(self, real_pwd):
        for i in range(3):
            pwd = input(f'请输入密码第{i+1}次，3次错误将锁卡：')
            if real_pwd == pwd:
                return True
        print('密码错误3次, 系统自动退出...')
        return False
    
    # 2
    def search_user(self, base = 1):
        if base == 1:
            input_id = input('请输入您的卡号：')
        elif base == 2:
            input_id = input('请输入转出卡号：')
        elif base == 3:
            input_id = input('请输入转入卡号：')

        user = self.all_user.get(input_id)
        if not user:
            print('卡号不存在')
            return -1
        if user.card.card_lock:
            print('卡号已锁定...')
            return -1
        if not self.check_pwd(user.card.card_pwd):
            print('密码错误...卡号已锁定...')
            user.card.card_lock = True
            return -1
        if base != 3:
            print(f'姓名：{user.name}，身份证号：{user.id}，电话号码：{user.phone}，卡号：{user.card.card_id}，余额：{user.card.money}')
        return user
    # ---

    # 3
    def get_money(self):
        user_tf = self.search_user()
        if user_tf == -1:
            return -1
        money = float(input('请输入取款金额：'))
        if money > int(user_tf.card.money):
            print('余额不足')
            return -1
        user_tf.card.money = float(user_tf.card.money) - money
        print(f'取款成功，卡号：{user_tf.card.card_id}，余额：{user_tf.card.money}')


    # 4
    def save_money(self):
        user_tf = self.search_user()
        if user_tf == -1:
            return -1
        money = float(input('请输入存款金额：'))
        if money <= 0:
            print('存款金额必须大于0')
            return -1
        user_tf.card.money = float(user_tf.card.money) + money
        print(f'存款成功，卡号：{user_tf.card.card_id}，余额：{user_tf.card.money}')


    # 5
    def transfer_money(self):
        user_out = self.search_user(2)
        if user_out == -1:
            return -1
        user_in = self.search_user(3)
        if user_in == -1:
            return -1
        money = float(input('请输入转账金额：'))
        if money > int(user_out.card.money):
            print('余额不足')
            return -1
        option = input('确认转账？(Y/N):')
        if option == 'N':
            print('转账取消')
            return -1
        user_out.card.money = float(user_out.card.money) - money
        user_in.card.money = float(user_in.card.money) + money
        print(f'转账成功，转出卡号：{user_out.card.card_id}，转入卡号：{user_in.card.card_id}，余额：{user_out.card.money}')
        

    # 6
    def lock_card(self):
        input_id = input('请输入卡号：')
        user = self.all_user.get(input_id)
        if not user:
            print('卡号不存在')
            return -1
        if user.card.card_lock:
            print('卡号已锁定, 无需重复操作')
            return -1
        # if not self.check_pwd(user.card.card_pwd):
        #     print('密码错误...锁定失败···')
        #     return -1
        user.card.card_lock = True
        print('锁定成功')


    # 7
    def unlock_card(self):
        input_id = input('请输入卡号：')
        user = self.all_user.get(input_id)
        if not user:
            print('卡号不存在')
            return -1
        if not user.card.card_lock:
            print('卡号未锁定, 无需解锁')
            return -1
        if not self.check_pwd(user.card.card_pwd):
            print('密码错误...解锁失败···')
            return -1
        user.card.card_lock = False
        print('解锁成功')