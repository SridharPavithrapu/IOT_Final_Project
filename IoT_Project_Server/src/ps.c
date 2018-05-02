/********************************************************************************************************************
* File Name 	  : ps.c
* File Description: This file contains the routines for persistent data load and store
* Author		  : Rishi Soni
* Date			  : 03/29/2018
* Compiler : arm-none-eabi-gcc
* Linker   : arm-none-eabi-ld
* Debugger : gdb
********************************************************************************************************************
 * <b> (C) Copyright 2016 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************************************************
 * This file contains licensed libraries under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 ******************************************************************************************************************/
#include "main.h"


// Persistent memory data functions

// Key values: 0x4000 to 0x407F
// Maximum bytes per key: 56 bytes

/*Function stores data in the persistent memory corresponding to key*/
uint16_t ps_save_object(uint16_t key, void *pValue, uint8_t size)
{
	struct gecko_msg_flash_ps_save_rsp_t *pResp;

	pResp = gecko_cmd_flash_ps_save(key, size, pValue);

	return(pResp->result);
}

/*Function loads data from the persistent memory corresponding to key*/
uint16_t ps_load_object(uint16_t key, void *pValue, uint8_t size)
{
	struct gecko_msg_flash_ps_load_rsp_t *pResp;

	pResp = gecko_cmd_flash_ps_load(key);

	if(pResp->result == 0)
	{
		memcpy(pValue, pResp->value.data, pResp->value.len);

		// sanity check: length of data stored in PS key must match the expected value
		if(size != pResp->value.len)
		{
			return(bg_err_unspecified);
		}
	}

	return(pResp->result);
}

///*Function to save threshold temperature in persistent memory corresponding to key*/
//void temp_ps_init(uint32_t threshold, uint16_t key)
//{
//	if(!(ps_save_object(key, (void*)&threshold, sizeof(threshold))))
//	{
//		GRAPHICS_AppendString("PS data save SUCCESS\n");
//		GRAPHICS_Update();
//	}
//}

