/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 30 "core/cfg.y" /* yacc.c:339  */


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include "route_struct.h"
#include "globals.h"
#ifdef SHM_MEM
#include "shm_init.h"
#endif /* SHM_MEM */
#include "route.h"
#include "switch.h"
#include "dprint.h"
#include "sr_module.h"
#include "modparam.h"
#include "ip_addr.h"
#include "resolve.h"
#include "socket_info.h"
#include "name_alias.h"
#include "ut.h"
#include "dset.h"
#include "select.h"
#include "flags.h"
#include "tcp_init.h"
#include "tcp_options.h"
#include "sctp_core.h"
#include "pvar.h"
#include "lvalue.h"
#include "rvalue.h"
#include "sr_compat.h"
#include "msg_translator.h"
#include "async_task.h"

#include "kemi.h"
#include "ppcfg.h"
#include "pvapi.h"
#include "config.h"
#include "cfg_core.h"
#include "cfg/cfg.h"
#ifdef CORE_TLS
#include "tls/tls_config.h"
#endif
#include "timer_ticks.h"

#ifdef DEBUG_DMALLOC
#include <dmalloc.h>
#endif

/* hack to avoid alloca usage in the generated C file (needed for compiler
 with no built in alloca, like icc*/
#undef _ALLOCA_H

#define onsend_check(s) \
	do{\
		if (rt!=ONSEND_ROUTE) yyerror( s " allowed only in onsend_routes");\
	}while(0)

	#define IF_AUTO_BIND_IPV6(x) x

#ifdef USE_DNS_CACHE
	#define IF_DNS_CACHE(x) x
#else
	#define IF_DNS_CACHE(x) warn("dns cache support not compiled in")
#endif

#ifdef USE_DNS_FAILOVER
	#define IF_DNS_FAILOVER(x) x
#else
	#define IF_DNS_FAILOVER(x) warn("dns failover support not compiled in")
#endif

#ifdef USE_NAPTR
	#define IF_NAPTR(x) x
#else
	#define IF_NAPTR(x) warn("dns naptr support not compiled in")
#endif

#ifdef USE_DST_BLACKLIST
	#define IF_DST_BLACKLIST(x) x
#else
	#define IF_DST_BLACKLIST(x) warn("dst blacklist support not compiled in")
#endif

#ifdef USE_SCTP
	#define IF_SCTP(x) x
#else
	#define IF_SCTP(x) warn("sctp support not compiled in")
#endif

#ifdef USE_RAW_SOCKS
	#define IF_RAW_SOCKS(x) x
#else
	#define IF_RAW_SOCKS(x) warn("raw socket support not compiled in")
#endif


extern int yylex();
/* safer then using yytext which can be array or pointer */
extern char* yy_number_str;

static void yyerror(char* s, ...);
static void yyerror_at(struct cfg_pos* pos, char* s, ...);
static char* tmp;
static int i_tmp;
static unsigned u_tmp;
static struct socket_id* lst_tmp;
static struct name_lst*  nl_tmp;
static int rt;  /* Type of route block for find_export */
static str* str_tmp;
static str s_tmp;
static struct ip_addr* ip_tmp;
static struct avp_spec* s_attr;
static select_t sel;
static select_t* sel_ptr;
static pv_spec_t* pv_spec;
static struct action *mod_func_action;
static struct lvalue* lval_tmp;
static struct rvalue* rval_tmp;

static void warn(char* s, ...);
static void warn_at(struct cfg_pos* pos, char* s, ...);
static void get_cpos(struct cfg_pos* pos);
static struct rval_expr* mk_rve_rval(enum rval_type, void* v);
static struct rval_expr* mk_rve1(enum rval_expr_op op, struct rval_expr* rve1);
static struct rval_expr* mk_rve2(enum rval_expr_op op, struct rval_expr* rve1,
									struct rval_expr* rve2);
static int rval_expr_int_check(struct rval_expr *rve);
static int warn_ct_rve(struct rval_expr *rve, char* name);
static struct socket_id* mk_listen_id(char*, int, int);
static struct name_lst* mk_name_lst(char* name, int flags);
static struct socket_id* mk_listen_id2(struct name_lst*, int, int);
static void free_name_lst(struct name_lst* lst);
static void free_socket_id_lst(struct socket_id* i);

static struct case_stms* mk_case_stm(struct rval_expr* ct, int is_re, 
									struct action* a, int* err);
static int case_check_type(struct case_stms* stms);
static int case_check_default(struct case_stms* stms);
static int mod_f_params_pre_fixup(struct action* a);
static void free_mod_func_action(struct action* a);


extern int line;
extern int column;
extern int startcolumn;
extern int startline;
extern char *finame;
extern char *routename;
extern char *default_routename;

#define set_cfg_pos(x) \
	do{\
		if(x) {\
		(x)->cline = line;\
		(x)->cfile = (finame!=0)?finame:((cfg_file!=0)?cfg_file:"default");\
		(x)->rname = (routename!=0)?routename:((default_routename!=0)?default_routename:"DEFAULT");\
		}\
	}while(0)



#line 235 "core/cfg.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cfg.tab.h".  */
#ifndef YY_YY_CORE_CFG_TAB_H_INCLUDED
# define YY_YY_CORE_CFG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FORWARD = 258,
    FORWARD_TCP = 259,
    FORWARD_TLS = 260,
    FORWARD_SCTP = 261,
    FORWARD_UDP = 262,
    EXIT = 263,
    DROP = 264,
    RETURN = 265,
    BREAK = 266,
    LOG_TOK = 267,
    ERROR = 268,
    ROUTE = 269,
    ROUTE_REQUEST = 270,
    ROUTE_FAILURE = 271,
    ROUTE_ONREPLY = 272,
    ROUTE_REPLY = 273,
    ROUTE_BRANCH = 274,
    ROUTE_SEND = 275,
    ROUTE_EVENT = 276,
    EXEC = 277,
    SET_HOST = 278,
    SET_HOSTPORT = 279,
    SET_HOSTPORTTRANS = 280,
    PREFIX = 281,
    STRIP = 282,
    STRIP_TAIL = 283,
    SET_USERPHONE = 284,
    APPEND_BRANCH = 285,
    REMOVE_BRANCH = 286,
    CLEAR_BRANCHES = 287,
    SET_USER = 288,
    SET_USERPASS = 289,
    SET_PORT = 290,
    SET_URI = 291,
    REVERT_URI = 292,
    FORCE_RPORT = 293,
    ADD_LOCAL_RPORT = 294,
    FORCE_TCP_ALIAS = 295,
    UDP_MTU = 296,
    UDP_MTU_TRY_PROTO = 297,
    UDP4_RAW = 298,
    UDP4_RAW_MTU = 299,
    UDP4_RAW_TTL = 300,
    IF = 301,
    ELSE = 302,
    SET_ADV_ADDRESS = 303,
    SET_ADV_PORT = 304,
    FORCE_SEND_SOCKET = 305,
    SET_FWD_NO_CONNECT = 306,
    SET_RPL_NO_CONNECT = 307,
    SET_FWD_CLOSE = 308,
    SET_RPL_CLOSE = 309,
    SWITCH = 310,
    CASE = 311,
    DEFAULT = 312,
    WHILE = 313,
    CFG_SELECT = 314,
    CFG_RESET = 315,
    URIHOST = 316,
    URIPORT = 317,
    MAX_LEN = 318,
    SETFLAG = 319,
    RESETFLAG = 320,
    ISFLAGSET = 321,
    SETAVPFLAG = 322,
    RESETAVPFLAG = 323,
    ISAVPFLAGSET = 324,
    METHOD = 325,
    URI = 326,
    FROM_URI = 327,
    TO_URI = 328,
    SRCIP = 329,
    SRCPORT = 330,
    DSTIP = 331,
    DSTPORT = 332,
    TOIP = 333,
    TOPORT = 334,
    SNDIP = 335,
    SNDPORT = 336,
    SNDPROTO = 337,
    SNDAF = 338,
    PROTO = 339,
    AF = 340,
    MYSELF = 341,
    MSGLEN = 342,
    UDP = 343,
    TCP = 344,
    TLS = 345,
    SCTP = 346,
    WS = 347,
    WSS = 348,
    DEBUG_V = 349,
    FORK = 350,
    FORK_DELAY = 351,
    MODINIT_DELAY = 352,
    LOGSTDERROR = 353,
    LOGFACILITY = 354,
    LOGNAME = 355,
    LOGCOLOR = 356,
    LOGPREFIX = 357,
    LOGPREFIXMODE = 358,
    LOGENGINETYPE = 359,
    LOGENGINEDATA = 360,
    XAVPVIAPARAMS = 361,
    LISTEN = 362,
    ADVERTISE = 363,
    ALIAS = 364,
    SR_AUTO_ALIASES = 365,
    DNS = 366,
    REV_DNS = 367,
    DNS_TRY_IPV6 = 368,
    DNS_TRY_NAPTR = 369,
    DNS_SRV_LB = 370,
    DNS_UDP_PREF = 371,
    DNS_TCP_PREF = 372,
    DNS_TLS_PREF = 373,
    DNS_SCTP_PREF = 374,
    DNS_RETR_TIME = 375,
    DNS_RETR_NO = 376,
    DNS_SERVERS_NO = 377,
    DNS_USE_SEARCH = 378,
    DNS_SEARCH_FMATCH = 379,
    DNS_NAPTR_IGNORE_RFC = 380,
    DNS_CACHE_INIT = 381,
    DNS_USE_CACHE = 382,
    DNS_USE_FAILOVER = 383,
    DNS_CACHE_FLAGS = 384,
    DNS_CACHE_NEG_TTL = 385,
    DNS_CACHE_MIN_TTL = 386,
    DNS_CACHE_MAX_TTL = 387,
    DNS_CACHE_MEM = 388,
    DNS_CACHE_GC_INT = 389,
    DNS_CACHE_DEL_NONEXP = 390,
    DNS_CACHE_REC_PREF = 391,
    AUTO_BIND_IPV6 = 392,
    DST_BLST_INIT = 393,
    USE_DST_BLST = 394,
    DST_BLST_MEM = 395,
    DST_BLST_TTL = 396,
    DST_BLST_GC_INT = 397,
    DST_BLST_UDP_IMASK = 398,
    DST_BLST_TCP_IMASK = 399,
    DST_BLST_TLS_IMASK = 400,
    DST_BLST_SCTP_IMASK = 401,
    IP_FREE_BIND = 402,
    PORT = 403,
    STAT = 404,
    CHILDREN = 405,
    SOCKET_WORKERS = 406,
    ASYNC_WORKERS = 407,
    ASYNC_USLEEP = 408,
    CHECK_VIA = 409,
    PHONE2TEL = 410,
    MEMLOG = 411,
    MEMDBG = 412,
    MEMSUM = 413,
    MEMSAFETY = 414,
    MEMJOIN = 415,
    MEMSTATUSMODE = 416,
    CORELOG = 417,
    SIP_WARNING = 418,
    SERVER_SIGNATURE = 419,
    SERVER_HEADER = 420,
    USER_AGENT_HEADER = 421,
    REPLY_TO_VIA = 422,
    LOADMODULE = 423,
    LOADPATH = 424,
    MODPARAM = 425,
    CFGENGINE = 426,
    MAXBUFFER = 427,
    SQL_BUFFER_SIZE = 428,
    USER = 429,
    GROUP = 430,
    CHROOT = 431,
    WDIR = 432,
    RUNDIR = 433,
    MHOMED = 434,
    DISABLE_TCP = 435,
    TCP_ACCEPT_ALIASES = 436,
    TCP_CHILDREN = 437,
    TCP_CONNECT_TIMEOUT = 438,
    TCP_SEND_TIMEOUT = 439,
    TCP_CON_LIFETIME = 440,
    TCP_POLL_METHOD = 441,
    TCP_MAX_CONNECTIONS = 442,
    TLS_MAX_CONNECTIONS = 443,
    TCP_NO_CONNECT = 444,
    TCP_SOURCE_IPV4 = 445,
    TCP_SOURCE_IPV6 = 446,
    TCP_OPT_FD_CACHE = 447,
    TCP_OPT_BUF_WRITE = 448,
    TCP_OPT_CONN_WQ_MAX = 449,
    TCP_OPT_WQ_MAX = 450,
    TCP_OPT_RD_BUF = 451,
    TCP_OPT_WQ_BLK = 452,
    TCP_OPT_DEFER_ACCEPT = 453,
    TCP_OPT_DELAYED_ACK = 454,
    TCP_OPT_SYNCNT = 455,
    TCP_OPT_LINGER2 = 456,
    TCP_OPT_KEEPALIVE = 457,
    TCP_OPT_KEEPIDLE = 458,
    TCP_OPT_KEEPINTVL = 459,
    TCP_OPT_KEEPCNT = 460,
    TCP_OPT_CRLF_PING = 461,
    TCP_OPT_ACCEPT_NO_CL = 462,
    TCP_OPT_ACCEPT_HEP3 = 463,
    TCP_CLONE_RCVBUF = 464,
    TCP_REUSE_PORT = 465,
    DISABLE_TLS = 466,
    ENABLE_TLS = 467,
    TLSLOG = 468,
    TLS_PORT_NO = 469,
    TLS_METHOD = 470,
    TLS_HANDSHAKE_TIMEOUT = 471,
    TLS_SEND_TIMEOUT = 472,
    SSLv23 = 473,
    SSLv2 = 474,
    SSLv3 = 475,
    TLSv1 = 476,
    TLS_VERIFY = 477,
    TLS_REQUIRE_CERTIFICATE = 478,
    TLS_CERTIFICATE = 479,
    TLS_PRIVATE_KEY = 480,
    TLS_CA_LIST = 481,
    DISABLE_SCTP = 482,
    ENABLE_SCTP = 483,
    SCTP_CHILDREN = 484,
    ADVERTISED_ADDRESS = 485,
    ADVERTISED_PORT = 486,
    DISABLE_CORE = 487,
    OPEN_FD_LIMIT = 488,
    SHM_MEM_SZ = 489,
    SHM_FORCE_ALLOC = 490,
    MLOCK_PAGES = 491,
    REAL_TIME = 492,
    RT_PRIO = 493,
    RT_POLICY = 494,
    RT_TIMER1_PRIO = 495,
    RT_TIMER1_POLICY = 496,
    RT_TIMER2_PRIO = 497,
    RT_TIMER2_POLICY = 498,
    MCAST_LOOPBACK = 499,
    MCAST_TTL = 500,
    MCAST = 501,
    TOS = 502,
    PMTU_DISCOVERY = 503,
    KILL_TIMEOUT = 504,
    MAX_WLOOPS = 505,
    PVBUFSIZE = 506,
    PVBUFSLOTS = 507,
    PVCACHELIMIT = 508,
    PVCACHEACTION = 509,
    HTTP_REPLY_PARSE = 510,
    VERSION_TABLE_CFG = 511,
    VERBOSE_STARTUP = 512,
    ROUTE_LOCKS_SIZE = 513,
    CFG_DESCRIPTION = 514,
    SERVER_ID = 515,
    KEMI = 516,
    ONSEND_ROUTE_CALLBACK = 517,
    REPLY_ROUTE_CALLBACK = 518,
    EVENT_ROUTE_CALLBACK = 519,
    MAX_RECURSIVE_LEVEL = 520,
    MAX_BRANCHES_PARAM = 521,
    LATENCY_CFG_LOG = 522,
    LATENCY_LOG = 523,
    LATENCY_LIMIT_DB = 524,
    LATENCY_LIMIT_ACTION = 525,
    MSG_TIME = 526,
    ONSEND_RT_REPLY = 527,
    FLAGS_DECL = 528,
    AVPFLAGS_DECL = 529,
    ATTR_MARK = 530,
    SELECT_MARK = 531,
    ATTR_FROM = 532,
    ATTR_TO = 533,
    ATTR_FROMURI = 534,
    ATTR_TOURI = 535,
    ATTR_FROMUSER = 536,
    ATTR_TOUSER = 537,
    ATTR_FROMDOMAIN = 538,
    ATTR_TODOMAIN = 539,
    ATTR_GLOBAL = 540,
    ADDEQ = 541,
    SUBST = 542,
    SUBSTDEF = 543,
    SUBSTDEFS = 544,
    EQUAL = 545,
    LOG_OR = 546,
    LOG_AND = 547,
    BIN_OR = 548,
    BIN_AND = 549,
    BIN_XOR = 550,
    BIN_LSHIFT = 551,
    BIN_RSHIFT = 552,
    EQUAL_T = 553,
    DIFF = 554,
    MATCH = 555,
    INTEQ = 556,
    INTDIFF = 557,
    STREQ = 558,
    STRDIFF = 559,
    GT = 560,
    LT = 561,
    GTE = 562,
    LTE = 563,
    PLUS = 564,
    MINUS = 565,
    STAR = 566,
    SLASH = 567,
    MODULO = 568,
    NOT = 569,
    UNARY = 570,
    BIN_NOT = 571,
    DEFINED = 572,
    INTCAST = 573,
    STRCAST = 574,
    DOT = 575,
    STRLEN = 576,
    STREMPTY = 577,
    NUMBER = 578,
    ID = 579,
    NUM_ID = 580,
    STRING = 581,
    IPV6ADDR = 582,
    PVAR = 583,
    AVP_OR_PVAR = 584,
    EVENT_RT_NAME = 585,
    COMMA = 586,
    SEMICOLON = 587,
    RPAREN = 588,
    LPAREN = 589,
    LBRACE = 590,
    RBRACE = 591,
    LBRACK = 592,
    RBRACK = 593,
    CR = 594,
    COLON = 595
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 199 "core/cfg.y" /* yacc.c:355  */

	long intval;
	unsigned long uval;
	char* strval;
	struct expr* expr;
	struct action* action;
	struct case_stms* case_stms;
	struct net* ipnet;
	struct ip_addr* ipaddr;
	struct socket_id* sockid;
	struct name_lst* name_l;
	struct avp_spec* attr;
	struct _pv_spec* pvar;
	struct lvalue* lval;
	struct rvalue* rval;
	struct rval_expr* rv_expr;
	select_t* select;

#line 635 "core/cfg.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CORE_CFG_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 652 "core/cfg.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  447
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   12134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  341
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  881
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1648

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   595

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   618,   618,   621,   622,   623,   626,   627,   628,   629,
     630,   631,   631,   632,   632,   633,   634,   634,   635,   635,
     636,   636,   637,   638,   641,   657,   665,   679,   680,   686,
     687,   691,   692,   693,   694,   695,   698,   699,   700,   701,
     702,   703,   704,   707,   708,   711,   712,   713,   714,   715,
     719,   720,   721,   722,   723,   727,   728,   731,   732,   735,
     736,   738,   739,   742,   745,   751,   752,   756,   757,   760,
     761,   764,   770,   771,   772,   773,   774,   775,   776,   777,
     778,   781,   782,   788,   789,   790,   791,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   804,   805,   806,
     807,   808,   809,   810,   811,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   823,   824,   825,   826,   827,
     828,   829,   830,   831,   832,   833,   834,   835,   836,   837,
     838,   839,   840,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   865,   866,   869,   870,   873,
     874,   875,   876,   879,   880,   883,   884,   887,   888,   891,
     892,   893,   894,   895,   900,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,   917,   918,   919,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   931,   932,   933,   936,   937,
     944,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   973,   974,   981,
     982,   989,   990,   997,   998,  1005,  1006,  1016,  1017,  1031,
    1045,  1046,  1053,  1054,  1061,  1062,  1069,  1070,  1079,  1080,
    1089,  1090,  1097,  1098,  1105,  1106,  1113,  1114,  1121,  1122,
    1129,  1130,  1137,  1138,  1145,  1146,  1153,  1154,  1161,  1162,
    1169,  1170,  1177,  1178,  1185,  1186,  1193,  1194,  1201,  1202,
    1209,  1210,  1217,  1218,  1225,  1227,  1234,  1235,  1246,  1247,
    1254,  1255,  1262,  1263,  1270,  1271,  1278,  1279,  1286,  1293,
    1300,  1307,  1314,  1321,  1322,  1329,  1330,  1337,  1338,  1345,
    1346,  1353,  1354,  1361,  1362,  1369,  1370,  1377,  1378,  1385,
    1386,  1393,  1394,  1395,  1396,  1399,  1400,  1403,  1404,  1405,
    1406,  1418,  1431,  1433,  1444,  1445,  1446,  1447,  1453,  1454,
    1464,  1465,  1466,  1467,  1468,  1469,  1476,  1477,  1484,  1485,
    1486,  1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,  1495,
    1496,  1497,  1498,  1499,  1500,  1501,  1508,  1509,  1516,  1517,
    1524,  1531,  1532,  1533,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,
    1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1592,  1593,
    1602,  1603,  1612,  1613,  1614,  1615,  1616,  1617,  1618,  1619,
    1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,
    1631,  1632,  1634,  1636,  1637,  1638,  1641,  1642,  1645,  1646,
    1647,  1650,  1651,  1654,  1655,  1656,  1664,  1669,  1674,  1679,
    1684,  1687,  1692,  1700,  1706,  1707,  1717,  1718,  1728,  1729,
    1740,  1751,  1752,  1758,  1759,  1765,  1769,  1770,  1773,  1802,
    1817,  1818,  1822,  1833,  1834,  1838,  1839,  1843,  1852,  1870,
    1871,  1874,  1883,  1901,  1905,  1906,  1911,  1911,  1920,  1921,
    1923,  1922,  1947,  1952,  1961,  1979,  1981,  1990,  2008,  2010,
    2029,  2032,  2033,  2034,  2035,  2036,  2037,  2059,  2060,  2061,
    2062,  2065,  2066,  2067,  2068,  2071,  2072,  2078,  2079,  2080,
    2081,  2082,  2083,  2084,  2087,  2088,  2089,  2090,  2097,  2098,
    2099,  2106,  2107,  2108,  2112,  2113,  2114,  2115,  2116,  2121,
    2122,  2125,  2126,  2127,  2133,  2135,  2137,  2138,  2140,  2142,
    2144,  2146,  2148,  2149,  2151,  2152,  2153,  2154,  2156,  2158,
    2160,  2162,  2164,  2166,  2167,  2203,  2205,  2207,  2209,  2212,
    2214,  2216,  2218,  2222,  2223,  2234,  2235,  2239,  2240,  2256,
    2272,  2273,  2276,  2277,  2278,  2287,  2288,  2304,  2320,  2322,
    2329,  2371,  2372,  2375,  2376,  2377,  2380,  2381,  2382,  2383,
    2384,  2385,  2386,  2387,  2390,  2398,  2408,  2425,  2432,  2439,
    2446,  2453,  2458,  2463,  2464,  2465,  2466,  2467,  2470,  2479,
    2486,  2511,  2527,  2528,  2533,  2552,  2561,  2573,  2588,  2589,
    2592,  2592,  2602,  2603,  2604,  2605,  2606,  2607,  2608,  2609,
    2610,  2613,  2616,  2617,  2620,  2627,  2630,  2637,  2643,  2644,
    2653,  2654,  2655,  2658,  2659,  2671,  2695,  2706,  2737,  2741,
    2751,  2765,  2777,  2778,  2780,  2781,  2782,  2796,  2797,  2798,
    2799,  2800,  2801,  2802,  2806,  2807,  2808,  2821,  2827,  2828,
    2829,  2830,  2831,  2832,  2833,  2834,  2835,  2836,  2837,  2838,
    2839,  2840,  2841,  2859,  2860,  2861,  2862,  2863,  2864,  2865,
    2866,  2867,  2868,  2869,  2870,  2871,  2872,  2873,  2874,  2875,
    2877,  2879,  2880,  2881,  2882,  2883,  2886,  2904,  2905,  2906,
    2909,  2910,  2911,  2912,  2913,  2914,  2915,  2916,  2917,  2918,
    2919,  2920,  2921,  2922,  2923,  2924,  2925,  2926,  2927,  2928,
    2929,  2930,  2931,  2932,  2933,  2934,  2935,  2936,  2937,  2938,
    2939,  2940,  2941,  2942,  2943,  2951,  2959,  2967,  2975,  2983,
    2991,  2999,  3007,  3015,  3016,  3018,  3026,  3034,  3042,  3051,
    3060,  3069,  3077,  3086,  3094,  3095,  3097,  3100,  3101,  3102,
    3103,  3110,  3117,  3118,  3124,  3131,  3132,  3138,  3145,  3146,
    3152,  3155,  3158,  3159,  3160,  3163,  3164,  3165,  3174,  3183,
    3184,  3185,  3186,  3187,  3188,  3189,  3190,  3191,  3192,  3193,
    3194,  3195,  3196,  3197,  3198,  3199,  3200,  3204,  3208,  3209,
    3210,  3211,  3212,  3213,  3214,  3215,  3216,  3217,  3218,  3219,
    3220,  3221,  3222,  3223,  3224,  3225,  3226,  3227,  3228,  3229,
    3230,  3231,  3232,  3233,  3234,  3235,  3243,  3251,  3259,  3260,
    3262,  3264,  3275,  3276,  3277,  3293,  3294,  3295,  3299,  3302,
    3303,  3306,  3309,  3312,  3315,  3318,  3321,  3324,  3327,  3330,
    3333,  3334,  3335,  3338,  3339,  3340,  3340,  3368,  3370,  3372,
    3373,  3376,  3393,  3397,  3401,  3405,  3410,  3414,  3419,  3423,
    3427,  3431
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FORWARD", "FORWARD_TCP", "FORWARD_TLS",
  "FORWARD_SCTP", "FORWARD_UDP", "EXIT", "DROP", "RETURN", "BREAK",
  "LOG_TOK", "ERROR", "ROUTE", "ROUTE_REQUEST", "ROUTE_FAILURE",
  "ROUTE_ONREPLY", "ROUTE_REPLY", "ROUTE_BRANCH", "ROUTE_SEND",
  "ROUTE_EVENT", "EXEC", "SET_HOST", "SET_HOSTPORT", "SET_HOSTPORTTRANS",
  "PREFIX", "STRIP", "STRIP_TAIL", "SET_USERPHONE", "APPEND_BRANCH",
  "REMOVE_BRANCH", "CLEAR_BRANCHES", "SET_USER", "SET_USERPASS",
  "SET_PORT", "SET_URI", "REVERT_URI", "FORCE_RPORT", "ADD_LOCAL_RPORT",
  "FORCE_TCP_ALIAS", "UDP_MTU", "UDP_MTU_TRY_PROTO", "UDP4_RAW",
  "UDP4_RAW_MTU", "UDP4_RAW_TTL", "IF", "ELSE", "SET_ADV_ADDRESS",
  "SET_ADV_PORT", "FORCE_SEND_SOCKET", "SET_FWD_NO_CONNECT",
  "SET_RPL_NO_CONNECT", "SET_FWD_CLOSE", "SET_RPL_CLOSE", "SWITCH", "CASE",
  "DEFAULT", "WHILE", "CFG_SELECT", "CFG_RESET", "URIHOST", "URIPORT",
  "MAX_LEN", "SETFLAG", "RESETFLAG", "ISFLAGSET", "SETAVPFLAG",
  "RESETAVPFLAG", "ISAVPFLAGSET", "METHOD", "URI", "FROM_URI", "TO_URI",
  "SRCIP", "SRCPORT", "DSTIP", "DSTPORT", "TOIP", "TOPORT", "SNDIP",
  "SNDPORT", "SNDPROTO", "SNDAF", "PROTO", "AF", "MYSELF", "MSGLEN", "UDP",
  "TCP", "TLS", "SCTP", "WS", "WSS", "DEBUG_V", "FORK", "FORK_DELAY",
  "MODINIT_DELAY", "LOGSTDERROR", "LOGFACILITY", "LOGNAME", "LOGCOLOR",
  "LOGPREFIX", "LOGPREFIXMODE", "LOGENGINETYPE", "LOGENGINEDATA",
  "XAVPVIAPARAMS", "LISTEN", "ADVERTISE", "ALIAS", "SR_AUTO_ALIASES",
  "DNS", "REV_DNS", "DNS_TRY_IPV6", "DNS_TRY_NAPTR", "DNS_SRV_LB",
  "DNS_UDP_PREF", "DNS_TCP_PREF", "DNS_TLS_PREF", "DNS_SCTP_PREF",
  "DNS_RETR_TIME", "DNS_RETR_NO", "DNS_SERVERS_NO", "DNS_USE_SEARCH",
  "DNS_SEARCH_FMATCH", "DNS_NAPTR_IGNORE_RFC", "DNS_CACHE_INIT",
  "DNS_USE_CACHE", "DNS_USE_FAILOVER", "DNS_CACHE_FLAGS",
  "DNS_CACHE_NEG_TTL", "DNS_CACHE_MIN_TTL", "DNS_CACHE_MAX_TTL",
  "DNS_CACHE_MEM", "DNS_CACHE_GC_INT", "DNS_CACHE_DEL_NONEXP",
  "DNS_CACHE_REC_PREF", "AUTO_BIND_IPV6", "DST_BLST_INIT", "USE_DST_BLST",
  "DST_BLST_MEM", "DST_BLST_TTL", "DST_BLST_GC_INT", "DST_BLST_UDP_IMASK",
  "DST_BLST_TCP_IMASK", "DST_BLST_TLS_IMASK", "DST_BLST_SCTP_IMASK",
  "IP_FREE_BIND", "PORT", "STAT", "CHILDREN", "SOCKET_WORKERS",
  "ASYNC_WORKERS", "ASYNC_USLEEP", "CHECK_VIA", "PHONE2TEL", "MEMLOG",
  "MEMDBG", "MEMSUM", "MEMSAFETY", "MEMJOIN", "MEMSTATUSMODE", "CORELOG",
  "SIP_WARNING", "SERVER_SIGNATURE", "SERVER_HEADER", "USER_AGENT_HEADER",
  "REPLY_TO_VIA", "LOADMODULE", "LOADPATH", "MODPARAM", "CFGENGINE",
  "MAXBUFFER", "SQL_BUFFER_SIZE", "USER", "GROUP", "CHROOT", "WDIR",
  "RUNDIR", "MHOMED", "DISABLE_TCP", "TCP_ACCEPT_ALIASES", "TCP_CHILDREN",
  "TCP_CONNECT_TIMEOUT", "TCP_SEND_TIMEOUT", "TCP_CON_LIFETIME",
  "TCP_POLL_METHOD", "TCP_MAX_CONNECTIONS", "TLS_MAX_CONNECTIONS",
  "TCP_NO_CONNECT", "TCP_SOURCE_IPV4", "TCP_SOURCE_IPV6",
  "TCP_OPT_FD_CACHE", "TCP_OPT_BUF_WRITE", "TCP_OPT_CONN_WQ_MAX",
  "TCP_OPT_WQ_MAX", "TCP_OPT_RD_BUF", "TCP_OPT_WQ_BLK",
  "TCP_OPT_DEFER_ACCEPT", "TCP_OPT_DELAYED_ACK", "TCP_OPT_SYNCNT",
  "TCP_OPT_LINGER2", "TCP_OPT_KEEPALIVE", "TCP_OPT_KEEPIDLE",
  "TCP_OPT_KEEPINTVL", "TCP_OPT_KEEPCNT", "TCP_OPT_CRLF_PING",
  "TCP_OPT_ACCEPT_NO_CL", "TCP_OPT_ACCEPT_HEP3", "TCP_CLONE_RCVBUF",
  "TCP_REUSE_PORT", "DISABLE_TLS", "ENABLE_TLS", "TLSLOG", "TLS_PORT_NO",
  "TLS_METHOD", "TLS_HANDSHAKE_TIMEOUT", "TLS_SEND_TIMEOUT", "SSLv23",
  "SSLv2", "SSLv3", "TLSv1", "TLS_VERIFY", "TLS_REQUIRE_CERTIFICATE",
  "TLS_CERTIFICATE", "TLS_PRIVATE_KEY", "TLS_CA_LIST", "DISABLE_SCTP",
  "ENABLE_SCTP", "SCTP_CHILDREN", "ADVERTISED_ADDRESS", "ADVERTISED_PORT",
  "DISABLE_CORE", "OPEN_FD_LIMIT", "SHM_MEM_SZ", "SHM_FORCE_ALLOC",
  "MLOCK_PAGES", "REAL_TIME", "RT_PRIO", "RT_POLICY", "RT_TIMER1_PRIO",
  "RT_TIMER1_POLICY", "RT_TIMER2_PRIO", "RT_TIMER2_POLICY",
  "MCAST_LOOPBACK", "MCAST_TTL", "MCAST", "TOS", "PMTU_DISCOVERY",
  "KILL_TIMEOUT", "MAX_WLOOPS", "PVBUFSIZE", "PVBUFSLOTS", "PVCACHELIMIT",
  "PVCACHEACTION", "HTTP_REPLY_PARSE", "VERSION_TABLE_CFG",
  "VERBOSE_STARTUP", "ROUTE_LOCKS_SIZE", "CFG_DESCRIPTION", "SERVER_ID",
  "KEMI", "ONSEND_ROUTE_CALLBACK", "REPLY_ROUTE_CALLBACK",
  "EVENT_ROUTE_CALLBACK", "MAX_RECURSIVE_LEVEL", "MAX_BRANCHES_PARAM",
  "LATENCY_CFG_LOG", "LATENCY_LOG", "LATENCY_LIMIT_DB",
  "LATENCY_LIMIT_ACTION", "MSG_TIME", "ONSEND_RT_REPLY", "FLAGS_DECL",
  "AVPFLAGS_DECL", "ATTR_MARK", "SELECT_MARK", "ATTR_FROM", "ATTR_TO",
  "ATTR_FROMURI", "ATTR_TOURI", "ATTR_FROMUSER", "ATTR_TOUSER",
  "ATTR_FROMDOMAIN", "ATTR_TODOMAIN", "ATTR_GLOBAL", "ADDEQ", "SUBST",
  "SUBSTDEF", "SUBSTDEFS", "EQUAL", "LOG_OR", "LOG_AND", "BIN_OR",
  "BIN_AND", "BIN_XOR", "BIN_LSHIFT", "BIN_RSHIFT", "EQUAL_T", "DIFF",
  "MATCH", "INTEQ", "INTDIFF", "STREQ", "STRDIFF", "GT", "LT", "GTE",
  "LTE", "PLUS", "MINUS", "STAR", "SLASH", "MODULO", "NOT", "UNARY",
  "BIN_NOT", "DEFINED", "INTCAST", "STRCAST", "DOT", "STRLEN", "STREMPTY",
  "NUMBER", "ID", "NUM_ID", "STRING", "IPV6ADDR", "PVAR", "AVP_OR_PVAR",
  "EVENT_RT_NAME", "COMMA", "SEMICOLON", "RPAREN", "LPAREN", "LBRACE",
  "RBRACE", "LBRACK", "RBRACK", "CR", "COLON", "$accept", "cfg",
  "statements", "statement", "$@1", "$@2", "$@3", "$@4", "$@5",
  "listen_id", "listen_id_lst", "listen_id2", "proto", "eqproto", "port",
  "phostport", "listen_phostport", "id_lst", "intno", "flags_decl",
  "flag_list", "flag_spec", "flag_name", "avpflags_decl", "avpflag_list",
  "avpflag_spec", "assign_stm", "cfg_var_id", "cfg_var_idn", "cfg_var",
  "module_stm", "ip", "ipv4", "ipv6addr", "ipv6", "route_name",
  "route_main", "route_stm", "failure_route_stm", "route_reply_main",
  "onreply_route_stm", "$@6", "$@7", "branch_route_stm", "send_route_stm",
  "event_route_stm", "preprocess_stm", "equalop", "cmpop", "strop",
  "rve_equalop", "rve_cmpop", "uri_type", "eint_op_onsend", "eint_op",
  "eip_op_onsend", "eip_op", "exp_elem", "ipnet", "host", "host_if_id",
  "host_or_if", "fcmd", "stm", "actions", "action", "if_cmd", "ct_rval",
  "single_case", "case_stms", "switch_cmd", "while_cmd", "select_param",
  "select_params", "select_id", "$@8", "attr_class_spec", "attr_name_spec",
  "attr_spec", "attr_mark", "attr_id", "attr_id_num_idx", "attr_id_no_idx",
  "attr_id_ass", "attr_id_any", "attr_id_any_str", "pvar", "avp_pvar",
  "assign_op", "lval", "rval", "rve_un_op", "rval_expr", "assign_action",
  "avpflag_oper", "cmd", "$@9", "func_params", "func_param", "ret_cmd", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595
};
# endif

