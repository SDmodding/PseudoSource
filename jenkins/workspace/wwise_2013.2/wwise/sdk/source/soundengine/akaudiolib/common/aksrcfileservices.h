// File Line: 33
// RVA: 0xA99510
signed __int64 __fastcall AK::SrcFileServices::IsPrebufferingReady(AK::IAkAutoStream *in_pStream, unsigned int in_uSizeLeft)
{
  unsigned int v2; // edi
  AK::IAkAutoStream *v3; // rbx
  signed __int64 result; // rax
  unsigned int v5; // eax
  int v6; // [rsp+30h] [rbp+8h]

  v2 = in_uSizeLeft;
  v3 = in_pStream;
  result = in_pStream->vfptr->QueryBufferingStatus(in_pStream, (unsigned int *)&v6);
  if ( (unsigned int)(result - 45) <= 1 )
  {
    v5 = v3->vfptr->GetNominalBuffering(v3);
    result = (unsigned int)(v2 + v6 < v5) + 45;
  }
  else if ( (_DWORD)result == 17 )
  {
    result = 45i64;
  }
  return result;
}

