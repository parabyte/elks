#ifndef LX86_LINUXMT_MM_H
#define LX86_LINUXMT_MM_H

#include <linuxmt/sched.h>
#include <linuxmt/errno.h>
#include <linuxmt/kernel.h>
#include <linuxmt/string.h>

extern unsigned long high_memory;

#ifdef __KERNEL__

#define VERIFY_READ 0
#define VERIFY_WRITE 1

#define MM_MEM	0
#ifdef CONFIG_SWAP
#define MM_SWAP	1
#endif

#define verify_area(mode,point,size) verfy_area(point,size)

/*@-namechecks@*/

extern void memcpy_fromfs(void *,void *,size_t);
extern void memcpy_tofs(void *,void *,size_t);

extern int strlen_fromfs(void *);

/*@+namechecks@*/

extern int verfy_area(void *,size_t);
extern void put_user_long(unsigned long int,void *);
extern void put_user_char(unsigned char,void *);
extern void put_user(unsigned short int,void *);
extern unsigned long int get_user_long(void *);
extern unsigned char get_user_char(void *);
extern unsigned short int get_user(void *);
extern int fs_memcmp(void *,void *,size_t);
extern int verified_memcpy_tofs(void *,void *,size_t);
extern int verified_memcpy_fromfs(void *,void *,size_t);

extern void mm_init(seg_t,seg_t);
extern seg_t mm_alloc(segext_t);
extern seg_t mm_realloc(seg_t);
extern seg_t mm_dup(seg_t);

extern void mm_free(seg_t);
extern int do_swapper_run(struct task_struct *);
extern unsigned int mm_get_usage(int,int);

extern void pokew(__u16,__u16,__u16);

extern __u8  peekb(__u16,__u16);
extern __u16 peekw(__u16,__u16);

extern void fmemcpy(__u16,__u16,__u16,__u16,__u16);
extern void fmemset(__u16,__u16,__u16,__u16);

extern void far_memmove(unsigned,unsigned,unsigned,unsigned,unsigned);

/* FIXME: Following function prototypes are apparently phantom ones,
 *	  so are defined here with void parameters for now.
 */

extern int mm_swapon(void);

#endif
#endif
