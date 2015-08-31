/*
   nicole cranon <nicole.cranon@ucdenver.edu>
   csci 4640, fall 2015
   assignment 1 - micro scanner
 */

#ifndef _SCANNER
#define _SCANNER

#include <string>
#include <fstream>

namespace scanner {
  // define type token which is returned by function scanner
  typedef enum {

    BeginSym,
    EndSym,
    ReadSym,
    WriteSym,
    Id,
    IntLiteral,
    LParen,
    RParen,
    SemiColon,
    Comma,
    AssignOp,
    ExpOp,
    PlusOp,
    MinusOp,
    EqualOp,
    EofSym

  } token;

  // for use in printing the token type
  extern std::string token_type[]; 

  // holds the token strings built
  extern std::string tokenBuffer;

  // file stream buffer
  extern std::ifstream file;

  /*
     scan

     precondition -
     an existing file

     postcondition -
     produces a token
   */
  token scan ();

  /*
     checkReserved

     precondition -
     a string to check for reserved words

     postcondition -
     returns either an Id token or a terminal symbol
   */
  token checkReserved (const std::string& checkString);

  /*
     read

     precondition -  
     an existing file stream buffer

     postcondition -
     returns the next char from the stream and advances the input stream is advanced to the
     the next char
   */
  char read ();

  /*
     inspect

     precondition -
     an existing file stream buffer

     postcondition -
     returns the next char is returned, but the input stream is not advanced
   */
  char inspect ();

  /*
     advance

     precondition -
     an existing file stream buffer

     postcondition -
     the next input character is removed from the input stream, but not returned
   */
  void advance ();

  /*
     clearBuffer

     precondition -
     tokenBuffer exists

     postcondition -
     assigns the empty string to the tokenBuffer
   */
  void clearBuffer ();

  /*
     bufferChar

     precondition -
     tokenBuffer exists, and the character to append to the buffer

     postcondition -
     appends the provided character to the tokenBuffer
   */
  void bufferChar (const char& c);

}

#endif
