        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   WinSetWindowPos:PROC
        PUBLIC  _WinSetWindowPos
_WinSetWindowPos PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+32]
    push   dword ptr [esp+32]
    push   dword ptr [esp+32]
    push   dword ptr [esp+32]
    push   dword ptr [esp+32]
    push   dword ptr [esp+32]
    push   dword ptr [esp+32]
    call   WinSetWindowPos
    add    esp, 28
    pop    fs
    ret
_WinSetWindowPos ENDP

CODE32          ENDS

                END
