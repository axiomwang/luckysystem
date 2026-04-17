cmake_minimum_required(VERSION 3.21)

project(LuckySystem VERSION 0.1.0 LANGUAGES CXX)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR
        "In-source builds are not allowed.\n"
        "Use: cmake -S . -B build -G Ninja\n"
        "Then: cmake --build build"
    )
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(LUCKYSYSTEM_SOURCES
    main.cpp
    nameinterface.cpp
    namesetting.cpp
    participantinterface.cpp
    person.cpp
    personlistmanager.cpp
    raffleinterface.cpp
    rafflemode.cpp
    raffleresult.cpp
    rafflesetting.cpp
    startinterface.cpp
    widget.cpp
)

set(LUCKYSYSTEM_HEADERS
    config.h
    nameinterface.h
    namesetting.h
    participantinterface.h
    person.h
    personlistmanager.h
    raffleinterface.h
    rafflemode.h
    raffleresult.h
    rafflesetting.h
    startinterface.h
    widget.h
)

set(LUCKYSYSTEM_FORMS
    nameinterface.ui
    namesetting.ui
    participantinterface.ui
    raffleinterface.ui
    raffleresult.ui
    rafflesetting.ui
    startinterface.ui
    widget.ui
)

qt_add_executable(LuckySystem
    MANUAL_FINALIZATION
    ${LUCKYSYSTEM_SOURCES}
    ${LUCKYSYSTEM_HEADERS}
    ${LUCKYSYSTEM_FORMS}
)

target_link_libraries(LuckySystem PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

if(APPLE)
    target_compile_options(LuckySystem PRIVATE
        -Wno-error=implicit-function-declaration
        -Wno-implicit-function-declaration
    )
endif()

set_target_properties(LuckySystem PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(LuckySystem)
