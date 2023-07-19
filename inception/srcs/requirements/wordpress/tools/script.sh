#!/bin/bash

cd /usr/local/bin/ 
pwd

cd /usr/local/bin/ && pwd
curl -o wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
chmod +x wp

# alias wpr="wp --allow-root" #일회용 설정

# wpr cli update
# php wp --info

# wpr core download 
# wpr plugin install akismet  
# wpr config create --dbname=$db1_name --dbuser=$db1_user --dbpass=$db1_pwd --dbhost=$db1_host 
