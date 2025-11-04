FROM ubuntu:14.04
MAINTAINER Danny Ho <hoyc.danny@gmail.com>
RUN apt-get update
RUN apt-get install -y curl wget git vim sudo openjdk-7-jdk
RUN java -version
RUN wget https://archive.apache.org/dist/activemq/5.14.3/apache-activemq-5.14.3-bin.tar.gz
RUN tar xzf apache-activemq-5.14.3-bin.tar.gz
RUN mv apache-activemq-5.14.3 activemq
RUN addgroup --quiet --system activemq
RUN adduser --quiet --system --ingroup activemq --no-create-home --disabled-password activemq
RUN usermod -c "ActiveMQ Broker" -d /opt/activemq -g activemq activemq
RUN chown -R activemq:activemq /opt/activemq
RUN chmod u=rwx,g=rxs,o= /opt/activemq
RUN cp /opt/activemq/bin/env /etc/default/activemq
RUN chown root:root /etc/default/activemq
