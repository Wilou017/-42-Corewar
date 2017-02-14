.name "GodFather"
.comment "I'm gonna make him an offer he can't refuse"

sti		r1, %:myld, %2
fork	%9
myld:
	ld %0, r4

sti		r16, %:drh, %0

drh:
sti		r16, %:myld, %0
