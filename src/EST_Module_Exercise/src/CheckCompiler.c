/******************************************************************************/
/**
 * @file         CheckCompiler.c
 *
 * @brief        C file for CheckCompiler
 *
 * @version      1.00
 * @date         Feb/18/2010
 * @warning
 * @note
 * <pre>
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2010-02-18   1.00             - Creation Release
 * </pre>
 *
 */
/******************************************************************************/

#ifndef CHECKCOMPILER_C
#define CHECKCOMPILER_C

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/

/**** Standard types & definitions ****/
#include "stdio.h"
#include "PlatformTypes.h"

/**** Project types & definitions ****/

/**** Miscellaneous types & definitions ****/


/******************************************************************************/
/* DEFINITIONS AND MACROS (scope: file)                                       */
/******************************************************************************/


/******************************************************************************/
/* TYPEDEFS AND STRUCTURES (scope: file)                                      */
/******************************************************************************/

/**** enum type definitions ***************************************************/


/**** structures type definitions ********************************************/


/**** extra type definitions ****/

/******************************************************************************/
/* EXPORTED VARIABLES (scope: exported)                                       */
/******************************************************************************/


/******************************************************************************/
/* FILE VARIABLES (scope: file)                                               */
/******************************************************************************/


/******************************************************************************/
/* Function Prototype (scope: file)                                           */
/******************************************************************************/


/******************************************************************************/
/* Function Implementation (scope: file)                                      */
/******************************************************************************/


/******************************************************************************/
/* Function Implementation (scope: exported)                                  */
/******************************************************************************/


void CheckSize(void)
{
  printf("Size of char      :%3d\n", sizeof(char));
  printf("Size of short     :%3d\n", sizeof(short));
  printf("Size of int       :%3d\n", sizeof(int));
  printf("Size of long      :%3d\n", sizeof(long));
  printf("Size of long long :%3d\n", sizeof(long long));
  printf("Size of float     :%3d\n", sizeof(float));
  printf("Size of double    :%3d\n", sizeof(double));
  printf("\n");
  printf("Size of _Bool      :%3d\n", sizeof(_Bool));
  printf("Size of int8_t     :%3d\n", sizeof(int8_t));
  printf("Size of int16_t    :%3d\n", sizeof(int16_t));
  printf("Size of int32_t    :%3d\n", sizeof(int32_t));
  printf("Size of int64_t    :%3d\n", sizeof(int64_t));
  printf("Size of float_t    :%3d\n", sizeof(float_t));
  printf("Size of double_t   :%3d\n", sizeof(double_t));
  printf("\n");

}


void CheckDivision(void)
{
	int q = 0;
	int r = 0;

	q = 5 / 3;
	r = 5 % 3;
	printf("  5/3 = %d, 5%3 =  %d \n", q, r);

	q = -5 / 3;
	r = -5 % 3;
	printf(" -5/3 = %d, -5%3 = %d \n", q, r);

	q = 5 / -3;
	r = 5 % -3;
	printf(" 5/-3 = %d, 5%-3 =  %d \n", q, r);

	q = -5 / -3;
	r = -5 % -3;
	printf(" -5/-3 = %d, -5%-3 = %d \n", q, r);
}


void CheckBitField(void)
{
	struct bit_field
	{
		int16_t	  First4: 	4;
		int16_t	  Second2: 	2;
		uint16_t  Third1:	1;
		uint16_t  Fourth1:	1;
	} my_bit_field;

	my_bit_field.First4 = 15;
	my_bit_field.Second2 = 2;
	my_bit_field.Third1 = 1;
	my_bit_field.Fourth1 = 1;

	my_bit_field.First4 = 0;
	my_bit_field.Second2 = 0;
	my_bit_field.Third1 = 0;
	my_bit_field.Fourth1 = 0;

	my_bit_field.First4 = my_bit_field.Second2
			+ my_bit_field.Third1 + my_bit_field.Fourth1;
}


void CheckVolatile(void)
{
	int i;
	volatile int vi;

	i=0;
	i=1;
	i=2;
	i=3;

	vi=0;
	vi=1;
	vi=2;
	vi=3;

}

int main(void){
	CheckSize();
//	CheckDivision();
//	CheckBitField();
//	CheckVolatile();

	return(0);
}

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/


#endif
