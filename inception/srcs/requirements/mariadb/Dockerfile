FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install mariadb-server -y
RUN echo "port = 3306" >> /etc/mysql/my.cnf
RUN mkdir -p -m 755 /run/mysqld/
RUN chown mysql:mysql /run/mysqld/
RUN ./etc/init.d/mariadb start

# TODO delete line
RUN apt install -y vim tmux zsh git && sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

EXPOSE 3306