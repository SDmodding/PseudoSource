// File Line: 123
// RVA: 0x9677A0
Scaleform::Render::Text::HighlightDesc *__fastcall Scaleform::Render::Text::Highlighter::CreateHighlighter(Scaleform::Render::Text::Highlighter *this, Scaleform::Render::Text::HighlightDesc *desc)
{
  unsigned int v2; // esi
  Scaleform::Render::Text::HighlightDesc *v3; // rbp
  Scaleform::Render::Text::Highlighter *v4; // rdi
  signed __int64 v5; // r8
  unsigned __int64 v6; // rbx

  *(_WORD *)&this->Valid = 0;
  v2 = desc->Id;
  v3 = desc;
  v4 = this;
  if ( Scaleform::Render::Text::Highlighter::GetHighlighterPtr(this, desc->Id) )
    return 0i64;
  v5 = v4->Highlighters.Data.Size;
  v6 = 0i64;
  while ( v5 > 0 )
  {
    if ( (signed int)(v4->Highlighters.Data.Data[(v5 >> 1) + v6].Id - v2) >= 0 )
    {
      v5 >>= 1;
    }
    else
    {
      v6 += (v5 >> 1) + 1;
      v5 += -1 - (v5 >> 1);
    }
  }
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->Highlighters.Data,
    v6,
    v3);
  return &v4->Highlighters.Data.Data[v6];
}

// File Line: 139
// RVA: 0x9853C0
Scaleform::Render::Text::HighlightDesc *__fastcall Scaleform::Render::Text::Highlighter::GetHighlighterPtr(Scaleform::Render::Text::Highlighter *this, unsigned int id)
{
  signed __int64 v2; // rax
  unsigned __int64 v3; // r9
  Scaleform::Render::Text::HighlightDesc *result; // rax

  v2 = this->Highlighters.Data.Size;
  v3 = 0i64;
  while ( v2 > 0 )
  {
    if ( (signed int)(this->Highlighters.Data.Data[(v2 >> 1) + v3].Id - id) >= 0 )
    {
      v2 >>= 1;
    }
    else
    {
      v3 += (v2 >> 1) + 1;
      v2 += -1 - (v2 >> 1);
    }
  }
  if ( v3 >= this->Highlighters.Data.Size || (result = &this->Highlighters.Data.Data[v3], result->Id != id) )
    result = 0i64;
  return result;
}

// File Line: 180
// RVA: 0x98AB80
Scaleform::Render::Text::HighlighterPosIterator *__fastcall Scaleform::Render::Text::Highlighter::GetPosIterator(Scaleform::Render::Text::Highlighter *this, Scaleform::Render::Text::HighlighterPosIterator *result, unsigned __int64 startPos, unsigned __int64 len)
{
  Scaleform::Render::Text::HighlighterPosIterator *v4; // rbx

  result->pManager = this;
  result->CurAdjStartPos = startPos;
  result->NumGlyphs = len;
  result->CurDesc.StartPos = -1i64;
  result->CurDesc.Offset = -1i64;
  result->CurDesc.Length = 0i64;
  result->CurDesc.AdjStartPos = 0i64;
  result->CurDesc.GlyphNum = 0i64;
  *(_QWORD *)&result->CurDesc.Id = 0i64;
  *(_QWORD *)&result->CurDesc.Info.TextColor.Channels.Blue = 0i64;
  result->CurDesc.Info.Flags = 0;
  v4 = result;
  Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(result);
  return v4;
}

