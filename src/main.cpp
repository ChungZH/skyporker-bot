#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <tgbot/tgbot.h>

using namespace std;
namespace net = curly_hpp;

string SPBOT_TOKEN;
string QWEATHER_KEY;

// https://dev.qweather.com/docs/api/geo/
string getCityID(const string name) {
    string reqUrl = "https://geoapi.qweather.com/v2/city/lookup?key=" + QWEATHER_KEY + "&location=" + name;
    cout << "getCityID(): URL " << reqUrl << endl;    

}

int main() {
    SPBOT_TOKEN = getenv("SPBOT_TOKEN_ENV");
    cout << "TG TOKEN: " << SPBOT_TOKEN << endl;

    QWEATHER_KEY = getenv("QWEATHER_KEY");
    cout << "QWEATHER KEY: " << QWEATHER_KEY << endl;

    TgBot::Bot bot(SPBOT_TOKEN);
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });

    bot.getEvents().onCommand("weather", [&bot](TgBot::Message::Ptr message) {
        
    });
    
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/")) 
            return;
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}
