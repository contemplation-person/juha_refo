FROM debian:bullseye

RUN apt-get update -y

RUN apt-get install php-fpm php-mysql -y

RUN apt-get install curl -y

RUN apt-get install php -y
#RUN apt-get install php7.3 -y
RUN apt-get install php-cli -y
RUN apt-get install wget -y
RUN apt-get install php-mysql -y
RUN apt-get install php-mbstring -y
RUN apt-get install php-xml -y
RUN apt-get install sendmail -y
RUN apt-get install vim -y
# COPY ./wp-assets /var/www/html

# WORKDIR /usr/local/bin/
# RUN curl -o wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# RUN chmod +x wp

# RUN chmod +x wp-cli.phar
# RUN wp-cli.phar wp
# curl -o newfilename.html http://example.com/index.html

COPY ./tools/script.sh /
# COPY ./tools/wp-config.php /
# COPY ./wp-config.php /var/www/html/tmp_wp-config.php

CMD [ "./script.sh" ]

EXPOSE 9000

