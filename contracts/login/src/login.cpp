#include "../include/login.hpp"

login::login(name self, name code, datastream<const char*> ds) : contract(self, code, ds) {}

login::~login() {}

//======================== actions ========================

ACTION login::loginuser(name account_name, string login_code) {
    
    //authenticate
    require_auth(account_name);

    //open logins table, search for login
    logins_table logins(get_self(), get_self().value);
    auto l_itr = logins.find(account_name.value);

    if (l_itr == logins.end()) { //add new login
        
        //emplace new login, ram paid by account_name
        logins.emplace(account_name, [&](auto& col) {
            col.account_name = account_name;
            col.login_code = login_code;
        });

    } else {

        //update existing login
        logins.modify(*l_itr, same_payer, [&](auto& col) {
            col.login_code = login_code;
        });

    }

}

ACTION login::logoutuser(name account_name) {
    
    //open logins table, get login
    logins_table logins(get_self(), get_self().value);
    auto& l = logins.get(account_name.value, "login not found");

    //delete login
    logins.erase(l);

}