#define YYPACT_NINF -1123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1123)))

#define YYTABLE_NINF -866

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2516,  -195,     9,    28,  -171,  -166,  -149,  -141,  -134,  -125,
   -1123,  -116,  -111,  -101,   -82,   -54,   -51,   -43,   -33,   -27,
     -23,   -22,   -18,   -13,     0,    25,    39,    44,   372,    40,
      61,    72,   245,   320,   716,   745,   765,   806,   838,   847,
     848,   866,   878,   883,   886,   887,   888,   897,   898,   902,
     907,   908,   909,   914,   918,   924,   925,   928,   929,   933,
     934,   936,   937,   388,   401,   402,   436,   452,   467,   468,
     472,   477,   512,   518,   535,   548,   560,   561,   566,   574,
     586,   669,   680,   681,    74,   189,    37,   191,   685,   695,
     743,   759,   763,   764,   773,   776,   825,   831,   859,   864,
     873,   879,   885,   895,   904,   916,   923,   931,   932,   947,
     938,   939,   944,   945,   963,   968,   979,   985,   986,   989,
     992,  1031,  1032,  1038,  1064,  1065,  1082,  1083,  1096,  1098,
    1099,  1100,  1102,  1108,  1109,  1110,  1111,  1115,  1116,  1117,
    1118,  1119,  1120,  1121,  1130,  1141,  1143,  1144,  1145,  1146,
    1147,  1155,  1156,  1157,  1158,  1161,  1163,  1188,  1189,  1190,
     948,  1191,  1192,  1193,  1195,  1196,  1197,  1198,  1199,  1200,
    1201,  1202,   -34,  1203,  1204,  1205,  1211,  1212,  1213,  1214,
    1215,   111,   122,   105,   135,   174, -1123, -1123, -1123,   322,
    1638, -1123,   207,   286,   116,   357,   285, -1123, -1123, -1123,
    -254, -1123, -1123,   466, -1123, -1123, -1123, -1123,   632, -1123,
     195,   215,   802,   323,   242,   330,   353,   332,   359,   360,
     421,    32,   184,   422,   198,   481,   205,   219,   222,    71,
     141,   613,   653,   658, -1123,   522, -1123,   627, -1123,   654,
   -1123,  -230, -1123,  -230, -1123,  -230, -1123,  -230, -1123,   670,
   -1123,   671, -1123,   674, -1123,   678, -1123,   682, -1123,   700,
   -1123,   713, -1123,   729, -1123,   734, -1123,   754, -1123,   758,
   -1123,   771, -1123,   827, -1123,   867, -1123,   967, -1123,   971,
   -1123,  1017, -1123,  1183, -1123,  1185, -1123,  1186, -1123,  1276,
   -1123,  1300, -1123,  1301, -1123,  1302, -1123,  1303, -1123,  1304,
   -1123,  1305,   356,   660,   508,   666,   684,   686,   687,   688,
     693,   367,   449,   483,   531,   555,   584,   618,   696,   697,
     226,   240,   702, -1123, -1123, -1123,   258, -1123, -1123,   760,
   -1123,   264, -1123,   703,   704,   182,   187,   218,   233,   253,
     705,   706,   707,   708,   621,   655,   656,   269,   709,   711,
     714,   715,    16,   717,   718, -1123,  1306, -1123,  1307, -1123,
    1308, -1123,  1310,   719,   720,   721,   722,   723,   727,   728,
     733,   735,   736,   737,   738,   739,   742,   746,   751,   752,
     852,   753,   762,   767,   768,   274,   275,   277,   769,   770,
     772,    89,   774,   780,   782,   783,   784,   785,   786,   787,
     788,   789,   791,   793,   794,   795,   796,   270,    12, -1123,
    1311,   797,   799,   804,   808,   809,   810,   812,   280,   813,
     816,   817,   -11,  1312,  1313,   657,   659,   818,   819,   820,
     821, -1123, -1123, -1123, -1123,   677,   747, -1123, -1123, -1123,
    1314, -1123, -1123, -1123, -1123, -1123, -1123, -1123,  -195, -1123,
      15,    38,   683, -1123,    35, -1123,    41, -1123,    48, -1123,
      10, -1123,    -4,  1317, -1123, -1123, -1123, -1123,   761, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123,  1320, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123,  1324, -1123, -1123, -1123, -1123,
    -122,  1319, -1123,  1292,  1297,  1173,  1540, -1123, -1123, -1123,
   -1123, -1123,  -260, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,  1318, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123,  1324, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123,  1360,  1361,  1370, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123,  -245,  1338,  -245, -1123,   632, -1123, 11802,
   -1123, 11802,   632, -1123, 11802,   632, -1123, 11802,   632, -1123,
    1332, -1123, -1123, -1123,  1373,  1326, 11802,    45, -1123,  1344,
    1337,  1336,  1333,   307,  1000, -1123,  -122,   312,   315,  1346,
     281,   282,   283, -1123, -1123, -1123,  1335,    50,    54,    57,
      67,    68, 10745, 10830, 11163, -1123,    70,    73,    75,  1340,
      76,    83,    84,    90,    91,    93,    95,   104,  1341,   106,
     107,   109,   110,  1343,  1350,  1351,  1352,  1353, 11248,   113,
     119,   120,  1354,  1355,  1356,  1357,  6273, 11248,   124,   129,
     136,   138,   139, -1123, -1123, -1123, -1123,   142, -1123, -1123,
   -1123,    87,  3537, -1123, -1123, -1123, -1123,   964, -1123, -1123,
   -1123, -1123, -1123,  1380,  1362,   146, -1123,  1364,  3611,  1359,
    3945,  1363,  4014,  1365,  1367,   162,  1358,  4083, -1123,  1375,
    1372,  -122, -1123, -1123, -1123, -1123, -1123, -1123,  1381,  1382,
   -1123, -1123, -1123, -1123, -1123,  1368, -1123, -1123, -1123, -1123,
   -1123, -1123,  1385, -1123,    66, -1123,   199, -1123,   227, -1123,
     244, -1123,   265,   582, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123,   913, -1123,   913, -1123,   644,
   -1123, -1123,  1320, -1123, -1123,  6608,  6695,  6782,  1392,  1394,
   -1123,  5677, 11735, -1123,   597, -1123,   854, -1123,   692, -1123,
   -1123, -1123,   964, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
    7117,  2844,  5764,  2844,  6099,  2844, -1123,   193, -1123,   290,
   -1123,  7204,  1376, -1123,   291, -1123,   294, -1123,   295, -1123,
     297, -1123,   822, -1123,   828, -1123,  1396, -1123,   210,  1397,
   -1123,   298, -1123,   299, -1123,   300, -1123,   302,  1413,  1523,
    1524,   179,   823,  7291, 10678, -1123,   168, -1123,   832, -1123,
     249,  1525,  1526,  1564,  1567, -1123,  1220, 10678, -1123,   303,
   -1123,   306, -1123,   698, -1123,   961, -1123,  1012, -1123,  1568,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123,  1378, -1123,  1576, -1123, 11248,
   -1123, -1123,   232, -1123, -1123,  1566, -1123,  1579, -1123,  1580,
    1581, -1123,  1434,  1456,    -4, -1123, 11802,  1594, -1123,  -185,
    1595,  -155, 11802,  1586,  -215, -1123,  -161, -1123,   -89,   -96,
    1587,   -19,   511,   544,   860,  1588,   841,   850,   870,   869,
    1589,   899,   926,   940,   876,  1590,  1008,  1020,  1050,   900,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123,  7626,  5249,  5584,
   -1123,  1194,  1600, -1123, -1123, -1123, -1123, -1123, -1123,  7713,
    7800,  1596, -1123,  1663,  1664,  1665,  1666,  1265,  1624,  1592,
    4157, -1123,  8135, -1123, -1123, -1123, -1123, -1123,  8222,  8309,
   -1123,  1390,  1621, -1123, -1123,  8644,  8731,  8818,  9153, 11248,
   11248, 11248, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123,  9240,  9327,  9662,  9749,  9836, 10171, 10258,
   -1123, -1123,  1626,  1629,  1628,  1630,  1633,  1632,    53,  1309,
    1634,  1635,  1636,  1640,  1641,  1642,  1657,  1658,  1659,  1660,
    1661,  1662,  1672, -1123,  1683, -1123,  1685, -1123,  1686,  1687,
    1689,  1698,  1699,  1703,  1704,  1705, -1123, -1123, -1123,  1713,
    1726, -1123,  1727,  1728, 11802,  1919, -1123,  1729,  1730,  1731,
    1732,  1741,  1631,  1656,  1752, -1123, -1123, -1123, -1123,    30,
   -1123,  1754,  1757,  1756,  1758,  1767,  1768,  1772,  1773,  1774,
    1782, 11248,  1804,  1791,  2844,  1051, -1123,   964, -1123,  1799,
   -1123, 11802, 11802, 11802, 11802,  1805,  1806,  1843,  4491,  1814,
   -1123, -1123,  1810,  1821,  4560, -1123,    -5, -1123,  1833, -1123,
    1834, -1123,   108,   163,  1835, -1123, -1123,     2, -1123,  1837,
   -1123,  1846, -1123,  1847, -1123, -1123,   543, -1123,  1851, -1123,
    1852, -1123,  1853, -1123, -1123,   663, -1123,  1860, -1123,  1861,
   -1123,  1862, -1123, -1123,   694, -1123,  1863, -1123,  1864, -1123,
    1866, -1123, -1123,  2044,  1058, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123,  1058, -1123, -1123,  1058, -1123, -1123,
   -1123,  1865, -1123,  1883,  1871,  1639,  1872,  2291, -1123, -1123,
   -1123, -1123, -1123, -1123,  2113,  1058, -1123,  1058, -1123,  1035,
   -1123,  2187,  1324,  1975,  1894, -1123,  -143,  1058,  -165, -1123,
    2906, -1123,  1241, -1123,  1004, -1123,  1284,  2862,  2923,  2240,
   -1123,   557, -1123,   557, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123,  1058, -1123,  1035, -1123,  1881, -1123, -1123,  1882, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,  4629,
   11666, -1123, -1123, -1123, -1123, -1123,   454,  -122, -1123,  1892,
    6186,  1877, -1123, -1123,    -9, -1123, 11333, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123,  2844,  1054, -1123, -1123, -1123,
    -245, -1123, -1123,   273,  4703,  5037,  5106,  5175, -1123, -1123,
    -267, -1123,  1907, -1123, -1123, -1123,  1898,  1899,  1901,  1910,
   -1123, -1123, -1123, -1123,  1911,  1915,  1916,  1924,  1925,  1926,
    1927,  1928,  1929,  1930,  1931,  1932,  1956,  1957,  1958,  1959,
    1960,  1961,  1963,  1964,  1965,  -128,  1600, -1123, -1123, -1123,
   -1123,    18,  1962,  1968,  1969, -1123, -1123, -1123, -1123,  1971,
   -1123,  1972, 10345,  1973,  2844, 11802, -1123, -1123,  1981,  2517,
   11248, -1123,  1983,  1984,  1985, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123,  1967,  1982, -1123,
   -1123,  1324, -1123, -1123, -1123, -1123,  -185, 11802,  1986,  1987,
    2853,  2922, -1123, -1123, -1123, -1123, -1123, -1123, -1123, -1123,
   -1123,  2991, 11802, 11802, -1123,  3065,  3399,  3468
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   431,    22,    23,     0,
       0,     4,     0,     0,     0,     0,     0,     8,     9,     6,
       0,   429,    10,     0,    15,     7,   430,   478,     0,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,   105,     0,   107,     0,
     109,     0,   111,     0,   113,     0,   115,     0,   117,     0,
     119,     0,   121,     0,   123,     0,   125,     0,   127,     0,
     129,     0,   131,     0,   133,     0,   135,     0,   137,     0,
     141,     0,   139,     0,   143,     0,   145,     0,   147,     0,
     149,     0,   151,     0,   153,     0,   155,     0,   157,     0,
     159,     0,   161,     0,   163,     0,   165,     0,   167,     0,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   444,   443,   446,     0,   445,   451,     0,
     453,     0,   452,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,     0,   258,     0,   260,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   376,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    66,    65,    59,    61,    63,    68,    71,    67,
      69,   492,   491,   494,   493,   496,   495,     1,     5,     3,
       0,     0,     0,    12,     0,    14,     0,    17,     0,    19,
       0,    21,     0,     0,   476,   462,   463,   464,     0,   420,
     419,   418,   417,   422,    31,    32,    33,    34,    35,   421,
     424,     0,    57,   423,   426,   425,   428,   427,    73,    72,
      75,    74,    77,    76,    79,    78,    81,    80,    83,    82,
      85,    84,    87,    86,    89,    88,    91,    90,    93,    92,
      95,    94,    97,    96,   332,   574,   572,   573,    25,   459,
       0,     0,    30,    50,     0,    55,   330,    24,   456,   460,
     457,   575,    26,   334,   333,   336,   335,    99,    98,   101,
     100,   102,   104,   106,   108,   110,   112,   114,   116,   118,
     120,   122,   124,   126,   128,   130,   132,   134,   136,   140,
     138,   142,   144,   146,   148,   150,   152,   154,   156,   158,
     160,   162,   164,   166,   168,   171,   170,   178,   172,   173,
     180,   179,   182,   181,   184,   183,   186,   185,   188,   187,
     190,   189,   192,   191,   194,   193,   196,   195,   198,   197,
     200,   199,   202,   201,   204,   203,   206,   205,   323,   322,
     325,   324,   327,   326,   329,   328,   448,   447,     0,   455,
     454,   175,   174,   177,   176,   211,   210,   209,   214,   213,
     212,   217,   216,   215,   220,   219,   218,   223,   222,   221,
     225,   224,   227,   226,   229,   228,   231,   230,   233,   232,
     235,   234,   237,   236,   240,   238,   239,   242,   241,   244,
     243,   246,   245,   248,     0,   247,   250,   249,   252,   251,
     254,   253,   255,   257,   259,   261,   264,   263,   266,   265,
     268,   267,   270,   269,   272,   271,   274,   273,   276,   275,
     278,   277,   280,   279,   282,   281,   284,   283,   286,   285,
     288,   287,   290,   289,   292,   291,   294,   293,   296,   295,
     301,   297,   298,   299,   300,   313,   312,   315,   314,   303,
     302,   305,   304,   307,   306,   309,   308,   311,   310,   317,
     316,   319,   318,   321,   320,   338,   337,   340,   339,   342,
     341,   344,   343,   346,   345,   348,   347,   350,   349,   352,
     351,   354,   353,   356,   355,   358,   357,   360,   359,   362,
     361,   364,   363,   366,   365,   368,   367,   371,   369,   370,
     374,   372,   373,   375,   378,   377,   380,   379,   382,   381,
     384,   383,   386,   385,   388,   387,   390,   389,   208,   207,
     392,   391,   394,   393,   396,   395,     0,     0,     0,   403,
     404,   408,   407,   406,   405,   410,   409,   412,   411,   414,
     413,   416,   415,     0,     0,     0,   469,     0,   470,     0,
     473,     0,     0,   485,     0,     0,   488,     0,     0,   490,
       0,   434,   435,   433,     0,     0,     0,     0,    58,     0,
      27,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,    62,    64,    70,     0,     0,     0,     0,
       0,     0,   877,   874,   878,   881,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   830,   832,   834,   837,     0,     0,     0,
       0,     0,   851,   853,   855,   857,     0,     0,     0,     0,
       0,     0,     0,   707,   708,   709,   634,     0,   646,   647,
     592,     0,     0,   584,   587,   588,   589,     0,   638,   639,
     649,   650,   651,     0,     0,     0,   580,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   482,     0,
       0,     0,    29,   461,    54,    44,    43,    51,    52,     0,
     579,   574,   577,   578,   576,     0,   398,   397,   400,   399,
     402,   401,     0,   720,     0,   742,     0,   753,     0,   764,
       0,   731,     0,     0,   518,   519,   520,   531,   524,   532,
     525,   530,   522,   529,   521,     0,   523,     0,   526,     0,
     527,   620,   666,   664,   665,     0,     0,     0,     0,     0,
     653,     0,     0,   652,     0,   528,     0,   533,     0,   659,
     658,   657,     0,   640,   642,   641,   654,   655,   656,   667,
       0,   876,     0,   873,     0,   880,   768,     0,   785,     0,
     789,     0,     0,   793,     0,   812,     0,   815,     0,   796,
       0,   802,     0,   799,     0,   805,     0,   808,     0,     0,
     821,     0,   824,     0,   818,     0,   827,     0,     0,     0,
       0,     0,     0,     0,     0,   843,     0,   846,     0,   849,
       0,     0,     0,     0,     0,   612,     0,     0,   860,     0,
     863,     0,   772,     0,   775,     0,   778,     0,   867,     0,
     593,   586,   585,   467,   583,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,     0,   632,   635,   648,     0,
     591,   783,     0,   590,   471,     0,   483,     0,   486,     0,
       0,   440,   436,   437,     0,   477,     0,     0,    28,     0,
       0,     0,     0,     0,     0,   567,     0,   710,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     537,   497,   498,   506,   499,   500,   505,     0,     0,     0,
     562,     0,     0,   705,   688,   690,   669,   691,   670,     0,
       0,     0,   875,   640,   641,   655,   656,     0,     0,     0,
       0,   541,     0,   546,   501,   502,   503,   504,     0,     0,
     558,     0,   635,   689,   668,     0,     0,     0,     0,     0,
       0,     0,   507,   508,   513,   509,   510,   511,   512,   514,
     515,   516,   517,     0,     0,     0,     0,     0,     0,     0,
     872,   879,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   804,     0,   807,     0,   810,     0,     0,
       0,     0,     0,     0,     0,     0,   829,   831,   833,     0,
       0,   836,     0,     0,     0,   594,   581,     0,     0,     0,
       0,     0,    45,     0,     0,   850,   852,   854,   856,     0,
     614,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   868,     0,     0,   706,     0,   645,     0,   643,     0,
     644,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,   331,     0,     0,     0,   721,     0,   719,     0,   712,
       0,   713,     0,     0,     0,   711,   743,     0,   741,     0,
     734,     0,   735,     0,   733,   754,     0,   752,     0,   745,
       0,   746,     0,   744,   765,     0,   763,     0,   756,     0,
     757,     0,   755,   732,     0,   730,     0,   723,     0,   724,
       0,   722,   536,     0,   534,   552,    36,    37,    38,    39,
      40,    41,    42,   550,   551,   549,   547,   548,   561,   559,
     560,   615,   619,   621,     0,     0,     0,     0,   663,   685,
     662,   661,   660,   540,     0,   538,   545,   543,   544,   542,
     557,     0,    57,     0,   565,   553,   555,   554,     0,   702,
     684,   701,   683,   697,   676,   698,   677,   678,   679,   680,
     692,   671,   693,   672,   694,   673,   695,   674,   696,   675,
     700,   682,   699,   681,   769,     0,   766,   786,     0,   790,
     788,   787,   791,   794,   792,   813,   811,   816,   814,   797,
     795,   803,   801,   800,   798,   809,   806,   822,   820,   825,
     823,   819,   817,   828,   826,   838,   835,   840,   839,     0,
       0,   842,   841,   845,   844,   848,     0,     0,   847,     0,
       0,     0,   611,   609,     0,   861,     0,   864,   862,   770,
     771,   773,   774,   776,   777,   871,     0,   870,   633,   637,
       0,   782,   635,     0,     0,     0,     0,     0,   438,   439,
       0,   481,     0,   449,   450,   468,     0,     0,     0,     0,
     571,   569,   570,   568,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   703,   686,   704,
     687,     0,     0,     0,     0,   582,   595,    49,    46,    47,
     613,     0,     0,     0,   596,   602,   610,   608,    57,     0,
       0,   866,     0,     0,     0,   472,   484,   487,   489,   441,
     442,   458,   717,   718,   715,   716,   714,   739,   740,   737,
     738,   736,   750,   751,   748,   749,   747,   761,   762,   759,
     760,   758,   728,   729,   726,   727,   725,     0,     0,   618,
     566,   564,   563,   636,   767,   784,     0,   605,     0,     0,
       0,     0,   858,   859,   869,   781,   780,   779,   617,   616,
      48,     0,   606,   600,   607,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1123, -1123, -1123,  2131, -1123, -1123, -1123, -1123, -1123,  -386,
    1383,  1478,  -210,  1154, -1122, -1123, -1123,  -216,  -213, -1123,
    1512, -1123,  -181, -1123,  1513, -1123, -1123, -1123,  1206, -1123,
   -1123,  -946,  1978,  1811,  1979,   461, -1123, -1123, -1123, -1123,
   -1123, -1123, -1123, -1123, -1123, -1123, -1123,  -962, -1123,  -926,
   -1123, -1123,  1162, -1123, -1123, -1123,  1187, -1123, -1123,   132,
    -622, -1123,  -391, -1069,  -670,  -867, -1123,   790,   840, -1123,
   -1123, -1123,   803, -1123, -1123, -1123, -1123,  1059,  -997,  -563,
    -815, -1123,  -643, -1123, -1123, -1123,  -350,  -784, -1123, -1123,
   -1123, -1123,   151,  -872, -1123, -1123, -1123, -1123,   800, -1123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   522,
     841,   523,   524,  1383,   947,  1284,   525,   526,  1003,   197,
     434,   435,   436,   198,   439,   440,   199,   200,   834,   201,
     202,   527,   528,   529,   530,   468,   452,   453,   455,   203,
     204,   836,   939,   457,   459,   461,   205,  1166,  1199,  1167,
    1228,  1229,  1004,  1005,  1006,  1007,  1008,  1009,  1415,  1139,
     531,   532,  1010,  1275,   912,   913,   914,  1573,  1493,  1494,
     915,   916,  1392,  1393,  1011,  1172,  1105,  1106,  1107,  1012,
    1013,  1014,  1015,   920,  1016,  1309,  1017,  1018,  1109,   923,
    1019,  1020,  1187,   924,   925,   926,  1089,  1506,  1507,   927
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     483,   438,   479,   489,   918,   736,   918,  1320,  1290,   918,
     207,   829,   918,   770,   534,  1202,   816,   666,  1138,  1620,
    1143,   918,  1148,  1168,  1153,  1169,  1158,  1171,   544,   209,
     545,  1489,   546,   498,   547,   922,   820,   922,   328,   818,
     922,   234,   823,   922,  1198,  1094,   938,  1490,  1491,   826,
     847,   963,   922,   831,  1088,   965,  1589,  1526,   967,  1590,
     848,  1094,   236,  1094,  1535,  1094,   462,  1133,   969,   971,
    1094,  1026,   514,   238,  1028,   323,  1030,  1033,  1192,   432,
     481,   433,  1201,   463,  1035,  1037,  1490,  1491,  1090,   576,
     735,  1039,  1041,   482,  1043,   206,  1045,   918,   593,   595,
     597,   599,   601,   603,   605,  1047,   441,  1050,  1052,  1530,
    1054,  1056,   431,   918,  1065,   918,  1326,   918,  1327,   210,
    1067,  1069,   918,   437,   211,  1078,   945,  1134,   922,  1188,
    1080,   649,   651,   653,   840,   456,   443,  1082,   946,  1084,
    1086,   212,   533,  1088,   922,   481,   922,  1111,   922,   213,
    1188,   928,  1188,   922,   930,   481,   214,   932,   482,   474,
     475,   476,   477,  1121,  1532,   215,   937,  1332,   482,  1277,
    1328,  1322,  1329,  1509,   216,   445,   919,  1333,   919,   217,
    1269,   919,   481,   625,   919,   500,  1183,   918,   628,   218,
     325,  1188,   330,   919,  1232,   482,   469,  1276,  1617,   504,
    1140,   515,   516,   517,   518,   519,   508,  1183,   219,  1183,
    1276,  1254,   802,   804,  1332,   521,   471,  1186,   922,   631,
     510,   450,   451,   512,  1333,   952,   954,   610,  1145,   474,
     475,   476,   477,  1305,   634,  1334,   220,  1335,  1186,   221,
    1186,   612,  1330,   484,  1331,  1150,   240,   222,  1183,   918,
    1281,   796,   797,   798,   637,  1414,   917,   223,   917,   616,
    1141,   917,   918,   224,   917,   619,  1155,   225,   226,   919,
     654,   767,   227,   917,  1583,   723,   725,   228,   727,  1186,
     922,   788,   956,   958,   960,   919,   422,   919,  1146,   919,
     229,  1235,  1241,   922,   919,  1243,  1245,  1308,  1247,  1258,
    1260,  1262,   454,  1264,  1291,  1151,   460,  1293,   944,   845,
    1512,   918,  1337,   950,  1338,   230,   953,   918,  1527,   832,
     833,   242,   447,  1094,   480,  1536,  1156,  1576,  1310,   231,
     235,   486,  1190,   490,   232,   771,   772,   474,   475,   476,
     477,  1621,   922,   519,  -474,   519,   208,   830,   922,   917,
    -465,   237,   817,   521,   488,   521,   499,   575,  1184,   919,
     492,   494,   239,  -475,  1568,   917,  1492,   917,   592,   917,
     821,   329,   822,  -466,   917,   918,   824,   458,   825,  1184,
    -480,  1184,   478,   827,   964,   828,  1450,  -865,   966,   664,
    1135,   968,  1136,   519,   515,   516,   517,   518,   519,  1137,
     324,   970,   972,   521,  1027,   520,   922,  1029,   521,  1031,
    1034,  1566,   515,   516,   517,   518,   519,  1036,  1038,  1091,
    1184,   919,   496,   502,  1040,  1042,   521,  1044,   911,  1046,
     911,   442,  1531,   911,   919,   432,   911,   433,  1048,   917,
    1051,  1053,  1171,  1055,  1057,   911,   432,  1066,   433,  1171,
     594,  1094,   478,  1068,  1070,  1567,  1318,  1094,  1079,   918,
     949,   444,  1324,  1081,   515,   516,   517,   518,   519,   921,
    1083,   921,  1085,  1087,   921,   520,  -865,   921,   521,   326,
    1112,   331,   506,   919,   596,  1122,   921,  1533,  1123,   919,
     922,   515,   516,   517,   518,   519,   918,   918,   918,   918,
     446,   917,  1270,   918,  1640,   521,   626,   906,   627,   918,
     501,   629,  1271,   630,   917,   327,  1233,   332,   470,  1234,
     481,   911,   664,  1135,   505,  1142,   519,   922,   922,   922,
     922,   509,   598,   482,   922,   241,   521,   911,   472,   911,
     922,   911,   632,  1255,   633,   511,   911,   919,   513,  1307,
     664,  1135,   611,  1147,   519,   840,   600,   635,  1306,   636,
     478,   909,   921,   917,   521,   485,   613,   664,  1135,   917,
    1152,   519,   515,   516,   517,   518,   519,   638,   921,   639,
     921,   521,   921,  1160,   617,   602,   521,   921,   664,  1135,
     620,  1157,   519,   655,   768,   656,   769,   432,  1191,   433,
     724,   726,   521,   728,  1479,  1540,   789,   957,   959,   961,
     243,   911,  1094,  1276,   535,  1622,  1236,  1242,   945,   604,
    1244,  1246,   648,  1248,  1259,  1261,  1263,   917,  1265,  1292,
     946,   919,  1294,   481,   438,   951,   516,   517,   951,   516,
     517,  1514,  1515,  1516,  1517,  1170,   482,  1094,  1094,  1094,
    1094,  1185,   921,   487,   537,   491,   650,   652,   801,   539,
     803,   577,   233,   481,   918,   918,   481,   580,   919,   919,
     919,   919,  1185,   911,  1185,   919,   482,   481,   302,   482,
    1278,   919,   493,   495,  1282,   582,   911,   584,   586,   588,
     482,   303,   304,  1200,   590,   922,   922,   606,   608,   918,
     918,   918,   918,   614,   621,   623,   640,   642,   644,   646,
     657,   917,   659,  1185,   921,   661,   663,   244,   668,   670,
     676,   678,   680,   682,   684,  1545,   305,   921,   686,   688,
     922,   922,   922,   922,   690,   911,   692,   694,   696,   698,
     700,   911,   306,   702,   497,   503,   246,   704,   917,   917,
     917,   917,   706,   708,   715,   917,  1550,   307,   308,   481,
     918,   917,   309,   717,  1094,   945,   248,   310,   719,   721,
     729,   731,   482,   733,  1094,   737,   921,   946,  1094,  1094,
    1094,   739,   921,   741,   743,   745,   747,   749,   751,   753,
     755,   922,   757,   481,   759,   761,   763,   765,   774,   911,
     776,   464,   311,   473,   507,   778,   482,   250,   312,   780,
     782,   784,   918,   786,   790,   918,   918,   792,   794,   805,
     807,   809,   811,  1249,  1272,   313,   918,   918,   918,  1251,
     918,   918,   918,  1279,   579,  1256,   919,   919,   314,   252,
     921,   481,  1339,   922,  1340,   541,   922,   922,   254,   256,
     315,   316,  1273,   710,   482,  1193,   317,   922,   922,   922,
    1283,   922,   922,   922,   318,   481,  1541,   258,  1225,  1226,
    1227,   919,   919,   919,   919,  1341,   319,  1342,   482,   260,
    1161,  1162,  1163,   911,   262,  1164,  1165,   264,   266,   268,
     474,   475,   476,   477,   481,  1161,  1162,  1163,   270,   272,
    1164,  1165,  1296,   274,  1298,  1631,  1300,   482,   276,   278,
     280,   474,   475,   476,   477,   282,   917,   917,  1323,   284,
     911,   911,   911,   911,   921,   286,   288,   911,   481,   290,
     292,   481,   919,   911,   294,   296,   536,   298,   300,   355,
     357,   482,  1161,  1162,   482,   359,   361,  1164,  1165,   409,
     542,   917,   917,   917,   917,   465,   466,  1641,   467,   320,
    1645,   921,   921,   921,   921,   481,   481,   481,   921,   481,
     321,   322,  1646,  1647,   921,   333,   538,   543,   482,   482,
     482,   540,   482,   578,   919,   334,  1546,   919,   919,   581,
    1161,  1162,  1163,   548,   549,  1164,  1165,   550,   919,   919,
     919,   551,   919,   919,   919,   552,   245,   583,   813,   585,
     587,   589,   917,  1021,  1023,  1025,   591,  1551,   819,   607,
     609,  1295,   432,   553,   433,   615,   622,   624,   641,   643,
     645,   647,   658,   335,   660,   247,   554,   662,   664,  1064,
     669,   671,   677,   679,   681,   683,   685,  1076,  1077,   336,
     687,   689,   555,   337,   338,   249,   691,   556,   693,   695,
     697,   699,   701,   339,   917,   703,   340,   917,   917,   705,
     711,   712,   713,   714,   707,   709,   716,   557,   917,   917,
     917,   558,   917,   917,   917,   718,   618,   814,   911,   911,
     720,   722,   730,   732,   559,   734,   251,   738,  1144,   837,
    1149,  1569,  1154,   740,  1159,   742,   744,   746,   748,   750,
     752,   754,   756,   478,   758,   341,   760,   762,   764,   766,
     775,   342,   777,   911,   911,   911,   911,   779,   253,   921,
     921,   781,   783,   785,   478,   787,   791,   255,   257,   793,
     795,   806,   808,   810,   812,  1250,  1174,  1176,  1178,   343,
     560,  1252,  1161,  1162,   344,  1280,   259,  1164,  1165,  1194,
    1195,  1196,  1197,   345,   921,   921,   921,   921,   261,   346,
    1332,  1204,  1346,   263,  1347,   347,   265,   267,   269,  1332,
    1333,  1348,  1239,  1349,   911,   348,  1332,   271,   273,  1333,
     561,  1343,   275,  1344,   349,  1388,  1333,   277,   279,   281,
    1352,  1350,  1353,  1351,   283,  1562,   350,  1361,   285,  1362,
    1332,  1161,  1162,   351,   287,   289,  1164,  1165,   291,   293,
    1333,   352,   353,   295,   297,   921,   299,   301,   356,   358,
    1355,  1370,  1356,  1371,   360,   362,   911,   354,   410,   911,
     911,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
     911,   911,   911,   363,   911,   911,   911,  1357,   364,  1358,
    1304,   474,   475,   476,   477,   974,   975,   976,   977,   365,
     979,  1359,   981,  1360,   983,   366,   367,   921,   856,   368,
     921,   921,   369,   929,  1297,   432,   931,   433,  1104,   933,
     562,   921,   921,   921,   563,   921,   921,   921,  1208,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1374,  1384,
    1387,   370,   371,   515,   516,   517,   518,   519,   372,  1582,
    1395,  1397,  1584,  1416,   520,  1299,   432,   521,   433,  1364,
     564,  1365,  1618,  1405,  1223,  1224,  1225,  1226,  1227,  1407,
    1409,  1366,  1417,  1367,   373,   374,  1420,  1422,  1424,  1426,
    1427,  1428,  1429,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1227,   375,   376,  1431,  1433,  1435,  1437,  1439,  1441,
    1443,  1368,  1510,  1369,  1511,  1580,   377,  1581,   378,   379,
     380,  1410,   381,   857,   858,   859,   860,   861,   382,   383,
     384,   385,   866,   867,   868,   386,   387,   388,   389,   390,
     391,   392,   869,   870,   871,   872,   873,   874,   875,   876,
     393,   877,   878,   879,   880,   881,   882,   883,   884,   885,
     886,   394,   887,   395,   396,   397,   398,   399,   889,   890,
     891,   892,   893,   894,   895,   400,   401,   402,   403,   898,
     899,   404,  1505,   405,   900,   901,   902,   903,   904,   905,
     973,   974,   975,   976,   977,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,  1411,   990,   406,   407,
     408,   411,   412,   413,   478,   414,   415,   416,   417,   418,
     419,   420,   421,   423,   424,   425,   515,   516,   517,   518,
     519,   426,   427,   428,   429,   430,   565,   520,   566,   567,
     521,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,  1226,  1227,  1289,  1205,  1206,  1207,  1208,
    1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1399,   568,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,   569,   570,   571,   572,   573,   574,   672,
     673,   674,   843,   675,   773,   799,   800,   844,    -2,   448,
     835,  1574,  1451,   838,   839,   815,   519,  1579,   846,   849,
     850,   851,   -11,   -11,   -13,     2,     3,   -16,   -18,   -20,
     852,   854,   934,   935,   936,   906,   991,   940,   941,   942,
    1108,   943,   955,   962,  1032,  1049,     4,  1058,  1124,     5,
       6,     7,     8,     9,  1059,  1060,  1061,  1062,  1071,  1072,
    1073,  1074,  1127,  1315,  1110,    10,  1113,  1115,  1302,  1131,
     992,  1117,  1240,  1119,   993,  1120,   994,   995,   996,   997,
    1126,   998,   999,  1412,  1413,  1316,  1000,   519,   908,   909,
    1132,  1129,  1130,  1574,  1063,  1002,  1179,   521,  1180,  1253,
    1257,  1505,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,  1266,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,  1267,  1268,  1285,  1286,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,  1287,   171,   172,
    1288,  1311,  1301,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,  1303,  1312,  1313,  1314,  1319,  1321,  1325,
    1336,  1345,  1354,  1363,  1391,   183,   184,   185,  1401,  1398,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  -638,  -639,  -650,  -651,  1400,  1418,  1444,
    1445,  1446,   186,  1447,  1448,  1449,  1480,  1452,  1453,  1454,
     187,  1486,  1558,  1455,  1456,  1457,  1088,   188,  -567,  -567,
    -567,  -567,  -567,  -567,  -567,  -567,  -567,  -567,  -567,  -567,
    1458,  1459,  1460,  1461,  1462,  1463,  1487,  -567,  -567,  -567,
    -567,  -567,  -567,  -567,  -567,  1464,  -567,  -567,  -567,  -567,
    -567,  -567,  -567,  -567,  -567,  -567,  1465,  -567,  1466,  1467,
    1468,  -567,  1469,  -567,  -567,  -567,  -567,  -567,  -567,  -567,
    -567,  1470,  1471,  -567,  -567,  -567,  1472,  1473,  1474,  -567,
    -567,  -567,  -567,  -567,  -567,  1088,  1475,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  1476,
    1477,  1478,  1481,  1482,  1483,  1484,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  1485,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,  1488,  -535,  1495,  1496,  1497,
    -535,  1498,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,
    1499,  1500,  -535,  -535,  -535,  1501,  1502,  1503,  -535,  -535,
    -535,  -535,  -535,  -535,  1170,  1504,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  1104,  1509,
    1513,  1518,  1519,  1520,  1522,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  1523,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  1524,  -539,  1528,  1529,  1534,  -539,
    1537,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  1538,
    1539,  -539,  -539,  -539,  1542,  1543,  1544,  -539,  -539,  -539,
    -539,  -539,  -539,  1547,  1548,  1549,  1552,  1553,  1170,  1554,
    -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,
    -556,  -556,  1555,  1556,  1557,  1559,  1561,  1563,  1564,  -556,
    -556,  -556,  -556,  -556,  -556,  -556,  -556,  1575,  -556,  -556,
    -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  1570,  -556,
    1591,  1592,  1593,  -556,  1594,  -556,  -556,  -556,  -556,  -556,
    -556,  -556,  -556,  1595,  1596,  -556,  -556,  -556,  1597,  1598,
    -567,  -556,  -556,  -556,  -556,  -556,  -556,  1599,  1600,  1601,
    1602,  1603,  1604,  1605,  1606,  1607,  -567,  -567,  -567,  -567,
    -567,  -567,  -567,  -567,  -567,  -567,  -567,  -567,  -567,  -567,
    -567,  -567,  -567,  -567,  -567,  -567,  -567,  -567,  -567,  1608,
    1609,  1610,  1611,  1612,  1613,  -567,  1614,  1615,  1616,  -567,
    1623,  1624,  1625,  -567,  -567,  1638,  -567,  -567,  -567,  -865,
    -567,  1626,  1627,  1630,  1632,  -567,  1635,  1636,  1637,  -535,
    1639,   449,   948,  1386,  1128,   853,  1642,  1643,   855,   665,
    1317,   667,   842,  1389,  1577,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  1390,  1619,
       0,  1508,  1629,     0,     0,     0,     0,     0,  -535,     0,
       0,     0,  -535,  -535,     0,  -535,  -535,  -535,  -865,  -535,
    1634,     0,     0,     0,  -535,     0,     0,     0,  -539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -539,     0,     0,
       0,  -539,  -539,     0,  -539,  -539,  -539,     0,  -539,     0,
       0,     0,     0,  -539,     0,     0,     0,     0,     0,     0,
       0,     0,  -556,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -556,  -556,
    -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,
    -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,  -556,
    -556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -556,     0,     0,     0,  -556,  -556,     1,  -556,  -556,
    -556,     0,  -556,     0,     0,     0,     0,  -556,     0,     0,
     -11,   -11,   -13,     2,     3,   -16,   -18,   -20,  1212,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,     4,     0,     0,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,  1226,  1227,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,  1560,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,     0,   171,   172,     0,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,     0,     0,  1205,  1206,
    1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,     0,     0,     0,     0,     0,     0,   187,     0,
    1633,     0,     0,     0,  1644,   188,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,     0,     0,
       0,     0,     0,     0,     0,   869,   870,   871,   872,   873,
     874,   875,   876,     0,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,     0,   887,     0,     0,     0,   888,
       0,   889,   890,   891,   892,   893,   894,   895,   896,  -599,
    -599,   897,   898,   899,     0,     0,     0,   900,   901,   902,
     903,   904,   905,  1092,     0,   857,   858,   859,   860,   861,
     862,   863,   864,   865,   866,   867,   868,     0,     0,     0,
       0,     0,     0,     0,   869,   870,   871,   872,   873,   874,
     875,   876,     0,   877,   878,   879,   880,   881,   882,   883,
     884,   885,   886,     0,   887,     0,     0,     0,   888,     0,
     889,   890,   891,   892,   893,   894,   895,   896,  -601,  -601,
     897,   898,   899,     0,     0,     0,   900,   901,   902,   903,
     904,   905,  1092,     0,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   867,   868,     0,     0,     0,     0,
       0,     0,     0,   869,   870,   871,   872,   873,   874,   875,
     876,     0,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,     0,   887,     0,     0,     0,   888,     0,   889,
     890,   891,   892,   893,   894,   895,   896,  -603,  -603,   897,
     898,   899,     0,     0,     0,   900,   901,   902,   903,   904,
     905,     0,     0,     0,     0,     0,  1092,     0,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
       0,     0,     0,     0,     0,     0,     0,   869,   870,   871,
     872,   873,   874,   875,   876,     0,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,     0,   887,     0,     0,
       0,   888,     0,   889,   890,   891,   892,   893,   894,   895,
     896,  -597,  -597,   897,   898,   899,     0,     0,   906,   900,
     901,   902,   903,   904,   905,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1210,  1211,
    1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,
    1222,  1223,  1224,  1225,  1226,  1227,     0,   907,     0,     0,
       0,   908,   909,     0,     0,   910,     0,     0,     0,  -599,
       0,     0,     0,     0,     0,     0,     0,   906,  1206,  1207,
    1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,
    1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1225,  1226,  1227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   907,     0,     0,     0,
     908,   909,     0,     0,   910,     0,     0,     0,  -601,     0,
       0,     0,     0,     0,     0,     0,   906,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   907,     0,     0,     0,   908,
     909,     0,     0,   910,     0,     0,     0,  -603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     906,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   907,
       0,     0,     0,   908,   909,     0,     0,   910,     0,     0,
    1092,  -597,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,     0,     0,     0,     0,     0,     0,
       0,   869,   870,   871,   872,   873,   874,   875,   876,     0,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
       0,   887,     0,     0,     0,   888,     0,   889,   890,   891,
     892,   893,   894,   895,   896,  -604,  -604,   897,   898,   899,
       0,     0,     0,   900,   901,   902,   903,   904,   905,  1092,
       0,   857,   858,   859,   860,   861,   862,   863,   864,   865,
     866,   867,   868,     0,     0,     0,     0,     0,     0,     0,
     869,   870,   871,   872,   873,   874,   875,   876,     0,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,     0,
     887,     0,     0,     0,   888,     0,   889,   890,   891,   892,
     893,   894,   895,   896,  -598,  -598,   897,   898,   899,     0,
       0,     0,   900,   901,   902,   903,   904,   905,  1092,     0,
     857,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   868,     0,     0,     0,     0,     0,     0,     0,   869,
     870,   871,   872,   873,   874,   875,   876,     0,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,     0,   887,
       0,     0,     0,   888,     0,   889,   890,   891,   892,   893,
     894,   895,   896,     0,     0,   897,   898,   899,     0,     0,
       0,   900,   901,   902,   903,   904,   905,     0,     0,     0,
       0,     0,  1092,     0,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   867,   868,     0,     0,     0,     0,
       0,     0,     0,   869,   870,   871,   872,   873,   874,   875,
     876,     0,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,     0,   887,     0,     0,     0,   888,     0,   889,
     890,   891,   892,   893,   894,   895,   896,     0,     0,   897,
     898,   899,     0,     0,   906,   900,   901,   902,   903,   904,
     905,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   907,     0,     0,     0,   908,   909,     0,
       0,   910,     0,     0,     0,  -604,     0,     0,     0,     0,
       0,     0,     0,   906,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   907,     0,     0,     0,   908,   909,     0,     0,
     910,     0,     0,     0,  -598,     0,     0,     0,     0,     0,
       0,     0,   906,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   907,     0,     0,     0,   908,   909,     0,     0,   910,
       0,     0,     0,  1093,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   906,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   907,     0,     0,     0,   908,
     909,     0,     0,   910,     0,     0,  1092,  1114,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
       0,     0,     0,     0,     0,     0,     0,   869,   870,   871,
     872,   873,   874,   875,   876,     0,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,     0,   887,     0,     0,
       0,   888,     0,   889,   890,   891,   892,   893,   894,   895,
     896,     0,     0,   897,   898,   899,     0,     0,     0,   900,
     901,   902,   903,   904,   905,  1092,     0,   857,   858,   859,
     860,   861,   862,   863,   864,   865,   866,   867,   868,     0,
       0,     0,     0,     0,     0,     0,   869,   870,   871,   872,
     873,   874,   875,   876,     0,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,     0,   887,     0,     0,     0,
     888,     0,   889,   890,   891,   892,   893,   894,   895,   896,
       0,     0,   897,   898,   899,     0,     0,     0,   900,   901,
     902,   903,   904,   905,  1092,     0,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,     0,     0,
       0,     0,     0,     0,     0,   869,   870,   871,   872,   873,
     874,   875,   876,     0,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,     0,   887,     0,     0,     0,   888,
       0,   889,   890,   891,   892,   893,   894,   895,   896,     0,
       0,   897,   898,   899,     0,     0,     0,   900,   901,   902,
     903,   904,   905,     0,     0,     0,     0,     0,  1092,     0,
     857,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   868,     0,     0,     0,     0,     0,     0,     0,   869,
     870,   871,   872,   873,   874,   875,   876,     0,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,     0,   887,
       0,     0,     0,   888,     0,   889,   890,   891,   892,   893,
     894,   895,   896,     0,     0,   897,   898,   899,     0,     0,
     906,   900,   901,   902,   903,   904,   905,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   907,
       0,     0,     0,   908,   909,     0,     0,   910,     0,     0,
       0,  1116,     0,     0,     0,     0,     0,     0,     0,   906,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   907,     0,
       0,     0,   908,   909,     0,     0,   910,     0,     0,     0,
    1118,     0,     0,     0,     0,     0,     0,     0,   906,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   907,     0,     0,
       0,   908,   909,     0,     0,   910,     0,     0,     0,  1125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   906,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   907,     0,     0,     0,   908,   909,     0,     0,   910,
       0,     0,  1092,  1402,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   867,   868,     0,     0,     0,     0,
       0,     0,     0,   869,   870,   871,   872,   873,   874,   875,
     876,     0,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,     0,   887,     0,     0,     0,   888,     0,   889,
     890,   891,   892,   893,   894,   895,   896,     0,     0,   897,
     898,   899,     0,     0,     0,   900,   901,   902,   903,   904,
     905,  1092,     0,   857,   858,   859,   860,   861,   862,   863,
     864,   865,   866,   867,   868,     0,     0,     0,     0,     0,
       0,     0,   869,   870,   871,   872,   873,   874,   875,   876,
       0,   877,   878,   879,   880,   881,   882,   883,   884,   885,
     886,     0,   887,     0,     0,     0,   888,     0,   889,   890,
     891,   892,   893,   894,   895,   896,     0,     0,   897,   898,
     899,     0,     0,     0,   900,   901,   902,   903,   904,   905,
    1092,     0,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,     0,     0,     0,     0,     0,     0,
       0,   869,   870,   871,   872,   873,   874,   875,   876,     0,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
       0,   887,     0,     0,     0,   888,     0,   889,   890,   891,
     892,   893,   894,   895,   896,     0,     0,   897,   898,   899,
       0,     0,     0,   900,   901,   902,   903,   904,   905,     0,
       0,     0,     0,     0,  1092,     0,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,     0,     0,
       0,     0,     0,     0,     0,   869,   870,   871,   872,   873,
     874,   875,   876,     0,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,     0,   887,     0,     0,     0,   888,
       0,   889,   890,   891,   892,   893,   894,   895,   896,     0,
       0,   897,   898,   899,     0,     0,   906,   900,   901,   902,
     903,   904,   905,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   907,     0,     0,     0,   908,
     909,     0,     0,   910,     0,     0,     0,  1521,     0,     0,
       0,     0,     0,     0,     0,   906,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   907,     0,     0,     0,   908,   909,
       0,     0,   910,     0,     0,     0,  1525,     0,     0,     0,
       0,     0,     0,     0,   906,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   907,     0,     0,     0,   908,   909,     0,
       0,   910,     0,     0,     0,  1565,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   906,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   907,     0,     0,
       0,   908,   909,     0,     0,   910,     0,     0,  1092,  1585,
     857,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   868,     0,     0,     0,     0,     0,     0,     0,   869,
     870,   871,   872,   873,   874,   875,   876,     0,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,     0,   887,
       0,     0,     0,   888,     0,   889,   890,   891,   892,   893,
     894,   895,   896,     0,     0,   897,   898,   899,     0,     0,
       0,   900,   901,   902,   903,   904,   905,  1092,     0,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,     0,     0,     0,     0,     0,     0,     0,   869,   870,
     871,   872,   873,   874,   875,   876,     0,   877,   878,   879,
     880,   881,   882,   883,   884,   885,   886,     0,   887,     0,
       0,     0,   888,     0,   889,   890,   891,   892,   893,   894,
     895,   896,     0,     0,   897,   898,   899,     0,     0,     0,
     900,   901,   902,   903,   904,   905,  1092,     0,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
       0,     0,     0,     0,     0,     0,     0,   869,   870,   871,
     872,   873,   874,   875,   876,     0,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,     0,   887,     0,     0,
       0,   888,     0,   889,   890,   891,   892,   893,   894,   895,
     896,     0,     0,   897,   898,   899,     0,     0,     0,   900,
     901,   902,   903,   904,   905,     0,     0,     0,     0,     0,
    1375,     0,   857,   858,   859,   860,   861,     0,     0,     0,
       0,   866,   867,   868,     0,     0,     0,     0,     0,     0,
       0,   869,   870,   871,   872,   873,   874,   875,   876,     0,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
       0,   887,     0,     0,     0,     0,     0,   889,   890,   891,
     892,   893,   894,   895,     0,     0,     0,     0,   898,   899,
       0,     0,   906,   900,   901,   902,   903,   904,   905,   973,
     974,   975,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   985,   986,   987,   988,   989,   990,  1376,  1377,  1378,
    1379,  1380,  1381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   907,     0,     0,     0,   908,   909,     0,     0,   910,
       0,     0,     0,  1586,     0,     0,     0,     0,     0,     0,
       0,   906,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     907,     0,     0,     0,   908,   909,     0,     0,   910,     0,
       0,     0,  1587,     0,     0,     0,     0,     0,     0,     0,
     906,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   907,
       0,     0,     0,   908,   909,     0,     0,   910,     0,     0,
       0,  1588,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   906,   991,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   992,
    1382,     0,     0,   993,     0,   994,   995,   996,   997,     0,
     998,   999,   482,   907,     0,  1000,     0,   908,   909,     0,
       0,     0,     0,  1063,  1002,  1385,     0,   857,   858,   859,
     860,   861,     0,     0,     0,     0,   866,   867,   868,     0,
       0,     0,     0,     0,     0,     0,   869,   870,   871,   872,
     873,   874,   875,   876,     0,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,     0,   887,     0,     0,     0,
       0,     0,   889,   890,   891,   892,   893,   894,   895,     0,
       0,     0,     0,   898,   899,     0,     0,     0,   900,   901,
     902,   903,   904,   905,   973,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   987,   988,
     989,   990,  1376,  1377,  1378,  1379,  1380,  1381,  1181,     0,
     857,   858,   859,   860,   861,     0,     0,     0,     0,   866,
     867,   868,     0,     0,     0,     0,     0,     0,     0,   869,
     870,   871,   872,   873,   874,   875,   876,     0,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,     0,   887,
       0,     0,     0,     0,     0,   889,   890,   891,   892,   893,
     894,   895,     0,     0,     0,     0,   898,   899,     0,     0,
       0,   900,   901,   902,   903,   904,   905,   973,   974,   975,
     976,   977,   978,   979,   980,   981,   982,   983,   984,   985,
     986,   987,   988,   989,   990,  1181,     0,   857,   858,   859,
     860,   861,     0,     0,     0,     0,   866,   867,   868,     0,
       0,     0,     0,     0,     0,     0,   869,   870,   871,   872,
     873,   874,   875,   876,     0,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,     0,   887,     0,     0,     0,
       0,     0,   889,   890,   891,   892,   893,   894,   895,     0,
       0,     0,     0,   898,   899,     0,     0,     0,   900,   901,
     902,   903,   904,   905,   973,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   987,   988,
     989,   990,     0,     0,     0,     0,     0,     0,     0,   906,
     991,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   992,  1382,     0,     0,   993,     0,
     994,   995,   996,   997,     0,   998,   999,   482,   907,     0,
    1000,     0,   908,   909,     0,     0,     0,     0,  1063,  1002,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   906,   991,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   992,     0,     0,
       0,   993,     0,   994,   995,   996,   997,     0,   998,   999,
     482,   907,     0,  1000,     0,   908,   909,     0,     0,     0,
    1182,  1063,  1002,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   906,
     991,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   992,     0,     0,     0,   993,     0,
     994,   995,   996,   997,     0,   998,   999,   482,   907,     0,
    1000,     0,   908,   909,     0,     0,     0,  1230,  1063,  1002,
    1181,     0,   857,   858,   859,   860,   861,     0,     0,     0,
       0,   866,   867,   868,     0,     0,     0,     0,     0,     0,
       0,   869,   870,   871,   872,   873,   874,   875,   876,     0,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
       0,   887,     0,     0,     0,     0,     0,   889,   890,   891,
     892,   893,   894,   895,     0,     0,     0,     0,   898,   899,
       0,     0,     0,   900,   901,   902,   903,   904,   905,   973,
     974,   975,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   985,   986,   987,   988,   989,   990,  1571,     0,   857,
     858,   859,   860,   861,     0,     0,     0,     0,   866,   867,
     868,     0,     0,     0,     0,     0,     0,     0,   869,   870,
     871,   872,   873,   874,   875,   876,     0,   877,   878,   879,
     880,   881,   882,   883,   884,   885,   886,     0,   887,     0,
       0,     0,     0,     0,   889,   890,   891,   892,   893,   894,
     895,     0,     0,     0,     0,   898,   899,     0,     0,     0,
     900,   901,   902,   903,   904,   905,   973,   974,   975,   976,
     977,   978,   979,   980,   981,   982,   983,   984,   985,   986,
     987,   988,   989,   990,  1075,     0,   857,   858,   859,   860,
     861,     0,     0,     0,     0,   866,   867,   868,     0,     0,
       0,     0,     0,     0,     0,   869,   870,   871,   872,   873,
     874,   875,   876,     0,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,     0,   887,     0,     0,     0,     0,
       0,   889,   890,   891,   892,   893,   894,   895,     0,     0,
       0,     0,   898,   899,     0,     0,     0,   900,   901,   902,
     903,   904,   905,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   906,   991,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   992,
       0,     0,     0,   993,     0,   994,   995,   996,   997,     0,
     998,   999,   482,   907,     0,  1000,     0,   908,   909,     0,
       0,     0,  1231,  1063,  1002,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   906,   991,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   992,     0,  1572,     0,
     993,     0,   994,   995,   996,   997,     0,   998,   999,   482,
     907,     0,  1000,     0,   908,   909,     0,     0,     0,     0,
    1063,  1002,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   906,   991,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   992,     0,     0,     0,   993,     0,   994,
     995,   996,   997,     0,   998,   999,   482,   907,     0,  1000,
       0,   908,   909,     0,     0,     0,     0,  1063,  1002,  1173,
       0,   857,   858,   859,   860,   861,     0,     0,     0,     0,
     866,   867,   868,     0,     0,     0,     0,     0,     0,     0,
     869,   870,   871,   872,   873,   874,   875,   876,     0,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,     0,
     887,     0,     0,     0,     0,     0,   889,   890,   891,   892,
     893,   894,   895,     0,     0,     0,     0,   898,   899,     0,
       0,     0,   900,   901,   902,   903,   904,   905,   973,   974,
     975,   976,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,  1175,     0,   857,   858,
     859,   860,   861,     0,     0,     0,     0,   866,   867,   868,
       0,     0,     0,     0,     0,     0,     0,   869,   870,   871,
     872,   873,   874,   875,   876,     0,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,     0,   887,     0,     0,
       0,     0,     0,   889,   890,   891,   892,   893,   894,   895,
       0,     0,     0,     0,   898,   899,     0,     0,     0,   900,
     901,   902,   903,   904,   905,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   987,
     988,   989,   990,  1177,     0,   857,   858,   859,   860,   861,
       0,     0,     0,     0,   866,   867,   868,     0,     0,     0,
       0,     0,     0,     0,   869,   870,   871,   872,   873,   874,
     875,   876,     0,   877,   878,   879,   880,   881,   882,   883,
     884,   885,   886,     0,   887,     0,     0,     0,     0,     0,
     889,   890,   891,   892,   893,   894,   895,     0,     0,     0,
       0,   898,   899,     0,     0,     0,   900,   901,   902,   903,
     904,   905,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982,   983,   984,   985,   986,   987,   988,   989,   990,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   906,   991,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   992,     0,
       0,     0,   993,     0,   994,   995,   996,   997,     0,   998,
     999,   482,   907,     0,  1000,     0,   908,   909,     0,     0,
       0,     0,  1063,  1002,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     906,   991,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   992,     0,     0,     0,   993,
       0,   994,   995,   996,   997,     0,   998,   999,   482,   907,
       0,  1000,     0,   908,   909,     0,     0,     0,     0,  1063,
    1002,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   906,   991,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   992,     0,     0,     0,   993,     0,   994,   995,
     996,   997,     0,   998,   999,   482,   907,     0,  1000,     0,
     908,   909,     0,     0,     0,     0,  1063,  1002,  1203,     0,
     857,   858,   859,   860,   861,     0,     0,     0,     0,   866,
     867,   868,     0,     0,     0,     0,     0,     0,     0,   869,
     870,   871,   872,   873,   874,   875,   876,     0,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,     0,   887,
       0,     0,     0,     0,     0,   889,   890,   891,   892,   893,
     894,   895,     0,     0,     0,     0,   898,   899,     0,     0,
       0,   900,   901,   902,   903,   904,   905,   973,   974,   975,
     976,   977,   978,   979,   980,   981,   982,   983,   984,   985,
     986,   987,   988,   989,   990,  1237,     0,   857,   858,   859,
     860,   861,     0,     0,     0,     0,   866,   867,   868,     0,
       0,     0,     0,     0,     0,     0,   869,   870,   871,   872,
     873,   874,   875,   876,     0,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,     0,   887,     0,     0,     0,
       0,     0,   889,   890,   891,   892,   893,   894,   895,     0,
       0,     0,     0,   898,   899,     0,     0,     0,   900,   901,
     902,   903,   904,   905,   973,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   987,   988,
     989,   990,  1181,     0,   857,   858,   859,   860,   861,     0,
       0,     0,     0,   866,   867,   868,     0,     0,     0,     0,
       0,     0,     0,   869,   870,   871,   872,   873,   874,   875,
     876,     0,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,     0,   887,     0,     0,     0,     0,     0,   889,
     890,   891,   892,   893,   894,   895,     0,     0,     0,     0,
     898,   899,     0,     0,     0,   900,   901,   902,   903,   904,
     905,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   985,   986,   987,   988,   989,   990,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   906,   991,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   992,     0,     0,
       0,   993,     0,   994,   995,   996,   997,     0,   998,   999,
     482,   907,     0,  1000,     0,   908,   909,     0,     0,     0,
       0,  1063,  1002,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   906,
     991,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   992,     0,     0,     0,   993,     0,
     994,   995,   996,   997,     0,   998,   999,   482,  1238,     0,
    1000,     0,   908,   909,     0,     0,     0,     0,  1063,  1002,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   906,   991,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   992,     0,     0,     0,   993,     0,   994,   995,   996,
     997,     0,   998,   999,   482,   907,     0,  1000,     0,   908,
     909,     0,     0,     0,     0,  1063,  1002,  1372,     0,   857,
     858,   859,   860,   861,     0,     0,     0,     0,   866,   867,
     868,     0,     0,     0,     0,     0,     0,     0,   869,   870,
     871,   872,   873,   874,   875,   876,     0,   877,   878,   879,
     880,   881,   882,   883,   884,   885,   886,     0,   887,     0,
       0,     0,     0,     0,   889,   890,   891,   892,   893,   894,
     895,     0,     0,     0,     0,   898,   899,     0,     0,     0,
     900,   901,   902,   903,   904,   905,   973,   974,   975,   976,
     977,   978,   979,   980,   981,   982,   983,   984,   985,   986,
     987,   988,   989,   990,  1394,     0,   857,   858,   859,   860,
     861,     0,     0,     0,     0,   866,   867,   868,     0,     0,
       0,     0,     0,     0,     0,   869,   870,   871,   872,   873,
     874,   875,   876,     0,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,     0,   887,     0,     0,     0,     0,
       0,   889,   890,   891,   892,   893,   894,   895,     0,     0,
       0,     0,   898,   899,     0,     0,     0,   900,   901,   902,
     903,   904,   905,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,  1396,     0,   857,   858,   859,   860,   861,     0,     0,
       0,     0,   866,   867,   868,     0,     0,     0,     0,     0,
       0,     0,   869,   870,   871,   872,   873,   874,   875,   876,
       0,   877,   878,   879,   880,   881,   882,   883,   884,   885,
     886,     0,   887,     0,     0,     0,     0,     0,   889,   890,
     891,   892,   893,   894,   895,     0,     0,     0,     0,   898,
     899,     0,     0,     0,   900,   901,   902,   903,   904,   905,
     973,   974,   975,   976,   977,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,   989,   990,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   906,   991,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   992,     0,     0,     0,
     993,     0,   994,   995,   996,   997,     0,   998,   999,   482,
    1373,     0,  1000,     0,   908,   909,     0,     0,     0,     0,
    1063,  1002,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   906,   991,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   992,     0,     0,     0,   993,     0,   994,
     995,   996,   997,     0,   998,   999,   482,   907,     0,  1000,
       0,   908,   909,     0,     0,     0,     0,  1063,  1002,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   906,   991,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     992,     0,     0,     0,   993,     0,   994,   995,   996,   997,
       0,   998,   999,   482,   907,     0,  1000,     0,   908,   909,
       0,     0,     0,     0,  1063,  1002,  1403,     0,   857,   858,
     859,   860,   861,     0,     0,     0,     0,   866,   867,   868,
       0,     0,     0,     0,     0,     0,     0,   869,   870,   871,
     872,   873,   874,   875,   876,     0,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,     0,   887,     0,     0,
       0,     0,     0,   889,   890,   891,   892,   893,   894,   895,
       0,     0,     0,     0,   898,   899,     0,     0,     0,   900,
     901,   902,   903,   904,   905,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   987,
     988,  1404,   990,  1406,     0,   857,   858,   859,   860,   861,
       0,     0,     0,     0,   866,   867,   868,     0,     0,     0,
       0,     0,     0,     0,   869,   870,   871,   872,   873,   874,
     875,   876,     0,   877,   878,   879,   880,   881,   882,   883,
     884,   885,   886,     0,   887,     0,     0,     0,     0,     0,
     889,   890,   891,   892,   893,   894,   895,     0,     0,     0,
       0,   898,   899,     0,     0,     0,   900,   901,   902,   903,
     904,   905,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982,   983,   984,   985,   986,   987,   988,   989,   990,
    1408,     0,   857,   858,   859,   860,   861,     0,     0,     0,
       0,   866,   867,   868,     0,     0,     0,     0,     0,     0,
       0,   869,   870,   871,   872,   873,   874,   875,   876,     0,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
       0,   887,     0,     0,     0,     0,     0,   889,   890,   891,
     892,   893,   894,   895,     0,     0,     0,     0,   898,   899,
       0,     0,     0,   900,   901,   902,   903,   904,   905,   973,
     974,   975,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   985,   986,   987,   988,   989,   990,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     906,   991,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   992,     0,     0,     0,   993,
       0,   994,   995,   996,   997,     0,   998,   999,   482,   907,
       0,  1000,     0,   908,   909,     0,     0,     0,     0,  1063,
    1002,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   906,   991,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   992,     0,     0,     0,   993,     0,   994,   995,
     996,   997,     0,   998,   999,   482,   907,     0,  1000,     0,
     908,   909,     0,     0,     0,     0,  1063,  1002,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   906,   991,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   992,
       0,     0,     0,   993,     0,   994,   995,   996,   997,     0,
     998,   999,   482,   907,     0,  1000,     0,   908,   909,     0,
       0,     0,     0,  1063,  1002,  1419,     0,   857,   858,   859,
     860,   861,     0,     0,     0,     0,   866,   867,   868,     0,
       0,     0,     0,     0,     0,     0,   869,   870,   871,   872,
     873,   874,   875,   876,     0,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,     0,   887,     0,     0,     0,
       0,     0,   889,   890,   891,   892,   893,   894,   895,     0,
       0,     0,     0,   898,   899,     0,     0,     0,   900,   901,
     902,   903,   904,   905,   973,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   987,   988,
     989,   990,  1421,     0,   857,   858,   859,   860,   861,     0,
       0,     0,     0,   866,   867,   868,     0,     0,     0,     0,
       0,     0,     0,   869,   870,   871,   872,   873,   874,   875,
     876,     0,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,     0,   887,     0,     0,     0,     0,     0,   889,
     890,   891,   892,   893,   894,   895,     0,     0,     0,     0,
     898,   899,     0,     0,     0,   900,   901,   902,   903,   904,
     905,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   985,   986,   987,   988,   989,   990,  1423,
       0,   857,   858,   859,   860,   861,     0,     0,     0,     0,
     866,   867,   868,     0,     0,     0,     0,     0,     0,     0,
     869,   870,   871,   872,   873,   874,   875,   876,     0,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,     0,
     887,     0,     0,     0,     0,     0,   889,   890,   891,   892,
     893,   894,   895,     0,     0,     0,     0,   898,   899,     0,
       0,     0,   900,   901,   902,   903,   904,   905,   973,   974,
     975,   976,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   906,
     991,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   992,     0,     0,     0,   993,     0,
     994,   995,   996,   997,     0,   998,   999,   482,   907,     0,
    1000,     0,   908,   909,     0,     0,     0,     0,  1063,  1002,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   906,   991,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   992,     0,     0,     0,   993,     0,   994,   995,   996,
     997,     0,   998,   999,   482,   907,     0,  1000,     0,   908,
     909,     0,     0,     0,     0,  1063,  1002,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   906,   991,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   992,     0,
       0,     0,   993,     0,   994,   995,   996,   997,     0,   998,
     999,   482,   907,     0,  1000,     0,   908,   909,     0,     0,
       0,     0,  1063,  1002,  1425,     0,   857,   858,   859,   860,
     861,     0,     0,     0,     0,   866,   867,   868,     0,     0,
       0,     0,     0,     0,     0,   869,   870,   871,   872,   873,
     874,   875,   876,     0,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,     0,   887,     0,     0,     0,     0,
       0,   889,   890,   891,   892,   893,   894,   895,     0,     0,
       0,     0,   898,   899,     0,     0,     0,   900,   901,   902,
     903,   904,   905,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,  1430,     0,   857,   858,   859,   860,   861,     0,     0,
       0,     0,   866,   867,   868,     0,     0,     0,     0,     0,
       0,     0,   869,   870,   871,   872,   873,   874,   875,   876,
       0,   877,   878,   879,   880,   881,   882,   883,   884,   885,
     886,     0,   887,     0,     0,     0,     0,     0,   889,   890,
     891,   892,   893,   894,   895,     0,     0,     0,     0,   898,
     899,     0,     0,     0,   900,   901,   902,   903,   904,   905,
     973,   974,   975,   976,   977,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,   989,   990,  1432,     0,
     857,   858,   859,   860,   861,     0,     0,     0,     0,   866,
     867,   868,     0,     0,     0,     0,     0,     0,     0,   869,
     870,   871,   872,   873,   874,   875,   876,     0,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,     0,   887,
       0,     0,     0,     0,     0,   889,   890,   891,   892,   893,
     894,   895,     0,     0,     0,     0,   898,   899,     0,     0,
       0,   900,   901,   902,   903,   904,   905,   973,   974,   975,
     976,   977,   978,   979,   980,   981,   982,   983,   984,   985,
     986,   987,   988,   989,   990,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   906,   991,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   992,     0,     0,     0,   993,     0,   994,
     995,   996,   997,     0,   998,   999,   482,   907,     0,  1000,
       0,   908,   909,     0,     0,     0,     0,  1063,  1002,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   906,   991,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     992,     0,     0,     0,   993,     0,   994,   995,   996,   997,
       0,   998,   999,   482,   907,     0,  1000,     0,   908,   909,
       0,     0,     0,     0,  1063,  1002,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   906,   991,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   992,     0,     0,
       0,   993,     0,   994,   995,   996,   997,     0,   998,   999,
     482,   907,     0,  1000,     0,   908,   909,     0,     0,     0,
       0,  1063,  1002,  1434,     0,   857,   858,   859,   860,   861,
       0,     0,     0,     0,   866,   867,   868,     0,     0,     0,
       0,     0,     0,     0,   869,   870,   871,   872,   873,   874,
     875,   876,     0,   877,   878,   879,   880,   881,   882,   883,
     884,   885,   886,     0,   887,     0,     0,     0,     0,     0,
     889,   890,   891,   892,   893,   894,   895,     0,     0,     0,
       0,   898,   899,     0,     0,     0,   900,   901,   902,   903,
     904,   905,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982,   983,   984,   985,   986,   987,   988,   989,   990,
    1436,     0,   857,   858,   859,   860,   861,     0,     0,     0,
       0,   866,   867,   868,     0,     0,     0,     0,     0,     0,
       0,   869,   870,   871,   872,   873,   874,   875,   876,     0,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
       0,   887,     0,     0,     0,     0,     0,   889,   890,   891,
     892,   893,   894,   895,     0,     0,     0,     0,   898,   899,
       0,     0,     0,   900,   901,   902,   903,   904,   905,   973,
     974,   975,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   985,   986,   987,   988,   989,   990,  1438,     0,   857,
     858,   859,   860,   861,     0,     0,     0,     0,   866,   867,
     868,     0,     0,     0,     0,     0,     0,     0,   869,   870,
     871,   872,   873,   874,   875,   876,     0,   877,   878,   879,
     880,   881,   882,   883,   884,   885,   886,     0,   887,     0,
       0,     0,     0,     0,   889,   890,   891,   892,   893,   894,
     895,     0,     0,     0,     0,   898,   899,     0,     0,     0,
     900,   901,   902,   903,   904,   905,   973,   974,   975,   976,
     977,   978,   979,   980,   981,   982,   983,   984,   985,   986,
     987,   988,   989,   990,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   906,   991,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   992,     0,     0,     0,   993,     0,   994,   995,
     996,   997,     0,   998,   999,   482,   907,     0,  1000,     0,
     908,   909,     0,     0,     0,     0,  1063,  1002,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   906,   991,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   992,
       0,     0,     0,   993,     0,   994,   995,   996,   997,     0,
     998,   999,   482,   907,     0,  1000,     0,   908,   909,     0,
       0,     0,     0,  1063,  1002,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   906,   991,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   992,     0,     0,     0,
     993,     0,   994,   995,   996,   997,     0,   998,   999,   482,
     907,     0,  1000,     0,   908,   909,     0,     0,     0,     0,
    1063,  1002,  1440,     0,   857,   858,   859,   860,   861,     0,
       0,     0,     0,   866,   867,   868,     0,     0,     0,     0,
       0,     0,     0,   869,   870,   871,   872,   873,   874,   875,
     876,     0,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,     0,   887,     0,     0,     0,     0,     0,   889,
     890,   891,   892,   893,   894,   895,     0,     0,     0,     0,
     898,   899,     0,     0,     0,   900,   901,   902,   903,   904,
     905,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   985,   986,   987,   988,   989,   990,  1442,
       0,   857,   858,   859,   860,   861,     0,     0,     0,     0,
     866,   867,   868,     0,     0,     0,     0,     0,     0,     0,
     869,   870,   871,   872,   873,   874,   875,   876,     0,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,     0,
     887,     0,     0,     0,     0,     0,   889,   890,   891,   892,
     893,   894,   895,     0,     0,     0,     0,   898,   899,     0,
       0,     0,   900,   901,   902,   903,   904,   905,   973,   974,
     975,   976,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,  1628,     0,   857,   858,
     859,   860,   861,     0,     0,     0,     0,   866,   867,   868,
       0,     0,     0,     0,     0,     0,     0,   869,   870,   871,
     872,   873,   874,   875,   876,     0,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,     0,   887,     0,     0,
       0,     0,     0,   889,   890,   891,   892,   893,   894,   895,
       0,     0,     0,     0,   898,   899,     0,     0,     0,   900,
     901,   902,   903,   904,   905,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   987,
     988,   989,   990,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   906,   991,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   992,     0,     0,     0,   993,     0,   994,   995,   996,
     997,     0,   998,   999,   482,   907,     0,  1000,     0,   908,
     909,     0,     0,     0,     0,  1063,  1002,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   906,   991,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   992,     0,
       0,     0,   993,     0,   994,   995,   996,   997,     0,   998,
     999,   482,   907,     0,  1000,     0,   908,   909,     0,     0,
       0,     0,  1063,  1002,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     906,   991,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   992,     0,     0,     0,   993,
       0,   994,   995,   996,   997,     0,   998,   999,   482,   907,
       0,  1000,     0,   908,   909,     0,     0,     0,     0,  1063,
    1002,   857,   858,   859,   860,   861,   862,   863,   864,   865,
     866,   867,   868,     0,     0,     0,     0,     0,     0,     0,
     869,   870,   871,   872,   873,   874,   875,   876,     0,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,     0,
     887,     0,     0,     0,   888,     0,   889,   890,   891,   892,
     893,   894,   895,   896,     0,     0,   897,   898,   899,     0,
       0,     0,   900,   901,   902,   903,   904,   905,   857,   858,
     859,   860,   861,     0,     0,     0,     0,   866,   867,   868,
       0,     0,     0,     0,     0,     0,     0,   869,   870,   871,
     872,   873,   874,   875,   876,     0,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,     0,   887,     0,     0,
       0,     0,     0,   889,   890,   891,   892,   893,   894,   895,
       0,     0,     0,     0,   898,   899,     0,     0,     0,   900,
     901,   902,   903,   904,   905,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   987,
     988,   989,   990,   857,   858,   859,   860,   861,     0,     0,
       0,     0,   866,   867,   868,     0,     0,     0,     0,     0,
       0,     0,   869,   870,   871,   872,   873,   874,   875,   876,
       0,   877,   878,   879,   880,   881,   882,   883,   884,   885,
     886,     0,   887,     0,     0,     0,     0,     0,   889,   890,
     891,   892,   893,   894,   895,     0,     0,     0,     0,   898,
     899,     0,     0,     0,   900,   901,   902,   903,   904,   905,
     973,   974,   975,   976,   977,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,   989,   990,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   906,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   907,     0,     0,     0,   908,   909,     0,     0,
     910,     0,     0,  1274,     0,     0,     0,     0,     0,     0,
     906,   991,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   992,     0,     0,     0,   993,
       0,   994,   995,   996,   997,     0,   998,   999,   482,   907,
       0,  1000,     0,   908,   909,     0,     0,     0,     0,  1001,
    1002,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   906,   991,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     992,     0,     0,     0,   993,     0,   994,   995,   996,   997,
       0,   998,   999,   482,   907,     0,  1000,     0,   908,   909,
       0,     0,     0,     0,  1022,  1002,   857,   858,   859,   860,
     861,     0,     0,     0,     0,   866,   867,   868,     0,     0,
       0,     0,     0,     0,     0,   869,   870,   871,   872,   873,
     874,   875,   876,     0,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,     0,   887,     0,     0,     0,     0,
       0,   889,   890,   891,   892,   893,   894,   895,     0,     0,
       0,     0,   898,   899,     0,     0,     0,   900,   901,   902,
     903,   904,   905,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   857,   858,   859,   860,   861,     0,     0,     0,     0,
     866,   867,   868,     0,     0,     0,     0,     0,     0,     0,
     869,   870,   871,   872,   873,   874,   875,   876,     0,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,     0,
     887,     0,     0,     0,     0,     0,   889,   890,   891,   892,
     893,   894,   895,     0,     0,     0,     0,   898,   899,     0,
       0,     0,   900,   901,   902,   903,   904,   905,   973,   974,
     975,   976,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   857,   858,   859,   860,
     861,     0,     0,     0,     0,   866,   867,   868,     0,     0,
       0,     0,     0,     0,     0,   869,   870,   871,   872,   873,
     874,   875,   876,     0,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,     0,   887,     0,     0,     0,     0,
       0,   889,   890,   891,   892,   893,   894,   895,     0,     0,
       0,     0,   898,   899,     0,     0,     0,   900,   901,   902,
     903,   904,   905,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   906,   991,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   992,     0,     0,     0,   993,     0,   994,
     995,   996,   997,     0,   998,   999,   482,   907,     0,  1000,
       0,   908,   909,     0,     0,     0,     0,  1024,  1002,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   906,   991,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   992,     0,
       0,     0,   993,     0,   994,   995,   996,   997,     0,   998,
     999,   482,   907,     0,  1000,     0,   908,   909,     0,     0,
       0,     0,  1063,  1002,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   906,   991,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   992,     0,     0,     0,   993,     0,   994,
     995,   996,   997,     0,   998,   999,  1578,   907,     0,  1000,
       0,   908,   909,     0,     0,     0,     0,  1063,  1002,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,     0,     0,     0,     0,     0,     0,     0,   869,   870,
     871,   872,   873,   874,   875,   876,     0,   877,   878,   879,
     880,   881,   882,   883,   884,   885,   886,     0,   887,     0,
       0,     0,   888,     0,   889,   890,   891,   892,   893,   894,
     895,   896,     0,     0,   897,   898,   899,     0,     0,     0,
     900,   901,   902,   903,   904,   905,  1189,     0,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
       0,     0,     0,     0,     0,     0,     0,   869,   870,   871,
     872,   873,   874,   875,   876,     0,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,     0,   887,     0,     0,
       0,   888,     0,   889,   890,   891,   892,   893,   894,   895,
     896,     0,     0,   897,   898,   899,     0,     0,     0,   900,
     901,   902,   903,   904,   905,   857,   858,   859,   860,   861,
     862,   863,   864,   865,   866,   867,   868,     0,     0,     0,
       0,     0,     0,     0,   869,   870,   871,   872,   873,   874,
     875,   876,     0,   877,   878,   879,   880,   881,   882,   883,
     884,   885,   886,     0,   887,     0,     0,     0,   888,     0,
     889,   890,   891,   892,   893,   894,   895,   896,     0,     0,
     897,   898,   899,     0,     0,     0,   900,   901,   902,   903,
     904,   905,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   906,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     907,     0,     0,     0,   908,   909,     0,     0,   910,     0,
       0,  1274,     0,     0,     0,     0,     0,     0,     0,     0,
     906,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   907,
       0,     0,     0,   908,   909,     0,     0,   910,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   906,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   907,     0,     0,     0,
     908,   909,     0,     0,   910
};

