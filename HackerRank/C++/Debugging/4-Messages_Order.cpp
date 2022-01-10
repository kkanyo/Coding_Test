#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int ORDER = 0;       //For saving the order of sent messages

class Message {
public: 
    Message() {}
    Message(const string& text)
    : text_(text), order_(ORDER++) {}       //Initialize text and order of message
    const string& get_text() {
        return text_;
    }
    friend bool operator<(Message msg1, Message msg2) {     //Overload operator< function
        if (msg1.order_ < msg2.order_) return true;         //Compare the order of message with another one.
        else return false;
    }
private:
    string text_;
    int order_;
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text);                       //Use constructor of Message Object
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
