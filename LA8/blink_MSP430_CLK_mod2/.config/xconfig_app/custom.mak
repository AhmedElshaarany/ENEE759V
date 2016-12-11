## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e430X linker.cmd package/cfg/app_pe430X.oe430X

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/app_pe430X.xdl
	$(SED) 's"^\"\(package/cfg/app_pe430Xcfg.cmd\)\"$""\"C:/TI_RTOS/Workspace/blink_MSP430_CLK_mod2/.config/xconfig_app/\1\""' package/cfg/app_pe430X.xdl > $@
	-$(SETDATE) -r:max package/cfg/app_pe430X.h compiler.opt compiler.opt.defs