static const yytype_int16 yycheck[] =
{
     213,   182,   212,   216,   819,   391,   821,  1129,  1077,   824,
       1,     1,   827,     1,   230,  1012,     1,     1,   964,     1,
     966,   836,   968,   985,   970,   987,   972,   989,   241,     1,
     243,     1,   245,     1,   247,   819,     1,   821,     1,     1,
     824,     1,     1,   827,  1006,   912,     1,    56,    57,     1,
     310,     1,   836,    57,     1,     1,   323,    62,     1,   326,
     320,   928,     1,   930,    62,   932,   320,     1,     1,     1,
     937,     1,     1,     1,     1,     1,     1,     1,  1004,   324,
     310,   326,  1008,   337,     1,     1,    56,    57,     1,   302,
       1,     1,     1,   323,     1,   290,     1,   912,   311,   312,
     313,   314,   315,   316,   317,     1,     1,     1,     1,     1,
       1,     1,     1,   928,     1,   930,   331,   932,   333,   290,
       1,     1,   937,     1,   290,     1,   311,    61,   912,  1001,
       1,   344,   345,   346,   520,    19,     1,     1,   323,     1,
       1,   290,     1,     1,   928,   310,   930,     1,   932,   290,
    1022,   821,  1024,   937,   824,   310,   290,   827,   323,    88,
      89,    90,    91,     1,     1,   290,   836,   310,   323,     1,
     331,   326,   333,   338,   290,     1,   819,   320,   821,   290,
       1,   824,   310,     1,   827,     1,  1001,  1002,     1,   290,
       1,  1063,     1,   836,     1,   323,     1,  1064,   326,     1,
       1,   323,   324,   325,   326,   327,     1,  1022,   290,  1024,
    1077,     1,   425,   426,   310,   337,     1,  1001,  1002,     1,
       1,    14,    15,     1,   320,   847,   848,     1,     1,    88,
      89,    90,    91,     1,     1,   331,   290,   333,  1022,   290,
    1024,     1,   331,     1,   333,     1,     1,   290,  1063,  1064,
       1,   262,   263,   264,     1,  1201,   819,   290,   821,     1,
      61,   824,  1077,   290,   827,     1,     1,   290,   290,   912,
       1,     1,   290,   836,     1,     1,     1,   290,     1,  1063,
    1064,     1,     1,     1,     1,   928,   320,   930,    61,   932,
     290,     1,     1,  1077,   937,     1,     1,  1112,     1,     1,
       1,     1,    16,     1,     1,    61,    21,     1,     1,   525,
    1307,  1126,   331,     1,   333,   290,     1,  1132,   323,   323,
     324,     1,     0,  1190,     1,   323,    61,   336,  1112,   290,
     290,     1,  1002,     1,   290,   323,   324,    88,    89,    90,
      91,   323,  1126,   327,   335,   327,   337,   337,  1132,   912,
     335,   290,   337,   337,     1,   337,   324,     1,  1001,  1002,
       1,     1,   290,   335,  1486,   928,   336,   930,     1,   932,
     335,   334,   337,   335,   937,  1190,   335,    20,   337,  1022,
     335,  1024,   311,   335,   334,   337,   333,   334,   334,   323,
     324,   334,   326,   327,   323,   324,   325,   326,   327,   333,
     326,   334,   334,   337,   334,   334,  1190,   334,   337,   334,
     334,  1480,   323,   324,   325,   326,   327,   334,   334,   332,
    1063,  1064,     1,     1,   334,   334,   337,   334,   819,   334,
     821,   326,   324,   824,  1077,   324,   827,   326,   334,  1002,
     334,   334,  1404,   334,   334,   836,   324,   334,   326,  1411,
       1,  1318,   311,   334,   334,     1,  1126,  1324,   334,  1274,
     846,   326,  1132,   334,   323,   324,   325,   326,   327,   819,
     334,   821,   334,   334,   824,   334,   334,   827,   337,   290,
     334,   290,     1,  1126,     1,   323,   836,   324,   326,  1132,
    1274,   323,   324,   325,   326,   327,  1311,  1312,  1313,  1314,
     326,  1064,   323,  1318,  1626,   337,   324,   275,   326,  1324,
     326,   324,   333,   326,  1077,   326,   323,   326,   323,   326,
     310,   912,   323,   324,   326,   326,   327,  1311,  1312,  1313,
    1314,   326,     1,   323,  1318,   290,   337,   928,   323,   930,
    1324,   932,   324,   333,   326,   326,   937,  1190,   326,  1112,
     323,   324,   326,   326,   327,   941,     1,   324,   326,   326,
     311,   329,   912,  1126,   337,   323,   326,   323,   324,  1132,
     326,   327,   323,   324,   325,   326,   327,   324,   928,   326,
     930,   337,   932,     1,   326,     1,   337,   937,   323,   324,
     326,   326,   327,   324,   324,   326,   326,   324,     1,   326,
     326,   326,   337,   326,  1274,    62,   326,   326,   326,   326,
     290,  1002,  1479,  1480,     1,  1561,   326,   326,   311,     1,
     326,   326,     1,   326,   326,   326,   326,  1190,   326,   326,
     323,  1274,   326,   310,   815,   323,   324,   325,   323,   324,
     325,  1311,  1312,  1313,  1314,     1,   323,  1514,  1515,  1516,
    1517,  1001,  1002,   323,     1,   323,     1,     1,     1,     1,
       1,     1,   290,   310,  1479,  1480,   310,     1,  1311,  1312,
    1313,  1314,  1022,  1064,  1024,  1318,   323,   310,   290,   323,
    1066,  1324,   323,   323,  1070,     1,  1077,     1,     1,     1,
     323,   290,   290,     1,     1,  1479,  1480,     1,     1,  1514,
    1515,  1516,  1517,     1,     1,     1,     1,     1,     1,     1,
       1,  1274,     1,  1063,  1064,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,    62,   290,  1077,     1,     1,
    1514,  1515,  1516,  1517,     1,  1126,     1,     1,     1,     1,
       1,  1132,   290,     1,   323,   323,     1,     1,  1311,  1312,
    1313,  1314,     1,     1,     1,  1318,    62,   290,   290,   310,
    1575,  1324,   290,     1,  1631,   311,     1,   290,     1,     1,
       1,     1,   323,     1,  1641,     1,  1126,   323,  1645,  1646,
    1647,     1,  1132,     1,     1,     1,     1,     1,     1,     1,
       1,  1575,     1,   310,     1,     1,     1,     1,     1,  1190,
       1,   335,   290,     1,   323,     1,   323,     1,   290,     1,
       1,     1,  1627,     1,     1,  1630,  1631,     1,     1,     1,
       1,     1,     1,     1,     1,   290,  1641,  1642,  1643,     1,
    1645,  1646,  1647,     1,   326,  1048,  1479,  1480,   290,     1,
    1190,   310,   331,  1627,   333,   323,  1630,  1631,     1,     1,
     290,   290,  1062,     1,   323,     1,   290,  1641,  1642,  1643,
    1070,  1645,  1646,  1647,   290,   310,   323,     1,   311,   312,
     313,  1514,  1515,  1516,  1517,   331,   290,   333,   323,     1,
     298,   299,   300,  1274,     1,   303,   304,     1,     1,     1,
      88,    89,    90,    91,   310,   298,   299,   300,     1,     1,
     303,   304,  1083,     1,  1085,  1575,  1087,   323,     1,     1,
       1,    88,    89,    90,    91,     1,  1479,  1480,  1131,     1,
    1311,  1312,  1313,  1314,  1274,     1,     1,  1318,   310,     1,
       1,   310,  1575,  1324,     1,     1,   323,     1,     1,     1,
       1,   323,   298,   299,   323,     1,     1,   303,   304,     1,
     323,  1514,  1515,  1516,  1517,   323,   324,  1627,   326,   290,
    1630,  1311,  1312,  1313,  1314,   310,   310,   310,  1318,   310,
     290,   290,  1642,  1643,  1324,   290,   323,   323,   323,   323,
     323,   323,   323,   323,  1627,   290,   323,  1630,  1631,   323,
     298,   299,   300,   323,   323,   303,   304,   323,  1641,  1642,
    1643,   323,  1645,  1646,  1647,   323,   290,   323,   331,   323,
     323,   323,  1575,   862,   863,   864,   323,   323,   335,   323,
     323,   323,   324,   323,   326,   323,   323,   323,   323,   323,
     323,   323,   323,   290,   323,   290,   323,   323,   323,   888,
     323,   323,   323,   323,   323,   323,   323,   896,   897,   290,
     323,   323,   323,   290,   290,   290,   323,   323,   323,   323,
     323,   323,   323,   290,  1627,   323,   290,  1630,  1631,   323,
     218,   219,   220,   221,   323,   323,   323,   323,  1641,  1642,
    1643,   323,  1645,  1646,  1647,   323,   326,   340,  1479,  1480,
     323,   323,   323,   323,   323,   323,   290,   323,   966,   338,
     968,  1487,   970,   323,   972,   323,   323,   323,   323,   323,
     323,   323,   323,   311,   323,   290,   323,   323,   323,   323,
     323,   290,   323,  1514,  1515,  1516,  1517,   323,   290,  1479,
    1480,   323,   323,   323,   311,   323,   323,   290,   290,   323,
     323,   323,   323,   323,   323,   323,   995,   996,   997,   290,
     323,   323,   298,   299,   290,   323,   290,   303,   304,   305,
     306,   307,   308,   290,  1514,  1515,  1516,  1517,   290,   290,
     310,  1020,   331,   290,   333,   290,   290,   290,   290,   310,
     320,   331,  1031,   333,  1575,   290,   310,   290,   290,   320,
     323,   331,   290,   333,   290,     1,   320,   290,   290,   290,
     331,   331,   333,   333,   290,  1418,   290,   331,   290,   333,
     310,   298,   299,   290,   290,   290,   303,   304,   290,   290,
     320,   290,   290,   290,   290,  1575,   290,   290,   290,   290,
     331,   331,   333,   333,   290,   290,  1627,   290,   290,  1630,
    1631,   277,   278,   279,   280,   281,   282,   283,   284,   285,
    1641,  1642,  1643,   290,  1645,  1646,  1647,   331,   290,   333,
    1109,    88,    89,    90,    91,    71,    72,    73,    74,   290,
      76,   331,    78,   333,    80,   290,   290,  1627,   817,   290,
    1630,  1631,   290,   822,   323,   324,   825,   326,   324,   828,
     323,  1641,  1642,  1643,   323,  1645,  1646,  1647,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,  1167,  1168,
    1169,   290,   290,   323,   324,   325,   326,   327,   290,  1510,
    1179,  1180,  1513,  1201,   334,   323,   324,   337,   326,   331,
     323,   333,  1555,  1192,   309,   310,   311,   312,   313,  1198,
    1199,   331,  1201,   333,   290,   290,  1205,  1206,  1207,  1208,
    1209,  1210,  1211,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   290,   290,  1223,  1224,  1225,  1226,  1227,  1228,
    1229,   331,   331,   333,   333,   331,   290,   333,   290,   290,
     290,     1,   290,     3,     4,     5,     6,     7,   290,   290,
     290,   290,    12,    13,    14,   290,   290,   290,   290,   290,
     290,   290,    22,    23,    24,    25,    26,    27,    28,    29,
     290,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,   290,    42,   290,   290,   290,   290,   290,    48,    49,
      50,    51,    52,    53,    54,   290,   290,   290,   290,    59,
      60,   290,  1301,   290,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,   290,   290,
     290,   290,   290,   290,   311,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   323,   324,   325,   326,
     327,   290,   290,   290,   290,   290,   323,   334,   323,   323,
     337,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   335,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   333,   323,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   340,   323,   323,   323,   323,   340,     0,     1,
     323,  1490,   333,   323,   320,   331,   327,  1496,   108,   331,
     290,   290,    14,    15,    16,    17,    18,    19,    20,    21,
     290,   323,   330,   290,   338,   275,   276,   323,   331,   333,
     290,   338,   326,   338,   334,   334,    38,   334,   320,    41,
      42,    43,    44,    45,   334,   334,   334,   334,   334,   334,
     334,   334,   320,   259,   332,    57,   332,   338,   320,   331,
     310,   338,   326,   338,   314,   338,   316,   317,   318,   319,
     335,   321,   322,   323,   324,   259,   326,   327,   328,   329,
     335,   340,   340,  1572,   334,   335,   334,   337,   334,   333,
     333,  1580,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   333,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   333,   333,   333,   333,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   333,   260,   261,
     333,   335,   334,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   337,   335,   335,   335,   323,   323,   333,
     333,   333,   333,   333,   324,   287,   288,   289,   336,   333,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   290,   290,   290,   290,   333,   337,   333,
     331,   333,   324,   333,   331,   333,    47,   333,   333,   333,
     332,   340,   333,   333,   333,   333,     1,   339,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     333,   333,   333,   333,   333,   333,   340,    22,    23,    24,
      25,    26,    27,    28,    29,   333,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   333,    42,   333,   333,
     333,    46,   333,    48,    49,    50,    51,    52,    53,    54,
      55,   333,   333,    58,    59,    60,   333,   333,   333,    64,
      65,    66,    67,    68,    69,     1,   333,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   333,
     333,   333,   333,   333,   333,   333,    22,    23,    24,    25,
      26,    27,    28,    29,   333,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   333,    42,   333,   331,   333,
      46,   333,    48,    49,    50,    51,    52,    53,    54,    55,
     333,   333,    58,    59,    60,   333,   333,   333,    64,    65,
      66,    67,    68,    69,     1,   333,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   324,   338,
     331,   326,   326,   290,   320,    22,    23,    24,    25,    26,
      27,    28,    29,   333,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,   333,    42,   323,   323,   323,    46,
     323,    48,    49,    50,    51,    52,    53,    54,    55,   323,
     323,    58,    59,    60,   323,   323,   323,    64,    65,    66,
      67,    68,    69,   323,   323,   323,   323,   323,     1,   323,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,   337,   320,   333,   333,   312,   326,   326,    22,
      23,    24,    25,    26,    27,    28,    29,   340,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,   336,    42,
     323,   333,   333,    46,   333,    48,    49,    50,    51,    52,
      53,    54,    55,   333,   333,    58,    59,    60,   333,   333,
     275,    64,    65,    66,    67,    68,    69,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   333,
     333,   333,   333,   333,   333,   320,   333,   333,   333,   324,
     338,   333,   333,   328,   329,   338,   331,   332,   333,   334,
     335,   340,   340,   340,   333,   340,   333,   333,   333,   275,
     338,   190,   844,  1169,   941,   813,   340,   340,   815,   351,
    1124,   352,   521,  1171,  1494,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,  1171,  1556,
      -1,  1302,  1572,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,    -1,   328,   329,    -1,   331,   332,   333,   334,   335,
    1580,    -1,    -1,    -1,   340,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,   328,   329,    -1,   331,   332,   333,    -1,   335,    -1,
      -1,    -1,    -1,   340,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   324,    -1,    -1,    -1,   328,   329,     1,   331,   332,
     333,    -1,   335,    -1,    -1,    -1,    -1,   340,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,    38,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   333,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,    -1,    -1,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,   289,    -1,    -1,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,
     333,    -1,    -1,    -1,     1,   339,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,   275,    64,
      65,    66,    67,    68,    69,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,    -1,   324,    -1,    -1,
      -1,   328,   329,    -1,    -1,   332,    -1,    -1,    -1,   336,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,
     328,   329,    -1,    -1,   332,    -1,    -1,    -1,   336,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,   328,
     329,    -1,    -1,   332,    -1,    -1,    -1,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,    -1,    -1,   328,   329,    -1,    -1,   332,    -1,    -1,
       1,   336,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    -1,    -1,   275,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   324,    -1,    -1,    -1,   328,   329,    -1,
      -1,   332,    -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,    -1,   328,   329,    -1,    -1,
     332,    -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   324,    -1,    -1,    -1,   328,   329,    -1,    -1,   332,
      -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,   328,
     329,    -1,    -1,   332,    -1,    -1,     1,   336,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
     275,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,    -1,    -1,   328,   329,    -1,    -1,   332,    -1,    -1,
      -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,    -1,   328,   329,    -1,    -1,   332,    -1,    -1,    -1,
     336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,   328,   329,    -1,    -1,   332,    -1,    -1,    -1,   336,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   324,    -1,    -1,    -1,   328,   329,    -1,    -1,   332,
      -1,    -1,     1,   336,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,   275,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,   328,
     329,    -1,    -1,   332,    -1,    -1,    -1,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,   328,   329,
      -1,    -1,   332,    -1,    -1,    -1,   336,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   324,    -1,    -1,    -1,   328,   329,    -1,
      -1,   332,    -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,   328,   329,    -1,    -1,   332,    -1,    -1,     1,   336,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,   275,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   324,    -1,    -1,    -1,   328,   329,    -1,    -1,   332,
      -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,    -1,    -1,    -1,   328,   329,    -1,    -1,   332,    -1,
      -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,    -1,    -1,   328,   329,    -1,    -1,   332,    -1,    -1,
      -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   276,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,    -1,    -1,   314,    -1,   316,   317,   318,   319,    -1,
     321,   322,   323,   324,    -1,   326,    -1,   328,   329,    -1,
      -1,    -1,    -1,   334,   335,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,    -1,    -1,   314,    -1,
     316,   317,   318,   319,    -1,   321,   322,   323,   324,    -1,
     326,    -1,   328,   329,    -1,    -1,    -1,    -1,   334,   335,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   276,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,
      -1,   314,    -1,   316,   317,   318,   319,    -1,   321,   322,
     323,   324,    -1,   326,    -1,   328,   329,    -1,    -1,    -1,
     333,   334,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,   314,    -1,
     316,   317,   318,   319,    -1,   321,   322,   323,   324,    -1,
     326,    -1,   328,   329,    -1,    -1,    -1,   333,   334,   335,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   276,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
      -1,    -1,    -1,   314,    -1,   316,   317,   318,   319,    -1,
     321,   322,   323,   324,    -1,   326,    -1,   328,   329,    -1,
      -1,    -1,   333,   334,   335,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,   312,    -1,
     314,    -1,   316,   317,   318,   319,    -1,   321,   322,   323,
     324,    -1,   326,    -1,   328,   329,    -1,    -1,    -1,    -1,
     334,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,    -1,    -1,    -1,   314,    -1,   316,
     317,   318,   319,    -1,   321,   322,   323,   324,    -1,   326,
      -1,   328,   329,    -1,    -1,    -1,    -1,   334,   335,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   276,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,
      -1,    -1,   314,    -1,   316,   317,   318,   319,    -1,   321,
     322,   323,   324,    -1,   326,    -1,   328,   329,    -1,    -1,
      -1,    -1,   334,   335,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,   314,
      -1,   316,   317,   318,   319,    -1,   321,   322,   323,   324,
      -1,   326,    -1,   328,   329,    -1,    -1,    -1,    -1,   334,
     335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   310,    -1,    -1,    -1,   314,    -1,   316,   317,
     318,   319,    -1,   321,   322,   323,   324,    -1,   326,    -1,
     328,   329,    -1,    -1,    -1,    -1,   334,   335,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   276,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,
      -1,   314,    -1,   316,   317,   318,   319,    -1,   321,   322,
     323,   324,    -1,   326,    -1,   328,   329,    -1,    -1,    -1,
      -1,   334,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,   314,    -1,
     316,   317,   318,   319,    -1,   321,   322,   323,   324,    -1,
     326,    -1,   328,   329,    -1,    -1,    -1,    -1,   334,   335,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,   276,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,    -1,    -1,    -1,   314,    -1,   316,   317,   318,
     319,    -1,   321,   322,   323,   324,    -1,   326,    -1,   328,
     329,    -1,    -1,    -1,    -1,   334,   335,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,
     314,    -1,   316,   317,   318,   319,    -1,   321,   322,   323,
     324,    -1,   326,    -1,   328,   329,    -1,    -1,    -1,    -1,
     334,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,    -1,    -1,    -1,   314,    -1,   316,
     317,   318,   319,    -1,   321,   322,   323,   324,    -1,   326,
      -1,   328,   329,    -1,    -1,    -1,    -1,   334,   335,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   276,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     310,    -1,    -1,    -1,   314,    -1,   316,   317,   318,   319,
      -1,   321,   322,   323,   324,    -1,   326,    -1,   328,   329,
      -1,    -1,    -1,    -1,   334,   335,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,   314,
      -1,   316,   317,   318,   319,    -1,   321,   322,   323,   324,
      -1,   326,    -1,   328,   329,    -1,    -1,    -1,    -1,   334,
     335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   310,    -1,    -1,    -1,   314,    -1,   316,   317,
     318,   319,    -1,   321,   322,   323,   324,    -1,   326,    -1,
     328,   329,    -1,    -1,    -1,    -1,   334,   335,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   276,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
      -1,    -1,    -1,   314,    -1,   316,   317,   318,   319,    -1,
     321,   322,   323,   324,    -1,   326,    -1,   328,   329,    -1,
      -1,    -1,    -1,   334,   335,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,   314,    -1,
     316,   317,   318,   319,    -1,   321,   322,   323,   324,    -1,
     326,    -1,   328,   329,    -1,    -1,    -1,    -1,   334,   335,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,   276,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,    -1,    -1,    -1,   314,    -1,   316,   317,   318,
     319,    -1,   321,   322,   323,   324,    -1,   326,    -1,   328,
     329,    -1,    -1,    -1,    -1,   334,   335,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   276,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,
      -1,    -1,   314,    -1,   316,   317,   318,   319,    -1,   321,
     322,   323,   324,    -1,   326,    -1,   328,   329,    -1,    -1,
      -1,    -1,   334,   335,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,    -1,    -1,    -1,   314,    -1,   316,
     317,   318,   319,    -1,   321,   322,   323,   324,    -1,   326,
      -1,   328,   329,    -1,    -1,    -1,    -1,   334,   335,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   276,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     310,    -1,    -1,    -1,   314,    -1,   316,   317,   318,   319,
      -1,   321,   322,   323,   324,    -1,   326,    -1,   328,   329,
      -1,    -1,    -1,    -1,   334,   335,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   276,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,
      -1,   314,    -1,   316,   317,   318,   319,    -1,   321,   322,
     323,   324,    -1,   326,    -1,   328,   329,    -1,    -1,    -1,
      -1,   334,   335,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   310,    -1,    -1,    -1,   314,    -1,   316,   317,
     318,   319,    -1,   321,   322,   323,   324,    -1,   326,    -1,
     328,   329,    -1,    -1,    -1,    -1,   334,   335,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   276,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
      -1,    -1,    -1,   314,    -1,   316,   317,   318,   319,    -1,
     321,   322,   323,   324,    -1,   326,    -1,   328,   329,    -1,
      -1,    -1,    -1,   334,   335,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,
     314,    -1,   316,   317,   318,   319,    -1,   321,   322,   323,
     324,    -1,   326,    -1,   328,   329,    -1,    -1,    -1,    -1,
     334,   335,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,   276,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,    -1,    -1,    -1,   314,    -1,   316,   317,   318,
     319,    -1,   321,   322,   323,   324,    -1,   326,    -1,   328,
     329,    -1,    -1,    -1,    -1,   334,   335,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   276,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,
      -1,    -1,   314,    -1,   316,   317,   318,   319,    -1,   321,
     322,   323,   324,    -1,   326,    -1,   328,   329,    -1,    -1,
      -1,    -1,   334,   335,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,   314,
      -1,   316,   317,   318,   319,    -1,   321,   322,   323,   324,
      -1,   326,    -1,   328,   329,    -1,    -1,    -1,    -1,   334,
     335,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,    -1,   328,   329,    -1,    -1,
     332,    -1,    -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,   314,
      -1,   316,   317,   318,   319,    -1,   321,   322,   323,   324,
      -1,   326,    -1,   328,   329,    -1,    -1,    -1,    -1,   334,
     335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   276,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     310,    -1,    -1,    -1,   314,    -1,   316,   317,   318,   319,
      -1,   321,   322,   323,   324,    -1,   326,    -1,   328,   329,
      -1,    -1,    -1,    -1,   334,   335,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,    -1,    -1,    -1,   314,    -1,   316,
     317,   318,   319,    -1,   321,   322,   323,   324,    -1,   326,
      -1,   328,   329,    -1,    -1,    -1,    -1,   334,   335,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   276,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,
      -1,    -1,   314,    -1,   316,   317,   318,   319,    -1,   321,
     322,   323,   324,    -1,   326,    -1,   328,   329,    -1,    -1,
      -1,    -1,   334,   335,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,    -1,    -1,    -1,   314,    -1,   316,
     317,   318,   319,    -1,   321,   322,   323,   324,    -1,   326,
      -1,   328,   329,    -1,    -1,    -1,    -1,   334,   335,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,    -1,    -1,    -1,   328,   329,    -1,    -1,   332,    -1,
      -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,    -1,    -1,   328,   329,    -1,    -1,   332,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,
     328,   329,    -1,    -1,   332
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    17,    18,    38,    41,    42,    43,    44,    45,
      57,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   260,   261,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   287,   288,   289,   324,   332,   339,   342,
     343,   344,   345,   346,   347,   348,   349,   360,   364,   367,
     368,   370,   371,   380,   381,   387,   290,     1,   337,     1,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,     1,   290,     1,   290,     1,   290,
       1,   290,     1,   290,     1,   290,     1,   290,     1,   290,
       1,   290,     1,   290,     1,   290,     1,   290,     1,   290,
       1,   290,     1,   290,     1,   290,     1,   290,     1,   290,
       1,   290,     1,   290,     1,   290,     1,   290,     1,   290,
       1,   290,     1,   290,     1,   290,     1,   290,     1,   290,
       1,   290,     1,   290,     1,   290,     1,   290,     1,   290,
       1,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,     1,   326,     1,   290,   326,     1,   334,
       1,   290,   326,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,     1,   290,     1,   290,     1,
     290,     1,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,     1,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   320,   290,   290,   290,   290,   290,   290,   290,
     290,     1,   324,   326,   361,   362,   363,     1,   363,   365,
     366,     1,   326,     1,   326,     1,   326,     0,     1,   344,
      14,    15,   377,   378,    16,   379,    19,   384,    20,   385,
      21,   386,   320,   337,   335,   323,   324,   326,   376,     1,
     323,     1,   323,     1,    88,    89,    90,    91,   311,   353,
       1,   310,   323,   359,     1,   323,     1,   323,     1,   359,
       1,   323,     1,   323,     1,   323,     1,   323,     1,   324,
       1,   326,     1,   323,     1,   326,     1,   323,     1,   326,
       1,   326,     1,   326,     1,   323,   324,   325,   326,   327,
     334,   337,   350,   352,   353,   357,   358,   372,   373,   374,
     375,   401,   402,     1,   358,     1,   323,     1,   323,     1,
     323,   323,   323,   323,   359,   359,   359,   359,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,     1,   359,     1,   323,   326,
       1,   323,     1,   323,     1,   323,     1,   323,     1,   323,
       1,   323,     1,   359,     1,   359,     1,   359,     1,   359,
       1,   359,     1,   359,     1,   359,     1,   323,     1,   323,
       1,   326,     1,   326,     1,   323,     1,   326,   326,     1,
     326,     1,   323,     1,   323,     1,   324,   326,     1,   324,
     326,     1,   324,   326,     1,   324,   326,     1,   324,   326,
       1,   323,     1,   323,     1,   323,     1,   323,     1,   359,
       1,   359,     1,   359,     1,   324,   326,     1,   323,     1,
     323,     1,   323,     1,   323,   373,     1,   375,     1,   323,
       1,   323,   323,   323,   323,   323,     1,   323,     1,   323,
       1,   323,     1,   323,     1,   323,     1,   323,     1,   323,
       1,   323,     1,   323,     1,   323,     1,   323,     1,   323,
       1,   323,     1,   323,     1,   323,     1,   323,     1,   323,
       1,   218,   219,   220,   221,     1,   323,     1,   323,     1,
     323,     1,   323,     1,   326,     1,   326,     1,   326,     1,
     323,     1,   323,     1,   323,     1,   350,     1,   323,     1,
     323,     1,   323,     1,   323,     1,   323,     1,   323,     1,
     323,     1,   323,     1,   323,     1,   323,     1,   323,     1,
     323,     1,   323,     1,   323,     1,   323,     1,   324,   326,
       1,   323,   324,   323,     1,   323,     1,   323,     1,   323,
       1,   323,     1,   323,     1,   323,     1,   323,     1,   326,
       1,   323,     1,   323,     1,   323,   262,   263,   264,   323,
     323,     1,   359,     1,   359,     1,   323,     1,   323,     1,
     323,     1,   323,   331,   340,   331,     1,   337,     1,   335,
       1,   335,   337,     1,   335,   337,     1,   335,   337,     1,
     337,    57,   323,   324,   369,   323,   382,   338,   323,   320,
     350,   351,   374,   340,   340,   358,   108,   310,   320,   331,
     290,   290,   290,   361,   323,   365,   376,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    22,
      23,    24,    25,    26,    27,    28,    29,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    42,    46,    48,
      49,    50,    51,    52,    53,    54,    55,    58,    59,    60,
      64,    65,    66,    67,    68,    69,   275,   324,   328,   329,
     332,   403,   405,   406,   407,   411,   412,   420,   421,   423,
     424,   427,   428,   430,   434,   435,   436,   440,   405,   376,
     405,   376,   405,   376,   330,   290,   338,   405,     1,   383,
     323,   331,   333,   338,     1,   311,   323,   355,   352,   350,
       1,   323,   401,     1,   401,   326,     1,   326,     1,   326,
       1,   326,   338,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   334,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   276,   310,   314,   316,   317,   318,   319,   321,   322,
     326,   334,   335,   359,   393,   394,   395,   396,   397,   398,
     403,   415,   420,   421,   422,   423,   425,   427,   428,   431,
     432,   433,   334,   433,   334,   433,     1,   334,     1,   334,
       1,   334,   334,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   334,     1,   334,     1,   334,     1,   334,   334,
       1,   334,     1,   334,     1,   334,     1,   334,   334,   334,
     334,   334,   334,   334,   433,     1,   334,     1,   334,     1,
     334,   334,   334,   334,   334,     1,   433,   433,     1,   334,
       1,   334,     1,   334,     1,   334,     1,   334,     1,   437,
       1,   332,     1,   336,   406,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   324,   417,   418,   419,   290,   429,
     332,     1,   334,   332,   336,   338,   336,   338,   336,   338,
     338,     1,   323,   326,   320,   336,   335,   320,   351,   340,
     340,   331,   335,     1,    61,   324,   326,   333,   372,   400,
       1,    61,   326,   372,   400,     1,    61,   326,   372,   400,
       1,    61,   326,   372,   400,     1,    61,   326,   372,   400,
       1,   298,   299,   300,   303,   304,   388,   390,   388,   388,
       1,   388,   416,     1,   433,     1,   433,     1,   433,   334,
     334,     1,   333,   421,   423,   427,   428,   433,   434,     1,
     405,     1,   390,     1,   305,   306,   307,   308,   388,   389,
       1,   390,   419,     1,   433,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   391,   392,
     333,   333,     1,   323,   326,     1,   326,     1,   324,   433,
     326,     1,   326,     1,   326,     1,   326,     1,   326,     1,
     323,     1,   323,   333,     1,   333,   359,   333,     1,   326,
       1,   326,     1,   326,     1,   326,   333,   333,   333,     1,
     323,   333,     1,   353,   335,   404,   406,     1,   350,     1,
     323,     1,   350,   353,   356,   333,   333,   333,   333,   335,
     404,     1,   326,     1,   326,   323,   363,   323,   363,   323,
     363,   334,   320,   337,   433,     1,   326,   420,   421,   426,
     428,   335,   335,   335,   335,   259,   259,   369,   405,   323,
     355,   323,   326,   359,   405,   333,   331,   333,   331,   333,
     331,   333,   310,   320,   331,   333,   333,   331,   333,   331,
     333,   331,   333,   331,   333,   333,   331,   333,   331,   333,
     331,   333,   331,   333,   333,   331,   333,   331,   333,   331,
     333,   331,   333,   333,   331,   333,   331,   333,   331,   333,
     331,   333,     1,   324,   433,     1,    88,    89,    90,    91,
      92,    93,   311,   354,   433,     1,   354,   433,     1,   393,
     397,   324,   413,   414,     1,   433,     1,   433,   333,   333,
     333,   336,   336,     1,    86,   433,     1,   433,     1,   433,
       1,    86,   323,   324,   372,   399,   400,   433,   337,     1,
     433,     1,   433,     1,   433,     1,   433,   433,   433,   433,
       1,   433,     1,   433,     1,   433,     1,   433,     1,   433,
       1,   433,     1,   433,   333,   331,   333,   333,   331,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   405,
      47,   333,   333,   333,   333,   333,   340,   340,   333,     1,
      56,    57,   336,   409,   410,   333,   331,   333,   333,   333,
     333,   333,   333,   333,   333,   433,   438,   439,   418,   338,
     331,   333,   419,   331,   405,   405,   405,   405,   326,   326,
     290,   336,   320,   333,   333,   336,    62,   323,   323,   323,
       1,   324,     1,   324,   323,    62,   323,   323,   323,   323,
      62,   323,   323,   323,   323,    62,   323,   323,   323,   323,
      62,   323,   323,   323,   323,   337,   320,   333,   333,   333,
     333,   312,   359,   326,   326,   336,   404,     1,   355,   350,
     336,     1,   312,   408,   433,   340,   336,   409,   323,   433,
     331,   333,   363,     1,   363,   336,   336,   336,   336,   323,
     326,   323,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   326,   359,   413,
       1,   323,   372,   338,   333,   333,   340,   340,     1,   408,
     340,   405,   333,   333,   439,   333,   333,   333,   338,   338,
     355,   405,   340,   340,     1,   405,   405,   405
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   341,   342,   343,   343,   343,   344,   344,   344,   344,
     344,   345,   344,   346,   344,   344,   347,   344,   348,   344,
     349,   344,   344,   344,   350,   350,   350,   351,   351,   352,
     352,   353,   353,   353,   353,   353,   354,   354,   354,   354,
     354,   354,   354,   355,   355,   356,   356,   356,   356,   356,
     357,   357,   357,   357,   357,   358,   358,   359,   359,   360,
     360,   361,   361,   362,   362,   363,   363,   364,   364,   365,
     365,   366,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   368,   368,   369,   369,   369,   370,   370,   370,   370,
     370,   370,   370,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   372,   372,   373,   374,
     375,   375,   376,   376,   376,   377,   377,   378,   378,   378,
     378,   379,   379,   379,   380,   380,   382,   381,   381,   381,
     383,   381,   381,   384,   384,   384,   385,   385,   385,   386,
     386,   387,   387,   387,   387,   387,   387,   388,   388,   388,
     388,   389,   389,   389,   389,   390,   390,   391,   391,   391,
     391,   391,   391,   391,   392,   392,   392,   392,   393,   393,
     393,   394,   394,   394,   395,   395,   395,   395,   395,   396,
     396,   397,   397,   397,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   399,   399,   399,   399,   400,   400,   400,
     400,   400,   401,   401,   401,   402,   402,   402,   402,   402,
     403,   404,   404,   405,   405,   405,   406,   406,   406,   406,
     406,   406,   406,   406,   407,   407,   408,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   410,   410,
     411,   411,   411,   411,   412,   413,   413,   413,   414,   414,
     416,   415,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   418,   419,   419,   420,   421,   422,   423,   424,   424,
     425,   425,   425,   426,   426,   426,   427,   428,   429,   430,
     430,   430,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   432,   432,   432,   433,   433,   433,
     433,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   433,   433,   433,   433,   433,   434,   435,   435,   435,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   437,   436,   436,   438,   438,
     438,   439,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     0,     2,     0,     2,     1,     0,     2,     0,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     5,     3,
       1,     3,     3,     5,     3,     1,     2,     1,     2,     2,
       2,     1,     3,     1,     3,     1,     1,     2,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     7,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     5,     5,
       5,     5,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     1,     1,     1,     1,     1,     5,     5,     7,     7,
       5,     8,     8,     2,     2,     2,     2,     3,     3,     8,
       8,     2,     2,     2,     3,     3,     1,     1,     7,     1,
       1,     3,     1,     1,     1,     1,     1,     4,     7,     2,
       2,     4,     7,     2,     1,     1,     0,     5,     2,     2,
       0,     8,     5,     4,     7,     2,     4,     7,     2,     7,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     1,     3,     2,     1,     2,     2,     1,     1,     1,
       2,     2,     1,     2,     3,     5,     1,     4,     5,     3,
       4,     3,     2,     4,     5,     3,     4,     4,     2,     1,
       5,     4,     2,     5,     3,     1,     4,     4,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     5,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     2,     3,     1,     1,     1,
       3,     4,     4,     4,     6,     6,     6,     6,     6,     4,
       2,     4,     4,     4,     4,     6,     6,     6,     6,     6,
       4,     2,     4,     4,     4,     4,     6,     6,     6,     6,
       6,     4,     2,     4,     4,     4,     4,     6,     6,     6,
       6,     6,     4,     2,     4,     4,     4,     4,     6,     6,
       6,     6,     6,     4,     2,     4,     4,     6,     2,     4,
       4,     4,     2,     4,     4,     2,     4,     4,     2,     6,
       6,     6,     4,     2,     6,     2,     4,     4,     4,     2,
       4,     4,     4,     2,     4,     4,     2,     4,     4,     2,
       4,     4,     2,     4,     3,     2,     4,     3,     2,     4,
       3,     4,     2,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     4,     4,     2,     4,     4,     2,     4,     3,
       1,     3,     1,     3,     1,     4,     3,     1,     4,     4,
       4,     4,     4,     2,     4,     4,     2,     4,     4,     2,
       3,     1,     3,     1,     3,     1,     3,     1,     6,     6,
       2,     4,     4,     2,     4,     0,     5,     2,     0,     3,
       1,     1,     3,     2,     1,     3,     2,     1,     1,     3,
       2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 621 "core/cfg.y" /* yacc.c:1646  */
    {}
#line 5075 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 622 "core/cfg.y" /* yacc.c:1646  */
    {}
#line 5081 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 623 "core/cfg.y" /* yacc.c:1646  */
    { yyerror(""); YYABORT;}
#line 5087 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 631 "core/cfg.y" /* yacc.c:1646  */
    {rt=REQUEST_ROUTE;}
#line 5093 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 632 "core/cfg.y" /* yacc.c:1646  */
    {rt=FAILURE_ROUTE;}
#line 5099 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 634 "core/cfg.y" /* yacc.c:1646  */
    {rt=BRANCH_ROUTE;}
#line 5105 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 635 "core/cfg.y" /* yacc.c:1646  */
    {rt=ONSEND_ROUTE;}
#line 5111 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 636 "core/cfg.y" /* yacc.c:1646  */
    {rt=EVENT_ROUTE;}
#line 5117 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 641 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].ipaddr)){
			tmp=ip_addr2a((yyvsp[0].ipaddr));
			if (tmp==0) {
				LM_CRIT("cfg. parser: bad ip address.\n");
				(yyval.strval)=0;
			} else {
				(yyval.strval)=pkg_malloc(strlen(tmp)+1);
				if ((yyval.strval)==0) {
					LM_CRIT("cfg. parser: out of memory.\n");
				} else {
					strncpy((yyval.strval), tmp, strlen(tmp)+1);
				}
			}
		}
	}
