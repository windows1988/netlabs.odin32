        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   _O32_GetFileTime:PROC
        PUBLIC  O32_GetFileTime
O32_GetFileTime PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+20]
    push   dword ptr [esp+20]
    push   dword ptr [esp+20]
    push   dword ptr [esp+20]
    call   _O32_GetFileTime
    add    esp, 16
    pop    fs
    ret
O32_GetFileTime ENDP

CODE32          ENDS

                END
