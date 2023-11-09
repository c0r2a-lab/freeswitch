
#include <switch.h>
#include <switch_version.h>

const char *switch_version_major_str = SWITCH_VERSION_MAJOR;
const char *switch_version_minor_str = SWITCH_VERSION_MINOR;
const char *switch_version_micro_str = SWITCH_VERSION_MICRO;
const char *switch_version_revision_str = SWITCH_VERSION_REVISION;
const char *switch_version_revision_human_str = SWITCH_VERSION_REVISION_HUMAN;
const char *switch_version_full_str = SWITCH_VERSION_FULL;
const char *switch_version_full_human_str = SWITCH_VERSION_FULL_HUMAN;

SWITCH_DECLARE(const char *)switch_version_major(void) {return switch_version_major_str;}
SWITCH_DECLARE(const char *)switch_version_minor(void) {return switch_version_minor_str;}
SWITCH_DECLARE(const char *)switch_version_micro(void) {return switch_version_micro_str;}

SWITCH_DECLARE(const char *)switch_version_revision(void) {return switch_version_revision_str;}
SWITCH_DECLARE(const char *)switch_version_revision_human(void) {return switch_version_revision_human_str;}
SWITCH_DECLARE(const char *)switch_version_full(void) {return switch_version_full_str;}
SWITCH_DECLARE(const char *)switch_version_full_human(void) {return switch_version_full_human_str;}

