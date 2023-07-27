FROM debian:bullseye

RUN apt update && apt upgrade && apt install curl php7.4-fpm -y 
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
RUN mkdir -p /var/www/php_wp
RUN wp core download --path=/var/www/php_wp --allow-root

# RUN mkdir -p /var/www/html

EXPOSE 9000
#check wp --info