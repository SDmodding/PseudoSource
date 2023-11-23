// File Line: 21
// RVA: 0xA39960
signed __int64 UFG::qAssertHandlerPlat(
        const char *condition,
        const char *file,
        __int64 line,
        bool *ignoreAlways,
        const char *msg,
        ...)
{
  char dest[2056]; // [rsp+20h] [rbp-808h] BYREF
  va_list va; // [rsp+858h] [rbp+30h] BYREF

  va_start(va, msg);
  UFG::qPrintf(
    "\n"
    "\n"
    "*********************************\n"
    "********** ASSERT FAIL **********\n"
    "*********************************\n"
    "%s(%d):\n"
    "CONDITION = %s\n",
    file,
    line,
    condition);
  if ( msg )
  {
    dest[0] = 0;
    UFG::qVSPrintf(dest, 2048, msg, va);
  }
  return 1i64;
}

