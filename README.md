# ghgQtSqlCipherDriverForWindows

## Current build tested for
* Qt 5.9.2 x86
* MSVC 2015 x86
* SQLCipher 3.11.0

## Build instructions for QSQLCipher
* Taken from : http://www.jerryrw.com/howtocompile.php
* Located in sqlcipher/

## Additional build instructions
When building for a different version of Qt you need to replace the files:
* src/qsql_sqlite.cpp
* src/qsql_sqlite.h
with the ones located in <qt-source>/qtbase/src/plugins/sqldrivers/sqlite
