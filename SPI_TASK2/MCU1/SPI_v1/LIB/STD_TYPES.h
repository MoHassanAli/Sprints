/*
 * STD_TYPES.h
 *
 * Created: 7/13/2021 10:19:11 PM
 *  Author: Mohamed
 */ 

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* ***************************************************************************** */

typedef unsigned char     	 	uint8_t;
typedef unsigned short int 		uint16_t;
typedef unsigned long int  		uint32_t;

typedef signed char        		sint8_t;
typedef signed short int   		sint16_t;
typedef signed long int    		sint32_t;

typedef float              		float32_t;
typedef double             		float64_t;

typedef unsigned char	   		Error_Status;
typedef unsigned char	   		Flag_Status;

/* ***************************************************************************** */
#define E_NOK					(0)
#define E_OK					(1)

#define NULL					((void*)0)

/* ***************************************************************************** */

#endif