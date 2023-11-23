// File Line: 27
// RVA: 0x9C2BC0
bool __fastcall Scaleform::Render::TGA::FileWriter::Write(
        Scaleform::Render::TGA::FileWriter *this,
        Scaleform::File *out,
        Scaleform::Render::ImageData *imageData,
        Scaleform::Render::ImageWriteArgs *__formal)
{
  Scaleform::Render::ImageData *v4; // r14
  Scaleform::Render::ImageFormat Format; // ecx
  __int64 v7; // r12
  char v8; // di
  int v9; // r15d
  __int32 v10; // ecx
  __int32 v11; // ecx
  int v12; // ecx
  int v13; // ecx
  char v14; // si
  Scaleform::Render::ImagePlane *pPlanes; // rax
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::RefCountImplCoreVtbl *v17; // rax
  Scaleform::RefCountImplCoreVtbl *v18; // rax
  Scaleform::RefCountImplCoreVtbl *v19; // rax
  Scaleform::RefCountImplCoreVtbl *v20; // rax
  Scaleform::RefCountImplCoreVtbl *v21; // rax
  Scaleform::RefCountImplCoreVtbl *v22; // rax
  Scaleform::RefCountImplCoreVtbl *v23; // rax
  Scaleform::RefCountImplCoreVtbl *v24; // rax
  Scaleform::RefCountImplCoreVtbl *v25; // rax
  Scaleform::RefCountImplCoreVtbl *v26; // rax
  Scaleform::RefCountImplCoreVtbl *v27; // rax
  Scaleform::RefCountImplCoreVtbl *v28; // rax
  Scaleform::RefCountImplCoreVtbl *v29; // rax
  unsigned int i; // edi
  Scaleform::RefCountImplCoreVtbl *v31; // rax
  Scaleform::RefCountImplCoreVtbl *v32; // rax
  Scaleform::RefCountImplCoreVtbl *v33; // rax
  Scaleform::Render::ImagePlane *v34; // rax
  __int64 v35; // r13
  char *v36; // rdi
  int v37; // esi
  int v38; // r12d
  _BYTE *v39; // r14
  __int64 v40; // r15
  Scaleform::RefCountImplCoreVtbl *v41; // rax
  int v42; // esi
  int v43; // r15d
  _BYTE *v44; // r14
  __int64 v45; // r12
  Scaleform::RefCountImplCoreVtbl *v46; // rax
  __int64 v47; // rsi
  bool v48; // zf
  __int16 Width; // [rsp+20h] [rbp-40h] BYREF
  int v51; // [rsp+28h] [rbp-38h]
  int v52; // [rsp+2Ch] [rbp-34h]
  __int64 v53; // [rsp+30h] [rbp-30h]
  __int64 Height; // [rsp+38h] [rbp-28h]
  char v55; // [rsp+88h] [rbp+28h]

  v4 = imageData;
  if ( !out
    || !((unsigned __int8 (__fastcall *)(Scaleform::File *))out->vfptr[2].__vecDelDtor)(out)
    || !((unsigned __int8 (__fastcall *)(Scaleform::File *))out->vfptr[3].__vecDelDtor)(out) )
  {
    return 0;
  }
  Format = v4->Format;
  v7 = 0i64;
  v8 = 32;
  v51 = 2;
  v53 = 0i64;
  v9 = 0;
  v52 = 0;
  v10 = Format - 1;
  if ( !v10 )
    goto LABEL_13;
  v11 = v10 - 1;
  if ( !v11 )
  {
    v9 = 2;
    v51 = 0;
    v52 = 2;
LABEL_13:
    v14 = 32;
    v8 = 40;
    goto LABEL_14;
  }
  v12 = v11 - 1;
  if ( !v12 )
  {
LABEL_11:
    v14 = 24;
    goto LABEL_14;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    v9 = 2;
    v51 = 0;
    v52 = 2;
    goto LABEL_11;
  }
  if ( v13 != 5 )
    return 0;
  v14 = 8;
LABEL_14:
  pPlanes = v4->pPlanes;
  v55 = v14;
  if ( pPlanes->Width > 0xFFFF || pPlanes->Height > 0xFFFF )
    return 0;
  vfptr = out->vfptr;
  LOBYTE(Width) = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))vfptr[9].__vecDelDtor)(out, &Width, 1i64);
  v17 = out->vfptr;
  if ( v4->Format == Image_A8 )
  {
    LOBYTE(Width) = 1;
    v17[9].__vecDelDtor(out, (unsigned int)&Width);
    v18 = out->vfptr;
    LOBYTE(Width) = 1;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v18[9].__vecDelDtor)(out, &Width, 1i64);
    v19 = out->vfptr;
    Width = 0;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v19[9].__vecDelDtor)(out, &Width, 2i64);
    v20 = out->vfptr;
    Width = 256;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v20[9].__vecDelDtor)(out, &Width, 2i64);
    LOBYTE(Width) = 24;
  }
  else
  {
    LOBYTE(Width) = 0;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v17[9].__vecDelDtor)(out, &Width, 1i64);
    v21 = out->vfptr;
    LOBYTE(Width) = 2;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v21[9].__vecDelDtor)(out, &Width, 1i64);
    v22 = out->vfptr;
    Width = 0;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v22[9].__vecDelDtor)(out, &Width, 2i64);
    v23 = out->vfptr;
    Width = 0;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v23[9].__vecDelDtor)(out, &Width, 2i64);
    LOBYTE(Width) = 0;
  }
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Width, 1i64);
  v24 = out->vfptr;
  Width = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v24[9].__vecDelDtor)(out, &Width, 2i64);
  v25 = out->vfptr;
  Width = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v25[9].__vecDelDtor)(out, &Width, 2i64);
  v26 = out->vfptr;
  Width = v4->pPlanes->Width;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v26[9].__vecDelDtor)(out, &Width, 2i64);
  v27 = out->vfptr;
  Width = v4->pPlanes->Height;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v27[9].__vecDelDtor)(out, &Width, 2i64);
  v28 = out->vfptr;
  LOBYTE(Width) = v14;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v28[9].__vecDelDtor)(out, &Width, 1i64);
  v29 = out->vfptr;
  LOBYTE(Width) = v8;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v29[9].__vecDelDtor)(out, &Width, 1i64);
  if ( v4->Format == Image_A8 )
  {
    for ( i = 0; i < 0x100; ++i )
    {
      v31 = out->vfptr;
      LOBYTE(Width) = i;
      ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v31[9].__vecDelDtor)(out, &Width, 1i64);
      v32 = out->vfptr;
      LOBYTE(Width) = i;
      ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v32[9].__vecDelDtor)(out, &Width, 1i64);
      v33 = out->vfptr;
      LOBYTE(Width) = i;
      ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v33[9].__vecDelDtor)(out, &Width, 1i64);
    }
  }
  v34 = v4->pPlanes;
  v35 = v34->Width;
  if ( v34->Height )
  {
    Height = v34->Height;
    do
    {
      v36 = &v4->pPlanes->pData[v7 * v4->pPlanes->Pitch];
      if ( v14 == 24 )
      {
        if ( 3 * (_DWORD)v35 )
        {
          v37 = v9;
          v38 = v51 - v9;
          v39 = v36 + 1;
          v40 = (3 * (int)v35 - 1) / 3u + 1;
          do
          {
            LOBYTE(Width) = v36[v38 + v37];
            ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Width, 1i64);
            LOBYTE(Width) = *v39;
            ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Width, 1i64);
            v41 = out->vfptr;
            LOBYTE(Width) = v36[v37];
            ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v41[9].__vecDelDtor)(out, &Width, 1i64);
            v37 += 3;
            v39 += 3;
            --v40;
          }
          while ( v40 );
          v7 = v53;
          v4 = imageData;
LABEL_38:
          v14 = v55;
        }
      }
      else
      {
        if ( v14 != 32 )
        {
          if ( v14 != 8 || !(_DWORD)v35 )
            goto LABEL_39;
          v47 = v35;
          do
          {
            LOBYTE(Width) = *v36;
            ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Width, 1i64);
            ++v36;
            --v47;
          }
          while ( v47 );
          goto LABEL_38;
        }
        if ( 4 * (_DWORD)v35 )
        {
          v42 = v9;
          v43 = v51 - v52;
          v44 = v36 + 3;
          v45 = ((unsigned int)(4 * v35 - 1) >> 2) + 1;
          do
          {
            LOBYTE(Width) = v36[v42 + v43];
            ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Width, 1i64);
            LOBYTE(Width) = *(v44 - 2);
            ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Width, 1i64);
            v46 = out->vfptr;
            LOBYTE(Width) = v36[v42];
            ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))v46[9].__vecDelDtor)(out, &Width, 1i64);
            LOBYTE(Width) = *v44;
            ((void (__fastcall *)(Scaleform::File *, __int16 *, __int64))out->vfptr[9].__vecDelDtor)(out, &Width, 1i64);
            v42 += 4;
            v44 += 4;
            --v45;
          }
          while ( v45 );
          v7 = v53;
          v4 = imageData;
          goto LABEL_38;
        }
      }
LABEL_39:
      v9 = v52;
      ++v7;
      v48 = Height-- == 1;
      v53 = v7;
    }
    while ( !v48 );
  }
  return ((unsigned __int8 (__fastcall *)(Scaleform::File *))out->vfptr[3].__vecDelDtor)(out) != 0;
}

// File Line: 175
// RVA: 0x159C7A0
__int64 dynamic_initializer_for__Scaleform::Render::TGA::FileWriter::Instance__()
{
  Scaleform::Render::TGA::FileWriter::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::TGA::FileWriter::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::TGA::FileWriter::Instance__);
}

