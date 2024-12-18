
# Concrete Library

## Test Configuration

### Install Google Test via Package Manager
#### Install Google Test:
```
sudo apt install libgtest-dev cmake
```
#### Build Google Test libraries (these are not pre-built by default):
```
cd /usr/src/googletest
sudo cmake .
sudo make
sudo mv lib/libgtest*.a /usr/lib
```
This makes the static libraries (```libgtest.a```, ```libgtest_main.a```) available system-wide.