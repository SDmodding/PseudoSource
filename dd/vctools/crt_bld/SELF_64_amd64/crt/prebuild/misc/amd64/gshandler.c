// File Line: 78
// RVA: 0x12BB49C
signed __int64 __fastcall _GSHandlerCheck(_EXCEPTION_RECORD *ExceptionRecord, void *EstablisherFrame, _CONTEXT *ContextRecord, _DISPATCHER_CONTEXT *DispatcherContext)
{
  _GSHandlerCheckCommon(EstablisherFrame, DispatcherContext, (_GS_HANDLER_DATA *)DispatcherContext->HandlerData);
  return 1i64;
}

// File Line: 129
// RVA: 0x12BB4BC
void __fastcall _GSHandlerCheckCommon(void *EstablisherFrame, _DISPATCHER_CONTEXT *DispatcherContext, _GS_HANDLER_DATA *GSHandlerData)
{
  unsigned __int64 v3; // r9
  unsigned __int64 v4; // r10
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r9

  v3 = (unsigned __int64)EstablisherFrame;
  v4 = (unsigned __int64)EstablisherFrame;
  if ( *(_BYTE *)&GSHandlerData->u.Bits & 4 )
    v4 = -GSHandlerData->Alignment & ((unsigned __int64)EstablisherFrame + GSHandlerData->AlignedBaseOffset);
  v5 = DispatcherContext->ImageBase + DispatcherContext->FunctionEntry->UnwindInfoAddress;
  if ( *(_BYTE *)(v5 + 3) & 0xF )
    v3 += (unsigned __int8)(*(_BYTE *)(v5 + 3) & 0xF0);
  v6 = *(_QWORD *)((signed int)(GSHandlerData->u.CookieOffset & 0xFFFFFFF8) + v4) ^ v3;
}

