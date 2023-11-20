// File Line: 27
// RVA: 0x18ABE0
int (*__fastcall UFG::qSetAssertHandler(int (*handler)(const char *, const char *, int, bool *, const char *, ...)))(const char *, const char *, int, bool *, const char *, ...)
{
  int (*result)(const char *, const char *, int, bool *, const char *, ...); // rax

  result = UFG::qAssertFail;
  UFG::qAssertFail = handler;
  return result;
}

