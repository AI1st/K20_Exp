/* CodeWarrior ARM Runtime Support Library

 * Copyright � 2012 Freescale Semiconductors. All rights reserved.

 *

 * $Date: 2013/02/08 07:14:44 $

 * $Revision: 1.6 $

 */





/*

 *	__arm_start.c	-	entry-point for ARM programs

 *

 */

#include <string.h>

#include <stdlib.h>

#include <runtime_configuration.h>



_EWL_BEGIN_EXTERN_C



#if SUPPORT_SEMIHOST_ARGC_ARGV

#define __MAX_CMDLINE_ARGS 10

static char *argv[__MAX_CMDLINE_ARGS] = { 0 };

#else

static char *argv[] = { 0 };

#endif



#if __GNUC__

#define __call_static_initializers __init_cpp

#endif

#if SUPPORT_SEMIHOST_ARGC_ARGV

extern int __argc_argv(int, char **);

#endif /* SUPPORT_SEMIHOST_ARGC_ARGV */



extern void __call_static_initializers(void);

extern int main(int, char **);



#ifdef __VFPV4__

extern void __fp_init(void);

#endif /* __VFPV4__ */



extern void __init_registers();

extern void __init_hardware();

extern void __init_user();



#if defined(__APCS_ROPI)

extern void __init_pic();

#endif



#if defined(__APCS_RWPI)

extern void __init_pid();

#endif



#if defined(__APCS_ROPI) || defined(__APCS_RWPI)

extern void __load_static_base();

#endif



#if defined(__SEMIHOSTING)

extern void __init_semihost(void) _EWL_WEAK;

#endif



#if SUPPORT_ROM_TO_RAM

extern void __copy_rom_sections_to_ram(void);

extern char __S_romp[];

#endif



static void zero_fill_bss(void)

{

	extern char __START_BSS[];

	extern char __END_BSS[];



	memset(__START_BSS, 0, (__END_BSS - __START_BSS));

}



#ifndef __thumb // Thumb version

#error Thumb startup

#endif



// To keep iar debugger happy

void __iar_program_start(void) _EWL_NAKED;

void __thumb_startup(void);

void __iar_program_start()

{

	__thumb_startup();

}





void __thumb_startup(void) _EWL_NAKED;

void __thumb_startup(void)

{

		// Setup registers

		__init_registers();



		// setup hardware
[E@��	=d2���;��m)9��eV�̫	-�L��l��Q��.Ϛ��c{�wq������L��ʶ�~M�%ੋf���WS�*�y]'�r�J���G�Df`������bX�-����6U5�$7�o�4@U��U�c�AU�Q���,�z�j����dkK��`�v��ze��Lp�32�c�>[�/bP��B%�w*�:��ju�g�#��@0�f�/"3rCdl�f��LA5ި�A�y�`��v�d����2��ս`�Y�V�����u]���e��᷅�U�m��́���;�+���1Z+&[#[��nryP5\����ʀ1����:��U��(>7b'��H~59�L�jG2��	�:�|0\C�UfѬ��n���O�i�E���Lwr�aR�F�{��D���<{'KK���\���4�QW��䆳ꉜ��BG�ګ͉��;���/;W�&��_�m����cJ�@Q��	��)�OX޿�cP<�>���#�Eo�e\d��#J�Ooj����S\ZU�,� ��(��*��1�e���|��l*4�G�x$���D��[M'��S�:�����\}8�2�w���w
�!f�};K�lPS���٪��+�a5P�FGp:�zEtZۈ�c&�He���ʴbNc':	��+��oO��t`�nl�y�U�����C-�;갳
�	��\�'��N#e��X�,v��ƛc��d;�25��DIf��	�C�:p�>W29�`myF�*� �$K��ޖ��l�o* XKMU<���C/{UK[�x��n������9�k��2��8!��g�eRg�\��c�j�٧�e���#�p�'V�f��fu��y���@��u0�V�Jv����q�?��L[[E��w'>�F.}n���U�hQ�(��7u��xk�L�ٙn�KY�A�Q-Ch5ΞI>H$��L��V#�:��92�}�Ef䌃�04(��Ѱ]���"R������nv��1����=�R�

#if SUPPORT_SEMIHOST_ARGC_ARGV

		exit(main(__argc_argv(__MAX_CMDLINE_ARGS, argv), argv));

#else

		exit(main(0, argv));

#endif



		//	should never get here

		while (1);



}



_EWL_END_EXTERN_C

