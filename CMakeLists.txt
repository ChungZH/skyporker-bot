cmake_minimum_required(VERSION 2.8.12)
project(skyporker-bot)

add_definitions("-std=c++17")

add_subdirectory(3rdparty/tgbot-cpp)

add_executable(skyporker-bot src/main.cpp)
target_link_libraries(skyporker-bot TgBot)
