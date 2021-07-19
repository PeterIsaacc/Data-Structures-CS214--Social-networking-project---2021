cmake_minimum_required(VERSION 3.17.3)
project(DataStructureProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DataStructureProject
        main.cpp
        Treap.cpp
        Treap.h
        User.cpp
        User.h
        UserLinkedList.h
        UserLinkedList.cpp
        "menus/MenuManager.cpp" "menus/MenuManager.h" "menus/IMenu.h" "menus/MainMenu.h" "menus/MainMenu.cpp" "menus/MenuUtil.h" "menus/MenuUtil.cpp" "menus/UserMenu.cpp" "menus/UserMenu.h" UserManager.cpp UserManager.h)
