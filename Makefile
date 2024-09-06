.POSIX:

all:
	${CC} ${CFLAGS}  gettext_program.c -o gettext_program
	${CC} ${CFLAGS}  gettext.c -o gettext
	${CC} ${CFLAGS}  xgettext.c -o xgettext
	${CC} ${CFLAGS} -fPIC -nostdlib libgettextpo.c -o libgettextpo.so.0.5.10 ${LDFLAGS} -shared -Wl,-soname,libgettextpo.so.0

minimal:
	${CC} ${CFLAGS} -DJUST_TOUCH_FILES gettext_program.c -o gettext_program
	${CC} ${CFLAGS}  gettext.c -o gettext
	${CC} ${CFLAGS}  xgettext.c -o xgettext
	${CC} ${CFLAGS}  xgettext.c -o xgettext
	${CC} ${CFLAGS} -fPIC -nostdlib libgettextpo.c -o libgettextpo.so.0.5.10 ${LDFLAGS} -shared -Wl,-soname,libgettextpo.so.0

install:
	mkdir -p ${DESTDIR}/usr/bin
	cp -f gettext_program ${DESTDIR}/usr/bin/msgmerge
	cp -f gettext_program ${DESTDIR}/usr/bin/msgfmt
	ln -rsf ${DESTDIR}/usr/bin/msgfmt ${DESTDIR}/usr/bin/gmsgfmt
	cp -f gettext_program ${DESTDIR}/usr/bin/msginit
	cp -f gettext_program ${DESTDIR}/usr/bin/msgattrib
	cp -f gettext_program ${DESTDIR}/usr/bin/msgcat
	cp -f gettext_program ${DESTDIR}/usr/bin/msgcomm
	cp -f gettext_program ${DESTDIR}/usr/bin/msgconv
	cp -f gettext_program ${DESTDIR}/usr/bin/msgen
	cp -f gettext_program ${DESTDIR}/usr/bin/msgfilter
	cp -f gettext_program ${DESTDIR}/usr/bin/msggrep
	cp -f gettext_program ${DESTDIR}/usr/bin/msgunfmt
	cp -f gettext_program ${DESTDIR}/usr/bin/msguniq
	cp -f gettext ${DESTDIR}/usr/bin/gettext
	ln -rsf ${DESTDIR}/usr/bin/gettext ${DESTDIR}/usr/bin/ngettext
	cp -f xgettext ${DESTDIR}/usr/bin/xgettext
	mkdir -p ${DESTDIR}/usr/lib64
	cp -f libgettextpo.so.0.5.10 ${DESTDIR}/usr/lib64/libgettextpo.so.0.5.10
	ln -rsf ${DESTDIR}/usr/lib64/libgettextpo.so.0.5.10 ${DESTDIR}/usr/lib64/libgettextpo.so.0
	ln -rsf ${DESTDIR}/usr/lib64/libgettextpo.so.0 ${DESTDIR}/usr/lib64/libgettextpo.so
	mkdir -p ${DESTDIR}/usr/include
	cp -f gettext-po.h ${DESTDIR}/usr/include/gettext-po.h
	mkdir -p ${DESTDIR}/usr/share/aclocal
	cp -f aclocal/* ${DESTDIR}/usr/share/aclocal/
	touch ${DESTDIR}/usr/bin/autopoint
	chmod 755 ${DESTDIR}/usr/bin/autopoint
	touch ${DESTDIR}/usr/bin/envsubst
	chmod 755 ${DESTDIR}/usr/bin/envsubst
	touch ${DESTDIR}/usr/bin/gettextize
	chmod 755 ${DESTDIR}/usr/bin/gettextize
	touch ${DESTDIR}/usr/bin/msgcmp
	chmod 755 ${DESTDIR}/usr/bin/msgcmp
	touch ${DESTDIR}/usr/bin/msgexec
	chmod 755 ${DESTDIR}/usr/bin/msgexec
	touch ${DESTDIR}/usr/bin/recode-sr-latin
	chmod 755 ${DESTDIR}/usr/bin/recode-sr-latin

uninstal:
	rm -f ${DESTDIR}/usr/bin/msgmerge
	rm -f ${DESTDIR}/usr/bin/msgfmt
	rm -f ${DESTDIR}/usr/bin/gmsgfmt
	rm -f ${DESTDIR}/usr/bin/msginit
	rm -f ${DESTDIR}/usr/bin/msgattrib
	rm -f ${DESTDIR}/usr/bin/msgcat
	rm -f ${DESTDIR}/usr/bin/msgcomm
	rm -f ${DESTDIR}/usr/bin/msgconv
	rm -f ${DESTDIR}/usr/bin/msgen
	rm -f ${DESTDIR}/usr/bin/msgfilter
	rm -f ${DESTDIR}/usr/bin/msggrep
	rm -f ${DESTDIR}/usr/bin/msgunfmt
	rm -f ${DESTDIR}/usr/bin/msguniq
	rm -f ${DESTDIR}/usr/bin/gettext
	rm -f ${DESTDIR}/usr/bin/ngettext
	rm -f ${DESTDIR}/usr/bin/xgettext
	rm -f ${DESTDIR}/usr/lib64/libgettextpo.so.0.5.10
	rm -f ${DESTDIR}/usr/lib64/libgettextpo.so.0
	rm -f ${DESTDIR}/usr/lib64/libgettextpo.so
	rm -f ${DESTDIR}/usr/include/gettext-po.h
	rm -f ${DESTDIR}/usr/share/aclocal/build-to-host.m4
	rm -f ${DESTDIR}/usr/share/aclocal/host-cpu-c-abi.m4
	rm -f ${DESTDIR}/usr/share/aclocal/intlmacosx.m4
	rm -f ${DESTDIR}/usr/share/aclocal/lib-link.m4
	rm -f ${DESTDIR}/usr/share/aclocal/nls.m4
	rm -f ${DESTDIR}/usr/share/aclocal/progtest.m4
	rm -f ${DESTDIR}/usr/share/aclocal/gettext.m4
	rm -f ${DESTDIR}/usr/share/aclocal/iconv.m4
	rm -f ${DESTDIR}/usr/share/aclocal/lib-ld.m4
	rm -f ${DESTDIR}/usr/share/aclocal/lib-prefix.m4
	rm -f ${DESTDIR}/usr/share/aclocal/po.m4
	rm -f ${DESTDIR}/usr/bin/autopoint
	rm -f ${DESTDIR}/usr/bin/envsubst
	rm -f ${DESTDIR}/usr/bin/gettextize
	rm -f ${DESTDIR}/usr/bin/msgcmp
	rm -f ${DESTDIR}/usr/bin/msgexec
	rm -f ${DESTDIR}/usr/bin/recode-sr-latin

clean:
	rm -f gettext gettext_program libgettextpo.so.0.5.10 xgettext
