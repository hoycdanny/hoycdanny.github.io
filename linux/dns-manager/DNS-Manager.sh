# wget http://repo.mysql.com/mysql-community-release-el7-5.noarch.rpm
# sudo rpm -ivh mysql-community-release-el7-5.noarch.rpm
# yum update
# sudo yum install mysql-server
# sudo systemctl start mysqld
yum install perl httpd mod_ssl php php-intl php-ldap php-mysql php-soap php-xml php-process mysql-compat-server
wget wget https://repos.jethrocarr.com/pub/amberdms/linux/centos/7/jethrocarr-custom/x86_64/namedmanager-www-1.9.0-2.el7.centos.noarch.rpm
wget https://repos.jethrocarr.com/pub/amberdms/linux/centos/7/jethrocarr-custom/x86_64/namedmanager-bind-1.9.0-2.el7.centos.noarch.rpm
rpm -ivh namedmanager-www-1.9.0-2.el7.centos.noarch.rpm
rpm -ivh namedmanager-bind-1.9.0-2.el7.centos.noarch.rpm
