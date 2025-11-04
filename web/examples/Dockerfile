FROM ubuntu:16.04
RUN apt-get update 
RUN apt-get install git wget autoconf automake gcc  -y 
RUN git clone https://github.com/bagder/libbrotli
WORKDIR libbrotli
RUN ls
RUN apt-get install libtool -y
RUN apt-get install --reinstall build-essential -y
RUN ./autogen.sh
RUN ./configure --prefix=/usr
RUN make && make install
RUN ldconfig
