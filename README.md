# cpp-dapps
Dapper Apps C++ libraries.
Includes:
A fully [RFC2812](https://tools.ietf.org/html/rfc2812)-compliant IRC Client library.

installation
windows

make sure boost is installed properly.
Download the latest version
http://sourceforge.net/projects/boost/files/boost/1.58.0/

Windows x64:
bootstrap
b2 link=static,shared address-model=64 threading=single,multi --stagedir=stage64

Windows x32:
bootstrap
b2 link=static,shared address-model=32 threading=single,multi --stagedir=stage32

set your cmake preferences

make sure cpp-netlib 0.11.1+ is installed properly from:
http://cpp-netlib.org/
And not the development version on github.
