// File Line: 99
// RVA: 0x12B3210
__int64 __fastcall _C_specific_handler(
        _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        _CONTEXT *ContextRecord,
        _DISPATCHER_CONTEXT *DispatcherContext)
{
  unsigned __int64 ImageBase; // r12
  unsigned int *HandlerData; // rbx
  unsigned __int64 v6; // r15
  unsigned int v10; // esi
  int v11; // eax
  unsigned int ScopeIndex; // edi
  unsigned __int64 v14; // rsi
  __int64 v15; // rcx
  unsigned int v16; // r9d
  unsigned int *v17; // r8
  __int64 v18; // rax
  unsigned int v19; // edx
  _QWORD v20[2]; // [rsp+30h] [rbp-38h] BYREF

  ImageBase = DispatcherContext->ImageBase;
  HandlerData = (unsigned int *)DispatcherContext->HandlerData;
  v6 = DispatcherContext->ControlPc - ImageBase;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
  {
    ScopeIndex = DispatcherContext->ScopeIndex;
    v14 = DispatcherContext->TargetIp - ImageBase;
    while ( 1 )
    {
      v19 = *HandlerData;
      if ( ScopeIndex >= *HandlerData )
        break;
      v15 = 2i64 * ScopeIndex;
      if ( v6 >= HandlerData[4 * ScopeIndex + 1] && v6 < HandlerData[4 * ScopeIndex + 2] )
      {
        if ( (ExceptionRecord->ExceptionFlags & 0x20) != 0 )
        {
          v16 = 0;
          if ( v19 )
          {
            v17 = HandlerData + 2;
            do
            {
              if ( v14 >= *(v17 - 1)
                && v14 < *v17
                && v17[2] == HandlerData[4 * ScopeIndex + 4]
                && v17[1] == HandlerData[4 * ScopeIndex + 3] )
              {
                break;
              }
              ++v16;
              v17 += 4;
            }
            while ( v16 < v19 );
          }
          if ( v16 != v19 )
            return 1i64;
        }
        v18 = HandlerData[4 * ScopeIndex + 4];
        if ( (_DWORD)v18 )
        {
          if ( v14 == v18 )
            return 1i64;
        }
        else
        {
          DispatcherContext->ScopeIndex = ScopeIndex + 1;
          LOBYTE(v15) = 1;
          ((void (__fastcall *)(__int64, void *))(ImageBase + HandlerData[4 * ScopeIndex + 3]))(v15, EstablisherFrame);
        }
      }
      ++ScopeIndex;
    }
  }
  else
  {
    v10 = DispatcherContext->ScopeIndex;
    v20[0] = ExceptionRecord;
    v20[1] = ContextRecord;
    while ( v10 < *HandlerData )
    {
      if ( v6 >= HandlerData[4 * v10 + 1] && v6 < HandlerData[4 * v10 + 2] && HandlerData[4 * v10 + 4] )
      {
        if ( HandlerData[4 * v10 + 3] == 1 )
          goto LABEL_11;
        v11 = ((__int64 (__fastcall *)(_QWORD *, void *))(ImageBase + HandlerData[4 * v10 + 3]))(v20, EstablisherFrame);
        if ( v11 < 0 )
          return 0i64;
        if ( v11 > 0 )
        {
LABEL_11:
          if ( ExceptionRecord->ExceptionCode == -529697949 && pDestructExceptionObject )
          {
            if ( IsNonwritableInCurrentImage((char *)&pDestructExceptionObject) )
              pDestructExceptionObject(ExceptionRecord, 1);
          }
          NLG_Notify(ImageBase + HandlerData[4 * v10 + 4], EstablisherFrame, 1i64);
          RtlUnwindEx(
            EstablisherFrame,
            (PVOID)(ImageBase + HandlerData[4 * v10 + 4]),
            ExceptionRecord,
            (PVOID)ExceptionRecord->ExceptionCode,
            DispatcherContext->ContextRecord,
            DispatcherContext->HistoryTable);
          _NLG_Return2();
        }
      }
      ++v10;
    }
  }
  return 1i64;
}

