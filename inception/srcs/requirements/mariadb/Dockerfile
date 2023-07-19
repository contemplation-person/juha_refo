FROM debian:bullseye

ENV MYSQL_ROOT_PASSWORD=root 

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install mariadb-server -y

# TODO setting
# service mariadb start
# mysql_secure_installation
# init password : enter
# socker 인증 : y
# set root password :1q2w3e!@#
# retry :1q2w3e!@#
# remove test : y
# 원격 루트 로그인 허용? : n
# remove test : y
# road : y
# start


EXPOSE 3306








# 디렉터리 위치  나중에  다시  확인해보기
# COPY ./tools/50-server.cnf /etc/mysql/mariadb.conf.d/
# COPY ./tools/script.sh /

# CMD ["/script.sh"]

# RUN chmod +x /script.sh
# ENTRYPOINT ["/script.sh"]

# ENTRYPOINT [ "executable" ]

# 권한이 없어서 VM에서만 가능
# CMD ["/script.sh"]
