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
	reg "Flash Patch and Breakpoint Unit Registers/FP_COMP4" =W��hz)]e�4���3,��}��JU@��x7ևb�ሤ2�6�}��zJ����߶���DI�G?���3�ۇ�w�G���f����_�@���2��Dfvʵv{}u+p;%D�L�6~��-/��.�x&b"�:|������99�3Ԭ&��*k)����g�F��(�>�#�Y���$�ޏ��m����ӆɴMlP��.��w�n���g;��c��/���W=)��v�%�_��c��2�/�B���X�R+*�Ě�ZOq`#h�ԧ �x��[_�7T\$�,�
Xf��������*�r�.�� �D���Bڿ�cC�.��4t��]�D�#[S�;���.r��NB������hH��-���OI?�N�Z���n��Q��*5lo��>��X��>��0F/�h5�x���筙�6⇗�.)�R�Y	b'f�_�������	a�	��SvL(��1qG�R���;+O�W�z��7tN�K[�5E)�1k.��ӕ�/� ���_�N@�4"p�`G�/�e,�x�wF� �Js� n]�?%��=��`d��H�jd�I6���|׺�qM�&q���	�;,i�C2�G�cg6��[o��R2���H}�I�s��2�>?b�WcF,n������O��~����;-�b%)�R�B��%��v������6���LY�8��꾽?��X�J�n\G�Җ+��CA|�b�q��-�,����3h�r�=����}i�R�����u�8����P���}%�U���,������?��=up���SEEO��A�ܫ%mK�+�{	�3'BP��B��p@8.���8�8�U�F���:L;58^��@n�G��yt,����{T�D�k���b�����q�i���m��a��Z6����_|JC��{z����i�s+M��V�'�����#�{��R�#Q�e��~քq��
��yMy�J�ס=Gi��1���C�t=/z��p�d�e��-�1�FD�� �!\]Rг��l�5ta Watchpoint and Trace Unit Registers/DWT_MASK2" =0x0
    reg "Data Watchpoint and Trace Unit Registers/DWT_MASK3" =0x0
	# clear ITM registers
    reg "Instrumentation Trace Macrocell Registers/ITM_LAR" =0xc5acce55
	reg "Instrumentation Trace Macrocell Registers/ITM_TER" =0x0
	reg "Instrumentation Trace Macrocell Registers/ITM_TPR" =0x0
    reg "Instrumentation Trace Macrocell Registers/ITM_TCR" =0x0
    reg "Instrumentation Trace Macrocell Registers/ITM_LAR" =0x1
    # reset Funnel registers
    reg "Embedded Trace Funnel Registers/ETF_FCR" =0x300
    # clear MCM registers
    reg "Core Platform Miscellaneous Control Module (MCM) Registers/MCM_ETBCC" =0x0
    reg "Core Platform Miscellaneous Control Module (MCM) Registers/MCM_ETBRL" =0x0
    # set SCB_VTOR register for RAM
    reg "System Control Registers/SCB_VTOR" =0x20000000
}

proc envsetup {} {
	# Environment Setup
	radix x 
	config hexprefix 0x
	config MemIdentifier p 
	config MemWidth 32 
	config MemAccess 32 
	config MemSwap off
}

#-------------------------------------------------------------------------------
# Main                                                                          
#-------------------------------------------------------------------------------

  envsetup
  init_debug_modules
  init_trace_modules
