#!/bin/bash

# 디렉토리 존재 여부 확인
if [ -d "$dirName" ]; then
    echo "디렉토리 '$dirName'가 이미 존재합니다."
else
    echo "디렉토리 '$dirName'가 존재하지 않습니다."


    mkdir -p $dirName
    wp core download --path=$dirName --allow-root
    # exist wordpress config check website
    # wp config create --dbname=$dbname --dbuser=$dbuser --dbpass=$dbpass --dbhost=$dbhost --path=$dirName --allow-root
    mv /wp-config.php $dirName
    wp core install --url=$url --title="juha's inception" --admin_user=$admin --admin_password=$adminPassword --admin_email=$adminEmail --path=$dirName --skip-email --allow-root
	wp user create $newUser $newEmail --path=$dirName --role=author --user_pass=$newPassword --allow-root

    chown -R www-data:www-data $dirName
# erase this
# mv /wp-config.php $dirName
fi

php-fpm7.4 -F