#line 5138 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 657 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
		if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: out of memory.\n");
		} else {
				strncpy((yyval.strval), (yyvsp[0].strval), strlen((yyvsp[0].strval))+1);
		}
	}
#line 5151 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 665 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].strval)){
			(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
					LM_CRIT("cfg. parser: out of memory.\n");
			} else {
					strncpy((yyval.strval), (yyvsp[0].strval), strlen((yyvsp[0].strval))+1);
			}
		}
	}
#line 5166 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 679 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.name_l)=mk_name_lst((yyvsp[0].strval), SI_IS_MHOMED); }
#line 5172 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 680 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.name_l)=mk_name_lst((yyvsp[-2].strval), SI_IS_MHOMED);
										if ((yyval.name_l)) (yyval.name_l)->next=(yyvsp[0].name_l);
									}
#line 5180 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 686 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.name_l)=(yyvsp[-1].name_l); }
#line 5186 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 687 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.name_l)=mk_name_lst((yyvsp[0].strval), 0); }
#line 5192 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 691 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_UDP; }
#line 5198 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 692 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_TCP; }
#line 5204 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 693 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_TLS; }
#line 5210 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 694 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_SCTP; }
#line 5216 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 695 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=0; }
#line 5222 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 698 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_UDP; }
#line 5228 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 699 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_TCP; }
#line 5234 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 700 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_TLS; }
#line 5240 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 701 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_SCTP; }
#line 5246 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 702 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_WS; }
#line 5252 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 703 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=PROTO_WSS; }
#line 5258 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 704 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=0; }
#line 5264 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 707 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=(yyvsp[0].intval); }
#line 5270 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 708 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=0; }
#line 5276 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 711 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id((yyvsp[0].strval), 0, 0); }
#line 5282 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 712 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id((yyvsp[-2].strval), 0, (yyvsp[0].intval)); }
#line 5288 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 713 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id((yyvsp[0].strval), (yyvsp[-2].intval), 0); }
#line 5294 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 714 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id((yyvsp[-2].strval), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 5300 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 715 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=0; yyerror("port number expected"); }
#line 5306 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 719 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id2((yyvsp[0].name_l), 0, 0); }
#line 5312 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 720 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id2((yyvsp[-2].name_l), 0, (yyvsp[0].intval)); }
#line 5318 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 721 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id2((yyvsp[0].name_l), (yyvsp[-2].intval), 0); }
#line 5324 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 722 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=mk_listen_id2((yyvsp[-2].name_l), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 5330 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 723 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=0; yyerror("port number expected"); }
#line 5336 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 727 "core/cfg.y" /* yacc.c:1646  */
    {  (yyval.sockid)=(yyvsp[0].sockid) ; }
