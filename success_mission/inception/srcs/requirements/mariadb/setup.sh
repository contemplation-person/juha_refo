#!/bin/bash -x

set -e
/usr/bin/mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db
mariadbd --bootstrap << done 
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS $dbName; 
CREATE USER IF NOT EXISTS '$dbUser'@'%' IDENTIFIED BY '$dbPass'; 
-- GRANT ALL ON $dbName.* TO '$dbUser'@'%' IDENTIFIED BY '$dbPass' WITH GRANT OPTION; 
GRANT ALL PRIVILEGES ON $dbName.* TO '$dbUser'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$dbPass';
FLUSH PRIVILEGES;
done

exec mariadbd --user=mysql --datadir=/var/lib/mysql
