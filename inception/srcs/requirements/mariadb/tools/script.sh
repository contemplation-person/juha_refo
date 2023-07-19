#!/bin/bash

chown -R mysql:mysql /var/lib/mysql
service mariadb start

echo "CREATE DATABASE IF NOT EXISTS $db1_name ;" > /root/init.sql
echo "CREATE USER IF NOT EXISTS '"$db1_user"'@'%' IDENTIFIED BY '"$db1_pwd"' ;" >> /root/init.sql
echo "GRANT ALL PRIVILEGES ON $db1_name.* TO '"$db1_user"'@'%' ;" >> /root/init.sql
echo "FLUSH PRIVILEGES;" >> /root/init.sql
mysql < /root/init.sql
rm /root/init.sql

service mariadb stop
mariadbd --user=root