#line 5342 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 728 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.sockid)=(yyvsp[-1].sockid);  if ((yyval.sockid)) (yyval.sockid)->next=(yyvsp[0].sockid); }
#line 5348 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 732 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=-(yyvsp[0].intval); }
#line 5354 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 736 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("flag list expected\n"); }
#line 5360 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 742 "core/cfg.y" /* yacc.c:1646  */
    { if (register_flag((yyvsp[0].strval),-1)<0)
								yyerror("register flag failed");
						}
#line 5368 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 745 "core/cfg.y" /* yacc.c:1646  */
    {
						if (register_flag((yyvsp[-2].strval), (yyvsp[0].intval))<0)
								yyerror("register flag failed");
										}
#line 5377 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 751 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[0].strval); }
#line 5383 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 752 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[0].strval); }
#line 5389 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 757 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("avpflag list expected\n"); }
#line 5395 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 764 "core/cfg.y" /* yacc.c:1646  */
    {
		if (register_avpflag((yyvsp[0].strval))==0)
			yyerror("cannot declare avpflag");
	}
#line 5404 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 770 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.debug=(yyvsp[0].intval); }
#line 5410 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 771 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 5416 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 772 "core/cfg.y" /* yacc.c:1646  */
    { dont_fork= ! (yyvsp[0].intval); }
