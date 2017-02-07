.name "load"
.comment "load"

main:
	live	%1
	ld		%-128, r6
	zjmp	%:main
