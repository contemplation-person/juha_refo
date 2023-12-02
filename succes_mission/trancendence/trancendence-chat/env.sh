#!/bin/bash
    echo "CLIENT_ID=u-s4t2ud-0d6406d8666aa6e706225422720dc5b37bc3f0aadc6e808d1cae0369b1893629
    CLIENT_SECRET=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
    REDIRECT_URI=https://localhost/auth/callback
    POSTGRES_USER=postgres
    POSTGRES_PASSWORD=admin123
    POSTGRES_DB=pn
    POSTGRES_PORT=5432
    JWT_SECRET=ThisIsReallySecret
    GOOGLE_2FA_APP_NAME=pong-nyan" > ./backend/.env
    
    echo "NEXT_PUBLIC_CLIENT_ID=u-s4t2ud-0d6406d8666aa6e706225422720dc5b37bc3f0aadc6e808d1cae0369b1893629
    NEXT_PUBLIC_REDIRECT_URI=https://localhost/auth/callback
    NEXT_PUBLIC_API_URL=https://localhost/api" > ./frontend/.env
    
    echo "POSTGRES_USER=postgres
    POSTGRES_PASSWORD=admin123
    POSTGRES_DB=pn
    POSTGRES_PORT=5432" > ./database/.env
    
    echo "ENV WAS INSERTED!!"