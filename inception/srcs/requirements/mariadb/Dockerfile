FROM debian:bullseye

COPY setup.sh .

RUN apt update && apt upgrade -y && apt install mariadb-server -y

COPY my.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN mkdir -p -m 755 /run/mysqld/ \
&& chown -R mysql:mysql /run/mysqld /var/lib/mysql

EXPOSE 3306

ENTRYPOINT ./setup.sh