#!/bin/bash -x

set -e

if [[ ! -d "/var/lib/mysql/mysql" ]]; then 
    /usr/bin/mariadb-install-db --skip-test-db 
    mariadbd --bootstrap < setup_table
    
fi

mariadbd