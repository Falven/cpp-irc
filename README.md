-Dapper Apps C++ libraries.
 -Includes:
  A fully [RFC2812](https://tools.ietf.org/html/rfc2812)-compliant IRC Client library.
 -
 -installation
 Requires 64 bit static multithreaded boost installation.
 
 -windows
 -
 -make sure boost is installed properly.
 -Download the latest version
 -http://sourceforge.net/projects/boost/files/boost/1.58.0/
 -
 -bootstrap
 -b2 link=static address-model=64 threading=multi
 -
 -set your cmake preferences
 -
 -make sure cpp-netlib 0.11.1+ is installed properly from:
 -http://cpp-netlib.org/
 -And not the development version on github.
