cmake_minimum_required(VERSION 2.8.12)
project(skyporker-bot)

add_subdirectory(3rdparty/tgbot-cpp)

find_package(Qt6 COMPONENTS Core Network REQUIRED)

add_executable(skyporker-bot src/main.cpp)
target_link_libraries(skyporker-bot TgBot Qt6::Core Qt6::Network)
