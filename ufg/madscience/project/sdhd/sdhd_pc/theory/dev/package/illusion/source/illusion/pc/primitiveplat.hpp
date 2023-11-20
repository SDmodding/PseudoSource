// File Line: 38
// RVA: 0xA217F0
bool __fastcall Illusion::IPrimitivePlat::SetBuffers(Illusion::IPrimitivePlat *this, bool dupe_vertex_buffer)
{
  Illusion::IPrimitivePlat *v2; // rdi
  signed int v3; // esi
  char *v4; // rax
  int v5; // ebx
  __int64 v6; // rax
  signed int v7; // ecx
  unsigned __int16 v8; // ax
  signed int v9; // esi
  int v10; // eax
  signed int v11; // ebp
  char *v12; // r14
  __int64 v13; // r9
  unsigned __int16 v14; // dx
  __int16 v15; // ax
  _WORD *v16; // r9
  signed __int64 v17; // r8
  _WORD *v18; // rcx
  signed int v19; // ebx
  char *v20; // rax
  const void *v21; // rdx
  char *v22; // rcx
  unsigned __int16 i; // bx
  int v24; // er14

  v2 = this;
  if ( dupe_vertex_buffer )
  {
    v3 = *(unsigned __int16 *)&this[26] * *(_DWORD *)(*(_QWORD *)&this[8] + 100i64);
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.PrimitiveFrameWriteMemory, v3, 0x10u);
    v5 = (signed int)v4;
    if ( !v4 )
      return (char)v4;
    memmove(v4, *(const void **)v2, v3);
    *(_QWORD *)&v2[48] = Illusion::gPrimitiveFrameWriteMemoryPlat.mBuffer[Illusion::gPrimitiveFrameWriteMemoryPlat.mFrameMemoryBufferIndex];
    *(_DWORD *)&v2[56] = v5 - LODWORD(Illusion::gPrimitiveFrameWriteMemoryPlat.mLockData);
  }
  else
  {
    *(_QWORD *)&this[48] = Illusion::gFrameWriteMemoryPlat.mBuffer[Illusion::gFrameWriteMemoryPlat.mFrameMemoryBufferIndex];
    *(_DWORD *)&this[56] = *(_DWORD *)this - LODWORD(Illusion::gFrameWriteMemoryPlat.mLockData);
  }
  v6 = *(_QWORD *)&v2[16];
  if ( v6 )
    v7 = *(unsigned __int16 *)&v2[30];
  else
    v7 = 2;
  if ( v6 )
    v8 = *(_WORD *)&v2[32];
  else
    v8 = *(_WORD *)&v2[26];
  v9 = v8;
  if ( *(_WORD *)&v2[28] == 5 )
  {
    v10 = v8 - 3;
    v11 = v9;
    if ( v9 - 3 < 0 )
      v10 = 0;
    v9 += v10;
    v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.PrimitiveFrameWriteMemory, v7 * v9, 0x10u);
    if ( v12 )
    {
      v13 = *(_QWORD *)&v2[16];
      v14 = 3;
      if ( v13 )
      {
        v15 = *(_WORD *)(v13 + 2);
        v16 = (_WORD *)(v13 + 6);
        *(_WORD *)v12 = v15;
        v17 = (signed __int64)(v12 + 6);
        *(_WORD *)(v17 - 4) = *(v16 - 1);
        *(_WORD *)(v17 - 2) = *(v16 - 3);
        if ( v11 > 3 )
        {
          do
          {
            ++v14;
            v17 += 4i64;
            *(_WORD *)(v17 - 4) = *v16;
            ++v16;
            *(_WORD *)(v17 - 2) = **(_WORD **)&v2[16];
          }
          while ( v14 < v11 );
        }
      }
      else
      {
        *(_WORD *)v12 = 1;
        *(_DWORD *)(v12 + 2) = 2;
        v18 = v12 + 6;
        if ( v11 > 3 )
        {
          do
          {
            *v18 = v14++;
            v18[1] = 0;
            v18 += 2;
          }
          while ( v14 < v11 );
        }
      }
LABEL_28:
      *(_QWORD *)&v2[64] = Illusion::gPrimitiveFrameWriteMemoryPlat.mBuffer[Illusion::gPrimitiveFrameWriteMemoryPlat.mFrameMemoryBufferIndex];
      v24 = (_DWORD)v12 - LODWORD(Illusion::gPrimitiveFrameWriteMemoryPlat.mLockData);
      *(_DWORD *)&v2[76] = v9;
      *(_DWORD *)&v2[72] = v24;
      LOBYTE(v4) = 1;
      return (char)v4;
    }
  }
  else
  {
    v19 = v7 * v8;
    v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.PrimitiveFrameWriteMemory, v19, 0x10u);
    LODWORD(v12) = (_DWORD)v20;
    if ( v20 )
    {
      v21 = *(const void **)&v2[16];
      v22 = v20;
      if ( v21 )
      {
        memmove(v20, v21, v19);
      }
      else
      {
        for ( i = 0; i < v9; v22 += 2 )
          *(_WORD *)v22 = i++;
      }
      goto LABEL_28;
    }
  }
  LOBYTE(v4) = 0;
  return (char)v4;
}

// File Line: 143
// RVA: 0xA18A20
Illusion::Primitive *__fastcall Illusion::Primitive::Create(const char *description)
{
  const char *v1; // rbx
  Illusion::Primitive *result; // rax

  v1 = description;
  result = (Illusion::Primitive *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x50u, 4u);
  if ( result )
  {
    result->mDescription = v1;
    result->mIndexStream = 0i64;
    result->mVertexStream = 0i64;
    result->mVertexDecl = 0i64;
  }
  return result;
}

