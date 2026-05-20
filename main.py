class BankAccount:
    def __init__(self, account_no, name, balance=0):
        self.account_no = account_no
        self.name = name
        self.balance = balance
        self.transactions = []

    def deposit(self, amount):
        if amount <= 0:
            print("Invalid deposit amount.")
            return

        self.balance += amount
        self.transactions.append(f"Deposited ₹{amount}")
        print("Amount deposited successfully.")

    def withdraw(self, amount):
        if amount <= 0:
            print("Invalid withdrawal amount.")
            return

        if amount > self.balance:
            print("Insufficient balance.")
            return

        self.balance -= amount
        self.transactions.append(f"Withdrawn ₹{amount}")
        print("Amount withdrawn successfully.")

    def display(self):
        print("\nAccount Number:", self.account_no)
        print("Name:", self.name)
        print("Balance:", self.balance)
        print("------------------------")

    def show_transactions(self):
        if not self.transactions:
            print("No transactions yet.")
            return

        print("\nTransaction History:")
        for t in self.transactions:
            print("-", t)


class BankSystem:
    def __init__(self):
        self.accounts = {}

    def create_account(self):
        account_no = input("Enter account number: ")

        if account_no in self.accounts:
            print("Account already exists.")
            return

        name = input("Enter account holder name: ")
        balance = float(input("Enter opening balance: "))

        self.accounts[account_no] = BankAccount(account_no, name, balance)
        print("Account created successfully.")

    def view_accounts(self):
        if not self.accounts:
            print("No accounts found.")
            return

        for account in self.accounts.values():
            account.display()

    def search_account(self):
        account_no = input("Enter account number: ")

        if account_no in self.accounts:
            self.accounts[account_no].display()
        else:
            print("Account not found.")

    def deposit_money(self):
        account_no = input("Enter account number: ")

        if account_no not in self.accounts:
            print("Account not found.")
            return

        amount = float(input("Enter amount to deposit: "))
        self.accounts[account_no].deposit(amount)

    def withdraw_money(self):
        account_no = input("Enter account number: ")

        if account_no not in self.accounts:
            print("Account not found.")
            return

        amount = float(input("Enter amount to withdraw: "))
        self.accounts[account_no].withdraw(amount)

    def delete_account(self):
        account_no = input("Enter account number: ")

        if account_no in self.accounts:
            del self.accounts[account_no]
            print("Account deleted successfully.")
        else:
            print("Account not found.")

    def transaction_history(self):
        account_no = input("Enter account number: ")

        if account_no in self.accounts:
            self.accounts[account_no].show_transactions()
        else:
            print("Account not found.")

    def menu(self):
        while True:
            print("\n===== Bank Management System =====")
            print("1. Create Account")
            print("2. View Accounts")
            print("3. Search Account")
            print("4. Deposit Money")
            print("5. Withdraw Money")
            print("6. Delete Account")
            print("7. Transaction History")
            print("8. Exit")

            choice = input("Enter choice: ")

            if choice == "1":
                self.create_account()
            elif choice == "2":
                self.view_accounts()
            elif choice == "3":
                self.search_account()
            elif choice == "4":
                self.deposit_money()
            elif choice == "5":
                self.withdraw_money()
            elif choice == "6":
                self.delete_account()
            elif choice == "7":
                self.transaction_history()
            elif choice == "8":
                print("Exiting...")
                break
            else:
                print("Invalid choice.")


bank = BankSystem()
bank.menu()