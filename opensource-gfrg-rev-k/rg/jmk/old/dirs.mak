JMK_SUBDIRS+=$(JMK_SUBDIRS_m)
JMK_SUBDIRS+=$(JMK_SUBDIRS_y)

# *_SUBDIRS variables are using the mechanism in copy_db.mak
JMK_CLEAN_SUBDIRS?=$(JMK_SUBDIRS)
JMK_ARCHCONFIG_SUBDIRS?=$(JMK_SUBDIRS)
JMK_DOCS_SUBDIRS?=$(JMK_SUBDIRS)
JMK_RUN_UNITTESTS_SUBDIRS?=$(JMK_SUBDIRS)

DOCS_SUBDIRS_=$(JMK_DOCS_SUBDIRS:%=%/xmldocs.subdir__)
CLEAN_SUBDIRS_=$(JMK_CLEAN_SUBDIRS:%=%/clean.subdir__)
ARCHCONFIG_SUBDIRS_=$(JMK_ARCHCONFIG_SUBDIRS:%=%/archconfig.subdir__)
RUN_UNITTESTS_SUBDIRS_=$(JMK_RUN_UNITTESTS_SUBDIRS:%=%/run_unittests.subdir__)
SUBDIRS_=$(JMK_SUBDIRS:%=%/all.subdir__)

