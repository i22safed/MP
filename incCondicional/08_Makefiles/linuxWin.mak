#SISTEMA = _WINDOWS_
#SISTEMA = _LINUX_

ejecutable.exe: linuxWin.c
ifndef SISTEMA
	@echo Error: constante SISTEMA sin definir
	@echo "utilice: make -f linuxWin.mak [ SISTEMA =_WINDOWS_ | SISTEMA =_LINUX_]"
else
	gcc -D$(SISTEMA) linuxWin.c -o ejecutable.exe
endif