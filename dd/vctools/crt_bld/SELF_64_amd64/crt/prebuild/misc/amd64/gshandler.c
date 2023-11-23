// File Line: 78
// RVA: 0x12BB49C
__int64 __fastcall _GSHandlerCheck(
        _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        _CONTEXT *ContextRecord,
        _DISPATCHER_CONTEXT *DispatcherContext)
{
  _GSHandlerCheckCommon(EstablisherFrame, DispatcherContext, (_GS_HANDLER_DATA *)DispatcherContext->HandlerData);
  return 1i64;
}

// File Line: 129
// RVA: 0x12BB4BC
void __fastcall _GSHandlerCheckCommon(
        void *EstablisherFrame,
        _DISPATCHER_CONTEXT *DispatcherContext,
        _GS_HANDLER_DATA *GSHandlerData)
{
  ;
}

