.name				"My name is not be calllllled..."
.comment			"Harry Potter get my nose back!!!"
com1:	ld	%0,r2
com2:	st	r1,6
com3:	live	%69
com4:	fork	%:com3
com5:	ld	:com6,r2
com6:	st	r1,6
com7:	live	%69
com8:	zjmp	%:com6
com9:	ldi	%:com6,%4,r3
com10:	ldi	%:com7,%3,r4
com11:	ldi	%:com8,%2,r5
com12:	sti	r2,%100,%100
com13:	sti	r3,%100,%97
com14:	sti	r4,%100,%94
com15:	sti	r5,%100,%91
com16:	st	r1,6
com17:	live	%69
com18:	ld	%0,r6
com19:	fork	%152
com20:	zjmp	%:com3
