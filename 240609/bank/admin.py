class Admin:
    admin_name = 'admin'
    admin_pwd = '123'

    @staticmethod
    def print_admin_view():
        print('*' * 50)
        print('***' + ' ' * 44 + '***')
        print('***' + ' ' * 44 + '***')
        print('***' + ' ' * 14 + '欢迎登录银行系统' + ' ' * 14 + '***')
        print('***' + ' ' * 44 + '***')
        print('***' + ' ' * 44 + '***')
        print('*' * 50)

    @staticmethod
    def print_func_view():
        print('*' * 50)
        print('***' + ' ' * 44 + '***')
        print('***' + ' ' * 11 + '1.开户' + ' ' * 10 + '2.查询' + ' ' * 11 + '***')
        print('***' + ' ' * 11 + '3.取款' + ' ' * 10 + '4.存款' + ' ' * 11 + '***')
        print('***' + ' ' * 11 + '5.转账' + ' ' * 10 + '6.锁定' + ' ' * 11 + '***')
        print('***' + ' ' * 11 + '7.解锁' + ' ' * 27 + '***')
        print('***' + ' ' * 44 + '***')
        print('***' + ' ' * 11 + '退出 (Q或q)' + ' ' * 22 + '***')
        print('***' + ' ' * 44 + '***')
        print('*' * 50)

    def check_option(self):
        admin_input = input('请输入管理员账号：')
        if admin_input == self.admin_name:
            admin_pwd = input('请输入管理员密码：')
            if admin_pwd == self.admin_pwd:
                print('登录成功，请稍后...')
                return 0
            else:
                print('密码错误')
                return -1
        else:
            print('账号错误')
            return -1


# ad = Admin()
# ad.print_admin_view()