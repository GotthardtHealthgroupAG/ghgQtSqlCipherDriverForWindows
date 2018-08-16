## SQLCipher

SQLCipher is an SQLite extension that provides transparent 256-bit AES encryption of 
database files. Pages are encrypted before being written to disk and are decrypted 
when read back. Due to the small footprint and great performance it�s ideal for 
protecting embedded application databases and is well suited for mobile development.

The official SQLCipher software site is http://sqlcipher.net
License https://www.zetetic.net/sqlcipher/license/

## Built from sources https://github.com/sqlcipher/sqlcipher version 3.11.0

$ ./configure --enable-tempstore=yes --with-crypto-lib=none --disable-tcl 
    CFLAGS="-DSQLITE_HAS_CODEC -DSQLCIPHER_CRYPTO_OPENSSL -I/c/OpenSSL-Win32/include /c/OpenSSL-Win32/libeay32.dll -L/c/OpenSSL-Win32/lib/MinGW -static-libgcc" 
    LDFLAGS="-leay32"
$ make clean
$ make
$ make dll
