#include "./s21_string.h"

#if defined __linux__
#define MinCount -1
#define MaxCount 134
#define UnknownError "Unknown error: %d"
static const char *ErrorsMas[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#elif defined __APPLE__
#define MinCount -1
#define MaxCount 106
#define UnknownError "Unknown error: %d"
static const char *ErrorsMas[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
    "Unknown error"};
#endif

char *s21_strcpy(char *dest, const char *src) {
  char *p;

  if (dest != s21_NULL && src != s21_NULL) {
    p = dest;
    while (*src != '\0') {
      *dest = *src;
      dest++;
      src++;
    }
    *dest = '\0';
  } else {
    p = s21_NULL;
  }

  return p;
}

int compare(const char *haystack, const char *needle) {
  while (*haystack && *needle) {
    if (*haystack != *needle) {
      return 0;
    }
    haystack++;
    needle++;
  }

  return (*needle == '\0');
}

char *s21_strstr(const char *haystack, const char *needle) {
  const char *a;
  const char *b;

  b = needle;

  if (*b == 0) {
    return (char *)haystack;
  }

  for (; *haystack != 0; haystack += 1) {
    if (*haystack != *b) {
      continue;
    }

    a = haystack;
    while (1) {
      if (*b == 0) {
        return (char *)haystack;
      }
      if (*a++ != *b++) {
        break;
      }
    }
    b = needle;
  }

  return s21_NULL;
}

char *s21_find_last_separator(char *str, const char *delim) {
  int flag = 0;
  char *res = str;
  char *str1 = str;
  for (long unsigned int i = 0; i < s21_strlen(str1) && flag == 0; i++) {
    int next = 0;
    for (long unsigned int j = 0;
         j < s21_strlen(delim) && flag == 0 && next == 0; j++) {
      if (str[i] == delim[j]) {
        str[i] = '\0';
        str1 = &str[i + 1];
        next = 1;
      } else if (j == s21_strlen(delim) - 1) {
        flag = 1;
        res = &str[i];
      }
    }
  }
  if (flag == 0) res = 0;

  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *start = 0;
  if (str != 0) start = str;

  int flag = 0;
  char *search = start;

  if (start != 0 && s21_strlen(start) > 0) {
    for (long unsigned int i = 0; i < s21_strlen(start) && flag == 0; i++)
      for (long unsigned int j = 0; j < s21_strlen(delim) && flag == 0; j++)
        if (start[i] == delim[j]) {
          start[i] = '\0';
          start = s21_find_last_separator(start + i + 1, delim);
          flag = 1;
        }
  }
  if (flag == 0) search = 0;

  return search;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)str;
  unsigned char *isCharFind = s21_NULL;
  while ((str != s21_NULL) && (n--)) {
    if (*p != (unsigned char)c) {
      p++;
    } else {
      isCharFind = p;
      break;
    }
  }
  return isCharFind;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *p = (unsigned char *)str1;
  unsigned char *q = (unsigned char *)str2;
  int charCompareStatus = 0;
  s21_size_t i = 0;
  while (n > i) {
    if (*p != *q) {
      charCompareStatus = *p - *q;
    }
    i += n;
    p++;
    q++;
  }
  return charCompareStatus;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *pszDest = (char *)dest;
  const char *pszSource = (const char *)src;
  if ((pszDest != s21_NULL) && (pszSource != s21_NULL)) {
    while (n) {
      *(pszDest++) = *(pszSource++);
      --n;
    }
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *pDest = (char *)dest;
  const char *pSrc = (const char *)src;
  char *tmp = (char *)malloc(sizeof(char) * n);
  if (s21_NULL == tmp) {
    return s21_NULL;
  } else {
    unsigned int i = 0;
    for (i = 0; i < n; ++i) {
      *(tmp + i) = *(pSrc + i);
    }
    for (i = 0; i < n; ++i) {
      *(pDest + i) = *(tmp + i);
    }
    free(tmp);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *s = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    s[i] = c;
  }
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  char *rdest = dest;

  while (*dest) dest++;
  while ((*dest++ = *src++))
    ;
  return rdest;
}

char *s21_strncat(char *str1, const char *src, s21_size_t n) {
  if ((str1 == s21_NULL) && (src == s21_NULL)) return s21_NULL;
  char *dest = str1;
  while (*dest != '\0') {
    dest++;
  }
  char *p = dest + s21_strlen(dest);
  while (*src != '\0' && n--) {
    *p++ = *src++;
  }
  *p = '\0';

  return str1;
}

char *s21_strchr(const char *str, int c) {
  char *isCharFind = s21_NULL;
  if (str != s21_NULL) {
    do {
      if (*str == (char)c) {
        isCharFind = (char *)str;
        break;
      }
    } while (*str++);
  }
  return isCharFind;
}

int s21_strcmp(const char *str1, const char *str2) {
  int charCompareStatus = 0;
  for (int i = 0; str1[i] || str2[i]; i++) {
    if (str1[i] != str2[i]) {
      charCompareStatus = str1[i] - str2[i];
      break;
    }
  }
  return charCompareStatus;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  while (n--) {
    if (*str1 != *str2) {
      result = *str1 - *str2;
    } else {
      ++str1;
      ++str2;
    }
  }
  return result;
}

void *s21_to_upper(const char *str) {
  char *temporaryString;
  s21_size_t length = s21_strlen(str) + 1;
  if (str == s21_NULL) {
    temporaryString = s21_NULL;
  } else {
    temporaryString = calloc(length, sizeof(char));
    for (s21_size_t i = 0; i < length; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        temporaryString[i] = str[i] - 'a' + 'A';
      } else {
        temporaryString[i] = str[i];
      }
    }
  }
  return temporaryString;
}

