set(SOURCE_FILES
        main.cpp)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(TronGUI ${SOURCE_FILES})

target_link_libraries(TronGUI Qt5::Core)
target_link_libraries(TronGUI Qt5::Widgets)