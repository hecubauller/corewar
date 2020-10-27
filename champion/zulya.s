.name "Zulya"
.comment "Sibela Chechem"

loop:	
	sti r1, %:live, %21

live:	
	live %1
	ld %0, r2
	ld %0, r3
	ld %0, r4
	zjmp %:live
