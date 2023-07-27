FROM debian:bullseye

RUN apt update && apt upgrade && apt install -y mariadb-server
RUN mysql -u root -p
EXPOSE 80