        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   DosCreateNPipe:PROC
        PUBLIC  _DosCreateNPipe
_DosCreateNPipe PROC NEAR
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
    call   DosCreateNPipe
    add    esp, 28
    pop    fs
    ret
_DosCreateNPipe ENDP

CODE32          ENDS

                END
