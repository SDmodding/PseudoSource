// File Line: 28
// RVA: 0x9C28D0
char __fastcall Scaleform::Render::SIF::FileWriter::Write(
        Scaleform::Render::SIF::FileWriter *this,
        Scaleform::File *out,
        Scaleform::Render::ImageData *imageData,
        Scaleform::Render::ImageWriteArgs *argsVal)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::RefCountImplCoreVtbl *v7; // rax
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  Scaleform::RefCountImplCoreVtbl *v10; // rax
  unsigned int v11; // r15d
  unsigned __int16 v12; // r12
  Scaleform::Render::ImagePlane *pPlanes; // rcx
  unsigned __int64 v14; // r14
  Scaleform::RefCountImplCoreVtbl *v15; // rax
  Scaleform::RefCountImplCoreVtbl *v16; // rax
  Scaleform::RefCountImplCoreVtbl *v17; // rax
  unsigned __int64 v18; // rdi
  Scaleform::Render::ImagePlane *i; // rax
  char v20; // cl
  Scaleform::RefCountImplCoreVtbl *v21; // rax
  Scaleform::Render::Palette *pObject; // rax
  Scaleform::RefCountImplCoreVtbl *v23; // rax
  Scaleform::Render::Palette *v24; // rcx
  Scaleform::RefCountImplCoreVtbl *v25; // rax
  Scaleform::RefCountImplCoreVtbl *v27; // rax
  unsigned __int32 Format; // [rsp+58h] [rbp+28h] BYREF

  if ( !out
    || !((unsigned __int8 (__fastcall *)(Scaleform::File *))out->vfptr[2].__vecDelDtor)(out)
    || !((unsigned __int8 (__fastcall *)(Scaleform::File *))out->vfptr[3].__vecDelDtor)(out) )
  {
    return 0;
  }
  vfptr = out->vfptr;
  LOBYTE(Format) = 83;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))vfptr[9].__vecDelDtor)(out, &Format, 1i64);
  v7 = out->vfptr;
  LOBYTE(Format) = 73;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v7[9].__vecDelDtor)(out, &Format, 1i64);
  v8 = out->vfptr;
  LOBYTE(Format) = 70;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v8[9].__vecDelDtor)(out, &Format, 1i64);
  v9 = out->vfptr;
  LOBYTE(Format) = 32;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v9[9].__vecDelDtor)(out, &Format, 1i64);
  v10 = out->vfptr;
  LOBYTE(Format) = 17;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v10[9].__vecDelDtor)(out, &Format, 1i64);
  Format = imageData->Format;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Format, 4i64);
  Format = imageData->Use;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Format, 4i64);
  LOBYTE(Format) = imageData->Flags;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Format, 1i64);
  LOBYTE(Format) = imageData->LevelCount;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Format, 1i64);
  LOWORD(Format) = imageData->RawPlaneCount;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Format, 2i64);
  v11 = 0;
  v12 = 0;
  if ( imageData->RawPlaneCount )
  {
    pPlanes = imageData->pPlanes;
    do
    {
      v14 = v12;
      Format = pPlanes[v14].Width;
      ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))out->vfptr[9].__vecDelDtor)(
        out,
        &Format,
        4i64);
      v15 = out->vfptr;
      Format = imageData->pPlanes[v14].Height;
      ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v15[9].__vecDelDtor)(out, &Format, 4i64);
      v16 = out->vfptr;
      Format = imageData->pPlanes[v14].Pitch;
      ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v16[9].__vecDelDtor)(out, &Format, 4i64);
      v17 = out->vfptr;
      Format = imageData->pPlanes[v14].DataSize;
      ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v17[9].__vecDelDtor)(out, &Format, 4i64);
      pPlanes = imageData->pPlanes;
      v18 = 0i64;
      for ( i = &pPlanes[v14]; v18 < pPlanes[v14].DataSize; i = &pPlanes[v14] )
      {
        v20 = i->pData[v18];
        v21 = out->vfptr;
        LOBYTE(Format) = v20;
        ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v21[9].__vecDelDtor)(out, &Format, 1i64);
        pPlanes = imageData->pPlanes;
        ++v18;
      }
      ++v12;
    }
    while ( v12 < imageData->RawPlaneCount );
  }
  pObject = imageData->pPalette.pObject;
  if ( !pObject )
  {
    v27 = out->vfptr;
    LOWORD(Format) = 0;
    ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v27[9].__vecDelDtor)(out, &Format, 2i64);
    return 1;
  }
  LOWORD(Format) = pObject->ColorCount;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Format, 2i64);
  v23 = out->vfptr;
  LOBYTE(Format) = imageData->pPalette.pObject->HasAlphaFlag;
  ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v23[9].__vecDelDtor)(out, &Format, 1i64);
  v24 = imageData->pPalette.pObject;
  if ( !v24->ColorCount )
    return 1;
  do
  {
    v25 = out->vfptr;
    Format = v24->Colors[v11].Raw;
    ((void (__fastcall *)(Scaleform::File *, unsigned __int32 *, __int64))v25[9].__vecDelDtor)(out, &Format, 4i64);
    v24 = imageData->pPalette.pObject;
    ++v11;
  }
  while ( v11 < v24->ColorCount );
  return 1;
}

// File Line: 78
// RVA: 0x159C750
__int64 dynamic_initializer_for__Scaleform::Render::SIF::FileWriter::Instance__()
{
  Scaleform::Render::SIF::FileWriter::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::SIF::FileWriter::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SIF::FileWriter::Instance__);
}

