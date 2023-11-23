// File Line: 66
// RVA: 0x12BBDC4
__int64 __fastcall _GSHandlerCheck_EH(
        EHExceptionRecord *ExceptionRecord,
        void *EstablisherFrame,
        _CONTEXT *ContextRecord,
        _DISPATCHER_CONTEXT *DispatcherContext)
{
  char *HandlerData; // rbx
  int v9; // r11d
  unsigned int v10; // r8d

  HandlerData = (char *)DispatcherContext->HandlerData;
  _GSHandlerCheckCommon(EstablisherFrame, DispatcherContext, (_GS_HANDLER_DATA *)(HandlerData + 4));
  v9 = *((_DWORD *)HandlerData + 1) & 2;
  v10 = 1;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) == 0 )
    v9 = *((_DWORD *)HandlerData + 1) & 1;
  if ( v9 )
    return (unsigned int)_CxxFrameHandler3(
                           ExceptionRecord,
                           (unsigned __int64)EstablisherFrame,
                           ContextRecord,
                           (_xDISPATCHER_CONTEXT *)DispatcherContext);
  return v10;
}

