        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   _O32_CreateFontIndirect:PROC
        PUBLIC  O32_CreateFontIndirect
O32_CreateFontIndirect PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+8]
    call   _O32_CreateFontIndirect
    add    esp, 4
    pop    fs
    ret
O32_CreateFontIndirect ENDP

CODE32          ENDS

                END
