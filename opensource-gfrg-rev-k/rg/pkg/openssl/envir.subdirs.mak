JMK_EXPORT_HEADERS_DIR=openssl

CFLAG=-DTERMIO

ifeq ($(TARGET_ENDIANESS),BIG)
  JMK_CFLAGS+=-DB_ENDIAN
else
  JMK_CFLAGS+=-DL_ENDIAN
endif

PERL=perl