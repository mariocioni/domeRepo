CC      =  gcc
CFLAGS  = -O -Wall -lm
EXEC    =  bin/readF.out
OUT		=  bin/
SRC		=  src/
OBJS    =  $(OUT)distance_calculator.o $(OUT)reader2.o 
INCLS	=  $(SRC)distance_calculator.h

$(EXEC):  $(OBJS)
	$(CC)  $(CFLAGS) -o bin/readF.out $(OBJS) -lm
	
#$(OUT)reader2.o: src/distance_calculator.h $(OUT)distance_calculator.o
#	gcc -c src/reader2.c -o $(OUT)/reader2.o -lm
#$(OUT)distance_calculator.o: src/distance_calculator.h
#	gcc -c src/distance_calculator.c -o $(OUT)distance_calculator.o -lm	
$(OUT)reader2.o: src/distance_calculator.h $(OUT)distance_calculator.o
	$(CC) $(CFLAGS) -c $(SRC)reader2.c -o $(OUT)/reader2.o -lm
$(OUT)distance_calculator.o: src/distance_calculator.h
	$(CC) $(CFLAGS) -c $(SRC)distance_calculator.c -o $(OUT)distance_calculator.o -lm	


#$(OBJS): $(SRC)distance_calculator.h
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

#$(SRC)distance_calculator.h

#gcc -c src/distance_calculator.c -o bin/distance_calculator.o -lm
#gcc -c src/reader2.c -o bin/reader2.o -lm
#gcc bin/reader2.o bin/distance_calculator.o -o bin/readF.out -lm

