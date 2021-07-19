#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;
class Treap;

class User
{
    private:
        string username;
        string fullname;
        string email;
        Treap* friendsList;
    public:
        User();
        User(string username, string fullname, string email);

        string getUsername(){ return username; }
        string getFullname(){ return fullname; }
        string getEmail(){ return email; }

        void setUsername(string username){ this -> username = username; }
        void setFullname(string fullname){ this -> fullname = fullname; }
        void setEmail(string email){ this -> email = email; }

        bool AddFriend(User& user);
        bool RemoveFriend(User& user);
        void ListFriends();
        bool IsAFriend(User& user);
        bool operator==(const User& user);

        friend ostream& operator<<(ostream& os, const User& user)
        {
            os << "Fullname: " << user.fullname << endl
            << "Username: " << user.username << endl
            << "Email: " << user.email << endl;

            return os;
        }

        std::string toString() {
            return "Fullname: " + fullname + "\nUsername: " + username + "\nEmail: " + email + "\n";
        }
};

#endif