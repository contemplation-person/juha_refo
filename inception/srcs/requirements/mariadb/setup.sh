#!/bin/bash -x

set -e
/usr/bin/mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db
mariadbd --bootstrap < setup_table

exec mariadbd --user=mysql --datadir=/var/lib/mysql
