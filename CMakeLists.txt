#--------------------------------------------
# Qt SQLCipher Database Driver
#--------------------------------------------
cmake_minimum_required(VERSION 3.5)

project(qsqlitecipher)

# Activating C++ 11
set(CMAKE_CXX_STANDARD 11)
# Sets C++ 11 standard as required for compilers
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Disable compiler-specific C++ language extensions
set(CMAKE_CXX_EXTENSIONS OFF)
# Enable auto moc for Qt targets
set(CMAKE_AUTOMOC ON)

# Set paths to SQLCipher
set (SQLCipher_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/sqlcipher/include)
set (SQLCipher_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/sqlcipher/lib)
set (SQLCipher_LIBRARY_COMPONENTS sqlite3 libeay32)

add_definitions(-DQT_PLUGIN)

find_package(Qt5 5.9.6 REQUIRED COMPONENTS Core Sql)

foreach (SQLCipher_LIBRARY_COMPONENT ${SQLCipher_LIBRARY_COMPONENTS})
    find_library (${SQLCipher_LIBRARY_COMPONENT}_LIB
        NAMES ${SQLCipher_LIBRARY_COMPONENT}
        PATHS ${SQLCipher_LIBRARY_PATH}
        NO_DEFAULT_PATH)
    if (NOT ${SQLCipher_LIBRARY_COMPONENT}_LIB)
        message (FATAL_ERROR "Module library " ${SQLCipher_LIBRARY_COMPONENT} " not found in " ${SQLCipher_LIBRARY_PATH})
    endif ()
endforeach ()

# Tell cmake to put the plugin dll in sqldrivers directory
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/sqldrivers/${CMAKE_BUILD_TYPE})

add_library(${PROJECT_NAME} MODULE
    src/smain.cpp
    src/qsql_sqlite.cpp
)

# Link the library against dependencies.
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Sql
    ${sqlite3_LIB}
    ${libeay32_LIB}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${Qt5Sql_PRIVATE_INCLUDE_DIRS}
    ${SQLCIPHER_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src
)
