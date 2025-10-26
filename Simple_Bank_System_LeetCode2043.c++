class Bank {
    private:
    vector<long long> balance;

public:
    Bank(vector<long long>& balance) {
        this -> balance = balance;
    }
    //helper function to check if the input account exists
    bool valid(int account){
        return account >=1 && account <=balance.size();
    } // account <= balance.size()ensures that the account number is not beyond the total number of accounts.
    //and account >= 1, it makes sure the account is in the range [1, balance.size()]
    
    bool transfer(int account1, int account2, long long money) {
        if(!valid(account1) || !valid(account2)) return false;
        if(balance[account1 -1] < money) return false;

        balance[account1 -1] -= money;
        balance[account2 -1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!valid(account)) return false;
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!valid(account)) return false;
        if(balance[account-1]<money) return false;

        balance[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */