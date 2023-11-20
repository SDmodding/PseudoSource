// File Line: 27
// RVA: 0x9C2BC0
bool __fastcall Scaleform::Render::TGA::FileWriter::Write(Scaleform::Render::TGA::FileWriter *this, Scaleform::File *out, Scaleform::Render::ImageData *imageData, Scaleform::Render::ImageWriteArgs *__formal)
{
  Scaleform::Render::ImageData *v4; // r14
  Scaleform::File *v5; // rbx
  Scaleform::Render::ImageFormat v6; // ecx
  __int64 v7; // r12
  char v8; // di
  signed int v9; // er15
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  char v14; // si
  Scaleform::Render::ImagePlane *v15; // rax
  Scaleform::RefCountImplCoreVtbl *v16; // rax
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
  unsigned int v30; // edi
  Scaleform::RefCountImplCoreVtbl *v31; // rax
  Scaleform::RefCountImplCoreVtbl *v32; // rax
  Scaleform::RefCountImplCoreVtbl *v33; // rax
  Scaleform::Render::ImagePlane *v34; // rax
  __int64 v35; // r13
  char *v36; // rdi
  signed int v37; // esi
  int v38; // er12
  _BYTE *v39; // r14
  __int64 v40; // r15
  Scaleform::RefCountImplCoreVtbl *v41; // rax
  signed int v42; // esi
  int v43; // er15
  _BYTE *v44; // r14
  __int64 v45; // r12
  Scaleform::RefCountImplCoreVtbl *v46; // rax
  __int64 v47; // rsi
  bool v48; // zf
  __int16 v50; // [rsp+20h] [rbp-40h]
  int v51; // [rsp+28h] [rbp-38h]
  int v52; // [rsp+2Ch] [rbp-34h]
  __int64 v53; // [rsp+30h] [rbp-30h]
  __int64 v54; // [rsp+38h] [rbp-28h]
  char v55; // [rsp+88h] [rbp+28h]
  Scaleform::Render::ImageData *v56; // [rsp+90h] [rbp+30h]

  v56 = imageData;
  v4 = imageData;
  v5 = out;
  if ( !out
    || !((unsigned __int8 (__fastcall *)(Scaleform::File *, Scaleform::File *, Scaleform::Render::ImageData *, Scaleform::Render::ImageWriteArgs *))out->vfptr[2].__vecDelDtor)(
          out,
          out,
          imageData,
          __formal)
    || !((unsigned __int8 (__fastcall *)(Scaleform::File *))v5->vfptr[3].__vecDelDtor)(v5) )
  {
    return 0;
  }
  v6 = v4->Format;
  v7 = 0i64;
  v8 = 32;
  v51 = 2;
  v53 = 0i64;
  v9 = 0;
  v52 = 0;
  v10 = v6 - 1;
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
  v15 = v4->pPlanes;
  v55 = v14;
  if ( v15->Width > 0xFFFF || v15->Height > 0xFFFF )
    return 0;
  v16 = v5->vfptr;
  LOBYTE(v50) = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v16[9].__vecDelDtor)(v5, &v50, 1i64);
  v17 = v5->vfptr;
  if ( v4->Format == 9 )
  {
    LOBYTE(v50) = 1;
    v17[9].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v50);
    v18 = v5->vfptr;
    LOBYTE(v50) = 1;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v18[9].__vecDelDtor)(v5, &v50, 1i64);
    v19 = v5->vfptr;
    v50 = 0;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v19[9].__vecDelDtor)(v5, &v50, 2i64);
    v20 = v5->vfptr;
    v50 = 256;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v20[9].__vecDelDtor)(v5, &v50, 2i64);
    LOBYTE(v50) = 24;
  }
  else
  {
    LOBYTE(v50) = 0;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v17[9].__vecDelDtor)(v5, &v50, 1i64);
    v21 = v5->vfptr;
    LOBYTE(v50) = 2;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v21[9].__vecDelDtor)(v5, &v50, 1i64);
    v22 = v5->vfptr;
    v50 = 0;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v22[9].__vecDelDtor)(v5, &v50, 2i64);
    v23 = v5->vfptr;
    v50 = 0;
    ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v23[9].__vecDelDtor)(v5, &v50, 2i64);
    LOBYTE(v50) = 0;
  }
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v5->vfptr[9].__vecDelDtor)(v5, &v50, 1i64);
  v24 = v5->vfptr;
  v50 = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v24[9].__vecDelDtor)(v5, &v50, 2i64);
  v25 = v5->vfptr;
  v50 = 0;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v25[9].__vecDelDtor)(v5, &v50, 2i64);
  v26 = v5->vfptr;
  v50 = v4->pPlanes->Width;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v26[9].__vecDelDtor)(v5, &v50, 2i64);
  v27 = v5->vfptr;
  v50 = v4->pPlanes->Height;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v27[9].__vecDelDtor)(v5, &v50, 2i64);
  v28 = v5->vfptr;
  LOBYTE(v50) = v14;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v28[9].__vecDelDtor)(v5, &v50, 1i64);
  v29 = v5->vfptr;
  LOBYTE(v50) = v8;
  ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v29[9].__vecDelDtor)(v5, &v50, 1i64);
  if ( v4->Format == 9 )
  {
    v30 = 0;
    do
    {
      v31 = v5->vfptr;
      LOBYTE(v50) = v30;
      ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v31[9].__vecDelDtor)(v5, &v50, 1i64);
      v32 = v5->vfptr;
      LOBYTE(v50) = v30;
      ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v32[9].__vecDelDtor)(v5, &v50, 1i64);
      v33 = v5->vfptr;
      LOBYTE(v50) = v30;
      ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v33[9].__vecDelDtor)(v5, &v50, 1i64);
      ++v30;
    }
    while ( v30 < 0x100 );
  }
  v34 = v4->pPlanes;
  v35 = v34->Width;
  if ( v34->Height )
  {
    v54 = v34->Height;
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
          v40 = (3 * (signed int)v35 - 1) / 3u + 1;
          do
          {
            LOBYTE(v50) = v36[v38 + v37];
            ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
              v5,
              &v50,
              1i64);
            LOBYTE(v50) = *v39;
            ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
              v5,
              &v50,
              1i64);
            v41 = v5->vfptr;
            LOBYTE(v50) = v36[v37];
            ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v41[9].__vecDelDtor)(v5, &v50, 1i64);
            v37 += 3;
            v39 += 3;
            --v40;
          }
          while ( v40 );
          v7 = v53;
          v4 = v56;
LABEL_38:
          v14 = v55;
          goto LABEL_39;
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
            LOBYTE(v50) = *v36;
            ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
              v5,
              &v50,
              1i64);
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
            LOBYTE(v50) = v36[v42 + v43];
            ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
              v5,
              &v50,
              1i64);
            LOBYTE(v50) = *(v44 - 2);
            ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
              v5,
              &v50,
              1i64);
            v46 = v5->vfptr;
            LOBYTE(v50) = v36[v42];
            ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v46[9].__vecDelDtor)(v5, &v50, 1i64);
            LOBYTE(v50) = *v44;
            ((void (__fastcall *)(Scaleform::File *, __int16 *, signed __int64))v5->vfptr[9].__vecDelDtor)(
              v5,
              &v50,
              1i64);
            v42 += 4;
            v44 += 4;
            --v45;
          }
          while ( v45 );
          v7 = v53;
          v4 = v56;
          goto LABEL_38;
        }
      }
LABEL_39:
      v9 = v52;
      ++v7;
      v48 = v54-- == 1;
      v53 = v7;
    }
    while ( !v48 );
  }
  return ((unsigned __int8 (__fastcall *)(Scaleform::File *))v5->vfptr[3].__vecDelDtor)(v5) != 0;
}

// File Line: 175
// RVA: 0x159C7A0
__int64 dynamic_initializer_for__Scaleform::Render::TGA::FileWriter::Instance__()
{
  Scaleform::Render::TGA::FileWriter::Instance.vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::TGA::FileWriter::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::TGA::FileWriter::Instance__);
}

