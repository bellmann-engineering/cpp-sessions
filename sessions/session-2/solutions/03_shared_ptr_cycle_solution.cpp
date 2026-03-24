#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ChatRoom; // forward decleration

class User {
public:
    User(const std::string& name) : name_(name) {
        std::cout << "User " << name_ << " erstellt\n";
    }

    ~User() {
        std::cout << "User " << name_ << " zerstört\n";
    }

    void setRoom(const std::shared_ptr<ChatRoom>& room) {
        room_ = room;
    }

private:
    std::string name_;

    // FEHLER (Teil 1):
    // std::shared_ptr<ChatRoom> room_;

    // LÖSUNG (Teil 2):
    // weak_ptr besitzt NICHT -> durchbricht den Kreis
    std::weak_ptr<ChatRoom> room_;
};

class ChatRoom {
public:
    ChatRoom(const std::string& name) : name_(name) {
        std::cout << "ChatRoom " << name_ << " erstellt\n";
    }

    ~ChatRoom() {
        std::cout << "ChatRoom " << name_ << " zerstört\n";
    }

    void addUser(const std::shared_ptr<User>& user) {
        users_.push_back(user);
    }

private:
    std::string name_;
    std::vector<std::shared_ptr<User>> users_; // besitzt User -> bleibt shared_ptr
};

int main() {
    auto room = std::make_shared<ChatRoom>("C++");
    auto user1 = std::make_shared<User>("Anna");
    auto user2 = std::make_shared<User>("Ben");

    room->addUser(user1);
    room->addUser(user2);

    user1->setRoom(room);
    user2->setRoom(room);

    std::cout << "Ende von main\n";
    return 0;
}