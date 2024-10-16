/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    REAL = 259,                    /* REAL  */
    NAME = 260,                    /* NAME  */
    FNAME = 261,                   /* FNAME  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    FOR = 265,                     /* FOR  */
    RETURN = 266,                  /* RETURN  */
    BREAK = 267,                   /* BREAK  */
    CONTINUE = 268,                /* CONTINUE  */
    VOID = 269,                    /* VOID  */
    INT = 270,                     /* INT  */
    FLOAT = 271,                   /* FLOAT  */
    STR = 272,                     /* STR  */
    CHAR = 273,                    /* CHAR  */
    LE = 274,                      /* LE  */
    GE = 275,                      /* GE  */
    EQ = 276,                      /* EQ  */
    NE = 277,                      /* NE  */
    SHL = 278,                     /* SHL  */
    SHR = 279,                     /* SHR  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    ARROW = 282,                   /* ARROW  */
    INC = 283,                     /* INC  */
    DEC = 284,                     /* DEC  */
    ADD_ASSIGN = 285,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 286,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 287,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 288,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 289,              /* MOD_ASSIGN  */
    SHL_ASSIGN = 290,              /* SHL_ASSIGN  */
    SHR_ASSIGN = 291,              /* SHR_ASSIGN  */
    AND_ASSIGN = 292,              /* AND_ASSIGN  */
    XOR_ASSIGN = 293,              /* XOR_ASSIGN  */
    OR_ASSIGN = 294                /* OR_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 88 "parse.y"

    long long num;
    char* name;
    expr_info value;

#line 109 "parse.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
