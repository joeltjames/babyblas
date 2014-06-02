objects = dot.o dls.o ils.o mmm.o mvv.o vvm.o timers.o con.o
source = dot.c dls.c ils.c mmm.c mvv.c vvm.c timers.cc con.c

#Makes objects, library, and cleans up
all: only_obj only_lib clean
#Only makes the objects for the library
only_obj:
	gcc -c $(source)
#Only makes the library from the object files, removes the old library if it exists
only_lib:
	touch bblas.a
	rm bblas.a
	ar -cvq bblas.a $(objects)
#Removes un-needed object
clean:
	rm *.o