#line 5422 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 773 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5428 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 774 "core/cfg.y" /* yacc.c:1646  */
    { set_fork_delay((yyvsp[0].intval)); }
#line 5434 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 775 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5440 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 776 "core/cfg.y" /* yacc.c:1646  */
    { set_modinit_delay((yyvsp[0].intval)); }
#line 5446 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 777 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5452 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 778 "core/cfg.y" /* yacc.c:1646  */
    { if (!config_check)  /* if set from cmd line, don't overwrite from yyparse()*/
					if(log_stderr == 0) log_stderr=(yyvsp[0].intval);
				   }
#line 5460 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 781 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5466 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 782 "core/cfg.y" /* yacc.c:1646  */
    {
		if ( (i_tmp=str2facility((yyvsp[0].strval)))==-1)
			yyerror("bad facility (see syslog(3) man page)");
		if (!config_check)
			default_core_cfg.log_facility=i_tmp;
	}
#line 5477 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 788 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("ID expected"); }
#line 5483 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 789 "core/cfg.y" /* yacc.c:1646  */
    { log_name=(yyvsp[0].strval); }
#line 5489 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 790 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5495 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 791 "core/cfg.y" /* yacc.c:1646  */
    { log_color=(yyvsp[0].intval); }
#line 5501 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 792 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5507 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 793 "core/cfg.y" /* yacc.c:1646  */
    { log_prefix_fmt=(yyvsp[0].strval); }
#line 5513 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 794 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5519 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 795 "core/cfg.y" /* yacc.c:1646  */
    { log_prefix_mode=(yyvsp[0].intval); }
#line 5525 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 796 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5531 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 797 "core/cfg.y" /* yacc.c:1646  */
    { _km_log_engine_type=(yyvsp[0].strval); }
#line 5537 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 798 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5543 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 799 "core/cfg.y" /* yacc.c:1646  */
    { _km_log_engine_data=(yyvsp[0].strval); }
#line 5549 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 800 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5555 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 801 "core/cfg.y" /* yacc.c:1646  */
    { _ksr_xavp_via_params.s=(yyvsp[0].strval);
			_ksr_xavp_via_params.len=strlen((yyvsp[0].strval));
		}
#line 5563 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 804 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 5569 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 805 "core/cfg.y" /* yacc.c:1646  */
    { received_dns|= ((yyvsp[0].intval))?DO_DNS:0; }
#line 5575 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 806 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5581 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 807 "core/cfg.y" /* yacc.c:1646  */
    { received_dns|= ((yyvsp[0].intval))?DO_REV_DNS:0; }
#line 5587 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 808 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5593 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 809 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_try_ipv6=(yyvsp[0].intval); }
#line 5599 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 810 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5605 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 811 "core/cfg.y" /* yacc.c:1646  */
    { IF_NAPTR(default_core_cfg.dns_try_naptr=(yyvsp[0].intval)); }
#line 5611 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 812 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5617 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 813 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_FAILOVER(default_core_cfg.dns_srv_lb=(yyvsp[0].intval)); }
#line 5623 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 814 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5629 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 815 "core/cfg.y" /* yacc.c:1646  */
    { IF_NAPTR(default_core_cfg.dns_udp_pref=(yyvsp[0].intval));}
#line 5635 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 816 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5641 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 817 "core/cfg.y" /* yacc.c:1646  */
    { IF_NAPTR(default_core_cfg.dns_tcp_pref=(yyvsp[0].intval));}
#line 5647 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 818 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5653 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 819 "core/cfg.y" /* yacc.c:1646  */
    { IF_NAPTR(default_core_cfg.dns_tls_pref=(yyvsp[0].intval));}
#line 5659 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 820 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5665 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 821 "core/cfg.y" /* yacc.c:1646  */
    {
								IF_NAPTR(default_core_cfg.dns_sctp_pref=(yyvsp[0].intval)); }
#line 5672 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 823 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5678 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 824 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_retr_time=(yyvsp[0].intval); }
#line 5684 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 825 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5690 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 826 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_retr_no=(yyvsp[0].intval); }
#line 5696 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 827 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5702 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 828 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_servers_no=(yyvsp[0].intval); }
#line 5708 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 829 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 5714 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 830 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_search_list=(yyvsp[0].intval); }
#line 5720 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 831 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5726 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 832 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_search_fmatch=(yyvsp[0].intval); }
#line 5732 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 833 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5738 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 834 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.dns_naptr_ignore_rfc=(yyvsp[0].intval); }
#line 5744 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 835 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5750 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 836 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(dns_cache_init=(yyvsp[0].intval)); }
#line 5756 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 837 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5762 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 838 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.use_dns_cache=(yyvsp[0].intval)); }
#line 5768 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 839 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5774 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 840 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_FAILOVER(default_core_cfg.use_dns_failover=(yyvsp[0].intval));}
#line 5780 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 841 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5786 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 842 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_flags=(yyvsp[0].intval)); }
#line 5792 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 843 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5798 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 844 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_neg_cache_ttl=(yyvsp[0].intval)); }
#line 5804 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 845 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5810 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 846 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_max_ttl=(yyvsp[0].intval)); }
#line 5816 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 847 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5822 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 848 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_min_ttl=(yyvsp[0].intval)); }
#line 5828 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 849 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5834 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 850 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_max_mem=(yyvsp[0].intval)); }
#line 5840 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 851 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5846 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 852 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(dns_timer_interval=(yyvsp[0].intval)); }
#line 5852 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 853 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5858 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 854 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_del_nonexp=(yyvsp[0].intval)); }
#line 5864 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 855 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5870 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 856 "core/cfg.y" /* yacc.c:1646  */
    { IF_DNS_CACHE(default_core_cfg.dns_cache_rec_pref=(yyvsp[0].intval)); }
#line 5876 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 857 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5882 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 858 "core/cfg.y" /* yacc.c:1646  */
    {IF_AUTO_BIND_IPV6(auto_bind_ipv6 = (yyvsp[0].intval));}
#line 5888 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 859 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5894 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 860 "core/cfg.y" /* yacc.c:1646  */
    { IF_DST_BLACKLIST(dst_blacklist_init=(yyvsp[0].intval)); }
#line 5900 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 861 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5906 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 862 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.use_dst_blacklist=(yyvsp[0].intval));
	}
#line 5914 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 865 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5920 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 866 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_max_mem=(yyvsp[0].intval));
	}
#line 5928 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 869 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5934 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 870 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_timeout=(yyvsp[0].intval));
	}
#line 5942 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 873 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5948 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 874 "core/cfg.y" /* yacc.c:1646  */
    { IF_DST_BLACKLIST(blst_timer_interval=(yyvsp[0].intval));}
#line 5954 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 875 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 5960 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 876 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_udp_imask=(yyvsp[0].intval));
	}
#line 5968 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 879 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number(flags) expected"); }
#line 5974 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 880 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_tcp_imask=(yyvsp[0].intval));
	}
#line 5982 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 883 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number(flags) expected"); }
#line 5988 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 884 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_tls_imask=(yyvsp[0].intval));
	}
#line 5996 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 887 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number(flags) expected"); }
#line 6002 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 888 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_sctp_imask=(yyvsp[0].intval));
	}
#line 6010 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 891 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number(flags) expected"); }
#line 6016 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 892 "core/cfg.y" /* yacc.c:1646  */
    { _sr_ip_free_bind=(yyvsp[0].intval); }
#line 6022 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 893 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6028 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 894 "core/cfg.y" /* yacc.c:1646  */
    { port_no=(yyvsp[0].intval); }
#line 6034 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 895 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef STATS
				stat_file=(yyvsp[0].strval);
		#endif
	}
#line 6044 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 900 "core/cfg.y" /* yacc.c:1646  */
    { maxbuffer=(yyvsp[0].intval); }
#line 6050 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 901 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6056 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 902 "core/cfg.y" /* yacc.c:1646  */
    { sql_buffer_size=(yyvsp[0].intval); }
#line 6062 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 903 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6068 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 904 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6074 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 905 "core/cfg.y" /* yacc.c:1646  */
    { children_no=(yyvsp[0].intval); }
#line 6080 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 906 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6086 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 907 "core/cfg.y" /* yacc.c:1646  */
    { socket_workers=(yyvsp[0].intval); }
#line 6092 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 908 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6098 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 909 "core/cfg.y" /* yacc.c:1646  */
    { async_task_set_workers((yyvsp[0].intval)); }
#line 6104 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 910 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6110 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 911 "core/cfg.y" /* yacc.c:1646  */
    { async_task_set_usleep((yyvsp[0].intval)); }
#line 6116 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 912 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6122 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 913 "core/cfg.y" /* yacc.c:1646  */
    { check_via=(yyvsp[0].intval); }
#line 6128 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 914 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6134 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 915 "core/cfg.y" /* yacc.c:1646  */
    { phone2tel=(yyvsp[0].intval); }
#line 6140 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 916 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6146 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 917 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.memlog=(yyvsp[0].intval); }
#line 6152 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 918 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6158 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 919 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.memdbg=(yyvsp[0].intval); }
#line 6164 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 920 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6170 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 921 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.mem_summary=(yyvsp[0].intval); }
#line 6176 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 922 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6182 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 923 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.mem_safety=(yyvsp[0].intval); }
#line 6188 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 924 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6194 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 925 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.mem_join=(yyvsp[0].intval); }
#line 6200 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 926 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6206 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 927 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.mem_status_mode=(yyvsp[0].intval); }
#line 6212 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 928 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6218 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 929 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.corelog=(yyvsp[0].intval); }
#line 6224 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 930 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 6230 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 931 "core/cfg.y" /* yacc.c:1646  */
    { sip_warning=(yyvsp[0].intval); }
#line 6236 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 932 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6242 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 933 "core/cfg.y" /* yacc.c:1646  */
    { version_table.s=(yyvsp[0].strval);
			version_table.len=strlen(version_table.s);
	}
#line 6250 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 936 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6256 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 937 "core/cfg.y" /* yacc.c:1646  */
    {
		if (shm_initialized())
			yyerror("user must be before any modparam or the"
					" route blocks");
		else if (user==0)
			user=(yyvsp[0].strval);
	}
#line 6268 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 944 "core/cfg.y" /* yacc.c:1646  */
    {
		if (shm_initialized())
			yyerror("user must be before any modparam or the"
					" route blocks");
		else if (user==0)
			user=(yyvsp[0].strval);
	}
#line 6280 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 951 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6286 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 952 "core/cfg.y" /* yacc.c:1646  */
    { group=(yyvsp[0].strval); }
#line 6292 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 953 "core/cfg.y" /* yacc.c:1646  */
    { group=(yyvsp[0].strval); }
#line 6298 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 954 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6304 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 955 "core/cfg.y" /* yacc.c:1646  */
    { chroot_dir=(yyvsp[0].strval); }
#line 6310 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 956 "core/cfg.y" /* yacc.c:1646  */
    { chroot_dir=(yyvsp[0].strval); }
#line 6316 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 957 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6322 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 958 "core/cfg.y" /* yacc.c:1646  */
    { working_dir=(yyvsp[0].strval); }
#line 6328 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 959 "core/cfg.y" /* yacc.c:1646  */
    { working_dir=(yyvsp[0].strval); }
#line 6334 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 960 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6340 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 961 "core/cfg.y" /* yacc.c:1646  */
    { runtime_dir=(yyvsp[0].strval); }
#line 6346 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 962 "core/cfg.y" /* yacc.c:1646  */
    { runtime_dir=(yyvsp[0].strval); }
#line 6352 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 963 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 6358 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 964 "core/cfg.y" /* yacc.c:1646  */
    { mhomed=(yyvsp[0].intval); }
#line 6364 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 965 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6370 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 966 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_disable=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6382 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 973 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6388 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 974 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.accept_aliases=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6400 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 981 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6406 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 982 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_cfg_children_no=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6418 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 989 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6424 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 990 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.connect_timeout_s=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6436 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 997 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6442 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 998 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.send_timeout=S_TO_TICKS((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6454 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1005 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6460 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1006 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			if ((yyvsp[0].intval)<0)
				tcp_default_cfg.con_lifetime=-1;
			else
				tcp_default_cfg.con_lifetime=S_TO_TICKS((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6475 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1016 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6481 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1017 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_poll_method=get_poll_type((yyvsp[0].strval));
			if (tcp_poll_method==POLL_NONE) {
				LOG(L_CRIT, "bad poll method name:"
						" %s\n, try one of %s.\n",
						(yyvsp[0].strval), poll_support);
				yyerror("bad tcp_poll_method "
						"value");
			}
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6500 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1031 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_poll_method=get_poll_type((yyvsp[0].strval));
			if (tcp_poll_method==POLL_NONE) {
				LOG(L_CRIT, "bad poll method name:"
						" %s\n, try one of %s.\n",
						(yyvsp[0].strval), poll_support);
				yyerror("bad tcp_poll_method "
						"value");
			}
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6519 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1045 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("poll method name expected"); }
#line 6525 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1046 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_max_connections=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6537 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1053 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6543 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1054 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			tls_max_connections=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 6555 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1061 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6561 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1062 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.no_connect=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6573 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1069 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6579 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1070 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			if (tcp_set_src_addr((yyvsp[0].ipaddr))<0)
				warn("tcp_source_ipv4 failed");
		#else
			warn("tcp support not compiled in");
		#endif
		pkg_free((yyvsp[0].ipaddr));
	}
#line 6593 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1079 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("IPv4 address expected"); }
#line 6599 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1080 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
				if (tcp_set_src_addr((yyvsp[0].ipaddr))<0)
					warn("tcp_source_ipv6 failed");
		#else
			warn("tcp support not compiled in");
		#endif
		pkg_free((yyvsp[0].ipaddr));
	}
#line 6613 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1089 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("IPv6 address expected"); }
#line 6619 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1090 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.fd_cache=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6631 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1097 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6637 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1098 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.async=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6649 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1105 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6655 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1106 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.tcpconn_wq_max=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6667 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1113 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6673 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1114 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.tcp_wq_max=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6685 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1121 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6691 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1122 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.rd_buf_size=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6703 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1129 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6709 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1130 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.wq_blk_size=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6721 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1137 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6727 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1138 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.defer_accept=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6739 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1145 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6745 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1146 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.delayed_ack=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6757 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1153 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6763 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1154 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.syncnt=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6775 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1161 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6781 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1162 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.linger2=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6793 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1169 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6799 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1170 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepalive=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6811 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1177 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected");}
#line 6817 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1178 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepidle=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6829 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1185 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6835 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1186 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepintvl=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6847 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1193 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6853 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1194 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepcnt=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6865 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1201 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6871 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1202 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.crlf_ping=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6883 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1209 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6889 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1210 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_default_cfg.accept_no_cl=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6901 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1217 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6907 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1218 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			ksr_tcp_accept_hep3=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6919 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1225 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6925 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1227 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			tcp_set_clone_rcvbuf((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6937 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1234 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 6943 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1235 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
		#ifdef SO_REUSEPORT
			tcp_default_cfg.reuse_port=(yyvsp[0].intval);
		#else
			warn("support for SO_REUSEPORT not compiled in");
		#endif
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6959 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1246 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6965 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1247 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			tls_disable=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 6977 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1254 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 6983 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1255 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			tls_disable=!((yyvsp[0].intval));
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 6995 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1262 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7001 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1263 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_log=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7013 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1270 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 7019 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1271 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			tls_port_no=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7031 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1278 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7037 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1279 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv23;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7049 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1286 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv2;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7061 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1293 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv3;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7073 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1300 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_TLSv1;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7085 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1307 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected");
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7097 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1314 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_verify_cert=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7109 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1321 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7115 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1322 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_require_cert=(yyvsp[0].intval);
		#else
			warn( "tls-in-core support not compiled in");
		#endif
	}
#line 7127 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1329 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7133 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1330 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_cert_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7145 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1337 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7151 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1338 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_pkey_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7163 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1345 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7169 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1346 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_ca_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7181 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1353 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7187 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1354 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_handshake_timeout=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7199 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1361 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7205 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1362 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef CORE_TLS
			tls_send_timeout=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7217 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1369 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7223 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1370 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			sctp_disable=(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7235 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1377 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7241 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1378 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			sctp_disable=((yyvsp[0].intval)<=1)?!(yyvsp[0].intval):(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7253 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1385 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean or number expected"); }
#line 7259 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1386 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			sctp_children_no=(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7271 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1393 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7277 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1394 "core/cfg.y" /* yacc.c:1646  */
    { server_signature=(yyvsp[0].intval); }
#line 7283 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1395 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7289 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1396 "core/cfg.y" /* yacc.c:1646  */
    { server_hdr.s=(yyvsp[0].strval);
			server_hdr.len=strlen(server_hdr.s);
	}
#line 7297 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1399 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7303 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1400 "core/cfg.y" /* yacc.c:1646  */
    { user_agent_hdr.s=(yyvsp[0].strval);
			user_agent_hdr.len=strlen(user_agent_hdr.s);
	}
#line 7311 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1403 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string value expected"); }
#line 7317 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1404 "core/cfg.y" /* yacc.c:1646  */
    { reply_to_via=(yyvsp[0].intval); }
#line 7323 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1405 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7329 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1406 "core/cfg.y" /* yacc.c:1646  */
    {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 7346 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1418 "core/cfg.y" /* yacc.c:1646  */
    {
		for(lst_tmp=(yyvsp[-4].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									(yyvsp[-2].strval), (yyvsp[0].intval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-4].sockid));
	}
#line 7364 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1431 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("ip address, interface name or"
									" hostname expected"); }
#line 7371 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1433 "core/cfg.y" /* yacc.c:1646  */
    {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next){
			add_alias(	lst_tmp->addr_lst->name,
						strlen(lst_tmp->addr_lst->name),
						lst_tmp->port, lst_tmp->proto);
			for (nl_tmp=lst_tmp->addr_lst->next; nl_tmp; nl_tmp=nl_tmp->next)
				add_alias(nl_tmp->name, strlen(nl_tmp->name),
							lst_tmp->port, lst_tmp->proto);
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 7387 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1444 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("hostname expected"); }
#line 7393 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1445 "core/cfg.y" /* yacc.c:1646  */
    { sr_auto_aliases=(yyvsp[0].intval); }
#line 7399 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1446 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7405 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1447 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].strval)){
			default_global_address.s=(yyvsp[0].strval);
			default_global_address.len=strlen((yyvsp[0].strval));
		}
	}
#line 7416 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1453 "core/cfg.y" /* yacc.c:1646  */
    {yyerror("ip address or hostname expected"); }
#line 7422 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1454 "core/cfg.y" /* yacc.c:1646  */
    {
		tmp=int2str((yyvsp[0].intval), &i_tmp);
		if ((default_global_port.s=pkg_malloc(i_tmp))==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
			default_global_port.len=0;
		} else {
			default_global_port.len=i_tmp;
			memcpy(default_global_port.s, tmp, default_global_port.len);
		};
	}
#line 7437 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1464 "core/cfg.y" /* yacc.c:1646  */
    {yyerror("ip address or hostname expected"); }
#line 7443 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1465 "core/cfg.y" /* yacc.c:1646  */
    { disable_core_dump=(yyvsp[0].intval); }
#line 7449 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1466 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7455 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1467 "core/cfg.y" /* yacc.c:1646  */
    { open_files_limit=(yyvsp[0].intval); }
#line 7461 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1468 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7467 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1469 "core/cfg.y" /* yacc.c:1646  */
    {
		if (shm_initialized())
			yyerror("shm/shm_mem_size must be before any modparam or the"
					" route blocks");
		else if (shm_mem_size == 0 || shm_mem_size == SHM_MEM_POOL_SIZE)
			shm_mem_size=(yyvsp[0].intval) * 1024 * 1024;
	}
#line 7479 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1476 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7485 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1477 "core/cfg.y" /* yacc.c:1646  */
    {
		if (shm_initialized())
			yyerror("shm_force_alloc must be before any modparam or the"
					" route blocks");
		else
			shm_force_alloc=(yyvsp[0].intval);
	}
#line 7497 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1484 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7503 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1485 "core/cfg.y" /* yacc.c:1646  */
    { mlock_pages=(yyvsp[0].intval); }
#line 7509 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1486 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7515 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1487 "core/cfg.y" /* yacc.c:1646  */
    { real_time=(yyvsp[0].intval); }
#line 7521 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1488 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7527 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1489 "core/cfg.y" /* yacc.c:1646  */
    { rt_prio=(yyvsp[0].intval); }
#line 7533 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1490 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7539 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1491 "core/cfg.y" /* yacc.c:1646  */
    { rt_policy=(yyvsp[0].intval); }
#line 7545 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1492 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7551 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1493 "core/cfg.y" /* yacc.c:1646  */
    { rt_timer1_prio=(yyvsp[0].intval); }
#line 7557 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1494 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7563 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1495 "core/cfg.y" /* yacc.c:1646  */
    { rt_timer1_policy=(yyvsp[0].intval); }
#line 7569 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1496 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7575 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1497 "core/cfg.y" /* yacc.c:1646  */
    { rt_timer2_prio=(yyvsp[0].intval); }
#line 7581 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1498 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7587 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1499 "core/cfg.y" /* yacc.c:1646  */
    { rt_timer2_policy=(yyvsp[0].intval); }
#line 7593 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1500 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7599 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1501 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_MCAST
			mcast_loopback=(yyvsp[0].intval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7611 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1508 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7617 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1509 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_MCAST
			mcast_ttl=(yyvsp[0].intval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7629 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1516 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7635 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1517 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_MCAST
			mcast=(yyvsp[0].strval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7647 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1524 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_MCAST
			mcast=(yyvsp[0].strval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7659 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1531 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 7665 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1532 "core/cfg.y" /* yacc.c:1646  */
    { tos=(yyvsp[0].intval); }
#line 7671 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1533 "core/cfg.y" /* yacc.c:1646  */
    { if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWDELAY")) {
			tos=IPTOS_LOWDELAY;
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_THROUGHPUT")) {
			tos=IPTOS_THROUGHPUT;
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_RELIABILITY")) {
			tos=IPTOS_RELIABILITY;
#if defined(IPTOS_MINCOST)
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_MINCOST")) {
			tos=IPTOS_MINCOST;
#endif
#if defined(IPTOS_LOWCOST)
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWCOST")) {
			tos=IPTOS_LOWCOST;
#endif
		} else {
			yyerror("invalid tos value - allowed: "
				"IPTOS_LOWDELAY,IPTOS_THROUGHPUT,"
				"IPTOS_RELIABILITY"
#if defined(IPTOS_LOWCOST)
				",IPTOS_LOWCOST"
#endif
#if !defined(IPTOS_MINCOST)
				",IPTOS_MINCOST"
#endif
				"\n");
		}
	}
#line 7703 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1560 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7709 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1561 "core/cfg.y" /* yacc.c:1646  */
    { pmtu_discovery=(yyvsp[0].intval); }
#line 7715 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1562 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7721 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1563 "core/cfg.y" /* yacc.c:1646  */
    { ser_kill_timeout=(yyvsp[0].intval); }
#line 7727 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1564 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7733 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1565 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.max_while_loops=(yyvsp[0].intval); }
#line 7739 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1566 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7745 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1567 "core/cfg.y" /* yacc.c:1646  */
    { pv_set_buffer_size((yyvsp[0].intval)); }
#line 7751 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1568 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7757 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1569 "core/cfg.y" /* yacc.c:1646  */
    { pv_set_buffer_slots((yyvsp[0].intval)); }
#line 7763 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1570 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7769 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1571 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.pv_cache_limit=(yyvsp[0].intval); }
#line 7775 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1572 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7781 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1573 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.pv_cache_action=(yyvsp[0].intval); }
#line 7787 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1574 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7793 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1575 "core/cfg.y" /* yacc.c:1646  */
    { http_reply_parse=(yyvsp[0].intval); }
#line 7799 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1576 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7805 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1577 "core/cfg.y" /* yacc.c:1646  */
    { ksr_verbose_startup=(yyvsp[0].intval); }
#line 7811 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1578 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 7817 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1579 "core/cfg.y" /* yacc.c:1646  */
    { ksr_route_locks_size=(yyvsp[0].intval); }
#line 7823 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1580 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7829 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1581 "core/cfg.y" /* yacc.c:1646  */
    { server_id=(yyvsp[0].intval); }
#line 7835 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1582 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7841 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1583 "core/cfg.y" /* yacc.c:1646  */
    {
			kemi_onsend_route_callback.s = (yyvsp[0].strval);
			kemi_onsend_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_onsend_route_callback.len==4
					&& strcasecmp(kemi_onsend_route_callback.s, "none")==0) {
				kemi_onsend_route_callback.s = "";
				kemi_onsend_route_callback.len = 0;
			}
		}
#line 7855 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1592 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 7861 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1593 "core/cfg.y" /* yacc.c:1646  */
    {
			kemi_reply_route_callback.s = (yyvsp[0].strval);
			kemi_reply_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_reply_route_callback.len==4
					&& strcasecmp(kemi_reply_route_callback.s, "none")==0) {
				kemi_reply_route_callback.s = "";
				kemi_reply_route_callback.len = 0;
			}
		}
#line 7875 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1602 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 7881 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1603 "core/cfg.y" /* yacc.c:1646  */
    {
			kemi_event_route_callback.s = (yyvsp[0].strval);
			kemi_event_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_event_route_callback.len==4
					&& strcasecmp(kemi_event_route_callback.s, "none")==0) {
				kemi_event_route_callback.s = "";
				kemi_event_route_callback.len = 0;
			}
		}
#line 7895 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1612 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 7901 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1613 "core/cfg.y" /* yacc.c:1646  */
    { set_max_recursive_level((yyvsp[0].intval)); }
#line 7907 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1614 "core/cfg.y" /* yacc.c:1646  */
    { sr_dst_max_branches = (yyvsp[0].intval); }
#line 7913 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1615 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.latency_log=(yyvsp[0].intval); }
#line 7919 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1616 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7925 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1617 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.latency_cfg_log=(yyvsp[0].intval); }
#line 7931 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1618 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7937 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 1619 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.latency_limit_db=(yyvsp[0].intval); }
#line 7943 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 1620 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7949 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1621 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.latency_limit_action=(yyvsp[0].intval); }
#line 7955 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1622 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7961 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 1623 "core/cfg.y" /* yacc.c:1646  */
    { sr_msg_time=(yyvsp[0].intval); }
#line 7967 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 1624 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number  expected"); }
#line 7973 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1625 "core/cfg.y" /* yacc.c:1646  */
    { onsend_route_reply=(yyvsp[0].intval); }
#line 7979 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1626 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("int value expected"); }
#line 7985 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1627 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.udp_mtu=(yyvsp[0].intval); }
#line 7991 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 1628 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 7997 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 1630 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.force_rport=(yyvsp[0].intval); fix_global_req_flags(0, 0); }
#line 8003 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 1631 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("boolean value expected"); }
#line 8009 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 1633 "core/cfg.y" /* yacc.c:1646  */
    { default_core_cfg.udp_mtu_try_proto=(yyvsp[0].intval); fix_global_req_flags(0, 0); }
#line 8015 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 1635 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("TCP, TLS, SCTP or UDP expected"); }
#line 8021 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 1636 "core/cfg.y" /* yacc.c:1646  */
    { IF_RAW_SOCKS(default_core_cfg.udp4_raw=(yyvsp[0].intval)); }
#line 8027 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1637 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 8033 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1638 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_RAW_SOCKS(default_core_cfg.udp4_raw_mtu=(yyvsp[0].intval));
	}
#line 8041 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 1641 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 8047 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 1642 "core/cfg.y" /* yacc.c:1646  */
    {
		IF_RAW_SOCKS(default_core_cfg.udp4_raw_ttl=(yyvsp[0].intval));
	}
#line 8055 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1645 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("number expected"); }
#line 8061 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 1647 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("unknown config variable"); }
#line 8067 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 1651 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)="default" ; }
#line 8073 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 1655 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)="default" ; }
#line 8079 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 1656 "core/cfg.y" /* yacc.c:1646  */
    {
		yyerror("cfg var field name - use of number or reserved token not allowed: %s",
				yy_number_str);
		YYERROR;
	}
#line 8089 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 1664 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_declare_int((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].intval), 0, 0, NULL)) {
			yyerror("variable cannot be declared");
		}
	}
#line 8099 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 1669 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_declare_str((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval), NULL)) {
			yyerror("variable cannot be declared");
		}
	}
#line 8109 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 1674 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_declare_int((yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].intval), 0, 0, (yyvsp[0].strval))) {
			yyerror("variable cannot be declared");
		}
	}
#line 8119 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 1679 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_declare_str((yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval))) {
			yyerror("variable cannot be declared");
		}
	}
#line 8129 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 1684 "core/cfg.y" /* yacc.c:1646  */
    {
		yyerror("number or string expected");
	}
#line 8137 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 1687 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_ginst_var_int((yyvsp[-7].strval), (yyvsp[-5].intval), (yyvsp[-2].strval), (yyvsp[0].intval))) {
			yyerror("variable cannot be added to the group instance");
		}
	}
#line 8147 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 1692 "core/cfg.y" /* yacc.c:1646  */
    {
		if (cfg_ginst_var_string((yyvsp[-7].strval), (yyvsp[-5].intval), (yyvsp[-2].strval), (yyvsp[0].strval))) {
			yyerror("variable cannot be added to the group instance");
		}
	}
#line 8157 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 1700 "core/cfg.y" /* yacc.c:1646  */
    {
		LM_DBG("loading module %s\n", (yyvsp[0].strval));
			if (load_module((yyvsp[0].strval))!=0) {
				yyerror("failed to load module");
			}
	}
#line 8168 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 1706 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 8174 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 1707 "core/cfg.y" /* yacc.c:1646  */
    {
		if(mods_dir_cmd==0) {
			LM_DBG("loading modules under %s\n", (yyvsp[0].strval));
			printf("loading modules under config path: %s\n", (yyvsp[0].strval));
			mods_dir = (yyvsp[0].strval);
		} else {
			LM_DBG("ignoring mod path given in config: %s\n", (yyvsp[0].strval));
			printf("loading modules under command line path: %s\n", mods_dir);
		}
	}
#line 8189 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 1717 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 8195 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 1718 "core/cfg.y" /* yacc.c:1646  */
    {
		if(mods_dir_cmd==0) {
			LM_DBG("loading modules under %s\n", (yyvsp[0].strval));
			printf("loading modules under config path: %s\n", (yyvsp[0].strval));
			mods_dir = (yyvsp[0].strval);
		} else {
			LM_DBG("ignoring mod path given in config: %s\n", (yyvsp[0].strval));
			printf("loading modules under command line path: %s\n", mods_dir);
		}
	}
