.name "GodFather"
.comment "I'm gonna make him an offer he can't refuse"

fork		%:initfork
ld			%0, r16
base:
	live	%4294967295
	fork	%:shot
	sti		r1, %:initfork, %1
	sti		r1, %:initfork, %9
	sti		r1, %:initfork, %17
	sti		r1, %:wall, %1
	sti		r1, %:usine, %1
	sti		r1, %:usine, %9
	sti		r1, %:usine, %17
	sti		r1, %:usine, %25
	sti		r1, %:usine, %33
	sti		r1, %:alive, %1
	sti		r1, %:attforker, %1
	sti		r1, %:attforker, %9
	sti		r1, %:attforker, %17
	sti		r1, %:shot, %1
	sti		r1, %:initshot1, %1
	sti		r1, %:initshot2, %1
	sti		r1, %:salve, %1
	sti		r1, %:salve, %9
	sti		r1, %:salve, %17
	sti		r1, %:salve3, %1
	sti		r1, %:salve4, %1
	sti		r1, %:salve5, %1

initfork:
	live	%2863311530
	fork	%:wall
	live	%2863311530
	fork	%:usine
	live	%2863311530
	fork	%:initfork
	ld		%0, r16
	zjmp	%:initfork

wall:
	live	%2863311530
	# st			r16, -34
	st			r16, -43
	# st			r16, -52
	st			r16, -61
	# st			r16, -70
	st			r16, -79
	# st			r16, -88
	st			r16, -97
	# st			r16, -106
	st			r16, -115
	# st			r16, -124
	st			r16, -133
	# st			r16, -142
	st			r16, -151
	# st			r16, -160
	st			r16, -169
	# st			r16, -178
	st			r16, -187
	# st			r16, -196
	st			r16, -205
	# st			r16, -214
	st			r16, -223
	# st			r16, -232
	st			r16, -241
	# st			r16, -250
	st			r16, -259
	# st			r16, -268
	st			r16, -277
	# st			r16, -286
	st			r16, -295
	# st			r16, -304
	st			r16, -313
	# st			r16, -322
	st			r16, -331
	# st			r16, -340
	st			r16, -349
	# st			r16, -358
	st			r16, -367
	# st			r16, -376
	st			r16, -385
	st			r16, -394
	# ld		%0, r16
	zjmp	%:wall

usine:
	live	%2863311530
	fork	%:wall
	live	%2863311530
	fork	%:shot
	live	%2863311530
	fork	%:attforker
	live	%2863311530
	fork	%:usine
	live	%2863311530
	ld		%0, r16
	fork	%:alive
	zjmp	%:usine

alive:
	live	%2863311530
	zjmp	%:alive

attforker:
	live	%2863311530
	fork	%:attforker
	live	%2863311530
	fork	%:shot
	live	%2863311530
	fork	%:salve
	ld		%0, r16
	zjmp	%:attforker

shot:
	live	%2863311530
	fork	%:initshot2

initshot1:
	live	%2863311530
	ld      %190054927, r2
	ld      %506, r3
	ld		%0, r15
	zjmp    %:printshot

initshot2:
	live	%2863311530
	# ld      %50921472, r2 || jump 0
	ld      %50921973, r2
	ld      %510, r3
	ld		%0, r15
	zjmp    %:printshot

printshot:
	sti		r2, r15, r3
	zjmp	%501 # shot1 - 5

salve:
	live	%2863311530
	fork	%:salve
	live	%2863311530
	fork	%:salve4
	live	%2863311530
	fork	%:salve5

salve3:
	live	%2863311530
	fork	%:initsalve3

initsalve1:
	add		r16, r1, r2
	ld      %22, r3
	ld		%0, r15
	zjmp    %:printsalve

salve4:
	live	%2863311530
	fork	%:initsalve4

initsalve2:
	lld      %1409421059, r2
	ld      %17, r3
	ld		%0, r15
	zjmp    %:printsalve

salve5:
	live	%2863311530
	fork	%:initsalve6

initsalve5:
	add		r16, r1, r2
	ld      %511, r3
	ld		%0, r15
	zjmp    %:printsalve

initsalve3:
	# add		r16, r1, r2
	lld      %27962026, r2
	ld      %21, r3
	ld		%0, r15
	zjmp    %:printsalve

initsalve4:
	lld      %2852716550, r2
	ld      %25, r3
	ld		%0, r15
	zjmp    %:printsalve

initsalve6:
	lld      %150994955, r2
	ld      %13, r3
	ld		%0, r15
	zjmp    %:printsalve

printsalve:
	sti		r2, r15, r3
	zjmp	%10
