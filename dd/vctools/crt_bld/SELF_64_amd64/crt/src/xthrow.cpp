// File Line: 7
// RVA: 0x12DD96C
void __noreturn std::_Xbad_alloc(void)
{
  std::exception pExceptionObject; // [rsp+20h] [rbp-28h]
  char *_What; // [rsp+50h] [rbp+8h]

  _What = "bad allocation";
  std::exception::exception(&pExceptionObject, (const char *const *)&_What, 1);
  pExceptionObject.vfptr = (std::exceptionVtbl *)&std::bad_alloc::`vftable;
  CxxThrowException(&pExceptionObject, &TI2_AVbad_alloc_std__);
}

// File Line: 18
// RVA: 0x12DD9B0
void __fastcall __noreturn std::_Xlength_error(const char *_Message)
{
  std::exception pExceptionObject; // [rsp+20h] [rbp-28h]
  char *_What; // [rsp+50h] [rbp+8h]

  _What = (char *)_Message;
  std::exception::exception(&pExceptionObject, (const char *const *)&_What);
  pExceptionObject.vfptr = (std::exceptionVtbl *)&std::length_error::`vftable;
  CxxThrowException(&pExceptionObject, &TI3_AVlength_error_std__);
}

// File Line: 23
// RVA: 0x12DD9E8
void __fastcall __noreturn std::_Xout_of_range(const char *_Message)
{
  std::exception pExceptionObject; // [rsp+20h] [rbp-28h]
  char *_What; // [rsp+50h] [rbp+8h]

  _What = (char *)_Message;
  std::exception::exception(&pExceptionObject, (const char *const *)&_What);
  pExceptionObject.vfptr = (std::exceptionVtbl *)&std::out_of_range::`vftable;
  CxxThrowException(&pExceptionObject, &TI3_AVout_of_range_std__);
}

