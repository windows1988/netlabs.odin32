        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   RexxLoadMacroSpace:PROC
        PUBLIC  _RexxLoadMacroSpace
_RexxLoadMacroSpace PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+16]
    push   dword ptr [esp+16]
    push   dword ptr [esp+16]
    call   RexxLoadMacroSpace
    add    esp, 12
    pop    fs
    ret
_RexxLoadMacroSpace ENDP

CODE32          ENDS

                END
