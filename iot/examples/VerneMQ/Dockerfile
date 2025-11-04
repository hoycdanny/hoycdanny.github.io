FROM ubuntu:14.04
MAINTAINER Danny Ho <hoyc.danny@gmail.com>
RUN apt-get update
RUN apt-get install -y curl wget git vim libssl-dev logrotate sudo
RUN curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -
RUN apt-get update
RUN apt-get install -y nodejs
ENV VERNEMQ_VERSION 1.0.1
ADD https://bintray.com/artifact/download/erlio/vernemq/deb/trusty/vernemq_$VERNEMQ_VERSION-1_amd64.deb /tmp/vernemq.deb
RUN dpkg -i /tmp/vernemq.deb
RUN rm /tmp/vernemq.deb
RUN sed -i 's/allow_anonymous = off/allow_anonymous = on/g' /etc/vernemq/vernemq.conf
RUN sed -i 's/plugins.vmq_passwd = on/plugins.vmq_passwd = off/g' /etc/vernemq/vernemq.conf
