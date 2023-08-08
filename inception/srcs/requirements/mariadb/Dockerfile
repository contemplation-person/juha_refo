FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install mariadb-server -y

RUN apt install -y vim tmux zsh git && sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
# RUN mysql -u root -p
EXPOSE 3306