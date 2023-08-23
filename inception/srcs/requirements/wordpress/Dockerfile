FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install curl php7.4-fpm php-mysql mariadb-client -y 

COPY ./tools/wp-config.php .
COPY ./tools/www.conf /etc/php/7.4/fpm/php-fpm.conf
COPY ./tools/mkdir.sh .

RUN mkdir -p -m 755 /run/php \
&& curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
&& chmod 755 wp-cli.phar \
&& mv wp-cli.phar /usr/local/bin/wp

# TODO erase line
# RUN apt install -y vim tmux zsh git && sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
# CMD zsh

EXPOSE 9000
ENTRYPOINT /mkdir.sh
#check wp --info