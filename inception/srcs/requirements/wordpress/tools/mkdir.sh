#!/bin/bash

# 디렉토리 존재 여부 확인
if [ -d "$dir_name" ]; then
    echo "디렉토리 '$dir_name'가 이미 존재합니다."
else
    echo "디렉토리 '$dir_name'가 존재하지 않습니다."


    mkdir -p $dir_name
    wp core download --path=$dir_name --allow-root
    # exist wordpress config check website
    # wp config create --dbname=$dbname --dbuser=$dbuser --dbpass=$dbpass --dbhost=$dbhost --path=$dir_name --allow-root
    mv /wp-config.php $dir_name
    wp core install --url=$url --title="juha's inception" --admin_user=$admin --admin_password=$adminPassword --admin_email=$adminEmail --path=$dir_name --skip-email --allow-root
	wp user create $newUser $newEmail --path=$dir_name --role=author --user_pass=$newPassword --allow-root

    chown -R www-data:www-data $dir_name
# erase this
# mv /wp-config.php $dir_name
fi

php-fpm7.4 -F