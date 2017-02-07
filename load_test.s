.name "load"
.comment "load"

main:
	ld		%42, r1
	#add 	r1, r11, r13
	#sub 	r1, r11, r13
	#and 	r1, r1, r13
	#or 	r1, r13, r13
	#xor 	r1, r13, r13
	#lldi    %-2, %:main, r16
	#lld     %:main , r16
	live	%1
	zjmp	%:main
