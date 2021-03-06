#ifndef LX86_ARCH_POSIX_TYPES_H
#define LX86_ARCH_POSIX_TYPES_H

#include <arch/irq.h>

/*
 * This file is generally used by user-level software, so you need to
 * be a little careful about namespace pollution etc.  Also, we cannot
 * assume GCC is being used.
 */

/*@-namechecks@*/

#undef	__FD_SET
#define __FD_SET(fd,fdsetp) {				\
		int mask, addr = ((int) fdsetp);	\
							\
		addr += fd >> 4;			\
		mask = 1 << (fd & 0xf); 		\
		clr_irq();					\
		*(int*)addr |= mask;			\
		set_irq();					\
	}

#undef	__FD_CLR
#define __FD_CLR(fd,fdsetp) {				\
		int mask, addr = ((int) fdsetp);	\
							\
		addr += fd >> 4;			\
		mask = 1 << (fd & 0xf); 		\
		clr_irq();					\
		*(int*)addr &= ~mask;			\
		set_irq();					\
	}

#undef	__FD_ISSET
#define __FD_ISSET(fd,fdsetp)				\
	((((unsigned long *)fdsetp)[0] & (1<<(fd & 0x1f))) != 0)

#undef	__FD_ZERO
#define __FD_ZERO(fdsetp)	(((unsigned long *)fdsetp)[0] = 0UL)

/*@+namechecks@*/

#endif
