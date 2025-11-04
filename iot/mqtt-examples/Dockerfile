FROM ubuntu:14.04.2
MAINTAINER Danny Ho <hoyc.danny@gmail.com>
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install wget libwrap0-dev libc-ares-dev xsltproc  -y
RUN wget http://archive.ubuntu.com/ubuntu/pool/main/l/linux/linux-libc-dev_3.2.0-23.36_amd64.deb
RUN sudo dpkg -i linux-libc-dev_3.2.0-23.36_amd64.deb
RUN apt-get install build-essential build-essential libssl-dev uuid-dev -y
#WORKDIR adduser mosquitto
WORKDIR /home/root
RUN wget https://mosquitto.org/files/source/mosquitto-1.4.11.tar.gz
RUN tar xvzf mosquitto-1.4.11.tar.gz
WORKDIR mosquitto-1.4.11
RUN make
RUN make install
#RUN useradd -ms /bin/bash  mosquitto
#RUN adduser --disabled-password --gecos '' mosquitto
USER mosquitto
WORKDIR /home/mosquitto
CMD ["su", "-", "mosquitto", "-c", "/bin/bash"]
#RUN mosquitto_passwd -c /etc/mosquitto/pwfile owntracks
#RUN mkdir /var/lib/mosquitto/
#RUN chown mosquitto:mosquitto /var/lib/mosquitto/ -R
#RUN cp /etc/mosquitto/mosquitto.conf.example /etc/mosquitto/mosquitto.conf
#RUN editor /etc/mosquitto/mosquitto.conf
