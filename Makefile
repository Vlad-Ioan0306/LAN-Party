build:
	gcc ./src/main.c ./src/solve.c ./src/solve1.c ./src/solve2.c ./src/solve3.c -o lanParty

run1:
	./lanParty ./date/t1/c.in ./date/t1/d.in ./out/out1.out
	./lanParty ./date/t2/c.in ./date/t2/d.in ./out/out2.out
	./lanParty ./date/t3/c.in ./date/t3/d.in ./out/out3.out

run2:
	./lanParty ./date/t4/c.in ./date/t4/d.in ./out/out4.out
	./lanParty ./date/t5/c.in ./date/t5/d.in ./out/out5.out
	./lanParty ./date/t6/c.in ./date/t6/d.in ./out/out6.out

run3:
	./lanParty ./date/t7/c.in ./date/t7/d.in ./out/out7.out
	./lanParty ./date/t8/c.in ./date/t8/d.in ./out/out8.out
	./lanParty ./date/t9/c.in ./date/t9/d.in ./out/out9.out

runall: run1 run2 run3

clean:
	rm lanParty
