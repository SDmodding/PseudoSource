// File Line: 34
// RVA: 0x941930
void __fastcall Scaleform::Render::SIF::SIFFileImageSource::SIFFileImageSource(Scaleform::Render::SIF::SIFFileImageSource *this, Scaleform::File *file, Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::SIF::SIFFileImageSource *v3; // rbx
  signed __int64 v4; // [rsp+58h] [rbp+20h]

  v3 = this;
  Scaleform::Render::FileImageSource::FileImageSource(
    (Scaleform::Render::FileImageSource *)&this->vfptr,
    file,
    format,
    0i64);
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SIF::SIFFileImageSource::`vftable;
  v4 = (signed __int64)&v3->Data;
  *(_QWORD *)v4 = 0i64;
  *(_DWORD *)(v4 + 8) = 0x10000;
  *(_QWORD *)(v4 + 16) = (char *)v3 + 88;
  *(_QWORD *)(v4 + 24) = 0i64;
  *(_QWORD *)&v3->Data.Plane0.Width = 0i64;
  v3->Data.Plane0.Pitch = 0i64;
  v3->Data.Plane0.DataSize = 0i64;
  v3->Data.Plane0.pData = 0i64;
}

// File Line: 36
// RVA: 0x94C8A0
void __fastcall Scaleform::Render::SIF::SIFFileImageSource::~SIFFileImageSource(Scaleform::Render::SIF::SIFFileImageSource *this)
{
  Scaleform::Render::SIF::SIFFileImageSource *v1; // rdi
  Scaleform::Render::ImageData *v2; // rbx
  char v3; // al
  volatile signed __int32 *v4; // rdx
  Scaleform::File *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SIF::SIFFileImageSource::`vftable;
  v2 = &this->Data;
  v3 = this->Data.Flags;
  if ( v3 & 2 )
  {
    this->Data.Flags = v3 & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data.pPlanes);
  }
  v2->pPlanes = &v2->Plane0;
  v4 = &v2->pPalette.pObject->RefCount.Value;
  if ( v4 && !_InterlockedDecrement(v4) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FileImageSource::`vftable;
  v5 = v1->pFile.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) && v5 )
    v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 39
// RVA: 0x989A40
signed __int64 __fastcall Scaleform::Render::SIF::SIFFileImageSource::GetMipmapCount(Scaleform::Render::SIF::SIFFileImageSource *this)
{
  signed __int64 result; // rax

  result = (unsigned __int8)this->HeaderInfo.LevelCount;
  if ( (unsigned int)result < 1 )
    result = 1i64;
  return result;
}

// File Line: 45
// RVA: 0x9A5230
char __fastcall Scaleform::Render::SIF::SIFFileImageSource::ReadHeader(Scaleform::Render::SIF::SIFFileImageSource *this)
{
  Scaleform::Render::SIF::SIFFileImageSource *v1; // rbx
  Scaleform::File *v3; // rcx
  Scaleform::RefCountImplCoreVtbl *v4; // rax
  Scaleform::File *v5; // rcx
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  int v7; // eax
  Scaleform::File *v8; // rcx
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  Scaleform::File *v10; // rcx
  Scaleform::RefCountImplCoreVtbl *v11; // rax
  Scaleform::File *v12; // rcx
  Scaleform::RefCountImplCoreVtbl *v13; // rax
  Scaleform::File *v14; // rcx
  Scaleform::RefCountImplCoreVtbl *v15; // rax
  Scaleform::File *v16; // rcx
  Scaleform::RefCountImplCoreVtbl *v17; // rax
  Scaleform::File *v18; // rcx
  Scaleform::RefCountImplCoreVtbl *v19; // rax
  unsigned int v20; // eax
  int v21; // ecx
  unsigned __int32 v22; // [rsp+30h] [rbp+10h]
  char Str1; // [rsp+38h] [rbp+18h]

  v1 = this;
  ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))this->pFile.pObject->vfptr[10].__vecDelDtor)(
    this->pFile.pObject,
    &Str1,
    4i64);
  if ( strncmp(&Str1, "SIF ", 4ui64) )
    return 0;
  v3 = v1->pFile.pObject;
  v4 = v3->vfptr;
  LOBYTE(v22) = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v4[10].__vecDelDtor)(v3, &v22, 1i64);
  if ( (_BYTE)v22 != 17 )
    return 0;
  v5 = v1->pFile.pObject;
  v6 = v5->vfptr;
  v22 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v6[10].__vecDelDtor)(v5, &v22, 4i64);
  v7 = v22;
  v8 = v1->pFile.pObject;
  v1->Format = v22;
  v1->HeaderInfo.Format = v7;
  v9 = v8->vfptr;
  v22 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v9[10].__vecDelDtor)(v8, &v22, 4i64);
  v10 = v1->pFile.pObject;
  v1->Use = v22;
  v11 = v10->vfptr;
  LOBYTE(v22) = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v11[10].__vecDelDtor)(v10, &v22, 1i64);
  v12 = v1->pFile.pObject;
  v1->HeaderInfo.Flags = v22 & 0xFD;
  v13 = v12->vfptr;
  LOBYTE(v22) = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v13[10].__vecDelDtor)(v12, &v22, 1i64);
  v14 = v1->pFile.pObject;
  v1->HeaderInfo.LevelCount = v22;
  v15 = v14->vfptr;
  LOWORD(v22) = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v15[10].__vecDelDtor)(v14, &v22, 2i64);
  v16 = v1->pFile.pObject;
  v1->HeaderInfo.RawPlaneCount = v22;
  v17 = v16->vfptr;
  v22 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v17[10].__vecDelDtor)(v16, &v22, 4i64);
  v18 = v1->pFile.pObject;
  v1->HeaderInfo.Width = v22;
  v19 = v18->vfptr;
  v22 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v19[10].__vecDelDtor)(v18, &v22, 4i64);
  v20 = v1->HeaderInfo.Width;
  v21 = v22;
  v1->HeaderInfo.Height = v22;
  v1->Size.Width = v20;
  v1->Size.Height = v21;
  v1->FilePos = ((__int64 (*)(void))v1->pFile.pObject->vfptr[5].__vecDelDtor)();
  return 1;
}

// File Line: 69
// RVA: 0x96BBD0
char __fastcall Scaleform::Render::SIF::SIFFileImageSource::Decode(Scaleform::Render::SIF::SIFFileImageSource *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  Scaleform::Render::SIF::SIFFileImageSource *v4; // r14
  Scaleform::File *v5; // rcx
  Scaleform::Render::ImageData *v6; // rdi
  Scaleform::File *v7; // rcx
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  Scaleform::File *v9; // rcx
  Scaleform::RefCountImplCoreVtbl *v10; // rax
  Scaleform::Render::ImagePlane *v11; // rcx
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // rbx
  Scaleform::File *v14; // rcx
  Scaleform::RefCountImplCoreVtbl *v15; // rax
  unsigned __int16 v16; // r12
  Scaleform::File *v17; // rcx
  Scaleform::RefCountImplCoreVtbl *v18; // rax
  Scaleform::File *v19; // rcx
  Scaleform::RefCountImplCoreVtbl *v20; // rax
  Scaleform::File *v21; // rcx
  Scaleform::RefCountImplCoreVtbl *v22; // rax
  Scaleform::File *v23; // rcx
  Scaleform::RefCountImplCoreVtbl *v24; // rax
  Scaleform::Render::ImagePlane *v25; // rcx
  unsigned __int64 v26; // rbx
  signed __int64 v27; // rsi
  Scaleform::File *v28; // rcx
  Scaleform::RefCountImplCoreVtbl *v29; // rax
  Scaleform::File *v30; // rcx
  Scaleform::RefCountImplCoreVtbl *v31; // rax
  unsigned __int16 v32; // bx
  Scaleform::File *v33; // rcx
  Scaleform::RefCountImplCoreVtbl *v34; // rax
  bool v35; // r12
  signed int v36; // esi
  volatile signed __int32 *v37; // rax
  volatile signed __int32 *v38; // rbx
  volatile signed __int32 *v39; // rdx
  unsigned __int16 v40; // bx
  Scaleform::File *v41; // rcx
  Scaleform::RefCountImplCoreVtbl *v42; // rax
  __int64 v43; // rdx
  volatile signed __int32 *v45; // rdx
  char v46; // [rsp+20h] [rbp-40h]
  char v47; // [rsp+21h] [rbp-3Fh]
  unsigned __int16 v48; // [rsp+24h] [rbp-3Ch]
  int v49; // [rsp+28h] [rbp-38h]
  int v50; // [rsp+2Ch] [rbp-34h]
  unsigned int v51; // [rsp+30h] [rbp-30h]
  int v52; // [rsp+34h] [rbp-2Ch]
  int v53; // [rsp+38h] [rbp-28h]
  int v54; // [rsp+3Ch] [rbp-24h]
  int v55; // [rsp+40h] [rbp-20h]
  char v56; // [rsp+80h] [rbp+20h]

  v4 = this;
  v5 = this->pFile.pObject;
  v6 = pdest;
  if ( !v5
    || ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD, void *))v5->vfptr[15].__vecDelDtor)(
         v5,
         v4->FilePos,
         0i64,
         arg) != v4->FilePos )
  {
    return 0;
  }
  v6->Flags |= v4->HeaderInfo.Flags;
  v7 = v4->pFile.pObject;
  v8 = v7->vfptr;
  v49 = 0;
  ((void (__fastcall *)(Scaleform::File *, int *, signed __int64))v8[10].__vecDelDtor)(v7, &v49, 4i64);
  v9 = v4->pFile.pObject;
  v10 = v9->vfptr;
  v53 = 0;
  ((void (__fastcall *)(Scaleform::File *, int *, signed __int64))v10[10].__vecDelDtor)(v9, &v53, 4i64);
  v11 = v6->pPlanes;
  v12 = v11->DataSize;
  if ( v12 != v53 || v11->Pitch != v49 )
    return 0;
  v13 = 0i64;
  if ( v12 )
  {
    do
    {
      v14 = v4->pFile.pObject;
      v15 = v14->vfptr;
      v56 = 0;
      ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v15[10].__vecDelDtor)(v14, &v56, 1i64);
      v6->pPlanes->pData[++v13 - 1] = v56;
    }
    while ( v13 < v6->pPlanes->DataSize );
  }
  v16 = 1;
  if ( v6->RawPlaneCount <= 1u )
  {
LABEL_13:
    v30 = v4->pFile.pObject;
    v31 = v30->vfptr;
    v48 = 0;
    ((void (__fastcall *)(Scaleform::File *, unsigned __int16 *, signed __int64))v31[10].__vecDelDtor)(v30, &v48, 2i64);
    v32 = v48;
    if ( v48 )
    {
      v33 = v4->pFile.pObject;
      v34 = v33->vfptr;
      v46 = 0;
      ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v34[10].__vecDelDtor)(v33, &v46, 1i64);
      v35 = v46 != 0;
      v36 = v32;
      v37 = (volatile signed __int32 *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                         Scaleform::Memory::pGlobalHeap,
                                         4i64 * ((unsigned int)v32 - 1) + 12,
                                         0i64);
      v38 = v37;
      if ( v37 )
      {
        *v37 = 1;
        *((_WORD *)v37 + 2) = v36;
        *((_BYTE *)v37 + 6) = v35;
        memset((void *)(v37 + 2), 0, 4i64 * (unsigned int)v36);
      }
      if ( v38 )
        _InterlockedExchangeAdd(v38, 1u);
      v39 = &v6->pPalette.pObject->RefCount.Value;
      if ( v39 && !_InterlockedDecrement(v39) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v6->pPalette.pObject = (Scaleform::Render::Palette *)v38;
      v40 = 0;
      if ( v36 > 0 )
      {
        do
        {
          v41 = v4->pFile.pObject;
          v42 = v41->vfptr;
          v51 = 0;
          ((void (__fastcall *)(Scaleform::File *, unsigned int *, signed __int64))v42[10].__vecDelDtor)(
            v41,
            &v51,
            4i64);
          v43 = v40++;
          v6->pPalette.pObject->Colors[v43].Raw = v51;
        }
        while ( v40 < v36 );
        return 1;
      }
    }
    else
    {
      v45 = &v6->pPalette.pObject->RefCount.Value;
      if ( v45 && !_InterlockedDecrement(v45) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v6->pPalette.pObject = 0i64;
    }
    return 1;
  }
  while ( 1 )
  {
    v17 = v4->pFile.pObject;
    v18 = v17->vfptr;
    v54 = 0;
    ((void (__fastcall *)(Scaleform::File *, int *, signed __int64))v18[10].__vecDelDtor)(v17, &v54, 4i64);
    v19 = v4->pFile.pObject;
    v20 = v19->vfptr;
    v55 = 0;
    ((void (__fastcall *)(Scaleform::File *, int *, signed __int64))v20[10].__vecDelDtor)(v19, &v55, 4i64);
    v21 = v4->pFile.pObject;
    v22 = v21->vfptr;
    v50 = 0;
    ((void (__fastcall *)(Scaleform::File *, int *, signed __int64))v22[10].__vecDelDtor)(v21, &v50, 4i64);
    v23 = v4->pFile.pObject;
    v24 = v23->vfptr;
    v52 = 0;
    ((void (__fastcall *)(Scaleform::File *, int *, signed __int64))v24[10].__vecDelDtor)(v23, &v52, 4i64);
    v25 = v6->pPlanes;
    if ( v25->DataSize != v52 || v25->Pitch != v50 )
      return 0;
    v26 = 0i64;
    v27 = v16;
    if ( v25[v27].DataSize > 0 )
    {
      do
      {
        v28 = v4->pFile.pObject;
        v29 = v28->vfptr;
        v47 = 0;
        ((void (__fastcall *)(Scaleform::File *, char *, signed __int64))v29[10].__vecDelDtor)(v28, &v47, 1i64);
        v6->pPlanes[v27].pData[++v26 - 1] = v47;
      }
      while ( v26 < v6->pPlanes[v27].DataSize );
    }
    if ( ++v16 >= v6->RawPlaneCount )
      goto LABEL_13;
  }
}

// File Line: 136
// RVA: 0x99A610
bool __fastcall Scaleform::Render::SIF::FileReader::MatchFormat(Scaleform::Render::SIF::FileReader *this, Scaleform::File *file, char *headerArg, unsigned __int64 headerArgSize)
{
  Scaleform::Render::FileHeaderReaderImpl v5; // [rsp+30h] [rbp-18h]
  char tempBuffer; // [rsp+38h] [rbp-10h]

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v5, file, headerArg, headerArgSize, &tempBuffer, 4);
  return v5.pHeader && *v5.pHeader == 83 && v5.pHeader[1] == 73 && v5.pHeader[2] == 70 && v5.pHeader[3] == 32;
}

// File Line: 146
// RVA: 0x9A58A0
Scaleform::Render::SIF::SIFFileImageSource *__fastcall Scaleform::Render::SIF::FileReader::ReadImageSource(Scaleform::Render::SIF::FileReader *this, Scaleform::File *file, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageCreateArgs *v3; // rdi
  Scaleform::File *v4; // rbx
  Scaleform::Render::SIF::SIFFileImageSource *v5; // rax
  Scaleform::Render::SIF::SIFFileImageSource *v6; // rax
  Scaleform::Render::SIF::SIFFileImageSource *v7; // rbx

  v3 = args;
  v4 = file;
  if ( file && ((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
  {
    v5 = (Scaleform::Render::SIF::SIFFileImageSource *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         144ui64,
                                                         0i64);
    if ( v5 )
    {
      Scaleform::Render::SIF::SIFFileImageSource::SIFFileImageSource(v5, v4, v3->Format);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    if ( !v7 || Scaleform::Render::SIF::SIFFileImageSource::ReadHeader(v7) )
      return v7;
    ((void (__fastcall *)(Scaleform::Render::SIF::SIFFileImageSource *))v7->vfptr[2].__vecDelDtor)(v7);
  }
  return 0i64;
}

// File Line: 162
// RVA: 0x159C6B0
__int64 dynamic_initializer_for__Scaleform::Render::SIF::FileReader::Instance__()
{
  Scaleform::Render::SIF::FileReader::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::SIF::FileReader::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SIF::FileReader::Instance__);
}

