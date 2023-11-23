// File Line: 33
// RVA: 0xA99510
__int64 __fastcall AK::SrcFileServices::IsPrebufferingReady(AK::IAkAutoStream *in_pStream, unsigned int in_uSizeLeft)
{
  __int64 result; // rax
  unsigned int v5; // eax
  int v6; // [rsp+30h] [rbp+8h] BYREF

  result = ((__int64 (__fastcall *)(AK::IAkAutoStream *, int *))in_pStream->vfptr->QueryBufferingStatus)(
             in_pStream,
             &v6);
  if ( (unsigned int)(result - 45) <= 1 )
  {
    v5 = in_pStream->vfptr->GetNominalBuffering(in_pStream);
    return (unsigned int)(in_uSizeLeft + v6 < v5) + 45;
  }
  else if ( (_DWORD)result == 17 )
  {
    return 45i64;
  }
  return result;
}

