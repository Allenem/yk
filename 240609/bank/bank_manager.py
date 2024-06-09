from admin import Admin
from atm import ATM
from card import Card
from user import User
import os

class BankManager():
    def __init__(self):
        self.all_user_dict = {}
        if os.path.exists('user.txt'):
            with open('user.txt', 'r') as f:
                for line in f:
                    user_list = line.strip().split(' ')
                    name = user_list[0]
                    id = user_list[1]
                    phone = user_list[2]
                    card_id = user_list[3]
                    card_pwd = user_list[4]
                    money = float(user_list[5])
                    card_lock = True if user_list[6] == 'True' else False
                    card = Card(card_id, card_pwd, money)
                    card.card_lock = card_lock
                    user = User(name, id, phone, card)
                    self.all_user_dict[card_id] = user
        for user in self.all_user_dict.values():
            print(user.name, user.id, user.phone, user.card.card_id, user.card.card_pwd, user.card.money, user.card.card_lock)
        self.atm = ATM(self.all_user_dict)
        self.admin = Admin()

    def save_user(self):
        self.all_user_dict.update(self.atm.all_user)
        # save in txt format
        with open('user.txt', 'w') as f:
            for user in self.all_user_dict.values():
                f.write(f'{user.name} {user.id} {user.phone} {user.card.card_id} {user.card.card_pwd} {user.card.money} {user.card.card_lock}\n')
            
        print('保存成功')

    def work(self):
        # 欢迎界面
        self.admin.print_admin_view()
        # 管理员登录
        result = self.admin.check_option()
        # if result:
        #     print('登录失败')
        # else:
        #     print('登录成功')
        if not result:
            while True:
                self.admin.print_func_view()
                option = input('请输入操作：')
                if option not in ['1', '2', '3', '4', '5', '6', '7', 'Q', 'q']:
                    print('输入有误，请重新输入')
                    continue
                if option == '1':
                    print('开户')
                    self.atm.create_user()
                elif option == '2':
                    print('查询')
                    self.atm.search_user()
                elif option == '3':
                    print('取款')
                    self.atm.get_money()
                elif option == '4':
                    print('存款')
                    self.atm.save_money()
                elif option == '5':
                    print('转账')
                    self.atm.transfer_money()
                elif option == '6':
                    print('锁定')
                    self.atm.lock_card()
                elif option == '7':
                    print('解锁')
                    self.atm.unlock_card()
                elif option in ['Q', 'q']:
                    print('退出')
                    if not self.admin.check_option():
                        self.save_user()
                        print('退出成功')
                        return -1


if __name__ == '__main__':
    bm = BankManager()
    bm.work()
