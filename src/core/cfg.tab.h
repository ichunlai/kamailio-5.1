/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 199 "core/cfg.y" /* yacc.c:1909  */

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

#line 414 "core/cfg.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CORE_CFG_TAB_H_INCLUDED  */
