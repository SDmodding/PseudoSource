// File Line: 30
// RVA: 0xEEE4F4
bool __fastcall OSuite::psock::uuid::updatestate()
{
  int v0; // eax
  unsigned __int64 v1; // rbx
  __timeb64 tp; // [rsp+20h] [rbp-58h] BYREF
  OSuite::psock::interface_t dest; // [rsp+30h] [rbp-48h] BYREF

  v0 = OSuite::psock::getinterfaces(&dest, 1);
  if ( v0 )
  {
    ftime64_s(&tp);
    v1 = 10000 * (tp.millitm + 1000 * (tp.time + 0x2D8466D80i64));
    if ( !g_bValid || memcmp(dest.mac, g_anNode, 6ui64) )
      OSuite::psock::crypto::randomize(&g_nSequence, 2ui64);
    if ( g_bValid && g_nTime >= v1 )
      ++g_nSequence;
    g_nTime = v1;
    memmove(g_anNode, dest.mac, 6ui64);
    g_bValid = 1;
    LOBYTE(v0) = 1;
  }
  return v0;
}

// File Line: 111
// RVA: 0xEECB3C
void __fastcall OSuite::psock::uuid::create(char *destination, int version)
{
  int v3; // edx
  unsigned __int64 v4; // rcx
  char v5; // cl

  v3 = version - 1;
  if ( !v3 )
  {
    WaitForSingleObject(OSuite::psock::uuid::g_lock, 0xFFFFFFFF);
    if ( OSuite::psock::uuid::updatestate() )
    {
      v4 = g_nTime;
      *destination = byte_1424C072B;
      destination[1] = byte_1424C072A;
      destination[2] = BYTE1(v4);
      destination[3] = v4;
      v4 >>= 32;
      destination[4] = BYTE1(v4);
      destination[5] = v4;
      LOWORD(v4) = word_1424C072E & 0xFFF | 0x1000;
      destination[6] = BYTE1(v4);
      destination[7] = v4;
      destination[9] = g_nSequence;
      destination[8] = HIBYTE(g_nSequence) & 0x3F | 0x80;
      memmove(destination + 10, g_anNode, 6ui64);
      ReleaseMutex(OSuite::psock::uuid::g_lock);
      return;
    }
    ReleaseMutex(OSuite::psock::uuid::g_lock);
    goto LABEL_7;
  }
  if ( v3 == 3 )
  {
LABEL_7:
    OSuite::psock::crypto::randomize(destination, 0x10ui64);
    destination[8] &= 0x3Fu;
    destination[8] |= 0x80u;
    v5 = destination[7];
    destination[6] = destination[6] & 0xF | 0x40;
    destination[7] = v5;
  }
}

