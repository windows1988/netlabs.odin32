        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   WinLoadMessage:PROC
        PUBLIC  _WinLoadMessage
_WinLoadMessage PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+24]
    push   dword ptr [esp+24]
    push   dword ptr [esp+24]
    push   dword ptr [esp+24]
    push   dword ptr [esp+24]
    call   WinLoadMessage
    add    esp, 20
    pop    fs
    ret
_WinLoadMessage ENDP

CODE32          ENDS

                END
