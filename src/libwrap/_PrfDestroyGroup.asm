        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   PrfDestroyGroup:PROC
        PUBLIC  _PrfDestroyGroup
_PrfDestroyGroup PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+12]
    push   dword ptr [esp+12]
    call   PrfDestroyGroup
    add    esp, 8
    pop    fs
    ret
_PrfDestroyGroup ENDP

CODE32          ENDS

                END
