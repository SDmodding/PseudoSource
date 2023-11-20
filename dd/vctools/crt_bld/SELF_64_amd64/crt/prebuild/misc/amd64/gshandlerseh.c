// File Line: 70
// RVA: 0x12D7354
__int64 __fastcall _GSHandlerCheck_SEH(_EXCEPTION_RECORD *ExceptionRecord, void *EstablisherFrame, _CONTEXT *ContextRecord, _DISPATCHER_CONTEXT *DispatcherContext)
{
  void *v4; // rsi
  _CONTEXT *v5; // r14
  _EXCEPTION_RECORD *v6; // rbp
  _DISPATCHER_CONTEXT *v7; // rdi
  char *v8; // rbx
  int v9; // er11
  unsigned int v10; // edx

  v4 = EstablisherFrame;
  v5 = ContextRecord;
  v6 = ExceptionRecord;
  v7 = DispatcherContext;
  v8 = (char *)DispatcherContext->HandlerData + 16 * *(unsigned int *)DispatcherContext->HandlerData;
  _GSHandlerCheckCommon(EstablisherFrame, DispatcherContext, (_GS_HANDLER_DATA *)(v8 + 4));
  v9 = *((_DWORD *)v8 + 1) & 2;
  v10 = 1;
  if ( !(v6->ExceptionFlags & 0x66) )
    v9 = *((_DWORD *)v8 + 1) & 1;
  if ( v9 )
    v10 = _C_specific_handler(v6, v4, v5, v7);
  return v10;
}

