set(SOURCE_FILES
        main.cpp MenuWindow.cpp MenuWindow.h GameWindow.cpp GameWindow.h Player.cpp Player.h Computer.cpp Computer.h User.cpp User.h)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

qt5_add_resources(RESOURCE_ADDED resources/resources.qrc)

add_executable(TronGUI ${SOURCE_FILES} ${RESOURCE_ADDED})

target_link_libraries(TronGUI Qt5::Core)
target_link_libraries(TronGUI Qt5::Widgets)