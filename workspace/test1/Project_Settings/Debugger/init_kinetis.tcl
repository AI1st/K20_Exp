# this method initializes debug modules which are not affected by software reset 
# register names should be referenced including the register group name to improve performance 

proc init_debug_modules {} {
	# initialize LR to avoid invalid stack after reset
	reg "User\\/System Mode Registers/LR" = 0xFFFFFFFF

    # clear DWT function registers
	reg "Core Debug Registers/DEMCR" = 0x1000001
	reg "Data Watchpoint and Trace Unit Registers/DWT_FUNCTION0" = 0x0
	reg "Data Watchpoint and Trace Unit Registers/DWT_FUNCTION1" = 0x0
	reg "Data Watchpoint and Trace Unit Registers/DWT_FUNCTION2" = 0x0
	reg "Data Watchpoint and Trace Unit Registers/DWT_FUNCTION3" = 0x0
	# clear FPB comparators
	reg "Flash Patch and Breakpoint Unit Registers/FP_COMP0" = 0x0
	reg "Flash Patch and Breakpoint Unit Registers/FP_COMP1" = 0x0
	reg "Flash Patch and Breakpoint Unit Registers/FP_COMP2" = 0x0
	reg "Flash Patch and Breakpoint Unit Registers/FP_COMP3" = 0x0
	reg "Flash Patch and Breakpoint Unit Registers/FP_COMP4" =_<7lA���g<ċs�����DݔС�ʍ#��`-C\ ���_�,Co���,d2�
5�Y����]E�=`��*�S b�1�����de�0���9���W�nJ���/��ޢA��$��?�e�H	|��K5�ρP�Z��O��0��ə��ͽ���{N���=Y��H��P��]7�F��?��O�b��d5Y	�MO��4Y�0E���o	)�4ސ�.���rJ|���"��̨�w���tY�?h2��W;��Jl��B�d��n1	�B�i�lC�)A���;IB�n��:��Cݪ��i.�Ų"(�O��@[��l ��RvKT~����8ci��çAH��_A�!��˯}m�������a��
����#���H��z��������k��G��|N��:X�B���)%�&(tl`��G6H�$���.|�����87m�kv�]����L�lC�n,�,���RR�V�_�_��t���Rt�Ф
���Ζ��[t�ʌ�'+�_P}H�O]y�h5	ԡ:2��@�P�K��T�sl�h��Pz�iM�Z����{�]?B$q[����A�R)�ijA����~~����r��<�)�[@?��v>�����*U�_|�Xϡ��I�z��f��i�\�	ث��¡����h:���́�����ddJ_�������-�^E��Ԥ�L@�`�Z�<�f���S��R)qP�/T�JEA�$�s�Ǫ�{~H�J����#���}����D�?�,LN��P��#��:��3�������Ty6��?3��:H����)����κ�1��y�=�%j4B�.���'l�V�O��;j�p��_�jږ�PH�O�m���������Χr_�p��ڪib�$]��O�l���+�Ǟ�t���e�[�Wn*�R������f��vËJ�8]���:B�}��#�p���P��kЁ���7�23����@'���mH����W&~��M��d�Q�1���RC.��B��+�v��H��CI�+�ج�2��M�����V?�N4Ϥ��(�՘��/]	�SПSf�g�f-����gD�T�ZYm������\���~�䫳��

���j�ް��\/���H
�N�8]6�+q
�.���@�� ��q��Kf���͐~�x��e�i���blwe�ի�|[�Cݼ�P%<���rrzj�rh����a �d�E�H��/��cx�<jHB�V�̩�{�6���lh��MG�s�`OՅ���UM#����/�]�pCu5�v��|f��~�:U��{����K#�4��-w�������?%�E�/��5�Լf�{Ȋx���i!����g��+���5���YR?`t��W_�/��>�Yq�f�w����wLL���[�4|e��A��d�� o����:}a�>���_6��R�f��6��9�B��;U�H���B������&���ӌ+�Z�q��XR��5 ��,oo���cZ?�#OͶ���=�<�q���ȵ����րp�<U!h���F�����D�v�����Y�B�k%nMF�c��m�tէ��rr�}�]��R�U�ZA�VA�_Z`���9�.�
nq���D��$����$���e��ٖܒ�?��y-m���*i��l�ց��dX�8t~&H�L^Nӥ��r���<\ķ����IDa��Z3^�����F`7��Jf	�����o<�C�:�"+8,a��o��Z��{Lp�"^x����iR5��
�~,<��B$ԡ�>�o�(�0���Եsh1�O��9�'r<�J�������L��H.��
�Xj�@}��~T'I�ْ�;"��c��p�3��9r���g���'���I4���i�6Gvw�[#NMΠ�v"2-�{GƾzJu-�\u�<X�ws<#���j%.tm�ښ�61;����k܈嫌�	���� �2���d ̞�K��>jr����7Z�3qb�9s��`e%�0T7"5�5����Sh�g���сp[M��xy)Q�m�+V�EC��AEW �;.q��%9{ܪ�|H�׊�:sEI�%��ͦ&_�}�^�v�#0��w�����|��m�X>=ˑ�Z���������+^OZo֍^��a�N�r���rv`���AOݚ��(`['N��Q|~I������R�3�|U�g�����S$
:�N�k`0$�0�'?C>t->+/#ܰ�'�mK�^mC�o�J"Щ'�D@Ѧ�����.�����Uj)b�ࡍF�O�іL�q�e����xdB�(��s�`���