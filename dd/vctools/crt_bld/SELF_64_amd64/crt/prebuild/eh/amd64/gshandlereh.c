// File Line: 66
// RVA: 0x12BBDC4
__int64 __fastcall _GSHandlerCheck_EH(_EXCEPTION_RECORD *ExceptionRecord, void *EstablisherFrame, _CONTEXT *ContextRecord, _DISPATCHER_CONTEXT *DispatcherContext)
{
  char *v4; // rbx
  void *v5; // rsi
  _CONTEXT *v6; // r14
  EHExceptionRecord *v7; // rbp
  _DISPATCHER_CONTEXT *v8; // rdi
  int v9; // er11
  _EXCEPTION_DISPOSITION v10; // er8

  v4 = (char *)DispatcherContext->HandlerData;
  v5 = EstablisherFrame;
  v6 = ContextRecord;
  v7 = (EHExceptionRecord *)ExceptionRecord;
  v8 = DispatcherContext;
  _GSHandlerCheckCommon(EstablisherFrame, DispatcherContext, (_GS_HANDLER_DATA *)(v4 + 4));
  v9 = *((_DWORD *)v4 + 1) & 2;
  v10 = 1;
  if ( !(v7->ExceptionFlags & 0x66) )
    v9 = *((_DWORD *)v4 + 1) & 1;
  if ( v9 )
    v10 = _CxxFrameHandler3(v7, (unsigned __int64)v5, v6, (_xDISPATCHER_CONTEXT *)v8);
  return (unsigned int)v10;
}

