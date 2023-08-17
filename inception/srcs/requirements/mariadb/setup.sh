#!/bin/bash -x

set -e

if [[ ! -d "/var/lib/mysql/mysql" ]]; then 
    /usr/bin/mariadb-install-db --skip-test-db 
fi

mariadbd --bootstrap << EOF
FLUSH PRIVILEGES;
CREATE DATABASE WordPressDB; 
CREATE USER juha@localhost IDENTIFIED BY 'helloworld'; 
GRANT ALL ON WordPressDB.* TO juha@localhost IDENTIFIED BY 'helloworld' WITH GRANT OPTION; 
FLUSH PRIVILEGES;
EOF

mariadbd