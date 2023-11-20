// File Line: 76
// RVA: 0x12B0F28
void __fastcall __noreturn CxxThrowException(void *pExceptionObject, _s__ThrowInfo *pThrowInfo)
{
  _s__ThrowInfo *v2; // rbx
  PVOID v3; // rdx
  signed int v4; // eax
  ULONG_PTR Arguments; // [rsp+40h] [rbp-20h]
  void *v6; // [rsp+48h] [rbp-18h]
  _s_ThrowInfo *v7; // [rsp+50h] [rbp-10h]
  void *v8; // [rsp+58h] [rbp-8h]
  PVOID BaseOfImage; // [rsp+70h] [rbp+10h]

  v2 = pThrowInfo;
  Arguments = *(_QWORD *)&ExceptionTemplate_0.params.magicNumber;
  v6 = ExceptionTemplate_0.params.pExceptionObject;
  v7 = ExceptionTemplate_0.params.pThrowInfo;
  v8 = ExceptionTemplate_0.params.pThrowImageBase;
  if ( pThrowInfo && pThrowInfo->attributes & 0x10 )
    v2 = *(_s__ThrowInfo **)(*(_QWORD *)(*(_QWORD *)pExceptionObject - 8i64) + 48i64);
  v6 = pExceptionObject;
  v7 = (_s_ThrowInfo *)v2;
  v3 = RtlPcToFileHeader(v2, &BaseOfImage);
  BaseOfImage = v3;
  v8 = v3;
  if ( v2 )
  {
    if ( v2->attributes & 8 )
    {
      LODWORD(Arguments) = 26820608;
    }
    else
    {
      v4 = Arguments;
      if ( !v3 )
        v4 = 26820608;
      LODWORD(Arguments) = v4;
    }
  }
  RaiseException(
    ExceptionTemplate_0.ExceptionCode,
    ExceptionTemplate_0.ExceptionFlags,
    ExceptionTemplate_0.NumberParameters,
    &Arguments);
}

