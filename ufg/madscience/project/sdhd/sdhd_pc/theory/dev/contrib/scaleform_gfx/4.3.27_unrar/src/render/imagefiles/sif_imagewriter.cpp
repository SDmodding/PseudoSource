// File Line: 28
// RVA: 0x9C28D0
char __fastcall Scaleform::Render::SIF::FileWriter::Write(Scaleform::Render::SIF::FileWriter *this, Scaleform::File *out, Scaleform::Render::ImageData *imageData, Scaleform::Render::ImageWriteArgs *argsVal)
{
  Scaleform::Render::ImageData *v4; // rsi
  Scaleform::File *v5; // rbx
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  Scaleform::RefCountImplCoreVtbl *v7; // rax
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  Scaleform::RefCountImplCoreVtbl *v10; // rax
  unsigned int v11; // er15
  unsigned __int16 v12; // r12
  Scaleform::Render::ImagePlane *v13; // rcx
  signed __int64 v14; // r14
  Scaleform::RefCountImplCoreVtbl *v15; // rax
  Scaleform::RefCountImplCoreVtbl *v16; // rax
  Scaleform::RefCountImplCoreVtbl *v17; // rax
  unsigned __int64 v18; // rdi
  signed __int64 i; // rax
  char v20; // cl
  Scaleform::RefCountImplCoreVtbl *v21; // rax
  Scaleform::Render::Palette *v22; // rax
  Scaleform::RefCountImplCoreVtbl *v23; // rax
  Scaleform::Render::Palette *v24; // rcx
  Scaleform::RefCountImplCoreVtbl *v25; // rax
  Scaleform::RefCountImplCoreVtbl *v27; // rax
  unsigned __int32 v28; // [rsp+58h] [rbp+28h]

  v4 = imageData;
  v5 = out;
  if ( !out
    || !((unsigned __int8 (__fastcall *)(Scaleform::File *, Scaleform::File *, Scaleform::Render::ImageData *, Scaleform::Render::ImageWriteArgs *))out->vfptr[2].__vecDelDtor)(
          out,
          out,
          imageData,
          argsVal)
    || !((unsigned __int8 (__fastcall *)(Scaleform::File *))v5->vfptr[3].__vecDelDtor)(v5) )
  {
    return 0;
  }
  v6 = v5->vfptr;
  LOBYTE(v28) = 83;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v6[9].__vecDelDtor)(v5, &v28, 1i64);
  v7 = v5->vfptr;
  LOBYTE(v28) = 73;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v7[9].__vecDelDtor)(v5, &v28, 1i64);
  v8 = v5->vfptr;
  LOBYTE(v28) = 70;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v8[9].__vecDelDtor)(v5, &v28, 1i64);
  v9 = v5->vfptr;
  LOBYTE(v28) = 32;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v9[9].__vecDelDtor)(v5, &v28, 1i64);
  v10 = v5->vfptr;
  LOBYTE(v28) = 17;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v10[9].__vecDelDtor)(v5, &v28, 1i64);
  v28 = v4->Format;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
    v5,
    &v28,
    4i64);
  v28 = v4->Use;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
    v5,
    &v28,
    4i64);
  LOBYTE(v28) = v4->Flags;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
    v5,
    &v28,
    1i64);
  LOBYTE(v28) = v4->LevelCount;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
    v5,
    &v28,
    1i64);
  LOWORD(v28) = v4->RawPlaneCount;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
    v5,
    &v28,
    2i64);
  v11 = 0;
  v12 = 0;
  if ( v4->RawPlaneCount > 0u )
  {
    v13 = v4->pPlanes;
    do
    {
      v14 = v12;
      v28 = v13[v14].Width;
      ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
        v5,
        &v28,
        4i64);
      v15 = v5->vfptr;
      v28 = v4->pPlanes[v14].Height;
      ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v15[9].__vecDelDtor)(v5, &v28, 4i64);
      v16 = v5->vfptr;
      v28 = v4->pPlanes[v14].Pitch;
      ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v16[9].__vecDelDtor)(v5, &v28, 4i64);
      v17 = v5->vfptr;
      v28 = v4->pPlanes[v14].DataSize;
      ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v17[9].__vecDelDtor)(v5, &v28, 4i64);
      v13 = v4->pPlanes;
      v18 = 0i64;
      for ( i = (signed __int64)&v13[v14]; v18 < v13[v14].DataSize; i = (signed __int64)&v13[v14] )
      {
        v20 = *(_BYTE *)(v18 + *(_QWORD *)(i + 24));
        v21 = v5->vfptr;
        LOBYTE(v28) = v20;
        ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v21[9].__vecDelDtor)(
          v5,
          &v28,
          1i64);
        v13 = v4->pPlanes;
        ++v18;
      }
      ++v12;
    }
    while ( v12 < v4->RawPlaneCount );
  }
  v22 = v4->pPalette.pObject;
  if ( !v22 )
  {
    v27 = v5->vfptr;
    LOWORD(v28) = 0;
    ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v27[9].__vecDelDtor)(v5, &v28, 2i64);
    return 1;
  }
  LOWORD(v28) = v22->ColorCount;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
    v5,
    &v28,
    2i64);
  v23 = v5->vfptr;
  LOBYTE(v28) = v4->pPalette.pObject->HasAlphaFlag != 0;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v23[9].__vecDelDtor)(v5, &v28, 1i64);
  v24 = v4->pPalette.pObject;
  if ( v24->ColorCount <= 0u )
    return 1;
  do
  {
    v25 = v5->vfptr;
    v28 = v24->Colors[v11].Raw;
    ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, signed __int64))v25[9].__vecDelDtor)(v5, &v28, 4i64);
    v24 = v4->pPalette.pObject;
    ++v11;
  }
  while ( v11 < v24->ColorCount );
  return 1;
}

// File Line: 78
// RVA: 0x159C750
__int64 dynamic_initializer_for__Scaleform::Render::SIF::FileWriter::Instance__()
{
  Scaleform::Render::SIF::FileWriter::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::SIF::FileWriter::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SIF::FileWriter::Instance__);
}