#line 8210 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 1728 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 8216 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 1729 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_STRING, (yyvsp[-1].strval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 8232 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1740 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_INT, (void*)(yyvsp[-1].intval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 8248 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1751 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("Invalid arguments"); }
#line 8254 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 1752 "core/cfg.y" /* yacc.c:1646  */
    {
		if(sr_kemi_eng_setz((yyvsp[0].strval), NULL)) {
			yyerror("Can't set config routing engine");
			YYABORT;
		}
	}
#line 8265 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 1758 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 8271 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 1759 "core/cfg.y" /* yacc.c:1646  */
    {
		if(sr_kemi_eng_setz((yyvsp[0].strval), NULL)) {
			yyerror("Can't set config routing engine");
			YYABORT;
		}
	}
#line 8282 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 1765 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("string expected"); }
#line 8288 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 1769 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8294 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 1770 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8300 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 1773 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
		if ((yyval.ipaddr)==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
		} else {
			memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
			(yyval.ipaddr)->af=AF_INET;
			(yyval.ipaddr)->len=4;
			if (((yyvsp[-6].intval)>255) || ((yyvsp[-6].intval)<0) ||
				((yyvsp[-4].intval)>255) || ((yyvsp[-4].intval)<0) ||
				((yyvsp[-2].intval)>255) || ((yyvsp[-2].intval)<0) ||
				((yyvsp[0].intval)>255) || ((yyvsp[0].intval)<0)) {
				yyerror("invalid ipv4 address");
				(yyval.ipaddr)->u.addr32[0]=0;
				/* $$=0; */
			} else {
				(yyval.ipaddr)->u.addr[0]=(yyvsp[-6].intval);
				(yyval.ipaddr)->u.addr[1]=(yyvsp[-4].intval);
				(yyval.ipaddr)->u.addr[2]=(yyvsp[-2].intval);
				(yyval.ipaddr)->u.addr[3]=(yyvsp[0].intval);
				/*
				$$=htonl( ($1<<24)|
				($3<<16)| ($5<<8)|$7 );
				*/
			}
		}
	}
#line 8332 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 1802 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
		if ((yyval.ipaddr)==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
		} else {
			memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
			(yyval.ipaddr)->af=AF_INET6;
			(yyval.ipaddr)->len=16;
			if (inet_pton(AF_INET6, (yyvsp[0].strval), (yyval.ipaddr)->u.addr)<=0) {
				yyerror("bad ipv6 address");
			}
		}
	}
#line 8350 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1817 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8356 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 1818 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.ipaddr)=(yyvsp[-1].ipaddr); }
#line 8362 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 1822 "core/cfg.y" /* yacc.c:1646  */
    {
					tmp=int2str((yyvsp[0].intval), &i_tmp);
					if (((yyval.strval)=pkg_malloc(i_tmp+1))==0) {
						yyerror("out of  memory");
						YYABORT;
					} else {
						memcpy((yyval.strval), tmp, i_tmp);
						(yyval.strval)[i_tmp]=0;
					}
					routename = tmp;
						}
#line 8378 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1833 "core/cfg.y" /* yacc.c:1646  */
    { routename = (yyvsp[0].strval); (yyval.strval)=(yyvsp[0].strval); }
#line 8384 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1834 "core/cfg.y" /* yacc.c:1646  */
    { routename = (yyvsp[0].strval); (yyval.strval)=(yyvsp[0].strval); }
#line 8390 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 1838 "core/cfg.y" /* yacc.c:1646  */
    { routename=NULL; }
#line 8396 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 1839 "core/cfg.y" /* yacc.c:1646  */
    { routename=NULL; }
#line 8402 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 1843 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &main_rt.rlist[DEFAULT_RT]);
	}
#line 8416 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 1852 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&main_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (main_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &main_rt.rlist[i_tmp]);
	}
#line 8439 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 1870 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid  route  statement"); }
#line 8445 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 1871 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid  request_route  statement"); }
#line 8451 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 1874 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &failure_rt.rlist[DEFAULT_RT]);
	}
#line 8465 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 1883 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&failure_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (failure_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &failure_rt.rlist[i_tmp]);
	}
#line 8488 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 1901 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid failure_route statement"); }
#line 8494 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 1905 "core/cfg.y" /* yacc.c:1646  */
    { routename=NULL; }
#line 8500 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 1906 "core/cfg.y" /* yacc.c:1646  */
    { routename=NULL; }
#line 8506 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 1911 "core/cfg.y" /* yacc.c:1646  */
    {rt=CORE_ONREPLY_ROUTE;}
#line 8512 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 1911 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &onreply_rt.rlist[DEFAULT_RT]);
	}
#line 8526 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 1920 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid onreply_route statement"); }
#line 8532 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 1921 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid onreply_route statement"); }
#line 8538 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 1923 "core/cfg.y" /* yacc.c:1646  */
    {rt=(*(yyvsp[-1].strval)=='0' && (yyvsp[-1].strval)[1]==0)?CORE_ONREPLY_ROUTE:TM_ONREPLY_ROUTE;}
#line 8544 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 1924 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		if (*(yyvsp[-5].strval)=='0' && (yyvsp[-5].strval)[1]==0){
			/* onreply_route[0] {} is equivalent with onreply_route {}*/
			push((yyvsp[-1].action), &onreply_rt.rlist[DEFAULT_RT]);
		}else{
			i_tmp=route_get(&onreply_rt, (yyvsp[-5].strval));
			if (i_tmp==-1){
				yyerror("internal error");
				YYABORT;
			}
			if (onreply_rt.rlist[i_tmp]){
				yyerror("duplicate route");
				YYABORT;
			}
			push((yyvsp[-1].action), &onreply_rt.rlist[i_tmp]);
		}
	}
#line 8572 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 1947 "core/cfg.y" /* yacc.c:1646  */
    {
		yyerror("invalid onreply_route statement");
	}
#line 8580 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 1952 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &branch_rt.rlist[DEFAULT_RT]);
	}
#line 8594 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 1961 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&branch_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (branch_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &branch_rt.rlist[i_tmp]);
	}
#line 8617 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 1979 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid branch_route statement"); }
#line 8623 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 1981 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		push((yyvsp[-1].action), &onsend_rt.rlist[DEFAULT_RT]);
	}
#line 8637 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 1990 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&onsend_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (onsend_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &onsend_rt.rlist[i_tmp]);
	}
#line 8660 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 2008 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid onsend_route statement"); }
#line 8666 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 2010 "core/cfg.y" /* yacc.c:1646  */
    {
	#ifdef SHM_MEM
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
	#endif /* SHM_MEM */
		i_tmp=route_get(&event_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (event_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &event_rt.rlist[i_tmp]);
	}
#line 8689 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 2029 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid event_route statement"); }
#line 8695 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 2032 "core/cfg.y" /* yacc.c:1646  */
    { if(pp_subst_add((yyvsp[0].strval))<0) YYERROR; }
#line 8701 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 2033 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid subst preprocess statement"); }
#line 8707 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 2034 "core/cfg.y" /* yacc.c:1646  */
    { if(pp_substdef_add((yyvsp[0].strval), 0)<0) YYERROR; }
#line 8713 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 2035 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid substdef preprocess statement"); }
#line 8719 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 2036 "core/cfg.y" /* yacc.c:1646  */
    { if(pp_substdef_add((yyvsp[0].strval), 1)<0) YYERROR; }
#line 8725 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 2037 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("invalid substdefs preprocess statement"); }
#line 8731 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 2059 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=EQUAL_OP; }
#line 8737 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 2060 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=DIFF_OP; }
#line 8743 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 2061 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=EQUAL_OP; }
#line 8749 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 2062 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=DIFF_OP; }
#line 8755 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 501:
#line 2065 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=GT_OP; }
#line 8761 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 502:
#line 2066 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=LT_OP; }
#line 8767 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 2067 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=GTE_OP; }
#line 8773 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 504:
#line 2068 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=LTE_OP; }
#line 8779 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 2071 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[0].intval); }
#line 8785 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 2072 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=MATCH_OP; }
#line 8791 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 2078 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_EQ_OP; }
#line 8797 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 2079 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_DIFF_OP; }
#line 8803 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 2080 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_IEQ_OP; }
#line 8809 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 510:
#line 2081 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_IDIFF_OP; }
#line 8815 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2082 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_STREQ_OP; }
#line 8821 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2083 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_STRDIFF_OP; }
#line 8827 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2084 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_MATCH_OP; }
#line 8833 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2087 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_GT_OP; }
#line 8839 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2088 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_LT_OP; }
#line 8845 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2089 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_GTE_OP; }
#line 8851 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2090 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=RVE_LTE_OP; }
#line 8857 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2097 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=URI_O;}
#line 8863 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2098 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=FROM_URI_O;}
#line 8869 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2099 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.intval)=TO_URI_O;}
#line 8875 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2106 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=SNDPORT_O; }
#line 8881 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2107 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=TOPORT_O; }
#line 8887 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2108 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=SNDAF_O; }
#line 8893 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2112 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=SRCPORT_O; }
#line 8899 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2113 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=DSTPORT_O; }
#line 8905 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2114 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=AF_O; }
#line 8911 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2115 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=MSGLEN_O; }
#line 8917 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2121 "core/cfg.y" /* yacc.c:1646  */
    { onsend_check("snd_ip"); (yyval.intval)=SNDIP_O; }
#line 8923 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2122 "core/cfg.y" /* yacc.c:1646  */
    { onsend_check("to_ip");  (yyval.intval)=TOIP_O; }
#line 8929 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2125 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=SRCIP_O; }
#line 8935 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2126 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=DSTIP_O; }
#line 8941 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2134 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.expr)= mk_elem((yyvsp[-1].intval), METHOD_O, 0, RVE_ST, (yyvsp[0].rv_expr));}
#line 8947 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2136 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.expr) = mk_elem((yyvsp[-1].intval), METHOD_O, 0, STRING_ST,(yyvsp[0].strval)); }
#line 8953 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2137 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("string expected"); }
#line 8959 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2139 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("invalid operator,== , !=, or =~ expected"); }
#line 8965 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2141 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.expr) = mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr)); }
#line 8971 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2143 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, MYSELF_ST, 0); }
#line 8977 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2145 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("string or MYSELF expected"); }
#line 8983 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2147 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("invalid operator, == , != or =~ expected"); }
#line 8989 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2148 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 8995 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2150 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 9001 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2151 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("number expected"); }
#line 9007 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2152 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("number expected"); }
#line 9013 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2153 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); }
#line 9019 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2155 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), PROTO_O, 0, NUMBER_ST, (void*)(yyvsp[0].intval) ); }
#line 9025 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2157 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), PROTO_O, 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 9031 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2159 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("protocol expected (udp, tcp, tls, sctp, ws, or wss)"); }
#line 9037 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2161 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), SNDPROTO_O, 0, NUMBER_ST, (void*)(yyvsp[0].intval) ); }
#line 9043 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2163 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), SNDPROTO_O, 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 9049 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2165 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("protocol expected (udp, tcp, tls, sctp, ws, or wss)"); }
#line 9055 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2166 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, NET_ST, (yyvsp[0].ipnet)); }
#line 9061 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2167 "core/cfg.y" /* yacc.c:1646  */
    {
			s_tmp.s=0;
			(yyval.expr)=0;
			if (rve_is_constant((yyvsp[0].rv_expr))){
				i_tmp=rve_guess_type((yyvsp[0].rv_expr));
				if (i_tmp==RV_INT)
					yyerror("string expected");
				else if (i_tmp==RV_STR){
					if (((rval_tmp=rval_expr_eval(0, 0, (yyvsp[0].rv_expr)))==0) ||
								(rval_get_str(0, 0, &s_tmp, rval_tmp, 0)<0)){
						rval_destroy(rval_tmp);
						yyerror("bad rvalue expression");
					}else{
						rval_destroy(rval_tmp);
					}
				}else{
					yyerror("BUG: unexpected dynamic type");
				}
			}else{
					/* warn("non constant rvalue in ip comparison") */;
			}
			if (s_tmp.s){
				ip_tmp=str2ip(&s_tmp);
				if (ip_tmp==0)
					ip_tmp=str2ip6(&s_tmp);
				pkg_free(s_tmp.s);
				if (ip_tmp) {
					(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, NET_ST,
								mk_new_net_bitlen(ip_tmp, ip_tmp->len*8) );
				} else {
					(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr));
				}
			}else{
				(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr));
			}
		}
#line 9102 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2204 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, STRING_ST, (yyvsp[0].strval)); }
#line 9108 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2206 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, MYSELF_ST, 0); }
#line 9114 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2208 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror( "ip address or hostname expected" ); }
#line 9120 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2210 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("invalid operator, ==, != or =~ expected");}
#line 9126 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2213 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[0].intval), 0, MYSELF_ST, 0); }
#line 9132 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2215 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[0].intval), 0, MYSELF_ST, 0); }
#line 9138 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2217 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror("URI, SRCIP or DSTIP expected"); }
#line 9144 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2218 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.expr)=0; yyerror ("invalid operator, == or != expected"); }
#line 9150 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2222 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipnet)=mk_new_net((yyvsp[-2].ipaddr), (yyvsp[0].ipaddr)); }
#line 9156 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2223 "core/cfg.y" /* yacc.c:1646  */
    {
		if (((yyvsp[0].intval)<0) || ((yyvsp[0].intval)>(yyvsp[-2].ipaddr)->len*8)) {
			yyerror("invalid bit number in netmask");
			(yyval.ipnet)=0;
		} else {
			(yyval.ipnet)=mk_new_net_bitlen((yyvsp[-2].ipaddr), (yyvsp[0].intval));
		/*
			$$=mk_new_net($1, htonl( ($3)?~( (1<<(32-$3))-1 ):0 ) );
		*/
		}
	}
#line 9172 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2234 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipnet)=mk_new_net_bitlen((yyvsp[0].ipaddr), (yyvsp[0].ipaddr)->len*8); }
#line 9178 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2235 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.ipnet)=0; yyerror("netmask (eg:255.0.0.0 or 8) expected"); }
#line 9184 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2239 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[0].strval); }
#line 9190 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2240 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: memory allocation"
							" failure while parsing host\n");
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='.';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9211 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2256 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: memory allocation"
							" failure while parsing host\n");
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='-';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9232 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2272 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval)); yyerror("invalid hostname"); }
#line 9238 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2273 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval)); yyerror("invalid hostname"); }
#line 9244 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2278 "core/cfg.y" /* yacc.c:1646  */
    {
			/* get string version */
			(yyval.strval)=pkg_malloc(strlen(yy_number_str)+1);
			if ((yyval.strval))
				strcpy((yyval.strval), yy_number_str);
		}
#line 9255 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2287 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[0].strval); }
#line 9261 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2288 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: memory allocation"
							" failure while parsing host/interface name\n");
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='.';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9282 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2304 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				LM_CRIT("cfg. parser: memory allocation"
							" failure while parsing host/interface name\n");
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='-';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9303 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2320 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
								yyerror("invalid host or interface name"); }
#line 9310 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2322 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
								yyerror("invalid host or interface name"); }
#line 9317 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2329 "core/cfg.y" /* yacc.c:1646  */
    {
		/* check if allowed */
		if ((yyvsp[0].action) && rt==ONSEND_ROUTE) {
			switch((yyvsp[0].action)->type) {
				case DROP_T:
				case LOG_T:
				case SETFLAG_T:
				case RESETFLAG_T:
				case ISFLAGSET_T:
				case IF_T:
				case MODULE0_T:
				case MODULE1_T:
				case MODULE2_T:
				case MODULE3_T:
				case MODULE4_T:
				case MODULE5_T:
				case MODULE6_T:
				case MODULEX_T:
				case SET_FWD_NO_CONNECT_T:
				case SET_RPL_NO_CONNECT_T:
				case SET_FWD_CLOSE_T:
				case SET_RPL_CLOSE_T:
					(yyval.action)=(yyvsp[0].action);
					break;
				default:
					(yyval.action)=0;
					yyerror("command not allowed in onsend_route\n");
			}
		} else {
			(yyval.action)=(yyvsp[0].action);
		}
	}
#line 9354 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2371 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=(yyvsp[0].action); }
#line 9360 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2372 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=(yyvsp[-1].action); }
#line 9366 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2375 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=append_action((yyvsp[-1].action), (yyvsp[0].action)); }
#line 9372 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2376 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[0].action);}
#line 9378 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2377 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad command"); }
#line 9384 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2380 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[-1].action);}
#line 9390 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2381 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[0].action);}
#line 9396 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2382 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[0].action);}
#line 9402 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2383 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=(yyvsp[0].action); }
#line 9408 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2384 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=(yyvsp[-1].action); }
#line 9414 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2385 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=(yyvsp[-1].action);}
#line 9420 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2386 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0;}
#line 9426 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2387 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad command: missing ';'?"); }
#line 9432 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2390 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].rv_expr) && rval_expr_int_check((yyvsp[-1].rv_expr))>=0){
			warn_ct_rve((yyvsp[-1].rv_expr), "if");
			(yyval.action)=mk_action( IF_T, 3, RVE_ST, (yyvsp[-1].rv_expr), ACTIONS_ST, (yyvsp[0].action), NOSUBTYPE, 0);
			set_cfg_pos((yyval.action));
		}else
			YYERROR;
	}
#line 9445 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2398 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-3].rv_expr) && rval_expr_int_check((yyvsp[-3].rv_expr))>=0){
			warn_ct_rve((yyvsp[-3].rv_expr), "if");
			(yyval.action)=mk_action( IF_T, 3, RVE_ST, (yyvsp[-3].rv_expr), ACTIONS_ST, (yyvsp[-2].action), ACTIONS_ST, (yyvsp[0].action));
			set_cfg_pos((yyval.action));
		}else
			YYERROR;
	}
#line 9458 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2408 "core/cfg.y" /* yacc.c:1646  */
    {
			(yyval.rv_expr)=0;
			if ((yyvsp[0].rv_expr) && !rve_is_constant((yyvsp[0].rv_expr))){
				yyerror("constant expected");
				YYERROR;
			/*
			} else if ($1 &&
						!rve_check_type((enum rval_type*)&i_tmp, $1, 0, 0 ,0)){
				yyerror("invalid expression (bad type)");
			}else if ($1 && i_tmp!=RV_INT){
				yyerror("invalid expression type, int expected\n");
			*/
			}else
				(yyval.rv_expr)=(yyvsp[0].rv_expr);
		}
#line 9478 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2425 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-2].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-2].rv_expr), 0, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9490 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2432 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-2].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-2].rv_expr), 1, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9502 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2439 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-1].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-1].rv_expr), 0, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9514 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2446 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-1].rv_expr)==0) { yyerror ("bad regex case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-1].rv_expr), 1, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9526 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2453 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((((yyval.case_stms)=mk_case_stm(0, 0, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9536 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2458 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((((yyval.case_stms)=mk_case_stm(0, 0, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9546 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2463 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror("bad case label"); }
#line 9552 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2464 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror("bad case regex label"); }
#line 9558 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2465 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror("bad case label"); }
#line 9564 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2466 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror("bad case regex label"); }
#line 9570 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2467 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.case_stms)=0; yyerror ("bad case body"); }
#line 9576 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2470 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=(yyvsp[-1].case_stms);
		if ((yyvsp[0].case_stms)==0) yyerror ("bad case");
		if ((yyval.case_stms)){
			*((yyval.case_stms)->append)=(yyvsp[0].case_stms);
			if (*((yyval.case_stms)->append)!=0)
				(yyval.case_stms)->append=&((*((yyval.case_stms)->append))->next);
		}
	}
#line 9590 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2479 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.case_stms)=(yyvsp[0].case_stms);
		if ((yyvsp[0].case_stms)==0) yyerror ("bad case");
		else (yyval.case_stms)->append=&((yyval.case_stms)->next);
	}
#line 9600 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2486 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0;
		if ((yyvsp[-3].rv_expr)==0){
			yyerror("bad expression in switch(...)");
			YYERROR;
		}else if ((yyvsp[-1].case_stms)==0){
			yyerror ("bad switch body");
			YYERROR;
		}else if (case_check_default((yyvsp[-1].case_stms))!=0){
			yyerror_at(&(yyvsp[-3].rv_expr)->fpos, "bad switch(): too many "
							"\"default:\" labels\n");
			YYERROR;
		}else if (case_check_type((yyvsp[-1].case_stms))!=0){
			yyerror_at(&(yyvsp[-3].rv_expr)->fpos, "bad switch(): mixed integer and"
							" string/RE cases not allowed\n");
			YYERROR;
		}else{
			(yyval.action)=mk_action(SWITCH_T, 2, RVE_ST, (yyvsp[-3].rv_expr), CASE_ST, (yyvsp[-1].case_stms));
			if ((yyval.action)==0) {
				yyerror("internal error");
				YYABORT;
			}
			set_cfg_pos((yyval.action));
		}
	}
#line 9630 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2511 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0;
		warn("empty switch()");
		if ((yyvsp[-2].rv_expr)==0){
			yyerror("bad expression in switch(...)");
			YYERROR;
		}else{
			/* it might have sideffects, so leave it for the optimizer */
			(yyval.action)=mk_action(SWITCH_T, 2, RVE_ST, (yyvsp[-2].rv_expr), CASE_ST, 0);
			if ((yyval.action)==0) {
				yyerror("internal error");
				YYABORT;
			}
			set_cfg_pos((yyval.action));
		}
	}
#line 9651 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2527 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror ("bad expression in switch(...)"); }
#line 9657 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2529 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror ("bad switch body"); }
#line 9663 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2533 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].rv_expr) && rval_expr_int_check((yyvsp[-1].rv_expr))>=0){
			warn_ct_rve((yyvsp[-1].rv_expr), "while");
			(yyval.action)=mk_action( WHILE_T, 2, RVE_ST, (yyvsp[-1].rv_expr), ACTIONS_ST, (yyvsp[0].action));
			set_cfg_pos((yyval.action));
		}else{
			yyerror_at(&(yyvsp[-1].rv_expr)->fpos, "bad while(...) expression");
			YYERROR;
		}
	}
#line 9678 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2552 "core/cfg.y" /* yacc.c:1646  */
    {
		if (sel.n >= MAX_SELECT_PARAMS-1) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[0].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[0].strval));
		sel.n++;
	}
#line 9692 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2561 "core/cfg.y" /* yacc.c:1646  */
    {
		if (sel.n >= MAX_SELECT_PARAMS-2) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-3].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-3].strval));
		sel.n++;
		sel.params[sel.n].type = SEL_PARAM_INT;
		sel.params[sel.n].v.i = (yyvsp[-1].intval);
		sel.n++;
	}
#line 9709 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2573 "core/cfg.y" /* yacc.c:1646  */
    {
		if (sel.n >= MAX_SELECT_PARAMS-2) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-3].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-3].strval));
		sel.n++;
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-1].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-1].strval));
		sel.n++;
	}
#line 9727 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2592 "core/cfg.y" /* yacc.c:1646  */
    { sel.n = 0; sel.f[0] = 0; }
#line 9733 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2592 "core/cfg.y" /* yacc.c:1646  */
    {
		sel_ptr = (select_t*)pkg_malloc(sizeof(select_t));
		if (!sel_ptr) {
			yyerror("No memory left to allocate select structure\n");
		}
		memcpy(sel_ptr, &sel, sizeof(select_t));
		(yyval.select) = sel_ptr;
	}
#line 9746 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2602 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_FROM; }
#line 9752 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2603 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_TO; }
#line 9758 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2604 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_URI; }
#line 9764 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2605 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_URI; }
#line 9770 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2606 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_USER; }
#line 9776 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2607 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_USER; }
#line 9782 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2608 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_DOMAIN; }
#line 9788 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2609 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_DOMAIN; }
#line 9794 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2610 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_TRACK_ALL | AVP_CLASS_GLOBAL; }
#line 9800 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2613 "core/cfg.y" /* yacc.c:1646  */
    { s_attr->type |= AVP_NAME_STR; s_attr->name.s.s = (yyvsp[0].strval); s_attr->name.s.len = strlen ((yyvsp[0].strval)); }
#line 9806 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2620 "core/cfg.y" /* yacc.c:1646  */
    {
		s_attr = (struct avp_spec*)pkg_malloc(sizeof(struct avp_spec));
		if (!s_attr) { yyerror("No memory left"); YYABORT; }
		else s_attr->type = 0;
	}
#line 9816 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2627 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.attr) = s_attr; }
#line 9822 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2630 "core/cfg.y" /* yacc.c:1646  */
    {
		s_attr->type|= (AVP_NAME_STR | ((yyvsp[-1].intval)<0?AVP_INDEX_BACKWARD:AVP_INDEX_FORWARD));
		s_attr->index = ((yyvsp[-1].intval)<0?-(yyvsp[-1].intval):(yyvsp[-1].intval));
		(yyval.attr) = s_attr;
	}
#line 9832 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2637 "core/cfg.y" /* yacc.c:1646  */
    {
		s_attr->type|= AVP_INDEX_ALL;
		(yyval.attr) = s_attr;
	}
#line 9841 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2659 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].lval)->type==LV_AVP){
			s_attr = pkg_malloc(sizeof(struct avp_spec));
			if (!s_attr) { yyerror("No memory left"); YYABORT; }
			else{
				*s_attr=(yyvsp[0].lval)->lv.avps;
			}
			(yyval.attr)=s_attr;
		}else
			(yyval.attr)=0; /* not an avp, a pvar */
		pkg_free((yyvsp[0].lval));
	}
#line 9858 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2671 "core/cfg.y" /* yacc.c:1646  */
    {
		avp_spec_t *avp_spec;
		str s;
		int type, idx;
		avp_spec = pkg_malloc(sizeof(*avp_spec));
		if (!avp_spec) {
			yyerror("Not enough memory");
			YYABORT;
		}
		s.s = (yyvsp[0].strval);
		if (s.s[0] == '$')
			s.s++;
		s.len = strlen(s.s);
		if (parse_avp_name(&s, &type, &avp_spec->name, &idx)) {
			yyerror("error when parsing AVP");
			pkg_free(avp_spec);
			YYABORT;
		}
		avp_spec->type = type;
		avp_spec->index = idx;
		(yyval.attr) = avp_spec;
	}
#line 9885 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2695 "core/cfg.y" /* yacc.c:1646  */
    {
			s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen((yyvsp[0].strval));
			pv_spec=pv_cache_get(&s_tmp);
			if (!pv_spec) {
				yyerror("Can't get from cache: %s", (yyvsp[0].strval));
				YYABORT;
			}
			(yyval.pvar)=pv_spec;
		}
#line 9899 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2706 "core/cfg.y" /* yacc.c:1646  */
    {
				lval_tmp=pkg_malloc(sizeof(*lval_tmp));
				if (!lval_tmp) {
					yyerror("Not enough memory");
					YYABORT;
				}
				memset(lval_tmp, 0, sizeof(*lval_tmp));
				s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen(s_tmp.s);
				lval_tmp->lv.pvs = pv_cache_get(&s_tmp);
				if (lval_tmp->lv.pvs==NULL){
					lval_tmp->lv.avps.type|= AVP_NAME_STR;
					lval_tmp->lv.avps.name.s.s = s_tmp.s+1;
					lval_tmp->lv.avps.name.s.len = s_tmp.len-1;
					lval_tmp->type=LV_AVP;
				}else{
					lval_tmp->type=LV_PVAR;
				}
				(yyval.lval) = lval_tmp;
				DBG("parsed ambiguous avp/pvar \"%.*s\" to %d\n",
							s_tmp.len, s_tmp.s, lval_tmp->type);
			}
#line 9925 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2737 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval) = ASSIGN_T; }
#line 9931 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2741 "core/cfg.y" /* yacc.c:1646  */
    {
					lval_tmp=pkg_malloc(sizeof(*lval_tmp));
					if (!lval_tmp) {
						yyerror("Not enough memory");
						YYABORT;
					}
					lval_tmp->type=LV_AVP; lval_tmp->lv.avps=*(yyvsp[0].attr);
					pkg_free((yyvsp[0].attr)); /* free the avp spec we just copied */
					(yyval.lval)=lval_tmp;
				}
#line 9946 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2751 "core/cfg.y" /* yacc.c:1646  */
    {
					if (!pv_is_w((yyvsp[0].pvar)))
						yyerror("read only pvar in assignment left side");
					if ((yyvsp[0].pvar)->trans!=0)
						yyerror("pvar with transformations in assignment"
								" left side");
					lval_tmp=pkg_malloc(sizeof(*lval_tmp));
					if (!lval_tmp) {
						yyerror("Not enough memory");
						YYABORT;
					}
					lval_tmp->type=LV_PVAR; lval_tmp->lv.pvs=(yyvsp[0].pvar);
					(yyval.lval)=lval_tmp;
				}
#line 9965 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2765 "core/cfg.y" /* yacc.c:1646  */
    {
					if (((yyvsp[0].lval))->type==LV_PVAR){
						if (!pv_is_w((yyvsp[0].lval)->lv.pvs))
							yyerror("read only pvar in assignment left side");
						if ((yyvsp[0].lval)->lv.pvs->trans!=0)
							yyerror("pvar with transformations in assignment"
									" left side");
					}
					(yyval.lval)=(yyvsp[0].lval);
				}
#line 9980 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2777 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_INT, (void*)(yyvsp[0].intval)); }
#line 9986 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2778 "core/cfg.y" /* yacc.c:1646  */
    {	s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen((yyvsp[0].strval));
							(yyval.rv_expr)=mk_rve_rval(RV_STR, &s_tmp); }
#line 9993 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2780 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_AVP, (yyvsp[0].attr)); pkg_free((yyvsp[0].attr)); }
#line 9999 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2781 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_PVAR, (yyvsp[0].pvar)); }
#line 10005 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2782 "core/cfg.y" /* yacc.c:1646  */
    {
							switch((yyvsp[0].lval)->type){
								case LV_AVP:
									(yyval.rv_expr)=mk_rve_rval(RV_AVP, &(yyvsp[0].lval)->lv.avps);
									break;
								case LV_PVAR:
									(yyval.rv_expr)=mk_rve_rval(RV_PVAR, (yyvsp[0].lval)->lv.pvs);
									break;
								default:
									yyerror("BUG: invalid lvalue type ");
									YYABORT;
							}
							pkg_free((yyvsp[0].lval)); /* not needed anymore */
						}
#line 10024 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2796 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_SEL, (yyvsp[0].select)); pkg_free((yyvsp[0].select)); }
#line 10030 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 658:
#line 2797 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[0].action)); }
#line 10036 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 659:
#line 2798 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve_rval(RV_BEXPR, (yyvsp[0].expr)); }
#line 10042 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 660:
#line 2799 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[-1].action)); }
#line 10048 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 661:
#line 2800 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad command block"); }
#line 10054 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 662:
#line 2801 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[-1].action)); }
#line 10060 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 663:
#line 2802 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10066 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 664:
#line 2806 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=RVE_LNOT_OP; }
#line 10072 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 665:
#line 2807 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=RVE_BNOT_OP; }
#line 10078 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 666:
#line 2808 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval)=RVE_UMINUS_OP; }
#line 10084 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 667:
#line 2821 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=(yyvsp[0].rv_expr);
										if ((yyval.rv_expr)==0){
											/*yyerror("out of memory\n");*/
											YYERROR;
										}
									}
