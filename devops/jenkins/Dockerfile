FROM ubuntu:16.04
MAINTAINER Danny,Ho <danny.ho@hpe.com>
ENV JENKINS_VERSION jenkins_2.73.1_all.deb
RUN apt-get update
RUN apt-get -y install \
					openjdk-8-jre-headless \
					net-tools \
					daemon \
					psmisc \
					wget
RUN wget https://pkg.jenkins.io/debian-stable/binary/"$JENKINS_VERSION"
RUN dpkg -i "$JENKINS_VERSION"
COPY docker-entrypoint.sh /usr/local/bin/
RUN ln -s usr/local/bin/docker-entrypoint.sh /entrypoint.sh
ENTRYPOINT sh entrypoint.sh && bash
#CMD ["cat","/var/lib/jenkins/secrets/initialAdminPassword"]
EXPOSE 8080
