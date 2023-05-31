#include <stdio.h>
#include <ctype.h>
//#include <bits/stdc++.h>
//using namespace std; 


/* Global declarations */
/* Variables */
int charClass;
char lexeme [1000];
char nextChar;
int lexLen;
int nextToken;
FILE *in_fp;

/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define STRING 2
#define DB_QUOTATION 3
#define SINGLE_QUOT 4
#define UNKNOWN 99

/* Token codes */
enum Token{
INT_LIT = 10,
IDENT,
ASSIGN_OP,
ADD_OP,
SUB_OP,
MULT_OP,
DIV_OP,
EQUAL,
LEFT_PAREN,
RIGHT_PAREN,
GREAT_THAN,
LESS_THAN,
SEMI_COLON,
QUOT_LIT, 
COLON, 
HASHTAG, 
PERIOD, 
FIRST_BRAC, 
SECOND_BRAC,
FIRST_CURLY,
CLOSED_CURLY,
STRING_LIT,
COMMA,
PERCENT,
FORWARD_SLASH,
EXCLAMATION, 
OR,
AND
};

//use switch statement to print out the names of tokens
 
//logical and, or operator 
//quotation marks and curly brackets and semicolon 
//constants(nummbers)

/******************************************************/
/* main driver */
int main() 
{
    /* Open the input data file and process its contents */
    if ((in_fp = fopen("front.in", "r")) == NULL) {
        printf("ERROR - cannot open front.in \n");
    } else {
        getChar();
        do {
            lex();
        } while (nextToken != EOF);
    }

  //char *str; 
  
return 0; 
}


/*****************************************************/
/* lookup - a function to lookup operators and parentheses and return the 
 * token */
int lookup(char ch) {
    switch (ch) {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            break;
        case '=':
            addChar();
            nextToken = EQUAL;
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            break;
      
        case '>':
              addChar();
              nextToken = GREAT_THAN;
              break;
        case '<':
            addChar();
            nextToken = LESS_THAN;
            break;
        case ';':
            addChar();
            nextToken = SEMI_COLON;
            break;
         case ':':
            addChar();
            nextToken = COLON; 
            break;
         case '#':
            addChar();
            nextToken = HASHTAG; 
            break; 
        case '.':
            addChar();
            nextToken = PERIOD; 
            break; 
        case '[':
            addChar();
            nextToken = FIRST_BRAC; 
            break; 
        case ']':
            addChar();
            nextToken = SECOND_BRAC; 
            break; 
      case '{':
          addChar();
          nextToken = FIRST_CURLY;
          break;
      case '}':
        addChar();
        nextToken = CLOSED_CURLY;
        break;
      case '\"':
        addChar();
        nextToken = STRING_LIT;
        break;
      case ',':
      addChar();
      nextToken = COMMA;
      break;
    case '%':
      addChar();
      nextToken = PERCENT;
      break;
    case '\\':
      addChar();
      nextToken = FORWARD_SLASH; 
      break;
  case  '!':
      addChar();
      nextToken = EXCLAMATION;
      break; 
  case  '|':
      addChar();
      nextToken = OR;
      break; 
  case  '&':
      addChar();
      nextToken = AND;
      break; 
  case  '\'':
    addChar();
    nextToken = QUOT_LIT;
    break;
    default:
            addChar();
            nextToken = EOF;
            break;
    }
    return nextToken;
}
 char *lookupTokenName(int name){
  switch (name) {
  case INT_LIT:
    return "INTEGER"; 
    break; 
  case IDENT: 
    return "IDENTIFIER"; 
    break; 
  case ASSIGN_OP:
    return "ASSIGNMENT"; 
    break; 
  case ADD_OP:
    return "ADDITION";
    break; 
  case SUB_OP:
    return "SUBTRACTION";
    break; 
  case MULT_OP:
    return "MULTIPLICATION";
    break; 
  case DIV_OP:
    return "DIVISION";
    break;
  case EQUAL:
    return "EQUAL";
    break;
  case LEFT_PAREN:
    return "LEFT PARENTHESIS"; 
    break;
  case RIGHT_PAREN:
    return "RIGHT PARENTHESIS";
    break; 
  case GREAT_THAN:
    return "GREATER THAN"; 
    break; 
  case LESS_THAN:
    return "LESSER THAN"; 
    break; 
  case SEMI_COLON:
    return "SEMICOLON"; 
    break; 
  case COLON: 
    return "COLON"; 
    break;
  case HASHTAG:
     return "HASHTAG";
     break;
  case PERIOD:
      return "PERIOD";
      break; 
 case FIRST_BRAC:
      return "FIRST BRACKET";
      break;  
 case SECOND_BRAC:
    return "SECOND BRAKCET";
    break; 
  case FIRST_CURLY:
    return "FIRST CURLY BRACKET";
     break;
  case CLOSED_CURLY:
      return "OPEN CURLY BRACKET";
      break;
    case STRING_LIT:
      return "STRING";
      break;
  case COMMA:
    return "COMMA";
    break;
  case PERCENT:
    return "PERCENT";
    break;
  case FORWARD_SLASH:
    return "FORWARD SLASH";
    break;
  case EXCLAMATION:
    return "EXCLAMATION MARK";
    break;
  case OR:
    return "OR MARK";
    break;
  case AND:
    return "AND SIGN";
    break;
  case QUOT_LIT:
    return "SINGLE QUOTATION";
    break;
    
  default:
    return 0;  
  return 0; 
  }
}
/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar() {
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        printf("Error - lexeme is too long \n");
    }
}

/*****************************************************/
/* getChar - a function to get the next character of input and determine its 
 * character class */
void getChar() {
    if ((nextChar = getc(in_fp)) != EOF) {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
       else if(nextChar == 34){
        charClass = STRING; 
       }else if (nextChar == 39){
         charClass = SINGLE_QUOT; 
       } 
        else charClass = UNKNOWN;
    } else {
        charClass = EOF;
    }
 
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it returns a non-whitespace 
 * character */
void getNonBlank() {
    while (isspace(nextChar)) getChar();
}

/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic expressions */
int lex() {
    lexLen = 0;
    getNonBlank();

    switch (charClass) {
        /* Parse identifiers */
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;
        
        /* Parse integer literals */
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;
      case STRING: 
         addChar(); 
         getChar();
         while(charClass == LETTER || charClass == DIGIT){
            addChar(); 
         getChar(); 
          }
          nextToken = STRING_LIT; 
          break; 
      case SINGLE_QUOT:
      addChar();
      getChar();
      while(charClass == SINGLE_QUOT){
        addChar();
        getchar();
      }
      nextToken = QUOT_LIT;
      break;
//add a string here
        /* Parentheses and operators */
        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;

        /* EOF */
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    } /* End of switch */

    printf("Next token is: %s, Next lexeme is %s\n", lookupTokenName(nextToken), lexeme);
    return nextToken;
} /* End of function lex */
