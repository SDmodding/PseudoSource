// File Line: 123
// RVA: 0x9677A0
Scaleform::Render::Text::HighlightDesc *__fastcall Scaleform::Render::Text::Highlighter::CreateHighlighter(
        Scaleform::Render::Text::Highlighter *this,
        Scaleform::Render::Text::HighlightDesc *desc)
{
  unsigned int Id; // esi
  __int64 Size; // r8
  unsigned __int64 v6; // rbx

  *(_WORD *)&this->Valid = 0;
  Id = desc->Id;
  if ( Scaleform::Render::Text::Highlighter::GetHighlighterPtr(this, Id) )
    return 0i64;
  Size = this->Highlighters.Data.Size;
  v6 = 0i64;
  while ( Size > 0 )
  {
    if ( (int)(this->Highlighters.Data.Data[(Size >> 1) + v6].Id - Id) >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v6 += (Size >> 1) + 1;
      Size += -1 - (Size >> 1);
    }
  }
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->Highlighters,
    v6,
    desc);
  return &this->Highlighters.Data.Data[v6];
}

// File Line: 139
// RVA: 0x9853C0
Scaleform::Render::Text::HighlightDesc *__fastcall Scaleform::Render::Text::Highlighter::GetHighlighterPtr(
        Scaleform::Render::Text::Highlighter *this,
        unsigned int id)
{
  __int64 Size; // rax
  unsigned __int64 v3; // r9
  Scaleform::Render::Text::HighlightDesc *result; // rax

  Size = this->Highlighters.Data.Size;
  v3 = 0i64;
  while ( Size > 0 )
  {
    if ( (int)(this->Highlighters.Data.Data[(Size >> 1) + v3].Id - id) >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v3 += (Size >> 1) + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v3 >= this->Highlighters.Data.Size )
    return 0i64;
  result = &this->Highlighters.Data.Data[v3];
  if ( result->Id != id )
    return 0i64;
  return result;
}

// File Line: 180
// RVA: 0x98AB80
Scaleform::Render::Text::HighlighterPosIterator *__fastcall Scaleform::Render::Text::Highlighter::GetPosIterator(
        Scaleform::Render::Text::Highlighter *this,
        Scaleform::Render::Text::HighlighterPosIterator *result,
        unsigned __int64 startPos,
        unsigned __int64 len)
{
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
  Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(result);
  return result;
}

// File Line: 190
// RVA: 0x9BE4B0
void __fastcall Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(
        Scaleform::Render::Text::Highlighter *this,
        Scaleform::Render::Text::CompositionStringBase *pcs)
{
  unsigned __int64 Size; // rdi
  __int64 v3; // r8
  Scaleform::Render::Text::HighlightDesc *Data; // rax
  unsigned __int64 StartPos; // rdx
  unsigned __int64 Length; // r9
  unsigned __int64 CorrectionLen; // rbx
  unsigned __int64 CorrectionPos; // r11
  __int64 Offset; // rcx
  unsigned __int64 v11; // rcx

  Size = this->Highlighters.Data.Size;
  v3 = 0i64;
  this->CorrectionLen = 0i64;
  this->CorrectionPos = 0i64;
  for ( *(_WORD *)&this->Valid = 0; Size; --Size )
  {
    Data = this->Highlighters.Data.Data;
    StartPos = this->Highlighters.Data.Data[v3].StartPos;
    Length = this->Highlighters.Data.Data[v3].Length;
    Data[v3].AdjStartPos = StartPos;
    Data[v3].GlyphNum = Length;
    CorrectionLen = this->CorrectionLen;
    if ( CorrectionLen )
    {
      CorrectionPos = this->CorrectionPos;
      if ( !Length )
        goto LABEL_9;
      if ( StartPos > CorrectionPos )
        goto LABEL_10;
      if ( CorrectionPos < Length + StartPos )
      {
        Offset = Data[v3].Offset;
        if ( Offset >= 0 )
        {
          v11 = StartPos + Offset;
LABEL_11:
          Data[v3].AdjStartPos = v11;
          goto LABEL_12;
        }
        Data[v3].GlyphNum = CorrectionLen + Length;
      }
      else
      {
LABEL_9:
        if ( StartPos > CorrectionPos )
        {
LABEL_10:
          v11 = CorrectionLen + StartPos;
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
void __fastcall Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(
        Scaleform::Render::Text::HighlighterPosIterator *this)
{
  unsigned __int64 CurAdjStartPos; // rbx
  Scaleform::Render::Text::Highlighter *pManager; // rcx
  unsigned __int64 Size; // r11
  char v5; // dl
  unsigned int v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // ebp
  char *p_Flags; // rcx
  __int64 v10; // rax
  unsigned __int64 v11; // r9
  char v12; // al

  CurAdjStartPos = this->CurAdjStartPos;
  if ( CurAdjStartPos >= this->NumGlyphs )
  {
    *(_QWORD *)&this->CurDesc.Info.TextColor.Channels.Blue = 0i64;
    this->CurDesc.Info.BackgroundColor.Raw = 0;
    this->CurDesc.Info.Flags = 0;
    this->CurDesc.GlyphNum = 0i64;
    this->CurDesc.AdjStartPos = CurAdjStartPos;
    this->CurDesc.Id = 0;
  }
  else
  {
    pManager = this->pManager;
    Size = pManager->Highlighters.Data.Size;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    if ( Size )
    {
      p_Flags = &pManager->Highlighters.Data.Data->Info.Flags;
      do
      {
        v10 = *((_QWORD *)p_Flags - 3);
        if ( v10 )
        {
          v11 = *((_QWORD *)p_Flags - 4);
          if ( CurAdjStartPos >= v11 && CurAdjStartPos < v11 + v10 )
          {
            v12 = *p_Flags;
            if ( (*p_Flags & 7) != 0 )
              v5 = v12 & 7 | v5 & 0xF8;
            if ( (v12 & 8) != 0 )
            {
              v8 = *((_DWORD *)p_Flags - 3);
              v5 |= 8u;
            }
            if ( (v12 & 0x10) != 0 )
            {
              v7 = *((_DWORD *)p_Flags - 2);
              v5 |= 0x10u;
            }
            if ( (v12 & 0x20) != 0 )
            {
              v6 = *((_DWORD *)p_Flags - 1);
              v5 |= 0x20u;
            }
          }
        }
        p_Flags += 64;
        --Size;
      }
      while ( Size );
    }
    this->CurDesc.StartPos = -1i64;
    this->CurDesc.Length = 0i64;
    this->CurDesc.Offset = -1i64;
    this->CurDesc.AdjStartPos = 0i64;
    this->CurDesc.Id = 0;
    this->CurDesc.Info.BackgroundColor.Raw = v8;
    this->CurDesc.Info.TextColor.Raw = v7;
    this->CurDesc.Info.UnderlineColor.Raw = v6;
    this->CurDesc.Info.Flags = v5;
    this->CurDesc.GlyphNum = 1i64;
    this->CurDesc.AdjStartPos = CurAdjStartPos;
    this->CurDesc.Id = 0;
  }
}

