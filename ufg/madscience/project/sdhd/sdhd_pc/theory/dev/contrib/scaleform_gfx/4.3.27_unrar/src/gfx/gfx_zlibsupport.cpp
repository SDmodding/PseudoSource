// File Line: 35
// RVA: 0x8C4310
void __fastcall Scaleform::GFx::ZlibSupport::CreateZlibFile(Scaleform::GFx::ZlibSupport *this, Scaleform::File *in)
{
  Scaleform::File *v2; // rbx
  Scaleform::GFx::ZLibFile *v3; // rax
  int v4; // [rsp+50h] [rbp+18h]
  Scaleform::GFx::ZLibFile *v5; // [rsp+58h] [rbp+20h]

  v2 = in;
  v4 = 2;
  v3 = (Scaleform::GFx::ZLibFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ZlibSupport *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                     Scaleform::Memory::pGlobalHeap,
                                     this,
                                     24i64,
                                     &v4,
                                     -2i64);
  v5 = v3;
  if ( v3 )
    Scaleform::GFx::ZLibFile::ZLibFile(v3, v2);
}

// File Line: 43
// RVA: 0x8E3A10
void __fastcall Scaleform::GFx::ZlibSupport::InflateWrapper(Scaleform::GFx::ZlibSupport *this, Scaleform::GFx::Stream *pinStream, void *buffer, int bufferBytes)
{
  Scaleform::GFx::Stream *v4; // rbx
  unsigned int v5; // eax
  const char *v6; // rdx
  signed int v7; // esi
  char *v8; // rdi
  signed __int64 v9; // rbp
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  signed int v13; // eax
  unsigned int v14; // eax
  int v15; // er8
  int v16; // er9
  unsigned int v17; // edx
  unsigned int v18; // er10
  unsigned int v19; // ecx
  int v20; // ecx
  int v21; // er10
  int v22; // edi
  int v23; // er9
  unsigned int v24; // edx
  unsigned int v25; // er10
  unsigned int v26; // ecx
  int v27; // ecx
  int v28; // er10
  int v29; // edi
  char Dst[32]; // [rsp+20h] [rbp-98h]
  char *v31; // [rsp+40h] [rbp-78h]
  int v32; // [rsp+48h] [rbp-70h]
  void *v33; // [rsp+50h] [rbp-68h]
  int v34; // [rsp+58h] [rbp-60h]
  void *(__fastcall *v35)(void *, unsigned int, unsigned int); // [rsp+70h] [rbp-48h]
  void (__fastcall *v36)(void *, void *); // [rsp+78h] [rbp-40h]
  Scaleform::GFx::ZlibSupport *v37; // [rsp+80h] [rbp-38h]
  __int64 v38; // [rsp+88h] [rbp-30h]
  int v39; // [rsp+90h] [rbp-28h]

  v4 = pinStream;
  v35 = Scaleform::GFx::ZLibAllocFunc;
  v37 = this;
  v33 = buffer;
  v31 = 0i64;
  v32 = 0;
  v36 = Scaleform::GFx::ZLibFreeFunc;
  v34 = bufferBytes;
  v38 = 0i64;
  v39 = 0;
  v5 = inflateInit_(&v31, "1.2.7", 88i64);
  if ( v5 )
  {
    v6 = "GFx_InflateWrapper() inflateInit() returned %d";
LABEL_35:
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
      v6,
      v5);
    return;
  }
  do
  {
    v7 = 32;
    v8 = Dst;
    LODWORD(v9) = 0;
    v31 = Dst;
    if ( !v4->DataSize )
    {
      v10 = ((__int64 (*)(void))v4->pInput.pObject->vfptr[4].__vecDelDtor)();
      v4->ResyncFile = 0;
      v4->FilePos = v10;
    }
    v11 = v4->Pos;
    v12 = v4->DataSize;
    if ( v11 < v12 )
    {
      v9 = v12 - v11;
      if ( (unsigned int)v9 > 0x20 )
        v9 = 32i64;
      memmove(Dst, &v4->pBuffer[v11], (unsigned int)v9);
      v4->Pos += v9;
      v7 = 32 - v9;
      v8 = &Dst[v9];
    }
    if ( v4->Pos >= v4->DataSize )
      *(_QWORD *)&v4->Pos = 0i64;
    if ( v7 )
    {
      v13 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v4->pInput.pObject->vfptr[10].__vecDelDtor)(
              v4->pInput.pObject,
              v8,
              (unsigned int)v7);
      v4->FilePos += v13;
      LODWORD(v9) = v13 + v9;
      if ( v13 < v7 )
        memset(&v8[v13], 0, (unsigned int)(v7 - v13));
    }
    v32 = v9;
    v14 = inflate(&v31, 2i64);
    if ( v14 == 1 )
      goto LABEL_24;
  }
  while ( !v14 );
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
    "GFx_InflateWrapper() Inflate() returned %d",
    v14);
  v15 = v32;
  if ( !v32 )
    goto LABEL_33;
  v16 = v4->FilePos;
  v17 = v4->DataSize;
  v18 = v4->Pos;
  v19 = v4->FilePos;
  v4->UnusedBits = 0;
  v20 = v19 - v17;
  v21 = v20 + v18;
  v22 = v21 - v15;
  if ( v21 - v15 >= v20 && v22 < v16 )
  {
    v4->Pos = v22 + v17 - v16;
    goto LABEL_25;
  }
  if ( v4->ResyncFile || v21 != v22 )
  {
    if ( ((signed int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v4->pInput.pObject->vfptr[14].__vecDelDtor)(
           v4->pInput.pObject,
           (unsigned int)v22,
           0i64) >= 0 )
    {
      v4->ResyncFile = 0;
      *(_QWORD *)&v4->Pos = 0i64;
      v4->FilePos = v22;
    }
LABEL_24:
    v15 = v32;
  }
LABEL_25:
  if ( v15 )
  {
    v23 = v4->FilePos;
    v24 = v4->DataSize;
    v25 = v4->Pos;
    v26 = v4->FilePos;
    v4->UnusedBits = 0;
    v27 = v26 - v24;
    v28 = v27 + v25;
    v29 = v28 - v15;
    if ( v28 - v15 < v27 || v29 >= v23 )
    {
      if ( (v4->ResyncFile || v28 != v29)
        && ((signed int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v4->pInput.pObject->vfptr[14].__vecDelDtor)(
             v4->pInput.pObject,
             (unsigned int)v29,
             0i64) >= 0 )
      {
        v4->ResyncFile = 0;
        *(_QWORD *)&v4->Pos = 0i64;
        v4->FilePos = v29;
      }
    }
    else
    {
      v4->Pos = v29 + v24 - v23;
    }
  }
LABEL_33:
  v5 = inflateEnd(&v31);
  if ( v5 )
  {
    v6 = "GFx_InflateWrapper() InflateEnd() return %d";
    goto LABEL_35;
  }
}

