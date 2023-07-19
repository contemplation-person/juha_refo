FROM debian:bullseye

RUN apt-get update 
RUN apt-get upgrade -y
RUN apt-get install -y vim
RUN apt-get install -y build-essential
RUN apt-get install -y curl gnupg2 ca-certificates lsb-release debian-archive-keyring

RUN curl https://nginx.org/keys/nginx_signing.key | gpg --dearmor | tee /usr/share/keyrings/nginx-archive-keyring.gpg >/dev/null
RUN gpg --dry-run --quiet --no-keyring --import --import-options import-show /usr/share/keyrings/nginx-archive-keyring.gpg
RUN echo "deb [signed-by=/usr/share/keyrings/nginx-archive-keyring.gpg] http://nginx.org/packages/debian `lsb_release -cs` nginx" | tee /etc/apt/sources.list.d/nginx.list
RUN apt-get update && apt-get install -y nginx

COPY ./conf/default.conf ./etc/nginx/conf.d/default.conf

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt -subj "/C=KR/ST=Seoul/L=Seoul/O=42/CN=www.example.com"

#zsh remove
# RUN apt install git -y && apt install zsh -y && sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
# COPY ./html ./var/www/html

ENTRYPOINT nginx -g "daemon off;"

EXPOSE 443
# CMD [ "zsh" ]
