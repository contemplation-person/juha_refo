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
