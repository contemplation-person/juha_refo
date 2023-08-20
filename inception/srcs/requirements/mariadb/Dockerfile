FROM debian:bullseye

# TODO delete line
RUN apt update && apt install -y vim tmux zsh git && sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

RUN apt update && apt upgrade -y && apt install mariadb-server -y

COPY my.cnf /etc/mysql/.
COPY setup.sh .
COPY setup_table .

RUN mkdir -p -m 755 /run/mysqld/
RUN chown mysql:mysql /run/mysqld


EXPOSE 3306