        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   _O32_DeleteObject:PROC
        PUBLIC  O32_DeleteObject
O32_DeleteObject PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+8]
    call   _O32_DeleteObject
    add    esp, 4
    pop    fs
    ret
O32_DeleteObject ENDP

CODE32          ENDS

                END
