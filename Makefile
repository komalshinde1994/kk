TARGET ="server"
TARGET_2 = "client"
all:
	cc common.c  ${TARGET}.c -o ${TARGET} -lrdmacm -libverbs -lpthread
	cc common.c ${TARGET_2}.c -o ${TARGET_2} -lrdmacm -libverbs -lpthread


.PHONY: clean
clean:
       rm -f *.o ${TARGET} ${TARGET_2}
