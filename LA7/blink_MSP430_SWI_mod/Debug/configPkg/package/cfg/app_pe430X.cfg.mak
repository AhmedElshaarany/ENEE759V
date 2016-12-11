# invoke SourceDir generated makefile for app.pe430X
app.pe430X: .libraries,app.pe430X
.libraries,app.pe430X: package/cfg/app_pe430X.xdl
	$(MAKE) -f C:\TI_RTOS\Workspace\blink_MSP430_SWI_mod/src/makefile.libs

clean::
	$(MAKE) -f C:\TI_RTOS\Workspace\blink_MSP430_SWI_mod/src/makefile.libs clean

