.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
sti	r1, %:live, %1			;change live by the right value
sti	r1, %:live2, %1			;change live by the right value
ld	%1, r3
ld	%33, r6
#While (r2 < 10)
forks:
add	r2, r3, r2		;increment r2
xor	r2, %15, r4		;if (r4) {carry = 0}
live2:
	live 	%4
zjmp	%:endwhile		;if (carry)
fork	%:forks
ld	%0, r4			;carry = 1
zjmp	%:forks
#EndWhile
endwhile:
ld	%0, r4			;carry = 1

live:
live %4
zjmp %:live
<<<<<<< HEAD

;0b 68          01        00 45                 00 01
;0b 68          01        00 22                 00 01
;02 90          00 00 00 01             03
;02 90          00 00 00 21                     06
;04 54          02              03                      02
;08 64          02              00 00 00 0f 04
;01                     00 00 00 04
;09                     00 10    //Zjump endwhile
;0c                     ff eb    // Fork to forks
;02 90          00 00 00 00             04
;09                     ff e1   //Zjump to forks
;02 90          00 00 00 00             04
;01                     00 00 00 04
;09                     ff fb   //Zjump to live;
=======
>>>>>>> 30d26a99da1a56c5563db2903ee422ac083b7585
