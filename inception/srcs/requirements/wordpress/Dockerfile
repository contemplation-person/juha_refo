FROM debian:bullseye

RUN apt update && apt upgrade && apt install curl php7.4-fpm -y 
RUN mkdir -p /run/php && chmod 755 /run/php
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
RUN mkdir -p /var/www/php_wp
RUN wp core download --path=/var/www/php_wp --allow-root

# TODO docker compose copy
# RUN mkdir -p /var/www/html

# TODO erase line
RUN apt install -y vim tmux zsh git && sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
# CMD zsh

EXPOSE 9000

# ENTRYPOINT php-fpm7.4 -F
#check wp --info