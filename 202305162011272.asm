assume cs:code, ds:data, ss:stack

data segment
    num db 30h,30h,32h,35h,36h
data ends

code segment
    start:
        MOV AX, data
        MOV DS, AX
        MOV SI, offset num
        MOV BL, 0ah ; for MUL instruction
        MOV CX, 4h ; for LOOP instruction
        MOV AH, 0h ; for 
        MOV AL, DS:SI
        SUB AL, 30h
    p1:
        MUL BL
        INC SI
        MOV DL, [SI]
        SUB DL, 30h
        ADD AX, DX ; wht i do not need to care about DH here
        LOOP p1
        MOV CX, 10h
        MOV BX, AX
    p2:
        ROL BX, 1 
        MOV DL, BL
        AND DL, 01h
        ADD DL, 30h
        MOV AH, 02h
        INT 21h
        LOOP p2
        MOV AH, 4ch
        INT 21h                
code ends

end start