// File Line: 167
// RVA: 0xA7E00
void __fastcall HavokJobMemoryPoolTagger::onEndJob(HavokJobMemoryPoolTagger *this, hkJobType t)
{
  _QWORD *v2; // rax
  __int64 v3; // rdx
  char v4; // al

  v2 = NtCurrentTeb()->Reserved1[11];
  v3 = v2[tls_index] + 16i64;
  v4 = *(_BYTE *)(v2[tls_index] + 96i64);
  if ( v4 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v4 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
}

