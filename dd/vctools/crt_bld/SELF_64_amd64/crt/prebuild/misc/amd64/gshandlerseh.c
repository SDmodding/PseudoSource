// File Line: 70
// RVA: 0x12D7354
__int64 __fastcall _GSHandlerCheck_SEH(
        _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        _CONTEXT *ContextRecord,
        _DISPATCHER_CONTEXT *DispatcherContext)
{
  char *v8; // rbx
  int v9; // r11d
  unsigned int v10; // edx

  v8 = (char *)DispatcherContext->HandlerData + 16 * *(unsigned int *)DispatcherContext->HandlerData;
  _GSHandlerCheckCommon(EstablisherFrame, DispatcherContext, (_GS_HANDLER_DATA *)(v8 + 4));
  v9 = *((_DWORD *)v8 + 1) & 2;
  v10 = 1;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) == 0 )
    v9 = *((_DWORD *)v8 + 1) & 1;
  if ( v9 )
    return (unsigned int)_C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
  return v10;
}

