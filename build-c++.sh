sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-4.8 g++-4.8
CC=gcc-4.8 CXX=g++-4.8 make
CC=gcc-4.8 CXX=g++-4.8 make libReQLtest
