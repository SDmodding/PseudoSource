// File Line: 99
// RVA: 0x12B3210
signed __int64 __fastcall _C_specific_handler(_EXCEPTION_RECORD *ExceptionRecord, void *EstablisherFrame, _CONTEXT *ContextRecord, _DISPATCHER_CONTEXT *DispatcherContext)
{
  unsigned __int64 v4; // r12
  unsigned int *v5; // rbx
  unsigned __int64 v6; // r15
  _DISPATCHER_CONTEXT *v7; // r14
  void *v8; // r13
  _EXCEPTION_RECORD *v9; // rbp
  unsigned int v10; // esi
  int v11; // eax
  unsigned int v13; // edi
  unsigned __int64 v14; // rsi
  signed __int64 v15; // rcx
  unsigned int v16; // er9
  unsigned int *v17; // r8
  __int64 v18; // rax
  unsigned int v19; // edx
  _EXCEPTION_RECORD *v20; // [rsp+30h] [rbp-38h]
  _CONTEXT *v21; // [rsp+38h] [rbp-30h]

  v4 = DispatcherContext->ImageBase;
  v5 = (unsigned int *)DispatcherContext->HandlerData;
  v6 = DispatcherContext->ControlPc - v4;
  v7 = DispatcherContext;
  v8 = EstablisherFrame;
  v9 = ExceptionRecord;
  if ( ExceptionRecord->ExceptionFlags & 0x66 )
  {
    v13 = DispatcherContext->ScopeIndex;
    v14 = DispatcherContext->TargetIp - v4;
    while ( 1 )
    {
      v19 = *v5;
      if ( v13 >= *v5 )
        break;
      v15 = 2i64 * v13;
      if ( v6 >= v5[4 * v13 + 1] && v6 < v5[4 * v13 + 2] )
      {
        if ( v9->ExceptionFlags & 0x20 )
        {
          v16 = 0;
          if ( v19 )
          {
            v17 = v5 + 2;
            do
            {
              if ( v14 >= *(v17 - 1) && v14 < *v17 && v17[2] == v5[4 * v13 + 4] && v17[1] == v5[4 * v13 + 3] )
                break;
              ++v16;
              v17 += 4;
            }
            while ( v16 < v19 );
          }
          if ( v16 != v19 )
            return 1i64;
        }
        v18 = v5[4 * v13 + 4];
        if ( (_DWORD)v18 )
        {
          if ( v14 == v18 )
            return 1i64;
        }
        else
        {
          v7->ScopeIndex = v13 + 1;
          LOBYTE(v15) = 1;
          ((void (__fastcall *)(signed __int64, void *))(v4 + v5[4 * v13 + 3]))(v15, v8);
        }
      }
      ++v13;
    }
  }
  else
  {
    v10 = DispatcherContext->ScopeIndex;
    v20 = ExceptionRecord;
    v21 = ContextRecord;
    while ( v10 < *v5 )
    {
      if ( v6 >= v5[4 * v10 + 1] && v6 < v5[4 * v10 + 2] && v5[4 * v10 + 4] )
      {
        if ( v5[4 * v10 + 3] == 1 )
          goto LABEL_38;
        v11 = ((__int64 (__fastcall *)(_EXCEPTION_RECORD **, void *))(v4 + v5[4 * v10 + 3]))(&v20, v8);
        if ( v11 < 0 )
          return 0i64;
        if ( v11 > 0 )
        {
LABEL_38:
          if ( v9->ExceptionCode == -529697949 && pDestructExceptionObject )
          {
            if ( IsNonwritableInCurrentImage((char *)&pDestructExceptionObject) )
              pDestructExceptionObject(v9, 1);
          }
          NLG_Notify(v4 + v5[4 * v10 + 4], v8, 1i64);
          RtlUnwindEx(
            v8,
            (PVOID)(v4 + v5[4 * v10 + 4]),
            v9,
            (PVOID)v9->ExceptionCode,
            v7->ContextRecord,
            v7->HistoryTable);
          _NLG_Return2();
        }
      }
      ++v10;
    }
  }
  return 1i64;
}

