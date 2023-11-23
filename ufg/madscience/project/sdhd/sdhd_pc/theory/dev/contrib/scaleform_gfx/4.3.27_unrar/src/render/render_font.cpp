// File Line: 44
// RVA: 0x9D3070
void __fastcall Scaleform::Render::Font::calcLowerUpperTop(
        Scaleform::Render::Font *this,
        Scaleform::Render::GlyphCache *log)
{
  char *v4; // rbx
  unsigned __int8 v5; // cl
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  unsigned int v7; // eax
  int v8; // edi
  const char *v9; // rdi
  const char *v10; // rbx
  const char *v11; // rax
  int v12; // eax
  unsigned __int8 v13; // cl
  char *v14; // rbx
  Scaleform::RefCountImplCoreVtbl *v15; // rax
  unsigned int v16; // eax
  char v17[16]; // [rsp+30h] [rbp-38h] BYREF
  __int128 v18; // [rsp+40h] [rbp-28h] BYREF
  char v19[8]; // [rsp+70h] [rbp+8h] BYREF

  if ( *(_DWORD *)&this->LowerCaseTop )
    goto LABEL_6;
  v4 = v17;
  strcpy(v17, "HEFTUVWXZ");
  v5 = aHeftuvwx[0];
  strcpy(v19, "zxvwy");
  if ( !aHeftuvwx[0] )
    goto LABEL_6;
  while ( 1 )
  {
    vfptr = this->vfptr;
    v18 = 0i64;
    v7 = (unsigned int)vfptr[2].__vecDelDtor(this, v5);
    if ( v7 != -1 )
    {
      ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, __int128 *))this->vfptr[7].__vecDelDtor)(this, v7, &v18);
      v8 = (int)COERCE_FLOAT(DWORD1(v18) ^ _xmm[0]);
      if ( (_WORD)v8 )
        break;
    }
    v5 = *++v4;
    if ( !v5 )
      goto LABEL_6;
  }
  v13 = v19[0];
  v14 = v19;
  if ( v19[0] )
  {
    while ( 1 )
    {
      v15 = this->vfptr;
      v18 = 0i64;
      v16 = (unsigned int)v15[2].__vecDelDtor(this, v13);
      if ( v16 != -1 )
      {
        ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, __int128 *))this->vfptr[7].__vecDelDtor)(
          this,
          v16,
          &v18);
        v12 = (int)COERCE_FLOAT(DWORD1(v18) ^ _xmm[0]);
        if ( (_WORD)v12 )
          break;
      }
      v13 = *++v14;
      if ( !v13 )
        goto LABEL_6;
    }
    this->UpperCaseTop = v8;
  }
  else
  {
LABEL_6:
    if ( log )
    {
      v9 = &customCaption;
      v10 = &customCaption;
      if ( (this->Flags & 1) != 0 )
        v10 = " Italic";
      if ( (this->Flags & 2) != 0 )
        v9 = " Bold";
      v11 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))this->vfptr[1].__vecDelDtor)(this);
      Scaleform::Render::GlyphCache::LogWarning(
        log,
        "Font %s%s%s: No hinting chars (any of HEFTUVWXZ and zxvwy). Auto-Hinting disabled.",
        v11,
        v9,
        v10);
    }
    LOWORD(v12) = -1;
    this->UpperCaseTop = -1;
  }
  this->LowerCaseTop = v12;
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

