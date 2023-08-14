#!/bin/bash

# 확인할 디렉토리 이름
dir_name="/wp/php_wp"

# 디렉토리 존재 여부 확인
if [ -d "$dir_name" ]; then
    echo "디렉토리 '$dir_name'가 이미 존재합니다."
else
    echo "디렉토리 '$dir_name'가 존재하지 않습니다."
    mkdir -p $dir_name
    wp core download --path=$dir_name --allow-root
    mv /wp-config.php $dir_name
fi

php-fpm7.4 -F