<?php
/**
	 * The base configuration for WordPress
	 *
	 * The wp-config.php creation script uses this file during the installation.
	 * You don't have to use the web site, you can copy this file to "wp-config.php"
	 * and fill in the values.
	 *
	 * This file contains the following configurations:
	 *
	 * * Database settings
	 * * Secret keys
	 * * Database table prefix
	 * * ABSPATH
	 *
* @link https://wordpress.org/documentation/article/editing-wp-config-php/
*
* @package WordPress
*/

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'mysql' );

/** Database username */
define( 'DB_USER', 'juha' );

/** Database password */
define( 'DB_PASSWORD', 'helloWorld' );

/** Database hostname */
define( 'DB_HOST', 'mariadb:<strong>3306' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
* Authentication unique keys and salts.
*
* Change these to different unique phrases! You can generate these using
* the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
*
* You can change these at any point in time to invalidate all existing cookies.
* This will force all users to have to log in again.
*
* @since 2.6.0
*/
// define('AUTH_KEY',         '^RP+bc)!2@R8cCBF@o]b7<cR4`B=,2!E u8Fs8l,oilYv|;`*(Jtb3~TTn%ike!6');
// define('SECURE_AUTH_KEY',  '$_z%0:*>Y#%G$SKCo!N|1C+m6b|TAW<#EjSao-1?dr+fR-f{^~pFwi~PjNbyqgl!');
// define('LOGGED_IN_KEY',    'GNhy2g%}eB5 ?z<U]h-n&Kaw72X:j|I@@(G0]?`dY21!PUM2W=|U#Uu69d~|PEt|');
// define('NONCE_KEY',        '4E,tXGWrD3VP!!FB@`wU%{RIEvg[5I,&p_m_We8-!BH@WhM.ODGcU5=}j$-8Z-iD');
// define('AUTH_SALT',        'y,bpR88ElVs|-/W)(0GFo4^`g^6;3#$1,dFO X8-X`&yo!@qx 9-Pc-W`a{rjYx-');
// define('SECURE_AUTH_SALT', '6]mq<yCjx.80DN9{/eTRK-sw$/81}7(hp|8,N36o;Cog|IXC&Q6Z1l>z^a/f9Lx&');
// define('LOGGED_IN_SALT',   '-q`dHCU-_a{LvVOU:AHz+/C1XnL0 H(JNgx_-X3w5Dmw*FCr9~}8RmkNWc<Q!P7$');
// define('NONCE_SALT',       'n)MrvJ-%dDJJQH>b*n*-:lnp=_|)+_Rg&!-#>gW/].`#tiTla=!8$~M4vaB!5bQS');
/**#@-*/

/**
* WordPress database table prefix.
*
* You can have multiple installations in one database if you give each
* a unique prefix. Only numbers, letters, and underscores please!
*/
$table_prefix = 'wp_';

/**
* For developers: WordPress debugging mode.
*
* Change this to true to enable the display of notices during development.
* It is strongly recommended that plugin and theme developers use WP_DEBUG
* in their development environments.
*
* For information on other constants that can be used for debugging,
* visit the documentation.
*
* @link https://wordpress.org/documentation/article/debugging-in-wordpress/
*/
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';