#line 10095 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2827 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve1((yyvsp[-1].intval), (yyvsp[0].rv_expr)); }
#line 10101 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2828 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve1(RVE_INT_OP, (yyvsp[0].rv_expr)); }
#line 10107 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 670:
#line 2829 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve1(RVE_STR_OP, (yyvsp[0].rv_expr)); }
#line 10113 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 671:
#line 2830 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_PLUS_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10119 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 672:
#line 2831 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_MINUS_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10125 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 673:
#line 2832 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_MUL_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10131 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 674:
#line 2833 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_DIV_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10137 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 675:
#line 2834 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_MOD_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10143 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 676:
#line 2835 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BOR_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr)); }
#line 10149 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 677:
#line 2836 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BAND_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 10155 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 678:
#line 2837 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BXOR_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 10161 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 679:
#line 2838 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BLSHIFT_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 10167 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 680:
#line 2839 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve2(RVE_BRSHIFT_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 10173 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 681:
#line 2840 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve2( (yyvsp[-1].intval), (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 10179 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 682:
#line 2841 "core/cfg.y" /* yacc.c:1646  */
    {
			/* comparing with $null => treat as defined or !defined */
			if((yyvsp[0].rv_expr)->op==RVE_RVAL_OP && (yyvsp[0].rv_expr)->left.rval.type==RV_PVAR
					&& (yyvsp[0].rv_expr)->left.rval.v.pvs.type==PVT_NULL) {
				if((yyvsp[-1].intval)==RVE_DIFF_OP || (yyvsp[-1].intval)==RVE_IDIFF_OP
						|| (yyvsp[-1].intval)==RVE_STRDIFF_OP) {
					DBG("comparison with $null switched to notdefined operator\n");
					(yyval.rv_expr)=mk_rve1(RVE_DEFINED_OP, (yyvsp[-2].rv_expr));
				} else {
					DBG("comparison with $null switched to defined operator\n");
					(yyval.rv_expr)=mk_rve1(RVE_NOTDEFINED_OP, (yyvsp[-2].rv_expr));
				}
				/* free rve struct for $null */
				rve_destroy((yyvsp[0].rv_expr));
			} else {
				(yyval.rv_expr)=mk_rve2((yyvsp[-1].intval), (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));
			}
		}
#line 10202 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 683:
#line 2859 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve2(RVE_LAND_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 10208 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 684:
#line 2860 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve2(RVE_LOR_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 10214 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 685:
#line 2861 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=(yyvsp[-1].rv_expr);}
#line 10220 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 686:
#line 2862 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve1(RVE_STRLEN_OP, (yyvsp[-1].rv_expr));}
#line 10226 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 687:
#line 2863 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.rv_expr)=mk_rve1(RVE_STREMPTY_OP, (yyvsp[-1].rv_expr));}
#line 10232 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 688:
#line 2864 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=mk_rve1(RVE_DEFINED_OP, (yyvsp[0].rv_expr));}
#line 10238 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 689:
#line 2865 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10244 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 690:
#line 2866 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10250 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 691:
#line 2867 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10256 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 692:
#line 2868 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10262 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 693:
#line 2869 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10268 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 694:
#line 2870 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10274 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 695:
#line 2871 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10280 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 696:
#line 2872 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10286 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 697:
#line 2873 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10292 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 698:
#line 2874 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10298 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 699:
#line 2876 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10304 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 700:
#line 2878 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10310 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 701:
#line 2879 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10316 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 702:
#line 2880 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10322 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 703:
#line 2881 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10328 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 704:
#line 2882 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10334 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 705:
#line 2883 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10340 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 706:
#line 2886 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action((yyvsp[-1].intval), 2, LVAL_ST, (yyvsp[-2].lval),
														 	  RVE_ST, (yyvsp[0].rv_expr));
											set_cfg_pos((yyval.action));
										}
#line 10349 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 707:
#line 2904 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval) = 1; }
#line 10355 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 708:
#line 2905 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval) = 0; }
#line 10361 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 709:
#line 2906 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.intval) = -1; }
#line 10367 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 710:
#line 2909 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10373 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 711:
#line 2910 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(	FORWARD_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10379 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 712:
#line 2911 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(	FORWARD_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10385 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 713:
#line 2912 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(	FORWARD_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10391 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 714:
#line 2913 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10397 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 715:
#line 2914 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10403 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 716:
#line 2915 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10409 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 717:
#line 2916 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10415 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 718:
#line 2917 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10421 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 719:
#line 2918 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10427 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 720:
#line 2919 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10433 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 721:
#line 2920 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad forward argument"); }
#line 10439 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 722:
#line 2921 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10445 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 723:
#line 2922 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10451 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 724:
#line 2923 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10457 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 725:
#line 2924 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10463 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 726:
#line 2925 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10469 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 727:
#line 2926 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10475 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 728:
#line 2927 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10481 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 729:
#line 2928 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10487 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 730:
#line 2929 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10493 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 731:
#line 2930 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10499 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 732:
#line 2931 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad forward_udp argument"); }
#line 10505 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 733:
#line 2932 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10511 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 734:
#line 2933 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10517 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 735:
#line 2934 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10523 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 736:
#line 2935 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10529 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 737:
#line 2936 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10535 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 738:
#line 2937 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10541 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 739:
#line 2938 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10547 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 740:
#line 2939 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10553 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 741:
#line 2940 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10559 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 742:
#line 2941 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10565 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 743:
#line 2942 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad forward_tcp argument"); }
#line 10571 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 744:
#line 2943 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10584 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 745:
#line 2951 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10597 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 746:
#line 2959 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10610 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 747:
#line 2967 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10623 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 748:
#line 2975 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10636 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 749:
#line 2983 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
					}
#line 10649 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 750:
#line 2991 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10662 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 751:
#line 2999 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10675 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 752:
#line 3007 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10688 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 753:
#line 3015 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10694 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 754:
#line 3016 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0;
									yyerror("bad forward_tls argument"); }
#line 10701 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 755:
#line 3018 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10714 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 756:
#line 3026 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10727 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 757:
#line 3034 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10740 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 758:
#line 3042 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10754 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 759:
#line 3051 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10768 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 760:
#line 3060 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
					}
#line 10782 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 761:
#line 3069 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10795 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 762:
#line 3077 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10809 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 763:
#line 3086 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10822 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 764:
#line 3094 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10828 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 765:
#line 3095 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0;
									yyerror("bad forward_sctp argument"); }
#line 10835 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 766:
#line 3097 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(LOG_T, 2, NUMBER_ST,
										(void*)(L_DBG+1), STRING_ST, (yyvsp[-1].strval));
									set_cfg_pos((yyval.action)); }
#line 10843 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 767:
#line 3100 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(LOG_T, 2, NUMBER_ST, (void*)(yyvsp[-3].intval), STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 10849 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 768:
#line 3101 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10855 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 769:
#line 3102 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad log argument"); }
#line 10861 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 770:
#line 3103 "core/cfg.y" /* yacc.c:1646  */
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(SETFLAG_T, 1, NUMBER_ST,
													(void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 10873 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 771:
#line 3110 "core/cfg.y" /* yacc.c:1646  */
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(SETFLAG_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 10885 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 772:
#line 3117 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 10891 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 773:
#line 3118 "core/cfg.y" /* yacc.c:1646  */
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(RESETFLAG_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 10902 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 774:
#line 3124 "core/cfg.y" /* yacc.c:1646  */
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(RESETFLAG_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 10914 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 775:
#line 3131 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 10920 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 776:
#line 3132 "core/cfg.y" /* yacc.c:1646  */
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(ISFLAGSET_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 10931 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 777:
#line 3138 "core/cfg.y" /* yacc.c:1646  */
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(ISFLAGSET_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 10943 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 778:
#line 3145 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 10949 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 779:
#line 3146 "core/cfg.y" /* yacc.c:1646  */
    {
		i_tmp=get_avpflag_no((yyvsp[-1].strval));
		if (i_tmp==0) yyerror("avpflag not declared");
		(yyval.action)=mk_action(AVPFLAG_OPER_T, 3, AVP_ST, (yyvsp[-3].attr), NUMBER_ST, (void*)(long)i_tmp, NUMBER_ST, (void*)(yyvsp[-5].intval));
		set_cfg_pos((yyval.action));
	}
#line 10960 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 780:
#line 3152 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0; yyerror("error parsing flag name");
	}
#line 10968 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 781:
#line 3155 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0; yyerror("error parsing first parameter (avp or string)");
	}
#line 10976 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 782:
#line 3158 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad parameters"); }
#line 10982 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 783:
#line 3159 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 10988 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 784:
#line 3160 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(ERROR_T, 2, STRING_ST, (yyvsp[-3].strval), STRING_ST, (yyvsp[-1].strval));
			set_cfg_pos((yyval.action));
	}
#line 10996 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 785:
#line 3163 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11002 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 786:
#line 3164 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad error argument"); }
#line 11008 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 787:
#line 3165 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].rv_expr)) {
			(yyval.action) = mk_action(ROUTE_T, 1, RVE_ST, (void*)(yyvsp[-1].rv_expr));
			set_cfg_pos((yyval.action));
		} else {
			(yyval.action) = 0;
			YYERROR;
		}
	}
#line 11022 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 788:
#line 3174 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].strval)) {
			(yyval.action) = mk_action(ROUTE_T, 1, STRING_ST, (void*)(yyvsp[-1].strval));
			set_cfg_pos((yyval.action));
		} else {
			(yyval.action) = 0;
			YYERROR;
		}
	}
#line 11036 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 789:
#line 3183 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11042 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 790:
#line 3184 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad route argument"); }
#line 11048 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 791:
#line 3185 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(EXEC_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11054 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 792:
#line 3186 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_HOST_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11060 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 793:
#line 3187 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11066 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 794:
#line 3188 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11072 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 795:
#line 3189 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(PREFIX_T, 1, STRING_ST,  (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11078 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 796:
#line 3190 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11084 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 797:
#line 3191 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11090 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 798:
#line 3192 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(STRIP_TAIL_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11096 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 799:
#line 3193 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11102 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 800:
#line 3194 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11108 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 801:
#line 3195 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(STRIP_T, 1, NUMBER_ST, (void*) (yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11114 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 802:
#line 3196 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11120 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 803:
#line 3197 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11126 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 804:
#line 3198 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_USERPHONE_T, 0); set_cfg_pos((yyval.action)); }
#line 11132 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 805:
#line 3199 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11138 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 806:
#line 3200 "core/cfg.y" /* yacc.c:1646  */
    {
			(yyval.action)=mk_action(REMOVE_BRANCH_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
			set_cfg_pos((yyval.action));
	}
#line 11147 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 807:
#line 3204 "core/cfg.y" /* yacc.c:1646  */
    {
			(yyval.action)=mk_action(REMOVE_BRANCH_T, 0);
			set_cfg_pos((yyval.action));
	}
#line 11156 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 808:
#line 3208 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11162 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 809:
#line 3209 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11168 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 810:
#line 3210 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(CLEAR_BRANCHES_T, 0); set_cfg_pos((yyval.action)); }
#line 11174 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 811:
#line 3211 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_HOSTPORT_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11180 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 812:
#line 3212 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11186 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 813:
#line 3213 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11192 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 814:
#line 3214 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_HOSTPORTTRANS_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11198 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 815:
#line 3215 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11204 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 816:
#line 3216 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11210 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 817:
#line 3217 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_PORT_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11216 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 818:
#line 3218 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11222 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 819:
#line 3219 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11228 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 820:
#line 3220 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_USER_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11234 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 821:
#line 3221 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11240 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 822:
#line 3222 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11246 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 823:
#line 3223 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_USERPASS_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11252 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 824:
#line 3224 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11258 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 825:
#line 3225 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11264 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 826:
#line 3226 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(SET_URI_T, 1, STRING_ST,(yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11270 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 827:
#line 3227 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11276 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 828:
#line 3228 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11282 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 829:
#line 3229 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(REVERT_URI_T, 0); set_cfg_pos((yyval.action)); }
#line 11288 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 830:
#line 3230 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(REVERT_URI_T, 0); set_cfg_pos((yyval.action)); }
#line 11294 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 831:
#line 3231 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(FORCE_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11300 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 832:
#line 3232 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(FORCE_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11306 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 833:
#line 3233 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(ADD_LOCAL_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11312 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 834:
#line 3234 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=mk_action(ADD_LOCAL_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11318 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 835:
#line 3235 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11331 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 836:
#line 3243 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 0);
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11344 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 837:
#line 3251 "core/cfg.y" /* yacc.c:1646  */
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 0);
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11357 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 838:
#line 3259 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11363 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 839:
#line 3261 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=mk_action(UDP_MTU_TRY_PROTO_T, 1, NUMBER_ST, (yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11369 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 840:
#line 3263 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, UDP, TCP, TLS or SCTP expected"); }
#line 11375 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 841:
#line 3264 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0;
		if ((str_tmp=pkg_malloc(sizeof(str)))==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
		} else {
			str_tmp->s=(yyvsp[-1].strval);
			str_tmp->len=(yyvsp[-1].strval)?strlen((yyvsp[-1].strval)):0;
			(yyval.action)=mk_action(SET_ADV_ADDR_T, 1, STR_ST, str_tmp);
			set_cfg_pos((yyval.action));
		}
	}
#line 11391 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 842:
#line 3275 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11397 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 843:
#line 3276 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11403 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 844:
#line 3277 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0;
		tmp=int2str((yyvsp[-1].intval), &i_tmp);
		if ((str_tmp=pkg_malloc(sizeof(str)))==0) {
			LM_CRIT("cfg. parser: out of memory.\n");
		} else {
			if ((str_tmp->s=pkg_malloc(i_tmp))==0) {
				LM_CRIT("cfg. parser: out of memory.\n");
			} else {
				memcpy(str_tmp->s, tmp, i_tmp);
				str_tmp->len=i_tmp;
				(yyval.action)=mk_action(SET_ADV_PORT_T, 1, STR_ST, str_tmp);
				set_cfg_pos((yyval.action));
			}
		}
	}
#line 11424 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 845:
#line 3293 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11430 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 846:
#line 3294 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11436 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 847:
#line 3295 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(FORCE_SEND_SOCKET_T, 1, SOCKID_ST, (yyvsp[-1].sockid));
		set_cfg_pos((yyval.action));
	}
#line 11445 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 848:
#line 3299 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=0; yyerror("bad argument, [proto:]host[:port] expected");
	}
#line 11453 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 849:
#line 3302 "core/cfg.y" /* yacc.c:1646  */
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11459 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 850:
#line 3303 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_FWD_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11467 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 851:
#line 3306 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_FWD_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11475 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 852:
#line 3309 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_RPL_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11483 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 853:
#line 3312 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_RPL_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11491 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 854:
#line 3315 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_FWD_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11499 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 855:
#line 3318 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_FWD_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11507 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 856:
#line 3321 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_RPL_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11515 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 857:
#line 3324 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(SET_RPL_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11523 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 858:
#line 3327 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(CFG_SELECT_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
	}
#line 11531 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 859:
#line 3330 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(CFG_SELECT_T, 2, STRING_ST, (yyvsp[-3].strval), RVE_ST, (yyvsp[-1].rv_expr)); set_cfg_pos((yyval.action));
	}
#line 11539 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 860:
#line 3333 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11545 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 861:
#line 3334 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad arguments, string and number expected"); }
#line 11551 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 862:
#line 3335 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(CFG_RESET_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action));
	}
#line 11559 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 863:
#line 3338 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11565 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 864:
#line 3339 "core/cfg.y" /* yacc.c:1646  */
    { (yyval.action)=0; yyerror("bad arguments, string expected"); }
#line 11571 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 865:
#line 3340 "core/cfg.y" /* yacc.c:1646  */
    {mod_func_action = mk_action(MODULE0_T, 2, MODEXP_ST, NULL, NUMBER_ST,
			0); }
#line 11578 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 866:
#line 3341 "core/cfg.y" /* yacc.c:1646  */
    {
		mod_func_action->val[0].u.data =
			find_export_record((yyvsp[-4].strval), mod_func_action->val[1].u.number, rt,
								&u_tmp);
		if (mod_func_action->val[0].u.data == 0) {
			if (find_export_record((yyvsp[-4].strval), mod_func_action->val[1].u.number, 0,
									&u_tmp) ) {
					LM_ERR("misused command %s\n", (yyvsp[-4].strval));
					yyerror("Command cannot be used in the block\n");
			} else {
				LM_ERR("cfg. parser: failed to find command %s (params %ld)\n",
						(yyvsp[-4].strval), mod_func_action->val[1].u.number);
				yyerror("unknown command, missing loadmodule?\n");
			}
			free_mod_func_action(mod_func_action);
			mod_func_action=0;
		}else{
			if (mod_func_action && mod_f_params_pre_fixup(mod_func_action)<0) {
				/* error messages are printed inside the function */
				free_mod_func_action(mod_func_action);
				mod_func_action = 0;
				YYERROR;
			}
		}
		(yyval.action) = mod_func_action;
		set_cfg_pos((yyval.action));
	}
#line 11610 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 867:
#line 3368 "core/cfg.y" /* yacc.c:1646  */
    { yyerror("'('')' expected (function call)");}
#line 11616 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 869:
#line 3372 "core/cfg.y" /* yacc.c:1646  */
    { }
#line 11622 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 870:
#line 3373 "core/cfg.y" /* yacc.c:1646  */
    {}
#line 11628 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 871:
#line 3376 "core/cfg.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].rv_expr) && mod_func_action->val[1].u.number < MAX_ACTIONS-2) {
			mod_func_action->val[mod_func_action->val[1].u.number+2].type =
				RVE_ST;
			mod_func_action->val[mod_func_action->val[1].u.number+2].u.data =
				(yyvsp[0].rv_expr);
			mod_func_action->val[1].u.number++;
		} else if ((yyvsp[0].rv_expr)) {
			yyerror("Too many arguments\n");
			YYERROR;
		} else {
			YYERROR;
		}
	}
#line 11647 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 872:
#line 3393 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11656 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 873:
#line 3397 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11665 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 874:
#line 3401 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11674 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 875:
#line 3405 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11684 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 876:
#line 3410 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST, (void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11693 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 877:
#line 3414 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11703 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 878:
#line 3419 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)RETURN_R_F); set_cfg_pos((yyval.action));
	}
#line 11712 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 879:
#line 3423 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)RETURN_R_F); set_cfg_pos((yyval.action));
	}
#line 11721 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 880:
#line 3427 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST, (void*)RETURN_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11730 "core/cfg.tab.c" /* yacc.c:1646  */
    break;

  case 881:
#line 3431 "core/cfg.y" /* yacc.c:1646  */
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST, (void*)BREAK_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11739 "core/cfg.tab.c" /* yacc.c:1646  */
    break;


#line 11743 "core/cfg.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 3437 "core/cfg.y" /* yacc.c:1906  */


static void get_cpos(struct cfg_pos* pos)
{
	pos->s_line=startline;
	pos->e_line=line;
	pos->s_col=startcolumn;
	pos->e_col=column-1;
	if(finame==0)
		finame = (cfg_file!=0)?cfg_file:"default";
	pos->fname=finame;
	pos->rname=(routename!=0)?routename:default_routename;
}


static void warn_at(struct cfg_pos* p, char* format, ...)
{
	va_list ap;
	char s[256];

	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	if (p->e_line!=p->s_line)
		LM_WARN("warning in config file %s, from line %d, column %d to"
					" line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_line, p->e_col, s);
	else if (p->s_col!=p->e_col)
		LM_WARN("warning in config file %s, line %d, column %d-%d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_col, s);
	else
		LM_WARN("warning in config file %s, line %d, column %d: %s\n",
				p->fname, p->s_line, p->s_col, s);
	cfg_warnings++;
}



static void yyerror_at(struct cfg_pos* p, char* format, ...)
{
	va_list ap;
	char s[256];

	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	if (p->e_line!=p->s_line)
		LM_CRIT("parse error in config file %s, from line %d, column %d"
					" to line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_line, p->e_col, s);
	else if (p->s_col!=p->e_col)
		LM_CRIT("parse error in config file %s, line %d, column %d-%d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_col, s);
	else
		LM_CRIT("parse error in config file %s, line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, s);
	cfg_errors++;
}



static void warn(char* format, ...)
{
	va_list ap;
	char s[256];
	struct cfg_pos pos;

	get_cpos(&pos);
	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	warn_at(&pos, s);
}



static void yyerror(char* format, ...)
{
	va_list ap;
	char s[256];
	struct cfg_pos pos;

	get_cpos(&pos);
	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	yyerror_at(&pos, s);
}



/** mk_rval_expr_v wrapper.
 *  checks mk_rval_expr_v return value and sets the cfg. pos
 *  (line and column numbers)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr_v)
 */
static struct rval_expr* mk_rve_rval(enum rval_type type, void* v)
{
	struct rval_expr* ret;
	struct cfg_pos pos;

	get_cpos(&pos);
	ret=mk_rval_expr_v(type, v, &pos);
	if (ret==0){
		yyerror("internal error: failed to create rval expr");
		/* YYABORT; */
	}
	return ret;
}


/** mk_rval_expr1 wrapper.
 *  checks mk_rval_expr1 return value (!=0 and type checking)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr1)
 */
static struct rval_expr* mk_rve1(enum rval_expr_op op, struct rval_expr* rve1)
{
	struct rval_expr* ret;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;

	if (rve1==0)
		return 0;
	ret=mk_rval_expr1(op, rve1, &rve1->fpos);
	if (ret && (rve_check_type(&type, ret, &bad_rve, &bad_t, &exp_t)!=1)){
		yyerror_at(&rve1->fpos, "bad expression: type mismatch"
					" (%s instead of %s)", rval_type_name(bad_t),
					rval_type_name(exp_t));
		rve_destroy(ret);
		ret=0;
	}
	return ret;
}


/** mk_rval_expr2 wrapper.
 *  checks mk_rval_expr2 return value (!=0 and type checking)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr2)
 */
static struct rval_expr* mk_rve2(enum rval_expr_op op, struct rval_expr* rve1,
									struct rval_expr* rve2)
{
	struct rval_expr* ret;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;
	struct cfg_pos pos;

	if ((rve1==0) || (rve2==0))
		return 0;
	bad_rve=0;
	bad_t=0;
	exp_t=0;
	cfg_pos_join(&pos, &rve1->fpos, &rve2->fpos);
	ret=mk_rval_expr2(op, rve1, rve2, &pos);
	if (ret && (rve_check_type(&type, ret, &bad_rve, &bad_t, &exp_t)!=1)){
		if (bad_rve)
			yyerror_at(&pos, "bad expression: type mismatch:"
						" %s instead of %s at (%d,%d)",
						rval_type_name(bad_t), rval_type_name(exp_t),
						bad_rve->fpos.s_line, bad_rve->fpos.s_col);
		else
			yyerror("BUG: unexpected null \"bad\" expression\n");
		rve_destroy(ret);
		ret=0;
	}
	return ret;
}


/** check if the expression is an int.
 * if the expression does not evaluate to an int return -1 and
 * log an error.
 * @return 0 success, no warnings; 1 success but warnings; -1 on error */
static int rval_expr_int_check(struct rval_expr *rve)
{
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;

	if (rve==0){
		yyerror("invalid expression");
		return -1;
	}else if (!rve_check_type(&type, rve, &bad_rve, &bad_t ,&exp_t)){
		if (bad_rve)
			yyerror_at(&rve->fpos, "bad expression: type mismatch:"
						" %s instead of %s at (%d,%d)",
						rval_type_name(bad_t), rval_type_name(exp_t),
						bad_rve->fpos.s_line, bad_rve->fpos.s_col);
		else
			yyerror("BUG: unexpected null \"bad\" expression\n");
		return -1;
	}else if (type!=RV_INT && type!=RV_NONE){
		warn_at(&rve->fpos, "non-int expression (you might want to use"
				" casts)\n");
		return 1;
	}
	return 0;
}


/** warn if the expression is constant.
 * @return 0 on success (no warning), 1 when warning */
static int warn_ct_rve(struct rval_expr *rve, char* name)
{
	if (rve && rve_is_constant(rve)){
		warn_at(&rve->fpos, "constant value in %s%s",
				name?name:"expression", name?"(...)":"");
		return 1;
	}
	return 0;
}


static struct name_lst* mk_name_lst(char* host, int flags)
{
	struct name_lst* l;
	if (host==0) return 0;
	l=pkg_malloc(sizeof(struct name_lst));
	if (l==0) {
		LM_CRIT("cfg. parser: out of memory.\n");
	} else {
		l->name=host;
		l->flags=flags;
		l->next=0;
	}
	return l;
}


static struct socket_id* mk_listen_id(char* host, int proto, int port)
{
	struct socket_id* l;
	if (host==0) return 0;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0) {
		LM_CRIT("cfg. parser: out of memory.\n");
	} else {
		l->addr_lst=mk_name_lst(host, 0);
		if (l->addr_lst==0){
			pkg_free(l);
			return 0;
		}
		l->flags=0;
		l->port=port;
		l->proto=proto;
		l->next=0;
	}
	return l;
}


static void free_name_lst(struct name_lst* lst)
{
	struct name_lst* tmp;

	while(lst){
		tmp=lst;
		lst=lst->next;
		pkg_free(tmp);
	}
}


static struct socket_id* mk_listen_id2(struct name_lst* addr_l, int proto,
										int port)
{
	struct socket_id* l;
	if (addr_l==0) return 0;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0) {
		LM_CRIT("cfg. parser: out of memory.\n");
	} else {
		l->flags=addr_l->flags;
		l->port=port;
		l->proto=proto;
		l->addr_lst=addr_l;
		l->next=0;
	}
	return l;
}


static void free_socket_id(struct socket_id* i)
{
	free_name_lst(i->addr_lst);
	pkg_free(i);
}


static void free_socket_id_lst(struct socket_id* lst)
{
	struct socket_id* tmp;

	while(lst){
		tmp=lst;
		lst=lst->next;
		free_socket_id(tmp);
	}
}


/** create a temporary case statmenet structure.
 *  *err will be filled in case of error (return == 0):
 *   -1 - non constant expression
 *   -2 - expression error (bad type)
 *   -10 - memory allocation error
 */
static struct case_stms* mk_case_stm(struct rval_expr* ct, int is_re,
											struct action* a, int* err)
{
	struct case_stms* s;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;
	enum match_str_type t;

	t=MATCH_UNKNOWN;
	if (ct){
		/* if ct!=0 => case, else if ct==0 is a default */
		if (!rve_is_constant(ct)){
			yyerror_at(&ct->fpos, "non constant expression in case");
			*err=-1;
			return 0;
		}
		if (rve_check_type(&type, ct, &bad_rve, &bad_t, &exp_t)!=1){
			yyerror_at(&ct->fpos, "bad expression: type mismatch:"
							" %s instead of %s at (%d,%d)",
							rval_type_name(bad_t), rval_type_name(exp_t),
							bad_rve->fpos.s_line, bad_rve->fpos.s_col);
			*err=-2;
			return 0;
		}
		if (is_re)
			t=MATCH_RE;
		else if (type==RV_STR)
			t=MATCH_STR;
		else
			t=MATCH_INT;
	}

	s=pkg_malloc(sizeof(*s));
	if (s==0) {
		yyerror("internal error: memory allocation failure");
		*err=-10;
	} else {
		memset(s, 0, sizeof(*s));
		s->ct_rve=ct;
		s->type=t;
		s->actions=a;
		s->next=0;
		s->append=0;
	}
	return s;
}


/*
 * @return 0 on success, -1 on error.
 */
static int case_check_type(struct case_stms* stms)
{
	struct case_stms* c;
	struct case_stms* s;

	for(c=stms; c ; c=c->next){
		if (!c->ct_rve) continue;
		for (s=c->next; s; s=s->next){
			if (!s->ct_rve) continue;
			if ((s->type!=c->type) &&
				!(	(c->type==MATCH_STR || c->type==MATCH_RE) &&
					(s->type==MATCH_STR || s->type==MATCH_RE) ) ){
					yyerror_at(&s->ct_rve->fpos, "type mismatch in case");
					return -1;
			}
		}
	}
	return 0;
}


/*
 * @return 0 on success, -1 on error.
 */
static int case_check_default(struct case_stms* stms)
{
	struct case_stms* c;
	int default_no;

	default_no=0;
	for(c=stms; c ; c=c->next)
		if (c->ct_rve==0) default_no++;
	return (default_no<=1)?0:-1;
}



/** fixes the parameters and the type of a module function call.
 * It is done here instead of fix action, to have quicker feedback
 * on error cases (e.g. passing a non constant to a function with a
 * declared fixup)
 * The rest of the fixup is done inside do_action().
 * @param a - filled module function call (MODULE*_T) action structure
 *            complete with parameters, starting at val[2] and parameter
 *            number at val[1].
 * @return 0 on success, -1 on error (it will also print the error msg.).
 *
 */
static int mod_f_params_pre_fixup(struct action* a)
{
	sr31_cmd_export_t* cmd_exp;
	action_u_t* params;
	int param_no;
	struct rval_expr* rve;
	struct rvalue* rv;
	int r;
	str s;

	cmd_exp = a->val[0].u.data;
	param_no = a->val[1].u.number;
	params = &a->val[2];

	switch(cmd_exp->param_no) {
		case 0:
			a->type = MODULE0_T;
			break;
		case 1:
			a->type = MODULE1_T;
			break;
		case 2:
			a->type = MODULE2_T;
			break;
		case 3:
			a->type = MODULE3_T;
			break;
		case 4:
			a->type = MODULE4_T;
			break;
		case 5:
			a->type = MODULE5_T;
			break;
		case 6:
			a->type = MODULE6_T;
			break;
		case VAR_PARAM_NO:
			a->type = MODULEX_T;
			break;
		default:
			yyerror("function %s: bad definition"
					" (invalid number of parameters)", cmd_exp->name);
			return -1;
	}

	if ( cmd_exp->fixup) {
		if (is_fparam_rve_fixup(cmd_exp->fixup))
			/* mark known fparam rve safe fixups */
			cmd_exp->fixup_flags  |= FIXUP_F_FPARAM_RVE;
		else if (!(cmd_exp->fixup_flags & FIXUP_F_FPARAM_RVE) &&
				 cmd_exp->free_fixup == 0) {
			/* v0 or v1 functions that have fixups and no coresp. fixup_free
			   functions, need constant, string params.*/
			for (r=0; r < param_no; r++) {
				rve=params[r].u.data;
				if (!rve_is_constant(rve)) {
					yyerror_at(&rve->fpos, "function %s: parameter %d is not"
								" constant\n", cmd_exp->name, r+1);
					return -1;
				}
				if ((rv = rval_expr_eval(0, 0, rve)) == 0 ||
						rval_get_str(0, 0, &s, rv, 0) < 0 ) {
					/* out of mem or bug ? */
					rval_destroy(rv);
					yyerror_at(&rve->fpos, "function %s: bad parameter %d"
									" expression\n", cmd_exp->name, r+1);
					return -1;
				}
				rval_destroy(rv);
				rve_destroy(rve);
				params[r].type = STRING_ST; /* asciiz */
				params[r].u.string = s.s;
				params[r].u.str.len = s.len; /* not used right now */
			}
		}
	}/* else
		if no fixups are present, the RVEs can be transformed
		into strings at runtime, allowing seamless var. use
		even with old functions.
		Further optimizations -> in fix_actions()
		*/
	return 0;
}



/** frees a filled module function call action structure.
 * @param a - filled module function call action structure
 *            complete with parameters, starting at val[2] and parameter
 *            number at val[1].
 */
static void free_mod_func_action(struct action* a)
{
	action_u_t* params;
	int param_no;
	int r;

	param_no = a->val[1].u.number;
	params = &a->val[2];

	for (r=0; r < param_no; r++)
		if (params[r].u.data)
			rve_destroy(params[r].u.data);
	pkg_free(a);
}



/*
int main(int argc, char ** argv)
{
	if (yyparse()!=0)
		fprintf(stderr, "parsing error\n");
}
*/