// File Line: 190
// RVA: 0x9BE4B0
void __fastcall Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(Scaleform::Render::Text::Highlighter *this, Scaleform::Render::Text::CompositionStringBase *pcs)
{
  unsigned __int64 v2; // rdi
  __int64 v3; // r8
  Scaleform::Render::Text::Highlighter *v4; // r10
  Scaleform::Render::Text::HighlightDesc *v5; // rax
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // r9
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r11
  __int64 v10; // rcx
  unsigned __int64 v11; // rcx

  v2 = this->Highlighters.Data.Size;
  v3 = 0i64;
  v4 = this;
  this->CorrectionLen = 0i64;
  this->CorrectionPos = 0i64;
  for ( *(_WORD *)&this->Valid = 0; v2; --v2 )
  {
    v5 = v4->Highlighters.Data.Data;
    v6 = v4->Highlighters.Data.Data[v3].StartPos;
    v7 = v4->Highlighters.Data.Data[v3].Length;
    v5[v3].AdjStartPos = v6;
    v5[v3].GlyphNum = v7;
    v8 = v4->CorrectionLen;
    if ( v8 )
    {
      v9 = v4->CorrectionPos;
      if ( !v7 )
        goto LABEL_15;
      if ( v6 > v9 )
        goto LABEL_10;
      if ( v9 < v7 + v6 )
      {
        v10 = v5[v3].Offset;
        if ( v10 >= 0 )
        {
          v11 = v6 + v10;
LABEL_11:
          v5[v3].AdjStartPos = v11;
          goto LABEL_12;
        }
        v5[v3].GlyphNum = v8 + v7;
      }
      else
      {
LABEL_15:
        if ( v6 > v9 )
        {
LABEL_10:
          v11 = v8 + v6;
          goto LABEL_11;
        }
      }
    }
LABEL_12:
    ++v3;
  }
}

// File Line: 521
// RVA: 0x992EE0
void __fastcall Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(Scaleform::Render::Text::HighlighterPosIterator *this)
{
  unsigned __int64 v1; // rbx
  Scaleform::Render::Text::HighlighterPosIterator *v2; // r8
  Scaleform::Render::Text::Highlighter *v3; // rcx
  unsigned __int64 v4; // r11
  char v5; // dl
  unsigned int v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // ebp
  char *v9; // rcx
  __int64 v10; // rax
  unsigned __int64 v11; // r9
  char v12; // al

  v1 = this->CurAdjStartPos;
  v2 = this;
  if ( v1 >= this->NumGlyphs )
  {
    *(_QWORD *)&this->CurDesc.Info.TextColor.Channels.Blue = 0i64;
    this->CurDesc.Info.BackgroundColor.Raw = 0;
    this->CurDesc.Info.Flags = 0;
    this->CurDesc.GlyphNum = 0i64;
    this->CurDesc.AdjStartPos = v1;
    this->CurDesc.Id = 0;
  }
  else
  {
    v3 = this->pManager;
    v4 = v3->Highlighters.Data.Size;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    if ( v4 )
    {
      v9 = &v3->Highlighters.Data.Data->Info.Flags;
      do
      {
        v10 = *((_QWORD *)v9 - 3);
        if ( v10 )
        {
          v11 = *((_QWORD *)v9 - 4);
          if ( v1 >= v11 && v1 < v11 + v10 )
          {
            v12 = *v9;
            if ( *v9 & 7 )
              v5 = v12 & 7 | v5 & 0xF8;
            if ( v12 & 8 )
            {
              v8 = *((_DWORD *)v9 - 3);
              v5 |= 8u;
            }
            if ( v12 & 0x10 )
            {
              v7 = *((_DWORD *)v9 - 2);
              v5 |= 0x10u;
            }
            if ( v12 & 0x20 )
            {
              v6 = *((_DWORD *)v9 - 1);
              v5 |= 0x20u;
            }
          }
        }
        v9 += 64;
        --v4;
      }
      while ( v4 );
    }
    v2->CurDesc.StartPos = -1i64;
    v2->CurDesc.Length = 0i64;
    v2->CurDesc.Offset = -1i64;
    v2->CurDesc.AdjStartPos = 0i64;
    v2->CurDesc.Id = 0;
    v2->CurDesc.Info.BackgroundColor.Raw = v8;
    v2->CurDesc.Info.TextColor.Raw = v7;
    v2->CurDesc.Info.UnderlineColor.Raw = v6;
    v2->CurDesc.Info.Flags = v5;
    v2->CurDesc.GlyphNum = 1i64;
    v2->CurDesc.AdjStartPos = v1;
    v2->CurDesc.Id = 0;
  }
}

