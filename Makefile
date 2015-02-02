DIRS = lib 15-IPC

all:
	$(MAKE) './systype.sh'

clean:
	for i in $(DIRS); do \
		(cd $$i && $(MAKE) -f '../systype.sh'.mk clean) || exit 1; \
	done

freebsd:
	for i in $(DIRS); do \
		(cd $$i && $(MAKE) -f freebsd.mk) || exit 1; \
	done

linux:
	for i in $(DIRS); do \
		(cd $$i && $(MAKE) -f linux.mk) || exit 1; \
	done
