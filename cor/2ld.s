.name		"ld"
.comment	"LD"


start:
	ld		%:end, r1

body:
	ld		%0, r2
	ld		%50, r3
	ld		%100, r10
	ld		%500, r13
	ld		%1000, r16

end:
	ld		%:start, r1
	aff		r1