void *s21_to_lower(const char *str) {
  char *temporaryString;
  s21_size_t length = s21_strlen(str) + 1;
  if (str == s21_NULL) {
    temporaryString = s21_NULL;
  } else {
    temporaryString = calloc(length, sizeof(char));
    for (s21_size_t i = 0; i < length; i++) {
      if (str[i] < 'A' || str[i] > 'Z') {
        temporaryString[i] = str[i];
      } else {
        temporaryString[i] = str[i] + 32;
      }
    }
  }
  return temporaryString;
}
s21_size_t s21_strlen(const char *str) {
  const char *end = str;

  while (*end != '\0') {
    ++end;
  }

  return end - str;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (n != 0) {
    char *d = dest;
    const char *s = src;
    do {
      if ((*d++ = *s++) == 0) {
        while (--n > 0) *d++ = 0;

        break;
      }
    } while (--n > 0);
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int len1 = s21_strlen(str2);
  int count = 0;
  int flag = 0;
  char *str11 = (char *)str1;
  while (*str11 != '\0') {
    for (int i = 0; i < len1; i++) {
      if ((*str11) == str2[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
    str11++;
    count++;
  }

  return count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  if (*str2) {
    int flag = 1;
    for (; *s2 && flag; ++s2) {
      for (; *s2 && flag; ++s1) {
        if (*s2 == *s1) flag = 0;
      }
    }
    s1--;
  } else {
    s1 = s21_NULL;
  }
  return s1;
}

char *s21_strerror(int errnum) {
  char *buf = s21_NULL;
  static char str[100] = {'\0'};
  if (errnum >= MinCount && errnum <= MaxCount) {
    buf = (char *)ErrorsMas[errnum];
  } else {
    s21_sprintf(str, UnknownError, errnum);
    buf = str;
  }
  return buf;
}

char *s21_strrchr(const char *str, int c) {
  char *newMas = s21_NULL;
  int len = s21_strlen(str);
  char cc = (char)c;
  newMas = (char *)str + len;
  while (--newMas) {
    if ((*newMas) == cc) break;
  }

  return newMas;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  char *newMas = (char *)str1;
  int len = s21_strlen(str2);
  int flag = 0;
  int count = 0;
  int i = 0;
  while (*newMas != '\0' && flag == 0) {
    i = 0;
    while (i < len) {
      if ((*newMas) == str2[i]) {
        count++;
        break;
      }
      i++;
      if (i == len) {
        flag = 1;
      }
    }
    newMas++;
  }
  return count;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *strRes = s21_NULL;
  if (s21_strlen(str) != 0) {
    if (strRes != s21_NULL) {
      s21_size_t i = 0;
      strRes = (char *)calloc(1000, sizeof(char));
      while (i < (s21_size_t)start_index) {
        strRes[i] = src[i];
        i++;
      }
      s21_strcat(strRes, str);
      int len = s21_strlen(strRes);
      while (i < s21_strlen(src)) {
        strRes[len] = src[i];
        i++;
        len++;
      }
    }
  }
  return strRes;
}

int check_edges(const char *src, const char *totrim, int edge) {
  int res = 0;
  int size = s21_strlen(totrim);
  for (int i = 0; i < size; i++) {
    if (src[edge] == totrim[i]) res = 1;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      res = calloc(s21_strlen(src) + 1, sizeof(char));
      int start = 0, end = s21_strlen(src);
      while (check_edges(src, trim_chars, start)) start++;
      if (start != end) {
        while (check_edges(src, trim_chars, end - 1)) end--;
        for (int i = 0; start < end; i++) {
          res[i] = src[start];
          start++;
        }
      } else {
        res[0] = '\0';
      }
    } else {
      res = s21_trim(src, "\t\n ");
    }
  }
  return res;
}

void s21_char_to_int(int *num, char ch) {
  *num *= 10;
  *num += (int)(ch - '0');
}

void s21_check_star(FORMAT *s_format, int *pres_or_width, int *num, char f_ch) {
  if (f_ch == '*') {
    if (*pres_or_width) {
      s_format->error = 1;
    } else {
      *pres_or_width = '*';
      s_format->star = 1;
    }
  } else {
    if (*pres_or_width == '*') {
      s_format->error = 1;
    } else {
      s21_char_to_int(num, f_ch);
    }
  }
}

int s21_parser(int ptr_f, const char *format, FORMAT *s_format) {
  ptr_f++;
  int num_p = 0;
  int num_w = 0;
  int count = 0;
  while (!s_format->spec) {
    if (s21_IS_SPEC(format[ptr_f])) {
      s_format->spec = format[ptr_f];
    } else if (s21_IS_LENGTH(format[ptr_f])) {
      if (!count) {
        s_format->length = format[ptr_f];
        count++;
      } else {
        if (s_format->length != format[ptr_f]) {
          s_format->error = 1;
        } else {
          s_format->double_len = 1;
        }
      }
    } else if (format[ptr_f] == '.') {
      s_format->point = 1;
    } else if (format[ptr_f] == '0' && !num_w && !s_format->point) {
      s_format->zero = 1;
    } else if (s_format->point && s21_IS_NUMERIC(format[ptr_f])) {
      s21_check_star(s_format, &s_format->precision, &num_p, format[ptr_f]);
    } else if (s21_IS_NUMERIC(format[ptr_f])) {
      s21_check_star(s_format, &s_format->width, &num_w, format[ptr_f]);
    } else if (format[ptr_f] == '-') {
      s_format->minus = 1;
    } else if (format[ptr_f] == '+') {
      s_format->plus = 1;
    } else if (format[ptr_f] == ' ') {
      s_format->space = 1;
    } else if (format[ptr_f] == '#') {
      s_format->sharp = 1;
    } else {
      s_format->error = 1;
    }
    ptr_f++;
  }
  if (s_format->precision != 42) s_format->precision = num_p;
  if (s_format->width != 42) s_format->width = num_w;

  return ptr_f;
}

void s21_reverse_string(char *str, int i) {
  int left = 0;
  int right = i - 1;
  char temp;
  while (left < right) {
    temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    left++;
    right--;
  }
}

void s21_int_to_char(FORMAT s_format, unsigned long long int *num, char *buf,
                     int *i) {
  if (*num == 0 && s_format.spec != 'f' && !s_format.point) buf[*i] = '0';
  while (*num) {
    buf[*i] = (char)((*num % 10) + '0');
    *num = *num / 10;
    (*i)++;
  }
}

void s21_precision_int(FORMAT s_format, char *buf, int *i) {
  if (s_format.precision > 0) {
    while (*i < s_format.precision) {
      buf[*i] = '0';
      (*i)++;
    }
  }
}

void s21_make_width(FORMAT s_format, char *buf, int is_negative) {
  int len = (int)s21_strlen(buf);
  int edge = 0;
  if (s_format.width > len) {
    buf[s_format.width + 1] = '\0';
    if (s_format.zero) {
      if (is_negative || s_format.plus) edge++;
    }
    while (len >= edge) {
      buf[s_format.width--] = buf[len--];
    }
    for (; edge <= s_format.width; edge++) {
      if (strchr("diu", s_format.spec)) {
        if (s_format.zero && !s_format.point) {
          buf[edge] = '0';
        } else {
          buf[edge] = ' ';
        }
      }
      if (strchr("fcs", s_format.spec)) {
        if (s_format.zero) {
          buf[edge] = '0';
        } else {
          buf[edge] = ' ';
        }
      }
    }
  }
}

void s21_move_string(char *buf) {
  int pos = s21_strlen(buf);
  buf[pos + 1] = '\0';
  while (pos > 0) {
    buf[pos] = buf[pos - 1];
    pos--;
  }
}

void s21_make_flags(int is_negative, FORMAT s_format, char *buf) {
  int i = 0;
  if (!strchr("scuo\%", s_format.spec)) {
    if (is_negative) {
      s21_move_string(buf);
      buf[i] = '-';
    } else if (s_format.plus) {
      s21_move_string(buf);
      if (is_negative) {
        buf[i] = '-';
      } else {
        buf[i] = '+';
      }
    } else if (s_format.space) {
      s21_move_string(buf);
      if (is_negative) {
        buf[i] = '-';
      } else {
        buf[i] = ' ';
      }
    } else if (is_negative) {
      s21_move_string(buf);
      buf[i] = '-';
    }
  }
  if (s_format.minus) {
    i = s21_strlen(buf);
    while (i < s_format.width) {
      buf[i++] = ' ';
    }
  }
}

void s21_int_to_string(char *buf, FORMAT s_format, long long int num) {
  int i = 0;
  int is_negative = 0;
  if (num < 0) {
    is_negative = 1;
    num *= -1;
  }
  s21_int_to_char(s_format, (unsigned long long int *)&num, buf, &i);
  s21_precision_int(s_format, buf, &i);
  s21_reverse_string(buf, i);
  s21_make_flags(is_negative, s_format, buf);
  s21_make_width(s_format, buf, is_negative);
}

void s21_d_format(FORMAT s_format, va_list arg_list, char *buf) {
  if (!s_format.length) {
    s21_int_to_string(buf, s_format, va_arg(arg_list, int));
  } else if (s_format.length == 'l') {
    if (s_format.double_len) {
      s21_int_to_string(buf, s_format, va_arg(arg_list, long long int));
    } else {
      s21_int_to_string(buf, s_format, va_arg(arg_list, long int));
    }
  } else if (s_format.length == 'h') {
    if (s_format.double_len) {
      s21_int_to_string(buf, s_format, (signed char)va_arg(arg_list, int));
    } else {
      s21_int_to_string(buf, s_format, (short int)va_arg(arg_list, int));
    }
  }
}

void s21_c_format(va_list arg_list, FORMAT s_format, char *buf) {
  if (s_format.length == 'l') {
    buf[0] = (wchar_t)va_arg(arg_list, wchar_t);
  } else {
    buf[0] = va_arg(arg_list, int);
  }
  buf[1] = '\0';
  s21_make_flags(0, s_format, buf);
  s21_make_width(s_format, buf, 0);
}

void s21_s_format(FORMAT s_format, va_list arg_list, char *buf) {
  if (s_format.length == 'l') {
    wcstombs(buf, va_arg(arg_list, wchar_t *), 512);
  } else {
    buf = s21_strcat(buf, va_arg(arg_list, char *));
  }
  int accuracy = 0;
  if (s_format.point) {
    accuracy = s_format.precision;
  } else {
    accuracy = s21_strlen(buf);
  }
  int i = 0;
  for (; i < accuracy; i++) {
    ;
  }
  while (buf[i]) {
    buf[i] = 0;
    i++;
  }
  s21_make_flags(0, s_format, buf);
  s21_make_width(s_format, buf, 0);
}

void s21_percent_format(FORMAT s_format, char *buf) {
  s21_strcat(buf, "%");
  s21_make_flags(0, s_format, buf);
  s21_make_width(s_format, buf, 0);
}

char *s21_clear_str(char *str) {
  char *start_str = str;
  while (*str) {
    *str = 0;
    str++;
  }
  str = 0;
  return start_str;
}

long double s21_pow(long double base, long double exp) {
  int i = 1;
  while (i < exp) {
    base *= 10;
    i++;
  }
  if (exp == 0) base = 1;
  return base;
}

void s21_f_to_str(long double num, FORMAT s_format, char *buf) {
  char buf_dec[256] = {0};
  int accuracy = 0;
  if (s_format.point) {
    accuracy = s_format.precision;
  } else {
    accuracy = 6;
  }
  int is_negative = 0;
  if (num < 0) {
    is_negative = 1;
    num *= -1;
  }
  unsigned long long int pos_i = num;
  unsigned long long int pos_int = 0;
  if (accuracy != 0) {
    pos_int = num;
  } else {
    pos_int = roundl(num);
  }
  long double dec = (num - pos_i);
  int i = 0;
  if (pos_int == 0) {
    buf[i] = '0';
  } else {
    s21_int_to_char(s_format, &pos_int, buf, &i);
  }
  s21_reverse_string(buf, i);
  for (; buf[i]; i++) {
    ;
  }
  if (s_format.sharp || accuracy > 0) {
    buf[i++] = '.';
  }
  buf[i] = '\0';
  int decm = 0;
  char *zeroes = calloc(256, sizeof(char));
  for (int j = 0; dec < 1 && j < accuracy; j++) {
    dec *= 10;
    decm = dec;
    if (decm == 0) zeroes[j] = '0';
  }
  long long int int_dec =
      rint((dec / 10) * pow(10, (accuracy - s21_strlen(zeroes))));
  i = 0;
  if (accuracy > 0)
    s21_int_to_char(s_format, (long long unsigned int *)&int_dec, buf_dec, &i);
  s21_reverse_string(buf_dec, i);
  zeroes = s21_strcat(zeroes, buf_dec);
  buf = s21_strcat(buf, zeroes);
  free(zeroes);
  s21_make_flags(is_negative, s_format, buf);
  s21_make_width(s_format, buf, is_negative);
}

void s21_f_format(FORMAT s_format, va_list arg_list, char *buf) {
  if ((s_format.length == 'l' && s_format.double_len) ||
      s_format.length == 'L') {
    s21_f_to_str(va_arg(arg_list, long double), s_format, buf);
  } else {
    s21_f_to_str(va_arg(arg_list, double), s_format, buf);
  }
}

void s21_u_to_str(char *buf, FORMAT s_format, unsigned long long int num) {
  int i = 0;
  s21_int_to_char(s_format, (unsigned long long int *)&num, buf, &i);
  s21_precision_int(s_format, buf, &i);
  s21_reverse_string(buf, i);
  s21_make_flags(0, s_format, buf);
  s21_make_width(s_format, buf, 0);
}

void s21_u_format(FORMAT s_format, va_list arg_list, char *buf) {
  if (!s_format.length) {
    s21_u_to_str(buf, s_format, va_arg(arg_list, unsigned int));
  } else if (s_format.length == 'l') {
    if (s_format.double_len) {
      s21_u_to_str(buf, s_format, va_arg(arg_list, unsigned long long int));
    } else {
      s21_u_to_str(buf, s_format, va_arg(arg_list, unsigned long int));
    }
  } else if (s_format.length == 'h') {
    if (s_format.double_len) {
      s21_u_to_str(buf, s_format, (unsigned char)va_arg(arg_list, int));
    } else {
      s21_u_to_str(buf, s_format, (unsigned short int)va_arg(arg_list, int));
    }
  }
}

void s21_reset_format(FORMAT *s_format) {
  s_format->spec = 0;
  s_format->space = 0;
  s_format->minus = 0;
  s_format->plus = 0;
  s_format->point = 0;
  s_format->width = 0;
  s_format->length = 0;
  s_format->double_len = 0;
  s_format->precision = 0;
  s_format->zero = 0;
  s_format->sharp = 0;
  s_format->error = 0;
  s_format->star = 0;
}

void s21_format_string(FORMAT s_format, va_list arg_list, const char *format,
                       char *buf) {
  (void)format;
  switch (s_format.spec) {
    case 'c':
      s21_c_format(arg_list, s_format, buf);
      break;
    case 'i':
    case 'd':
      s21_d_format(s_format, arg_list, buf);
      break;
    case 'f':
      s21_f_format(s_format, arg_list, buf);
      break;
    case 's':
      s21_s_format(s_format, arg_list, buf);
      break;
    case 'u':
      s21_u_format(s_format, arg_list, buf);
      break;
    case '%':
      s21_percent_format(s_format, buf);
      break;
    default:
      break;
  }
}

void s21_star_into_num(FORMAT *s_format, int *pres_or_width, va_list arg_list) {
  if (*pres_or_width == '*') {
    *pres_or_width = va_arg(arg_list, int);
    if (s_format->width < 0) {
      s_format->width *= -1;
      s_format->minus = 1;
    }
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg_list;
  va_start(arg_list, format);
  int ptr_str = 0;
  int ptr_f = 0;
  FORMAT s_format = {0};
  while (format[ptr_f]) {
    if (format[ptr_f] == '%') {
      char *buf = s21_NULL;
      buf = calloc(1000, sizeof(char));
      if (buf) {
        s21_reset_format(&s_format);
        ptr_f = s21_parser(ptr_f, format, &s_format);
        if (!s_format.error) {
          s21_star_into_num(&s_format, &s_format.width, arg_list);
          s21_star_into_num(&s_format, &s_format.precision, arg_list);
          s21_format_string(s_format, arg_list, format, buf);
          str = s21_strcat(str, buf);
          ptr_str = s21_strlen(str);
        }
      }
      free(buf);
    } else {
      str[ptr_str] = format[ptr_f];
      ptr_f++;
      ptr_str++;
      str[ptr_str] = '\0';
    }
  }
  va_end(arg_list);
  int bytes = s21_strlen(str);
  return bytes;
}
