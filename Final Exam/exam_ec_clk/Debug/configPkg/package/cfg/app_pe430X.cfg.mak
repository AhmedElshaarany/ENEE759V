# invoke SourceDir generated makefile for app.pe430X
app.pe430X: .libraries,app.pe430X
.libraries,app.pe430X: package/cfg/app_pe430X.xdl
	$(MAKE) -f C:\Users\Ahmed\GOOGLE~1\Computer\SUMMER~1\EMBEDD~1\Exam\Workspace\exam_ec_clk/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Ahmed\GOOGLE~1\Computer\SUMMER~1\EMBEDD~1\Exam\Workspace\exam_ec_clk/src/makefile.libs clean

