// File Line: 76
// RVA: 0x12B0F28
void __fastcall __noreturn CxxThrowException(_QWORD *pExceptionObject, _s_ThrowInfo *pThrowInfo)
{
  _s_ThrowInfo *v2; // rbx
  PVOID v3; // rdx
  unsigned int magicNumber; // eax
  EHExceptionRecord::EHParameters Arguments; // [rsp+40h] [rbp-20h] BYREF
  PVOID BaseOfImage; // [rsp+70h] [rbp+10h] BYREF

  v2 = pThrowInfo;
  Arguments = ExceptionTemplate_0.params;
  if ( pThrowInfo && (pThrowInfo->attributes & 0x10) != 0 )
    v2 = *(_s_ThrowInfo **)(*(_QWORD *)(*pExceptionObject - 8i64) + 48i64);
  Arguments.pExceptionObject = pExceptionObject;
  Arguments.pThrowInfo = v2;
  v3 = RtlPcToFileHeader(v2, &BaseOfImage);
  BaseOfImage = v3;
  Arguments.pThrowImageBase = v3;
  if ( v2 )
  {
    if ( (v2->attributes & 8) != 0 )
    {
      Arguments.magicNumber = 26820608;
    }
    else
    {
      magicNumber = Arguments.magicNumber;
      if ( !v3 )
        magicNumber = 26820608;
      Arguments.magicNumber = magicNumber;
    }
  }
  RaiseException(
    ExceptionTemplate_0.ExceptionCode,
    ExceptionTemplate_0.ExceptionFlags,
    ExceptionTemplate_0.NumberParameters,
    (const ULONG_PTR *)&Arguments.magicNumber);
}

