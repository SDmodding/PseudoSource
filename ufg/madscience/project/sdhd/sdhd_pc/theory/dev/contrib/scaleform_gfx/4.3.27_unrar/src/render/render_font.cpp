// File Line: 44
// RVA: 0x9D3070
void __fastcall Scaleform::Render::Font::calcLowerUpperTop(Scaleform::Render::Font *this, Scaleform::Render::GlyphCache *log)
{
  Scaleform::Render::GlyphCache *v2; // rbp
  Scaleform::Render::Font *v3; // rsi
  __int64 *v4; // rbx
  unsigned __int8 v5; // cl
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  unsigned int v7; // eax
  signed int v8; // edi
  char *v9; // rdi
  char *v10; // rbx
  __int64 v11; // rax
  signed int v12; // eax
  unsigned __int8 v13; // cl
  int *v14; // rbx
  Scaleform::RefCountImplCoreVtbl *v15; // rax
  unsigned int v16; // eax
  __int64 v17; // [rsp+30h] [rbp-38h]
  __int16 v18; // [rsp+38h] [rbp-30h]
  __int128 v19; // [rsp+40h] [rbp-28h]
  int v20; // [rsp+70h] [rbp+8h]
  __int16 v21; // [rsp+74h] [rbp+Ch]

  v2 = log;
  v3 = this;
  if ( *(_DWORD *)&this->LowerCaseTop )
    goto LABEL_6;
  v4 = &v17;
  v17 = *(_QWORD *)aHeftuvwx;
  v5 = aHeftuvwx[0];
  v18 = 90;
  v20 = *(_DWORD *)aZxvw;
  v21 = 121;
  if ( !aHeftuvwx[0] )
    goto LABEL_6;
  while ( 1 )
  {
    v6 = v3->vfptr;
    v19 = 0i64;
    v7 = (__int64)v6[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v5);
    if ( v7 != -1 )
    {
      ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, __int128 *))v3->vfptr[7].__vecDelDtor)(v3, v7, &v19);
      v8 = (signed int)COERCE_FLOAT(DWORD1(v19) ^ _xmm[0]);
      if ( (_WORD)v8 )
        break;
    }
    v5 = *((_BYTE *)v4 + 1);
    v4 = (__int64 *)((char *)v4 + 1);
    if ( !v5 )
      goto LABEL_6;
  }
  v13 = v20;
  v14 = &v20;
  if ( (_BYTE)v20 )
  {
    while ( 1 )
    {
      v15 = v3->vfptr;
      v19 = 0i64;
      v16 = (__int64)v15[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, v13);
      if ( v16 != -1 )
      {
        ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, __int128 *))v3->vfptr[7].__vecDelDtor)(v3, v16, &v19);
        v12 = (signed int)COERCE_FLOAT(DWORD1(v19) ^ _xmm[0]);
        if ( (_WORD)v12 )
          break;
      }
      v13 = *((_BYTE *)v14 + 1);
      v14 = (int *)((char *)v14 + 1);
      if ( !v13 )
        goto LABEL_6;
    }
    v3->UpperCaseTop = v8;
  }
  else
  {
LABEL_6:
    if ( v2 )
    {
      v9 = &customWorldMapCaption;
      v10 = &customWorldMapCaption;
      if ( v3->Flags & 1 )
        v10 = " Italic";
      if ( (v3->Flags >> 1) & 1 )
        v9 = " Bold";
      v11 = ((__int64 (__fastcall *)(Scaleform::Render::Font *))v3->vfptr[1].__vecDelDtor)(v3);
      Scaleform::Render::GlyphCache::LogWarning(
        v2,
        "Font '%s%s%s': No hinting chars (any of 'HEFTUVWXZ' and 'zxvwy'). Auto-Hinting disabled.",
        v11,
        v9,
        v10);
    }
    LOWORD(v12) = -1;
    v3->UpperCaseTop = -1;
  }
  v3->LowerCaseTop = v12;
}

// File Line: 91
// RVA: 0x9974C0
bool __fastcall Scaleform::Render::Font::IsCJK(Scaleform::Render::Font *this, unsigned __int16 code)
{
  __int64 v2; // r8
  unsigned __int16 v3; // ax

  LODWORD(v2) = 0;
  v3 = 4352;
  while ( code < v3 || code > ranges[(unsigned int)(v2 + 1)] )
  {
    v2 = (unsigned int)(v2 + 2);
    v3 = ranges[v2];
    if ( !v3 )
      return v3;
  }
  LOBYTE(v3) = 1;
  return v3;
}

