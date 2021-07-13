/* Auther 		: 	Mohamed Hassan   */
/* Date		 	: 	7/7/2021         */
/* Version 		: 	V1               */

#ifndef LIBERARY_BIT_MATH_H_
#define LIBERARY_BIT_MATH_H_


#define SET_BIT(REG,BIT) REG|=(1<<BIT)


#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)


#define TGL_BIT(REG,BIT) REG^=(1<<BIT)


#define TGL_PORT(REG)	 REG=~REG


#define GET_BIT(REG,BIT) (REG>>BIT)&1


#endif /* LIBERARY_BIT_MATH_H_ */
