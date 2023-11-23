// File Line: 96
// RVA: 0x4AD050
bool __fastcall UFG::GameStatTracker::IsValidBuffer(
        UFG::GameStatTracker *this,
        unsigned __int64 timestamp,
        unsigned int headerSize,
        char *buffer,
        unsigned int bufferSize)
{
  char i; // r10
  unsigned int v7; // r9d
  char v8; // si
  char *v9; // r11
  unsigned int v10; // edi
  unsigned int v11; // r8d
  char v12; // dl
  char v13; // dl

  for ( i = 0; timestamp; timestamp &= timestamp - 1 )
    ++i;
  v7 = -1;
  v8 = 0;
  v9 = &buffer[headerSize];
  v10 = 0;
  v11 = bufferSize - headerSize - 4;
  if ( v11 )
  {
    do
    {
      ++v9;
      v12 = v10 + gScrambleKey[v8 & 0x1F] + gScrambleKey[(i + (_BYTE)v10) & 0x1F];
      ++v10;
      v13 = *(v9 - 1) ^ v12;
      v8 += v13;
      v7 = (v7 << 8) ^ sCrcTable32DupFromChecksumCPP[(unsigned __int8)(v13 ^ HIBYTE(v7))];
    }
    while ( v10 < v11 );
  }
  return *(_DWORD *)&buffer[bufferSize - 4] == v7;
}

// File Line: 123
// RVA: 0x4B93F0
void __fastcall UFG::GameStatTracker::Scramble(
        UFG::GameStatTracker *this,
        unsigned __int64 timestamp,
        unsigned int headerSize,
        char *buffer,
        unsigned int bufferSize)
{
  unsigned int v5; // r11d
  char i; // r10
  char *v8; // r8
  char v9; // bl
  char v10; // dl
  __int64 v11; // rax
  char v12; // cl

  v5 = 0;
  for ( i = 0; timestamp; timestamp &= timestamp - 1 )
    ++i;
  v8 = &buffer[headerSize];
  v9 = 0;
  if ( bufferSize - headerSize != 4 )
  {
    do
    {
      v10 = *v8;
      v11 = v9 & 0x1F;
      v9 += *v8++;
      v12 = v5 + gScrambleKey[v11] + gScrambleKey[(i + (_BYTE)v5) & 0x1F];
      ++v5;
      *(v8 - 1) = v10 ^ v12;
    }
    while ( v5 < bufferSize - headerSize - 4 );
  }
}

// File Line: 140
// RVA: 0x49ABA0
void __fastcall UFG::GameStatTracker::Descramble(
        UFG::GameStatTracker *this,
        unsigned __int64 timestamp,
        unsigned int headerSize,
        char *buffer,
        unsigned int bufferSize)
{
  unsigned int v5; // r11d
  char i; // r10
  char *v8; // rdx
  char v9; // r8
  char v10; // cl

  v5 = 0;
  for ( i = 0; timestamp; timestamp &= timestamp - 1 )
    ++i;
  v8 = &buffer[headerSize];
  v9 = 0;
  if ( bufferSize - headerSize != 4 )
  {
    do
    {
      ++v8;
      v10 = v5 + gScrambleKey[v9 & 0x1F] + gScrambleKey[(i + (_BYTE)v5) & 31];
      ++v5;
      *(v8 - 1) ^= v10;
      v9 += *(v8 - 1);
    }
    while ( v5 < bufferSize - headerSize - 4 );
  }
}

