// Login contract to authenticate users. Allows apps to query the chain for login verification.
//
// @author Craig Branscom
// @contract login
// @version v0.1.0

#include <eosio/eosio.hpp>
#include <eosio/singleton.hpp>

using namespace std;
using namespace eosio;

CONTRACT login : public contract {

    public:

    login(name self, name code, datastream<const char*> ds);

    ~login();

    //======================== user actions ========================

    //login a user
    ACTION loginuser(name account_name, string login_code);

    //deletes a login and returns ram
    ACTION logoutuser(name account_name);

    //======================== contract tables ========================

    //login table
    //scope: self
    TABLE login_event {
        name account_name;
        string login_code;

        uint64_t primary_key() const { return account_name.value; }
        EOSLIB_SERIALIZE(login_event, (account_name)(login_code))
    };
    typedef multi_index<name("logins"), login_event> logins_table;

};