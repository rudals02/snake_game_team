.global RandomApple_asm
RandomApple_asm:
                push    {lr}
                sub     sp, sp, #12 @sp<-sp-12
                bl      rand @r0<-rand()
                mov     r1, #80 @r1<-width
apple_loop_x:
            cmp     r0, r1
            blt     apple_x
            sub     r0, r0, r1 @r0<-r0-r1
            b       apple_loop_x
apple_x:
        str     r0, [sp, #0] @r0<-sp in 0
        bl      rand
        mov     r1, #24 @r1<-height
apple_loop_y:
            cmp     r0, r1
            blt     apple_y
            sub     r0, r0, r1
            b       apple_loop_y
apple_y:
        str     r0, [sp, #4]
        bl      rand
        mov     r1, #3 @r1<-3
apple_loop_size:
                cmp     r0, r1
                blt     apple_loop_size
                sub     r0, r0, r1
                b       apple_loop_size
apple_size:
            add     r0, r0, #1 @size+1
            str     r0, [sp, #8]

            mov     r0, sp @r0<-sp
            add     sp, sp, #12 @sp<-sp+12
            pop{pc}

