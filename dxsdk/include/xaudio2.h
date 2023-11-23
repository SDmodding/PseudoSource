// File Line: 1230
// RVA: 0xA953C0
HRESULT __fastcall XAudio2Create(LPVOID *ppXAudio2, unsigned int Flags, unsigned int XAudio2Processor)
{
  GUID *v6; // rcx
  HRESULT result; // eax
  HRESULT v8; // ebx
  LPVOID ppv; // [rsp+58h] [rbp+20h] BYREF

  v6 = &GUID_5a508685_a254_4fba_9b82_9a24b00306af;
  if ( (Flags & 1) != 0 )
    v6 = &GUID_db05ea35_0329_4d4b_a53a_6dead03d3852;
  result = CoCreateInstance(v6, 0i64, 1u, &GUID_8bcf1f58_9fe7_4583_8ac6_e2adc465c8bb, &ppv);
  if ( result >= 0 )
  {
    result = (*(__int64 (__fastcall **)(LPVOID, _QWORD, _QWORD))(*(_QWORD *)ppv + 40i64))(ppv, Flags, XAudio2Processor);
    v8 = result;
    if ( result < 0 )
    {
      (*(void (__fastcall **)(LPVOID))(*(_QWORD *)ppv + 16i64))(ppv);
      return v8;
    }
    else
    {
      *ppXAudio2 = ppv;
    }
  }
  return result;
}

