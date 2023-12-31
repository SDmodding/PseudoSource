// File Line: 34
// RVA: 0x941930
void __fastcall Scaleform::Render::SIF::SIFFileImageSource::SIFFileImageSource(
        Scaleform::Render::SIF::SIFFileImageSource *this,
        Scaleform::File *file,
        Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::FileImageSource::FileImageSource(this, file, format, 0i64);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SIF::SIFFileImageSource::`vftable;
  *(_QWORD *)&this->Data.Format = 0i64;
  *(_DWORD *)&this->Data.Flags = 0x10000;
  this->Data.pPlanes = &this->Data.Plane0;
  this->Data.pPalette.pObject = 0i64;
  *(_QWORD *)&this->Data.Plane0.Width = 0i64;
  this->Data.Plane0.Pitch = 0i64;
  this->Data.Plane0.DataSize = 0i64;
  this->Data.Plane0.pData = 0i64;
}

// File Line: 36
// RVA: 0x94C8A0
void __fastcall Scaleform::Render::SIF::SIFFileImageSource::~SIFFileImageSource(
        Scaleform::Render::SIF::SIFFileImageSource *this)
{
  Scaleform::Render::ImageData *p_Data; // rbx
  char Flags; // al
  volatile signed __int32 *p_Value; // rdx
  Scaleform::File *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SIF::SIFFileImageSource::`vftable;
  p_Data = &this->Data;
  Flags = this->Data.Flags;
  if ( (Flags & 2) != 0 )
  {
    this->Data.Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data.pPlanes);
  }
  p_Data->pPlanes = &p_Data->Plane0;
  p_Value = &p_Data->pPalette.pObject->RefCount.Value;
  if ( p_Value && !_InterlockedDecrement(p_Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FileImageSource::`vftable;
  pObject = this->pFile.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 39
// RVA: 0x989A40
__int64 __fastcall Scaleform::Render::SIF::SIFFileImageSource::GetMipmapCount(
        Scaleform::Render::SIF::SIFFileImageSource *this)
{
  __int64 result; // rax

  result = (unsigned __int8)this->HeaderInfo.LevelCount;
  if ( !this->HeaderInfo.LevelCount )
    return 1i64;
  return result;
}

// File Line: 45
// RVA: 0x9A5230
char __fastcall Scaleform::Render::SIF::SIFFileImageSource::ReadHeader(
        Scaleform::Render::SIF::SIFFileImageSource *this)
{
  Scaleform::File *pObject; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::File *v5; // rcx
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  Scaleform::Render::ImageFormat v7; // eax
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
  unsigned int Width; // eax
  unsigned int v21; // ecx
  unsigned __int32 v22; // [rsp+30h] [rbp+10h] BYREF
  char Str1; // [rsp+38h] [rbp+18h] BYREF

  ((void (__fastcall *)(Scaleform::File *, char *, __int64))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[10].__vecDelDtor)(
    this->pFile.pObject,
    &Str1,
    4i64);
  if ( strncmp(&Str1, "SIF ", 4ui64) )
    return 0;
  pObject = this->pFile.pObject;
  vfptr = pObject->vfptr;
  LOBYTE(v22) = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))vfptr[10].__vecDelDtor)(pObject, &v22, 1i64);
  if ( (_BYTE)v22 != 17 )
    return 0;
  v5 = this->pFile.pObject;
  v6 = v5->vfptr;
  v22 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v6[10].__vecDelDtor)(v5, &v22, 4i64);
  v7 = v22;
  v8 = this->pFile.pObject;
  this->Format = v22;
  this->HeaderInfo.Format = v7;
  v9 = v8->vfptr;
  v22 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v9[10].__vecDelDtor)(v8, &v22, 4i64);
  v10 = this->pFile.pObject;
  this->Use = v22;
  v11 = v10->vfptr;
  LOBYTE(v22) = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v11[10].__vecDelDtor)(v10, &v22, 1i64);
  v12 = this->pFile.pObject;
  this->HeaderInfo.Flags = v22 & 0xFD;
  v13 = v12->vfptr;
  LOBYTE(v22) = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v13[10].__vecDelDtor)(v12, &v22, 1i64);
  v14 = this->pFile.pObject;
  this->HeaderInfo.LevelCount = v22;
  v15 = v14->vfptr;
  LOWORD(v22) = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v15[10].__vecDelDtor)(v14, &v22, 2i64);
  v16 = this->pFile.pObject;
  this->HeaderInfo.RawPlaneCount = v22;
  v17 = v16->vfptr;
  v22 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v17[10].__vecDelDtor)(v16, &v22, 4i64);
  v18 = this->pFile.pObject;
  this->HeaderInfo.Width = v22;
  v19 = v18->vfptr;
  v22 = 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v19[10].__vecDelDtor)(v18, &v22, 4i64);
  Width = this->HeaderInfo.Width;
  v21 = v22;
  this->HeaderInfo.Height = v22;
  this->Size.Width = Width;
  this->Size.Height = v21;
  this->FilePos = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->Scaleform::Render::FileImageSource::vfptr[5].__vecDelDtor)(this->pFile.pObject);
  return 1;
}

// File Line: 69
// RVA: 0x96BBD0
char __fastcall Scaleform::Render::SIF::SIFFileImageSource::Decode(
        Scaleform::Render::SIF::SIFFileImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::File *pObject; // rcx
  Scaleform::File *v7; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::File *v9; // rcx
  Scaleform::RefCountImplCoreVtbl *v10; // rax
  Scaleform::Render::ImagePlane *pPlanes; // rcx
  unsigned __int64 DataSize; // rdx
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
  __int64 v27; // rsi
  Scaleform::File *v28; // rcx
  Scaleform::RefCountImplCoreVtbl *v29; // rax
  Scaleform::File *v30; // rcx
  Scaleform::RefCountImplCoreVtbl *v31; // rax
  unsigned __int16 v32; // bx
  Scaleform::File *v33; // rcx
  Scaleform::RefCountImplCoreVtbl *v34; // rax
  bool v35; // r12
  int v36; // esi
  Scaleform::Render::Palette *v37; // rax
  Scaleform::Render::Palette *v38; // rbx
  Scaleform::Render::Palette *v39; // rdx
  unsigned __int16 v40; // bx
  Scaleform::File *v41; // rcx
  Scaleform::RefCountImplCoreVtbl *v42; // rax
  __int64 v43; // rdx
  Scaleform::Render::Palette *v45; // rdx
  char v46; // [rsp+20h] [rbp-40h] BYREF
  char v47[3]; // [rsp+21h] [rbp-3Fh] BYREF
  unsigned __int16 v48; // [rsp+24h] [rbp-3Ch] BYREF
  int v49; // [rsp+28h] [rbp-38h] BYREF
  int v50; // [rsp+2Ch] [rbp-34h] BYREF
  unsigned int v51; // [rsp+30h] [rbp-30h] BYREF
  int v52; // [rsp+34h] [rbp-2Ch] BYREF
  int v53; // [rsp+38h] [rbp-28h] BYREF
  int v54; // [rsp+3Ch] [rbp-24h] BYREF
  int v55[4]; // [rsp+40h] [rbp-20h] BYREF
  char v56; // [rsp+80h] [rbp+20h] BYREF

  pObject = this->pFile.pObject;
  if ( !pObject
    || ((__int64 (__fastcall *)(Scaleform::File *, __int64, _QWORD, void *))pObject->vfptr[15].__vecDelDtor)(
         pObject,
         this->FilePos,
         0i64,
         arg) != this->FilePos )
  {
    return 0;
  }
  pdest->Flags |= this->HeaderInfo.Flags;
  v7 = this->pFile.pObject;
  vfptr = v7->vfptr;
  v49 = 0;
  ((void (__fastcall *)(Scaleform::File *, int *, __int64))vfptr[10].__vecDelDtor)(v7, &v49, 4i64);
  v9 = this->pFile.pObject;
  v10 = v9->vfptr;
  v53 = 0;
  ((void (__fastcall *)(Scaleform::File *, int *, __int64))v10[10].__vecDelDtor)(v9, &v53, 4i64);
  pPlanes = pdest->pPlanes;
  DataSize = pPlanes->DataSize;
  if ( DataSize != v53 || pPlanes->Pitch != v49 )
    return 0;
  v13 = 0i64;
  if ( DataSize )
  {
    do
    {
      v14 = this->pFile.pObject;
      v15 = v14->vfptr;
      v56 = 0;
      ((void (__fastcall *)(Scaleform::File *, char *, __int64))v15[10].__vecDelDtor)(v14, &v56, 1i64);
      pdest->pPlanes->pData[v13++] = v56;
    }
    while ( v13 < pdest->pPlanes->DataSize );
  }
  v16 = 1;
  if ( pdest->RawPlaneCount <= 1u )
  {
LABEL_13:
    v30 = this->pFile.pObject;
    v31 = v30->vfptr;
    v48 = 0;
    ((void (__fastcall *)(Scaleform::File *, unsigned __int16 *, __int64))v31[10].__vecDelDtor)(v30, &v48, 2i64);
    v32 = v48;
    if ( v48 )
    {
      v33 = this->pFile.pObject;
      v34 = v33->vfptr;
      v46 = 0;
      ((void (__fastcall *)(Scaleform::File *, char *, __int64))v34[10].__vecDelDtor)(v33, &v46, 1i64);
      v35 = v46 != 0;
      v36 = v32;
      v37 = (Scaleform::Render::Palette *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            4i64 * ((unsigned int)v32 - 1) + 12,
                                            0i64);
      v38 = v37;
      if ( v37 )
      {
        v37->RefCount.Value = 1;
        v37->ColorCount = v36;
        v37->HasAlphaFlag = v35;
        memset(v37->Colors, 0, 4i64 * (unsigned int)v36);
      }
      if ( v38 )
        _InterlockedExchangeAdd(&v38->RefCount.Value, 1u);
      v39 = pdest->pPalette.pObject;
      if ( v39 && !_InterlockedDecrement(&v39->RefCount.Value) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pdest->pPalette.pObject = v38;
      v40 = 0;
      if ( v36 > 0 )
      {
        do
        {
          v41 = this->pFile.pObject;
          v42 = v41->vfptr;
          v51 = 0;
          ((void (__fastcall *)(Scaleform::File *, unsigned int *, __int64))v42[10].__vecDelDtor)(v41, &v51, 4i64);
          v43 = v40++;
          pdest->pPalette.pObject->Colors[v43].Raw = v51;
        }
        while ( v40 < v36 );
        return 1;
      }
    }
    else
    {
      v45 = pdest->pPalette.pObject;
      if ( v45 && !_InterlockedDecrement(&v45->RefCount.Value) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pdest->pPalette.pObject = 0i64;
    }
    return 1;
  }
  while ( 1 )
  {
    v17 = this->pFile.pObject;
    v18 = v17->vfptr;
    v54 = 0;
    ((void (__fastcall *)(Scaleform::File *, int *, __int64))v18[10].__vecDelDtor)(v17, &v54, 4i64);
    v19 = this->pFile.pObject;
    v20 = v19->vfptr;
    v55[0] = 0;
    ((void (__fastcall *)(Scaleform::File *, int *, __int64))v20[10].__vecDelDtor)(v19, v55, 4i64);
    v21 = this->pFile.pObject;
    v22 = v21->vfptr;
    v50 = 0;
    ((void (__fastcall *)(Scaleform::File *, int *, __int64))v22[10].__vecDelDtor)(v21, &v50, 4i64);
    v23 = this->pFile.pObject;
    v24 = v23->vfptr;
    v52 = 0;
    ((void (__fastcall *)(Scaleform::File *, int *, __int64))v24[10].__vecDelDtor)(v23, &v52, 4i64);
    v25 = pdest->pPlanes;
    if ( v25->DataSize != v52 || v25->Pitch != v50 )
      return 0;
    v26 = 0i64;
    v27 = v16;
    if ( v25[v27].DataSize )
    {
      do
      {
        v28 = this->pFile.pObject;
        v29 = v28->vfptr;
        v47[0] = 0;
        ((void (__fastcall *)(Scaleform::File *, char *, __int64))v29[10].__vecDelDtor)(v28, v47, 1i64);
        pdest->pPlanes[v27].pData[v26++] = v47[0];
      }
      while ( v26 < pdest->pPlanes[v27].DataSize );
    }
    if ( ++v16 >= pdest->RawPlaneCount )
      goto LABEL_13;
  }
}

// File Line: 136
// RVA: 0x99A610
bool __fastcall Scaleform::Render::SIF::FileReader::MatchFormat(
        Scaleform::Render::SIF::FileReader *this,
        Scaleform::File *file,
        char *headerArg,
        unsigned __int64 headerArgSize)
{
  Scaleform::Render::FileHeaderReaderImpl v5; // [rsp+30h] [rbp-18h] BYREF
  char tempBuffer[16]; // [rsp+38h] [rbp-10h] BYREF

  Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(&v5, file, headerArg, headerArgSize, tempBuffer, 4u);
  return v5.pHeader && *v5.pHeader == 83 && v5.pHeader[1] == 73 && v5.pHeader[2] == 70 && v5.pHeader[3] == 32;
}

// File Line: 146
// RVA: 0x9A58A0
Scaleform::Render::SIF::SIFFileImageSource *__fastcall Scaleform::Render::SIF::FileReader::ReadImageSource(
        Scaleform::Render::SIF::FileReader *this,
        Scaleform::File *file,
        Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::SIF::SIFFileImageSource *v5; // rax
  Scaleform::Render::SIF::SIFFileImageSource *v6; // rax
  Scaleform::Render::SIF::SIFFileImageSource *v7; // rbx

  if ( file && ((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
  {
    v5 = (Scaleform::Render::SIF::SIFFileImageSource *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         144i64,
                                                         0i64);
    if ( v5 )
    {
      Scaleform::Render::SIF::SIFFileImageSource::SIFFileImageSource(v5, file, args->Format);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SIF::FileReader::Instance__);
}

