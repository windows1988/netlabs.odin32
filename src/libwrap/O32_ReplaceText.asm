        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   _O32_ReplaceText:PROC
        PUBLIC  O32_ReplaceText
O32_ReplaceText PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+8]
    call   _O32_ReplaceText
    add    esp, 4
    pop    fs
    ret
O32_ReplaceText ENDP

CODE32          ENDS

                END