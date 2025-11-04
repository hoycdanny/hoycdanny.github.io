yum install -y epel-release
yum install -y erlang perl gnuplot gd libpng zlib perl
wget http://tsung.erlang-projects.org/dist/tsung-1.6.0.tar.gz
tar -xvzf tsung-1.6.0.tar.gz
mv tsung-1.6.0 /opt/
cd /opt/tsung-1.6.0/
./configure --prefix=/usr/local/tsung --with-erlang=/usr/local/erlang
make
make install
wget http://cpan.org/modules/by-module/Template/Template-Toolkit-2.24.tar.gz
tar -zxvf Template-Toolkit-2.24.tar.gz
cd Template-Toolkit-2.24
perl Makefile.PL
make test
yum install -y ncurses-devel
