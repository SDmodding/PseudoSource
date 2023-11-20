// File Line: 1230
// RVA: 0xA953C0
HRESULT __fastcall XAudio2Create(IXAudio2 **ppXAudio2, unsigned int Flags, XAUDIO2_WINDOWS_PROCESSOR_SPECIFIER XAudio2Processor)
{
  IXAudio2 **v3; // rdi
  unsigned int v4; // ebx
  XAUDIO2_WINDOWS_PROCESSOR_SPECIFIER v5; // esi
  GUID *v6; // rcx
  HRESULT result; // eax
  HRESULT v8; // ebx
  LPVOID ppv; // [rsp+58h] [rbp+20h]

  v3 = ppXAudio2;
  v4 = Flags;
  v5 = XAudio2Processor;
  v6 = &GUID_5a508685_a254_4fba_9b82_9a24b00306af;
  if ( Flags & 1 )
    v6 = &GUID_db05ea35_0329_4d4b_a53a_6dead03d3852;
  result = CoCreateInstance(v6, 0i64, 1u, &GUID_8bcf1f58_9fe7_4583_8ac6_e2adc465c8bb, &ppv);
  if ( result >= 0 )
  {
    result = (*(__int64 (__fastcall **)(LPVOID, _QWORD, _QWORD))(*(_QWORD *)ppv + 40i64))(ppv, v4, v5);
    v8 = result;
    if ( result < 0 )
    {
      (*(void (**)(void))(*(_QWORD *)ppv + 16i64))();
      result = v8;
    }
    else
    {
      *v3 = (IXAudio2 *)ppv;
    }
  }
  return result;
}

