// File Line: 35
// RVA: 0x8C4310
void __fastcall Scaleform::GFx::ZlibSupport::CreateZlibFile(Scaleform::GFx::ZlibSupport *this, Scaleform::File *in)
{
  Scaleform::GFx::ZLibFile *v3; // rax
  int v4; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::GFx::ZLibFile *v5; // [rsp+58h] [rbp+20h]

  v4 = 2;
  v3 = (Scaleform::GFx::ZLibFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ZlibSupport *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                     Scaleform::Memory::pGlobalHeap,
                                     this,
                                     24i64,
                                     &v4,
                                     -2i64);
  v5 = v3;
  if ( v3 )
    Scaleform::GFx::ZLibFile::ZLibFile(v3, in);
}

// File Line: 43
// RVA: 0x8E3A10
void __fastcall Scaleform::GFx::ZlibSupport::InflateWrapper(
        Scaleform::GFx::ZlibSupport *this,
        Scaleform::GFx::Stream *pinStream,
        __int64 buffer,
        int bufferBytes)
{
  unsigned int v5; // eax
  int v6; // esi
  char *v7; // rdi
  __int64 v8; // rbp
  unsigned int v9; // eax
  unsigned int Pos; // eax
  unsigned int DataSize; // ecx
  int v12; // eax
  unsigned int v13; // eax
  int v14; // r8d
  signed int FilePos; // r9d
  unsigned int v16; // edx
  unsigned int v17; // r10d
  unsigned int v18; // r10d
  unsigned int v19; // edi
  signed int v20; // r9d
  unsigned int v21; // edx
  unsigned int v22; // r10d
  unsigned int v23; // r10d
  unsigned int v24; // edi
  unsigned int v25; // eax
  char Dst[32]; // [rsp+20h] [rbp-98h] BYREF
  char *v27; // [rsp+40h] [rbp-78h] BYREF
  int v28; // [rsp+48h] [rbp-70h]
  __int64 v29; // [rsp+50h] [rbp-68h]
  int v30; // [rsp+58h] [rbp-60h]
  void *(__fastcall *v31)(void *, unsigned int, unsigned int); // [rsp+70h] [rbp-48h]
  void (__fastcall *v32)(void *, void *); // [rsp+78h] [rbp-40h]
  Scaleform::GFx::ZlibSupport *v33; // [rsp+80h] [rbp-38h]
  __int64 v34; // [rsp+88h] [rbp-30h]
  int v35; // [rsp+90h] [rbp-28h]

  v31 = Scaleform::GFx::ZLibAllocFunc;
  v33 = this;
  v29 = buffer;
  v27 = 0i64;
  v28 = 0;
  v32 = Scaleform::GFx::ZLibFreeFunc;
  v30 = bufferBytes;
  v34 = 0i64;
  v35 = 0;
  v5 = inflateInit_(&v27, "1.2.7", 88i64);
  if ( v5 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      pinStream,
      "GFx_InflateWrapper() inflateInit() returned %d",
      v5);
  }
  else
  {
    do
    {
      v6 = 32;
      v7 = Dst;
      LODWORD(v8) = 0;
      v27 = Dst;
      if ( !pinStream->DataSize )
      {
        v9 = ((__int64 (__fastcall *)(Scaleform::File *))pinStream->pInput.pObject->vfptr[4].__vecDelDtor)(pinStream->pInput.pObject);
        pinStream->ResyncFile = 0;
        pinStream->FilePos = v9;
      }
      Pos = pinStream->Pos;
      DataSize = pinStream->DataSize;
      if ( Pos < DataSize )
      {
        v8 = DataSize - Pos;
        if ( (unsigned int)v8 > 0x20 )
          v8 = 32i64;
        memmove(Dst, &pinStream->pBuffer[Pos], (unsigned int)v8);
        pinStream->Pos += v8;
        v6 = 32 - v8;
        v7 = &Dst[v8];
      }
      if ( pinStream->Pos >= pinStream->DataSize )
        *(_QWORD *)&pinStream->Pos = 0i64;
      if ( v6 )
      {
        v12 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))pinStream->pInput.pObject->vfptr[10].__vecDelDtor)(
                pinStream->pInput.pObject,
                v7,
                (unsigned int)v6);
        pinStream->FilePos += v12;
        LODWORD(v8) = v12 + v8;
        if ( v12 < v6 )
          memset(&v7[v12], 0, (unsigned int)(v6 - v12));
      }
      v28 = v8;
      v13 = inflate(&v27, 2i64);
      if ( v13 == 1 )
        goto LABEL_24;
    }
    while ( !v13 );
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      pinStream,
      "GFx_InflateWrapper() Inflate() returned %d",
      v13);
    v14 = v28;
    if ( !v28 )
      goto LABEL_33;
    FilePos = pinStream->FilePos;
    v16 = pinStream->DataSize;
    v17 = pinStream->Pos;
    pinStream->UnusedBits = 0;
    v18 = FilePos - v16 + v17;
    v19 = v18 - v14;
    if ( (int)(v18 - v14) >= (int)(FilePos - v16) && (int)v19 < FilePos )
    {
      pinStream->Pos = v19 + v16 - FilePos;
      goto LABEL_25;
    }
    if ( pinStream->ResyncFile || v18 != v19 )
    {
      if ( ((int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pinStream->pInput.pObject->vfptr[14].__vecDelDtor)(
             pinStream->pInput.pObject,
             v19,
             0i64) >= 0 )
      {
        pinStream->ResyncFile = 0;
        *(_QWORD *)&pinStream->Pos = 0i64;
        pinStream->FilePos = v19;
      }
LABEL_24:
      v14 = v28;
    }
LABEL_25:
    if ( v14 )
    {
      v20 = pinStream->FilePos;
      v21 = pinStream->DataSize;
      v22 = pinStream->Pos;
      pinStream->UnusedBits = 0;
      v23 = v20 - v21 + v22;
      v24 = v23 - v14;
      if ( (int)(v23 - v14) < (int)(v20 - v21) || (int)v24 >= v20 )
      {
        if ( (pinStream->ResyncFile || v23 != v24)
          && ((int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pinStream->pInput.pObject->vfptr[14].__vecDelDtor)(
               pinStream->pInput.pObject,
               v24,
               0i64) >= 0 )
        {
          pinStream->ResyncFile = 0;
          *(_QWORD *)&pinStream->Pos = 0i64;
          pinStream->FilePos = v24;
        }
      }
      else
      {
        pinStream->Pos = v24 + v21 - v20;
      }
    }
LABEL_33:
    v25 = inflateEnd(&v27);
    if ( v25 )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
        pinStream,
        "GFx_InflateWrapper() InflateEnd() return %d",
        v25);
  }
}

