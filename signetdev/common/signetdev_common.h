#ifndef SIGNETDEV_COMMON_H
#define SIGNETDEV_COMMON_H

enum commands {
	STARTUP,
	OPEN_ID, //Defunct
	CLOSE_ID, //Defunct
	GET_DATA,
	SET_DATA,
	TYPE,
	LOGIN,
	LOGOUT,
	DELETE_ID,
	BUTTON_WAIT,
	GET_PROGRESS,
	GET_DEVICE_STATE,
	ERASE_FLASH_PAGES,
	WRITE_FLASH,
	RESET_DEVICE,
	INITIALIZE,
	CONNECT, //Defunct
	DISCONNECT,
	WIPE,
	CANCEL_BUTTON_PRESS,
	CHANGE_MASTER_PASSWORD,
	BACKUP_DEVICE,
	READ_BLOCK,
	BACKUP_DEVICE_DONE,
	RESTORE_DEVICE,
	WRITE_BLOCK,
	ERASE_BLOCK,
	RESTORE_DEVICE_DONE,
	GET_DEVICE_CAPACITY,
	UPDATE_FIRMWARE,
	GET_ALL_DATA,
	UPDATE_UID,
	READ_UID,
	READ_ALL_UIDS,
	ENTER_MOBILE_MODE
};

enum device_state {
	DISCONNECTED,
	RESET, //Defunct
	UNINITIALIZED,
	INITIALIZING,
	WIPING,
	ERASING_PAGES,
	FIRMWARE_UPDATE,
	LOGGED_OUT,
	LOGGED_IN,
	BACKING_UP_DEVICE,
	RESTORING_DEVICE
};

enum command_responses {
	OKAY,
	INVALID_STATE,
	INVALID_INPUT,
	ID_INVALID,
	ID_NOT_OPEN,
	TAG_INVALID,
	WRITE_FAILED,
	NOT_LOGGED_IN,
	NOT_INITIALIZED,
	BAD_PASSWORD,
	IN_PROGRESS,
	NOT_ENOUGH_SPACE,
	DONE,
	BUTTON_PRESS_CANCELED,
	BUTTON_PRESS_TIMEOUT,
	UNKNOWN_DB_FORMAT
};

#define SIGNET_MAJOR_VERSION 1
#define SIGNET_MINOR_VERSION 0
#define SIGNET_STEP_VERSION 1

#define SIGNET_ERROR_UNKNOWN -1
#define SIGNET_ERROR_DISCONNECT -2
#define SIGNET_ERROR_QUIT -3
#define SIGNET_ERROR_OVERFLOW -4

#define AES_BLK_SIZE (16)
#define AES_128_KEY_SIZE (16)
#define AES_256_KEY_SIZE (32)

#define SUB_BLK_SIZE (AES_BLK_SIZE)
#define SUB_BLK_MASK_SIZE (2)
#define SUB_BLK_DATA_SIZE (14)

#define SIZE_TO_SUB_BLK_COUNT(sz) (((sz) + (SUB_BLK_DATA_SIZE - 1))/SUB_BLK_DATA_SIZE)

#define BLK_SIZE (2048)
#define SUB_BLK_PER_BLOCK ((BLK_SIZE/SUB_BLK_SIZE) - 1)
#define BLK_USER_SIZE (SUB_BLK_PER_BLOCK * SUB_BLK_DATA_SIZE)
#define BLK_MASK_SIZE (SUB_BLK_PER_BLOCK * SUB_BLK_MASK_SIZE)

#define LOGIN_KEY_SZ (AES_256_KEY_SIZE)
#define SALT_SZ_V1 (AES_128_KEY_SIZE)
#define SALT_SZ_V2 (AES_256_KEY_SIZE)
#define HASH_FN_SZ (AES_BLK_SIZE)
#define CBC_IV_SZ (AES_BLK_SIZE)
#define INIT_RAND_DATA_SZ ((AES_256_KEY_SIZE * 2) + CBC_IV_SZ)
#define INITIALIZE_CMD_SIZE (LOGIN_KEY_SZ + HASH_FN_SZ + SALT_SZ_V2 + INIT_RAND_DATA_SZ)

#define TOTAL_STORAGE_SIZE (192 * 1024)
#define NUM_STORAGE_BLOCKS (TOTAL_STORAGE_SIZE/BLK_SIZE)

#define NUM_MASS_STORAGE_BLOCKS 0

#define MIN_ID 1
#define MAX_ID (NUM_STORAGE_BLOCKS-1-NUM_MASS_STORAGE_BLOCKS)

#define USB_VENDOR_ID (0x5E2A)
#define USB_SIGNET_DESKTOP_PRODUCT_ID (0x0001)
#define USB_SIGNET_MOBILE_PRODUCT_ID (0x0001)
#define USB_REV_ID (0x0483)
#define USB_RAW_HID_USAGE_PAGE	0xFFAB	// recommended: 0xFF00 to 0xFFFF
#define USB_RAW_HID_USAGE	0x0200	// recommended: 0x0100 to 0xFFFF
#define RAW_HID_PACKET_SIZE 64
#define RAW_HID_HEADER_SIZE 1
#define RAW_HID_PAYLOAD_SIZE (RAW_HID_PACKET_SIZE - RAW_HID_HEADER_SIZE)

#define CMD_PACKET_HEADER_SIZE 6
#define CMD_PACKET_PAYLOAD_SIZE (BLK_SIZE + CMD_PACKET_HEADER_SIZE + 1)
#define CMD_PACKET_BUF_SIZE (CMD_PACKET_PAYLOAD_SIZE + CMD_PACKET_HEADER_SIZE + RAW_HID_PAYLOAD_SIZE - 1)

#ifndef FIRMWARE
#include <stdint.h>
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
#endif

#endif
