#ifndef _SERVERSERIAL_H_
#define _SERVERSERIAL_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

/**
 * retrieve the server name.
 *
 * @param name: It is used to store the server name retrieved & name_len: It is used to store length of the name.
 *
 * @return Zero if the function completes successfully , non-zero
 * otherwise.
 */
int get_server_name(char *name, int name_len);


/**
 * retrieve the serial server number.
 *
 * @param serial: It is used to store the serial server retrieved & serial_len: It is used to store length of the serial number.
 *
 * @return Zero if the function completes successfully , non-zero
 * otherwise.
 */
int get_server_serial(char *serial, int serial_len);


/**
 * retrieve the baseboard name.
 *
 * @param name: It is used to store the board name retrieved & name_len: It is used to store length of the name.
 *
 * @return Zero if the function completes successfully , non-zero
 * otherwise.
 */
int get_baseboard_name(char *name, int name_len);


/**
 * retrieve the serial board number.
 *
 * @param serial: It is used to store the serial board number retrieved & serial_len: It is used to store length of the serial board number.
 *
 * @return Zero if the function completes successfully , non-zero
 * otherwise.
 */
int get_baseboard_serial(char *serial, int serial_len);


/**
 * retrieve the serial chassis number.
 *
 * @param serial: It is used to store the serial chassis number retrieved & serial_len: It is used to store length of the serial chassis number.
 *
 * @return Zero if the function completes successfully , non-zero
 * otherwise.
 */
int get_chassis_serial(char *serial, int serial_len);

 #endif /* _SERVERSERIAL_H_ */
