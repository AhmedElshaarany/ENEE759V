#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/tirtos_msp430_2_10_01_38/packages;C:/ti/tirtos_msp430_2_10_01_38/products/bios_6_41_00_26/packages;C:/ti/tirtos_msp430_2_10_01_38/products/uia_2_00_02_39/packages;C:/ti/ccsv6/ccs_base;C:/Users/Ahmed/GOOGLE~1/Computer/SUMMER~1/EMBEDD~1/Exam/Workspace/exam_p2_random/.config
override XDCROOT = c:/ti/xdctools_3_30_06_67_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/tirtos_msp430_2_10_01_38/packages;C:/ti/tirtos_msp430_2_10_01_38/products/bios_6_41_00_26/packages;C:/ti/tirtos_msp430_2_10_01_38/products/uia_2_00_02_39/packages;C:/ti/ccsv6/ccs_base;C:/Users/Ahmed/GOOGLE~1/Computer/SUMMER~1/EMBEDD~1/Exam/Workspace/exam_p2_random/.config;c:/ti/xdctools_3_30_06_67_core/packages;..
HOSTOS = Windows
endif
