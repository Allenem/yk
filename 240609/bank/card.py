class Card:
    def __init__(self, card_id, card_pwd, money):
        self.card_id = card_id
        self.card_pwd = card_pwd
        self.money = money
        self.card_lock = False