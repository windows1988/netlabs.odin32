        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   WinTerminateApp:PROC
        PUBLIC  _WinTerminateApp
_WinTerminateApp PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+8]
    call   WinTerminateApp
    add    esp, 4
    pop    fs
    ret
_WinTerminateApp ENDP

CODE32          ENDS

                END
