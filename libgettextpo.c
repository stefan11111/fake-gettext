 
#ifndef _GETTEXT_PO_H
#define _GETTEXT_PO_H 1
#include <stdlib.h>
#ifdef __cplusplus
"C" {
#endif
 
 
#define LIBGETTEXTPO_VERSION 0x001605
int libgettextpo_version;
 
 
typedef struct po_file *po_file_t;
 
typedef struct po_message_iterator *po_message_iterator_t;
 
typedef struct po_message *po_message_t;
 
typedef struct po_filepos *po_filepos_t;
 
struct po_error_handler
{
 
void (*error) (int status, int errnum,
const char *format, ...)
#if ((__GNUC__ == 3 && __GNUC_MINOR__ >= 1) || __GNUC__ > 3) && !__STRICT_ANSI__
__attribute__ ((__format__ (__printf__, 3, 4)))
#endif
;
 
void (*error_at_line) (int status, int errnum,
const char *filename, unsigned int lineno,
const char *format, ...)
#if ((__GNUC__ == 3 && __GNUC_MINOR__ >= 1) || __GNUC__ > 3) && !__STRICT_ANSI__
__attribute__ ((__format__ (__printf__, 5, 6)))
#endif
;
 
void (*multiline_warning) (char *prefix, char *message);
 
void (*multiline_error) (char *prefix, char *message);
};
typedef const struct po_error_handler *po_error_handler_t;
 
#define PO_SEVERITY_WARNING     0 /* just a warning, tell the user */
#define PO_SEVERITY_ERROR       1 /* an error, the operation cannot complete */
#define PO_SEVERITY_FATAL_ERROR 2 /* an error, the operation must be aborted */
struct po_xerror_handler
{
 
void (*xerror) (int severity,
po_message_t message,
const char *filename, size_t lineno, size_t column,
int multiline_p, const char *message_text);
 
void (*xerror2) (int severity,
po_message_t message1,
const char *filename1, size_t lineno1, size_t column1,
int multiline_p1, const char *message_text1,
po_message_t message2,
const char *filename2, size_t lineno2, size_t column2,
int multiline_p2, const char *message_text2);
};
typedef const struct po_xerror_handler *po_xerror_handler_t;
 
 
 
po_file_t po_file_create (void) { return 0; }
 
#define po_file_read po_file_read_v3
po_file_t po_file_read (const char *filename,
po_xerror_handler_t handler) { return 0; }
 
#define po_file_write po_file_write_v2
po_file_t po_file_write (po_file_t file, const char *filename,
po_xerror_handler_t handler) { return 0; }
 
void po_file_free (po_file_t file) {}
 
const char * const * po_file_domains (po_file_t file) { return 0; }
 
 
const char * po_file_domain_header (po_file_t file, const char *domain) { return 0; }
 
char * po_header_field (const char *header, const char *field) { return 0; }
 
char * po_header_set_field (const char *header, const char *field, const char *value) { return 0; }
 
 
po_message_iterator_t po_message_iterator (po_file_t file, const char *domain) { return 0; }
 
void po_message_iterator_free (po_message_iterator_t iterator) {}
 
po_message_t po_next_message (po_message_iterator_t iterator) { return 0; }
 
void po_message_insert (po_message_iterator_t iterator, po_message_t message) {}
 
 
po_message_t po_message_create (void) { return 0; }
 
const char * po_message_msgctxt (po_message_t message) { return 0; }
 
void po_message_set_msgctxt (po_message_t message, const char *msgctxt) {}
 
const char * po_message_msgid (po_message_t message) { return 0; }
 
void po_message_set_msgid (po_message_t message, const char *msgid) {}
 
const char * po_message_msgid_plural (po_message_t message) { return 0; }
 
void po_message_set_msgid_plural (po_message_t message, const char *msgid_plural) {}
 
const char * po_message_msgstr (po_message_t message) { return 0; }
 
void po_message_set_msgstr (po_message_t message, const char *msgstr) {}
 
const char * po_message_msgstr_plural (po_message_t message, int index) { return 0; }
 
void po_message_set_msgstr_plural (po_message_t message, int index, const char *msgstr) {}
 
const char * po_message_comments (po_message_t message) { return 0; }
 
void po_message_set_comments (po_message_t message, const char *comments) {}
 
const char * po_message_extracted_comments (po_message_t message) { return 0; }
 
void po_message_set_extracted_comments (po_message_t message, const char *comments) {}
 
po_filepos_t po_message_filepos (po_message_t message, int i) { return 0; }
 
void po_message_remove_filepos (po_message_t message, int i) {}
 
void po_message_add_filepos (po_message_t message, const char *file, size_t start_line) {}
 
const char * po_message_prev_msgctxt (po_message_t message) { return 0; }
 
void po_message_set_prev_msgctxt (po_message_t message, const char *prev_msgctxt) {}
 
const char * po_message_prev_msgid (po_message_t message) { return 0; }
 
void po_message_set_prev_msgid (po_message_t message, const char *prev_msgid) {}
 
const char * po_message_prev_msgid_plural (po_message_t message) { return 0; }
 
void po_message_set_prev_msgid_plural (po_message_t message, const char *prev_msgid_plural) {}
 
int po_message_is_obsolete (po_message_t message) { return 0; }
 
void po_message_set_obsolete (po_message_t message, int obsolete) {}
 
int po_message_is_fuzzy (po_message_t message) { return 0; }
 
void po_message_set_fuzzy (po_message_t message, int fuzzy) {}
 
int po_message_is_format (po_message_t message, const char *format_type) { return 0; }
 
void po_message_set_format (po_message_t message, const char *format_type, int value) {}
 
int po_message_is_range (po_message_t message, int *minp, int *maxp) { return 0; }
 
void po_message_set_range (po_message_t message, int min, int max) {}
 
 
const char * po_filepos_file (po_filepos_t filepos) { return 0; }
 
size_t po_filepos_start_line (po_filepos_t filepos) { return 0; }
 
 
const char * const * po_format_list (void) { return 0; }
 
const char * po_format_pretty_name (const char *format_type) { return 0; }
 
 
void po_file_check_all (po_file_t file, po_xerror_handler_t handler) {}
 
void po_message_check_all (po_message_t message, po_message_iterator_t iterator, po_xerror_handler_t handler) {}
 
#define po_message_check_format po_message_check_format_v2
void po_message_check_format (po_message_t message, po_xerror_handler_t handler) {}
#ifdef __cplusplus
}
#endif
#endif /* _GETTEXT_PO_H */
