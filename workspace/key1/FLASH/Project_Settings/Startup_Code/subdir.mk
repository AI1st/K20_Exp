W䴹��N P�Y-b(��hR�=-Z� ��boHMI+�_���@f�^�BJ�K�xR�^�n��z��r�3དྷo?9^�H��ԓ4vp>L�i���M!�!�sj�K�~A�<Z���nD��E�>9)U������U����e)c������e�/ �hu��^@����_w<Mڀ�d���o���t�w�7ӻ �п\�,��b��'E���;Ha����z�N�/���X2O�3�����qi:r �O%��۰�^w��fP�֡3)�RxB�s���_�A2 ��% eZ�X����/��_��k&Y�)�K�I�5^^��2J�&�x}#���X�O���N�0�̍�:~jT����e^0h"
x$�F�m�&BIy����s����ũ�=�#���d���eHt���Wʨr��Bp�����4Mct}��y��)��s� {GQb�G%d��Y�_�Ki�ʐ��"-@a�h͝}�B ��^�\H�N��A+�����&����"�ݲ��Ng����T�� �z& ��mKŇd�� D�G+���P��~8�o�.���:��	�c�ő��=D�Mw#�pHF��������?fF����t�#�Z6!���5�o��JzfoFD�K�#��U����h�5Y7OPb49�0���[���u�^�,���5j[��G���-�����oX��+P	�w"j{��=���)ɿ.Gx9�Q�ZS��o{ N���I��rw�=���o7?ώ��� ���g ��2���+�A��_��nJ6b Ŋ��?�L	� ��B��K��;ؠ��~�j8uDo���U�����H9]A�eю�?(44B��Ѣ�0�tt�r�h�ؽ��H�L\�%V�)�r���ij��w����4�Ly\̔)�P�U���+m;ZTA�_)r\��O�"Ǥ+`���M��q]��ɲ��hf����$�l�rBJ�U��cаT,	i�r��J���j#�^��U���_Settings/Startup_Code/__arm_end.o" \
"./Project_Settings/Startup_Code/__arm_start.o" \
"./Project_Settings/Startup_Code/kinetis_sysinit.o" \

C_DEPS_QUOTED += \
"./Project_Settings/Startup_Code/__arm_end.d" \
"./Project_Settings/Startup_Code/__arm_start.d" \
"./Project_Settings/Startup_Code/kinetis_sysinit.d" \

OBJS_OS_FORMAT += \
./Project_Settings/Startup_Code/__arm_end.o \
./Project_Settings/Startup_Code/__arm_start.o \
./Project_Settings/Startup_Code/kinetis_sysinit.o \


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/__arm_end.o: ../Project_Settings/Startup_Code/__arm_end.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Project_Settings/Startup_Code/__arm_end.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Project_Settings/Startup_Code/__arm_end.o"
	@echo 'Finished building: $<'
	@echo ' '

Project_Settings/Startup_Code/__arm_start.o: ../Project_Settings/Startup_Code/__arm_start.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Project_Settings/Startup_Code/__arm_start.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Project_Settings/Startup_Code/__arm_start.o"
	@echo 'Finished building: $<'
	@echo ' '

Project_Settings/Startup_Code/kinetis_sysinit.o: ../Project_Settings/Startup_Code/kinetis_sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Project_Settings/Startup_Code/kinetis_sysinit.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Project_Settings/Startup_Code/kinetis_sysinit.o"
	@echo 'Finished building: $<'
	@echo ' '


