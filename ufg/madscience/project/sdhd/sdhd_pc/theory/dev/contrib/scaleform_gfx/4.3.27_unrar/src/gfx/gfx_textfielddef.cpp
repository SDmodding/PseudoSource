// File Line: 45
// RVA: 0x89E6E0
void __fastcall Scaleform::GFx::TextFieldDef::TextFieldDef(Scaleform::GFx::TextFieldDef *this)
{
  Scaleform::GFx::TextFieldDef *v1; // rbx
  volatile int v2; // et1
  __int64 v3; // rax
  Scaleform::GFx::ResourcePtr<Scaleform::GFx::FontResource> *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable';
  v2 = this->RefCount.Value;
  v3 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable';
  this->Id.Id = 0x40000;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::TextFieldDef::`vftable';
  v4 = &this->pFont;
  v4->HType = 0;
  v4->pResource = 0i64;
  this->FontId.Id = 0;
  Scaleform::StringLH::StringLH(&this->FontClass);
  *(_QWORD *)&v1->TextRect.x1 = 0i64;
  *(_QWORD *)&v1->TextRect.x2 = 0i64;
  v1->TextHeight = 1.0;
  *(_QWORD *)&v1->MaxLength = 0i64;
  *(_QWORD *)&v1->RightMargin = 0i64;
  v1->Leading = 0.0;
  Scaleform::StringLH::StringLH(&v1->DefaultText);
  Scaleform::StringLH::StringLH(&v1->VariableName);
  v1->Flags = 0;
  v1->Alignment = 0;
  *(_WORD *)&v1->ColorV.Channels.Green = 0;
  v1->ColorV.Channels.Blue = 0;
  v1->ColorV.Channels.Alpha = -1;
  *(_QWORD *)&v1->TextRect.x1 = 0i64;
  *(_QWORD *)&v1->TextRect.x2 = 0i64;
}

// File Line: 50
// RVA: 0x8A8120
void __fastcall Scaleform::GFx::TextFieldDef::~TextFieldDef(Scaleform::GFx::TextFieldDef *this)
{
  Scaleform::GFx::TextFieldDef *v1; // rsi
  Scaleform::GFx::Resource *v2; // rdi
  Scaleform::GFx::ResourceLibBase *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::TextFieldDef::`vftable';
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->VariableName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->DefaultText.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v1->pFont.HType == RH_Pointer )
  {
    v2 = v1->pFont.pResource;
    if ( v2 )
    {
      if ( !_InterlockedDecrement(&v2->RefCount.Value) )
      {
        v3 = v2->pLib;
        if ( v3 )
        {
          v3->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v2);
          v2->pLib = 0i64;
        }
        v2->vfptr->__vecDelDtor(v2, 1u);
      }
    }
  }
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable';
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable';
}

// File Line: 54
// RVA: 0x8FA060
void __fastcall Scaleform::GFx::TextFieldDef::Read(Scaleform::GFx::TextFieldDef *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::LoadProcess *v3; // rbp
  Scaleform::GFx::TextFieldDef *v4; // rsi
  Scaleform::GFx::Stream *v5; // rdi
  Scaleform::Render::Rect<float> *v6; // rbx
  __m128d v7; // xmm3
  __m128d v8; // xmm2
  double v9; // ST28_8
  double v10; // ST20_8
  int v11; // ST28_4
  bool v12; // r12
  bool v13; // r13
  bool v14; // r14
  bool v15; // bl
  bool v16; // r15
  int v17; // ST30_4
  __int64 v18; // r9
  unsigned __int16 v19; // r8
  Scaleform::GFx::Resource *v20; // rcx
  Scaleform::GFx::Resource *v21; // r14
  Scaleform::GFx::ResourceLibBase *v22; // rcx
  Scaleform::GFx::ResourceHandle::HandleType v23; // eax
  Scaleform::GFx::Resource *v24; // rbx
  Scaleform::GFx::ResourceLibBase *v25; // rcx
  unsigned __int64 v26; // r8
  __int64 v27; // r9
  unsigned __int16 v28; // r8
  __int64 v29; // rdx
  char v30; // cl
  __int64 v31; // r9
  unsigned __int16 v32; // r8
  __int64 v33; // rdx
  Scaleform::GFx::TextFieldDef::alignment v34; // ecx
  __int64 v35; // r9
  unsigned __int16 v36; // r8
  __int64 v37; // r9
  unsigned __int16 v38; // r8
  __int64 v39; // r9
  __int16 v40; // r8
  __int64 v41; // r9
  __int16 v42; // r8
  __m128d v43; // xmm3
  double v44; // ST28_8
  double v45; // ST20_8
  __int64 v46; // r8
  unsigned __int64 v47; // r9
  unsigned __int64 v48; // r8
  Scaleform::GFx::ResourceHandle phandle; // [rsp+48h] [rbp-50h]
  bool v50; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::ResourceId rid; // [rsp+A8h] [rbp+10h]

  v3 = p;
  v4 = this;
  v5 = p->pAltStream;
  if ( !v5 )
    v5 = &p->ProcessInfo.Stream;
  v6 = &this->TextRect;
  Scaleform::GFx::Stream::ReadRect(v5, &this->TextRect);
  v7 = _mm_cvtps_pd((__m128)LODWORD(v4->TextRect.y1));
  v8 = _mm_cvtps_pd((__m128)LODWORD(v6->x1));
  v9 = v4->TextRect.y2;
  v10 = v4->TextRect.x2;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    "  TextRect = { l: %f, t: %f, r: %f, b: %f }\n");
  v5->UnusedBits = 0;
  v50 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 1u;
  else
    v4->Flags &= 0xFFFEu;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 2u;
  else
    v4->Flags &= 0xFFFDu;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 4u;
  else
    v4->Flags &= 0xFFFBu;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 8u;
  else
    v4->Flags &= 0xFFF7u;
  v11 = (v4->Flags >> 3) & 1;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    "  WordWrap = %d, Multiline = %d, Password = %d, ReadOnly = %d\n");
  v12 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  v13 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  v14 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  v15 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 0x10u;
  else
    v4->Flags &= 0xFFEFu;
  v16 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags &= 0xFFDFu;
  else
    v4->Flags |= 0x20u;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 0x40u;
  else
    v4->Flags &= 0xFFBFu;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 0x1000u;
  else
    v4->Flags &= 0xEFFFu;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 0x80u;
  else
    v4->Flags &= 0xFF7Fu;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags &= 0xFEFFu;
  else
    v4->Flags |= 0x100u;
  v17 = (v4->Flags >> 8) & 1;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    "  AutoSize = %d, Selectable = %d, Border = %d, Html = %d, UseDeviceFont = %d\n");
  if ( v14 )
  {
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
    v18 = v5->Pos;
    v19 = (unsigned __int8)v5->pBuffer[v18] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v18 + 1)] << 8);
    v5->Pos = v18 + 2;
    v4->FontId.Id = v19;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "  HasFont: font id = %d\n");
    phandle.HType = 0;
    phandle.pResource = 0i64;
    rid.Id = v4->FontId.Id;
    Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(v3->pLoadData.pObject, &phandle, (__int64)&rid);
    v20 = phandle.pResource;
    if ( phandle.HType == RH_Pointer && phandle.pResource )
    {
      _InterlockedExchangeAdd(&phandle.pResource->RefCount.Value, 1u);
      v20 = phandle.pResource;
    }
    if ( v4->pFont.HType == RH_Pointer )
    {
      v21 = v4->pFont.pResource;
      if ( v21 )
      {
        if ( !_InterlockedDecrement(&v21->RefCount.Value) )
        {
          v22 = v21->pLib;
          if ( v22 )
          {
            v22->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, (unsigned int)v21);
            v21->pLib = 0i64;
          }
          v21->vfptr->__vecDelDtor(v21, 1u);
        }
        v20 = phandle.pResource;
      }
    }
    v23 = phandle.HType;
    v4->pFont.HType = phandle.HType;
    v4->pFont.pResource = v20;
    if ( v23 == RH_Pointer && v20 && !_InterlockedDecrement(&v20->RefCount.Value) )
    {
      v24 = phandle.pResource;
      v25 = phandle.pResource->pLib;
      if ( v25 )
      {
        v25->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v25->vfptr, (unsigned int)phandle.pResource);
        v24->pLib = 0i64;
      }
      v24->vfptr->__vecDelDtor(v24, 1u);
    }
  }
  else
  {
    if ( !v15 )
      goto LABEL_57;
    Scaleform::GFx::Stream::ReadString(v5, (Scaleform::String *)&v4->FontClass.0);
    v26 = v4->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "  HasFontClass: font class = %s\n");
  }
  v5->UnusedBits = 0;
  if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
  v27 = v5->Pos;
  v28 = (unsigned __int8)v5->pBuffer[v27] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v27 + 1)] << 8);
  v5->Pos = v27 + 2;
  v4->TextHeight = (float)v28;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    "  FontHeight = %f\n");
LABEL_57:
  if ( v12 )
  {
    Scaleform::GFx::Stream::ReadRgb(v5, &v4->ColorV);
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 1);
    v29 = v5->Pos;
    v30 = v5->pBuffer[v29];
    v5->Pos = v29 + 1;
    v4->ColorV.Channels.Alpha = v30;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "  HasColor\n");
  }
  if ( v13 )
  {
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
    v31 = v5->Pos;
    v32 = (unsigned __int8)v5->pBuffer[v31] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v31 + 1)] << 8);
    v5->Pos = v31 + 2;
    v4->MaxLength = v32;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "  HasMaxLength: len = %d\n");
  }
  if ( v16 )
  {
    v4->Flags |= 0x200u;
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 1);
    v33 = v5->Pos;
    v34 = (unsigned __int8)v5->pBuffer[v33];
    v5->Pos = v33 + 1;
    v4->Alignment = v34;
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
    v35 = v5->Pos;
    v36 = (unsigned __int8)v5->pBuffer[v35] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v35 + 1)] << 8);
    v5->Pos = v35 + 2;
    v4->LeftMargin = (float)v36;
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
    v37 = v5->Pos;
    v38 = (unsigned __int8)v5->pBuffer[v37] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v37 + 1)] << 8);
    v5->Pos = v37 + 2;
    v4->RightMargin = (float)v38;
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
    v39 = v5->Pos;
    v40 = (unsigned __int8)v5->pBuffer[v39] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v39 + 1)] << 8);
    v5->Pos = v39 + 2;
    v4->Indent = (float)v40;
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
    v41 = v5->Pos;
    v42 = (unsigned __int8)v5->pBuffer[v41] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v41 + 1)] << 8);
    v5->Pos = v41 + 2;
    v4->Leading = (float)v42;
    v43 = _mm_cvtps_pd((__m128)LODWORD(v4->LeftMargin));
    v44 = v4->Indent;
    v45 = v4->RightMargin;
    v46 = (unsigned int)v4->Alignment;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "  HasLayout: alignment = %d, leftmarg = %f, rightmarg = %f, indent = %f, leading = %f\n");
  }
  Scaleform::GFx::Stream::ReadString(v5, (Scaleform::String *)&v4->VariableName.0);
  if ( v50 )
    Scaleform::GFx::Stream::ReadString(v5, (Scaleform::String *)&v4->DefaultText.0);
  v47 = (v4->DefaultText.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
  v48 = v4->VariableName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    "EditTextChar, varname = %s, text = %s\n");
}

// File Line: 162
// RVA: 0x86DE30
void __fastcall Scaleform::GFx::GFx_DefineEditTextLoader(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::TagInfo *v2; // r14
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::GFx::Stream *v4; // rbx
  __int64 v5; // r8
  int v6; // esi
  Scaleform::GFx::TextFieldDef *v7; // rax
  Scaleform::GFx::TextFieldDef *v8; // rax
  Scaleform::GFx::TextFieldDef *v9; // rbx
  Scaleform::GFx::ResourceLibBase *v10; // rcx
  Scaleform::MemoryHeap *rid; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::TextFieldDef *v12; // [rsp+58h] [rbp+10h]

  v2 = tagInfo;
  v3 = p;
  v4 = p->pAltStream;
  if ( !v4 )
    v4 = &p->ProcessInfo.Stream;
  v4->UnusedBits = 0;
  if ( (signed int)(v4->DataSize - v4->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
  v5 = v4->Pos;
  LOWORD(v6) = (unsigned __int8)v4->pBuffer[v5] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v5 + 1)] << 8);
  v4->Pos = v5 + 2;
  rid = v3->pLoadData.pObject->pHeap;
  v7 = (Scaleform::GFx::TextFieldDef *)rid->vfptr->Alloc((Scaleform::MemoryHeap *)p, 144ui64, 0i64);
  v12 = v7;
  if ( v7 )
  {
    Scaleform::GFx::TextFieldDef::TextFieldDef(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v12 = v9;
  v6 = (unsigned __int16)v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "EditTextChar, id = %d\n",
    (unsigned __int16)v6);
  Scaleform::GFx::TextFieldDef::Read(v9, v3, v2->TagType);
  if ( v3->LoadState == LS_LoadingRoot )
  {
    LODWORD(rid) = v6;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
      v3->pLoadData.pObject,
      (Scaleform::GFx::ResourceId)&rid,
      (Scaleform::GFx::Resource *)&v9->vfptr);
  }
  if ( v9 && !_InterlockedDecrement(&v9->RefCount.Value) )
  {
    v10 = v9->pLib;
    if ( v10 )
    {
      v10->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, (unsigned int)v9);
      v9->pLib = 0i64;
    }
    v9->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v9->vfptr, 1u);
  }
}

// File Line: 219
// RVA: 0x8CBB80
Scaleform::GFx::TextKeyMap::KeyMapEntry *__fastcall Scaleform::GFx::TextKeyMap::FindFirstEntry(Scaleform::GFx::TextKeyMap *this, unsigned int keyCode)
{
  signed __int64 v2; // rax
  unsigned __int64 v3; // r9
  Scaleform::GFx::TextKeyMap::KeyMapEntry *result; // rax

  v2 = this->Map.Data.Size;
  v3 = 0i64;
  while ( v2 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v2 >> 1) + v3].KeyCode - keyCode) >= 0 )
    {
      v2 >>= 1;
    }
    else
    {
      v3 += (v2 >> 1) + 1;
      v2 += -1 - (v2 >> 1);
    }
  }
  if ( v3 >= this->Map.Data.Size || (result = &this->Map.Data.Data[v3], result->KeyCode != keyCode) )
    result = 0i64;
  return result;
}

// File Line: 237
// RVA: 0x8CB6D0
Scaleform::GFx::TextKeyMap::KeyMapEntry *__fastcall Scaleform::GFx::TextKeyMap::Find(Scaleform::GFx::TextKeyMap *this, unsigned int keyCode, Scaleform::KeyModifiers *specKeys, Scaleform::GFx::TextKeyMap::KeyState state)
{
  Scaleform::GFx::TextKeyMap::KeyState v4; // edi
  Scaleform::KeyModifiers *v5; // rsi
  Scaleform::GFx::TextKeyMap *v6; // rbx
  Scaleform::GFx::TextKeyMap::KeyMapEntry *result; // rax
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v8; // r8
  signed __int64 v9; // rdx
  signed __int64 v10; // rdx

  v4 = state;
  v5 = specKeys;
  v6 = this;
  result = Scaleform::GFx::TextKeyMap::FindFirstEntry(this, keyCode);
  if ( !result )
    return 0i64;
  while ( result->mState != v4 || (result->SpecKeysPressed & (unsigned __int8)v5->States) != result->SpecKeysPressed )
  {
    v8 = v6->Map.Data.Data;
    v9 = result - v8;
    if ( v9 + 1 < v6->Map.Data.Size )
    {
      v10 = v9;
      if ( v8[v10 + 1].KeyCode == result->KeyCode )
      {
        result = &v8[v10 + 1];
        if ( result )
          continue;
      }
    }
    return 0i64;
  }
  return result;
}

// File Line: 250
// RVA: 0x8E4850
Scaleform::GFx::TextKeyMap *__fastcall Scaleform::GFx::TextKeyMap::InitWindowsKeyMap(Scaleform::GFx::TextKeyMap *this)
{
  unsigned __int64 v1; // r10
  Scaleform::GFx::TextKeyMap *v2; // rsi
  unsigned __int64 v3; // rdi
  signed __int64 v4; // rdx
  unsigned __int64 v5; // r8
  signed __int64 v6; // rdi
  unsigned __int64 v7; // r10
  unsigned __int64 v8; // rdi
  signed __int64 v9; // rcx
  unsigned __int64 v10; // r8
  signed __int64 v11; // rdi
  unsigned __int64 v12; // r10
  unsigned __int64 v13; // rdi
  signed __int64 v14; // rcx
  unsigned __int64 v15; // r8
  signed __int64 v16; // rdi
  unsigned __int64 v17; // r10
  unsigned __int64 v18; // rdi
  signed __int64 v19; // rcx
  unsigned __int64 v20; // r8
  signed __int64 v21; // rdi
  unsigned __int64 v22; // r10
  unsigned __int64 v23; // rdi
  signed __int64 v24; // rcx
  unsigned __int64 v25; // r8
  signed __int64 v26; // rdi
  unsigned __int64 v27; // r10
  unsigned __int64 v28; // rdi
  signed __int64 v29; // rcx
  unsigned __int64 v30; // r8
  signed __int64 v31; // rdi
  unsigned __int64 v32; // r10
  unsigned __int64 v33; // rdi
  signed __int64 v34; // rcx
  unsigned __int64 v35; // r8
  signed __int64 v36; // rdi
  unsigned __int64 v37; // r10
  unsigned __int64 v38; // rdi
  signed __int64 v39; // rcx
  unsigned __int64 v40; // r8
  signed __int64 v41; // rdi
  unsigned __int64 v42; // r10
  unsigned __int64 v43; // rdi
  signed __int64 v44; // rcx
  unsigned __int64 v45; // r8
  signed __int64 v46; // rdi
  unsigned __int64 v47; // r10
  unsigned __int64 v48; // rdi
  signed __int64 v49; // rcx
  unsigned __int64 v50; // r8
  signed __int64 v51; // rdi
  unsigned __int64 v52; // r10
  unsigned __int64 v53; // rdi
  signed __int64 v54; // rcx
  unsigned __int64 v55; // r8
  signed __int64 v56; // rdi
  unsigned __int64 v57; // r10
  unsigned __int64 v58; // rdi
  signed __int64 v59; // rcx
  unsigned __int64 v60; // r8
  signed __int64 v61; // rdi
  unsigned __int64 v62; // r10
  unsigned __int64 v63; // rdi
  signed __int64 v64; // rcx
  unsigned __int64 v65; // r8
  signed __int64 v66; // rdi
  unsigned __int64 v67; // r10
  unsigned __int64 v68; // rdi
  signed __int64 v69; // rcx
  unsigned __int64 v70; // r8
  signed __int64 v71; // rdi
  unsigned __int64 v72; // r10
  unsigned __int64 v73; // rdi
  signed __int64 v74; // rdx
  unsigned __int64 v75; // r8
  signed __int64 v76; // rdi
  unsigned __int64 v77; // r10
  unsigned __int64 v78; // rdi
  signed __int64 v79; // rcx
  unsigned __int64 v80; // r8
  signed __int64 v81; // rdi
  unsigned __int64 v82; // r10
  unsigned __int64 v83; // rdi
  signed __int64 v84; // rcx
  unsigned __int64 v85; // r8
  signed __int64 v86; // rdi
  unsigned __int64 v87; // r10
  unsigned __int64 v88; // rdi
  signed __int64 v89; // rcx
  unsigned __int64 v90; // r8
  signed __int64 v91; // rdi
  unsigned __int64 v92; // r10
  unsigned __int64 v93; // rdi
  signed __int64 v94; // rcx
  unsigned __int64 v95; // r8
  signed __int64 v96; // rdi
  unsigned __int64 v97; // r10
  unsigned __int64 v98; // rdi
  signed __int64 v99; // rcx
  unsigned __int64 v100; // r8
  signed __int64 v101; // rdi
  unsigned __int64 v102; // r10
  unsigned __int64 v103; // rdi
  signed __int64 v104; // rdx
  unsigned __int64 v105; // r8
  signed __int64 v106; // rdi
  unsigned __int64 v107; // r10
  unsigned __int64 v108; // rdi
  signed __int64 v109; // rcx
  unsigned __int64 v110; // r8
  signed __int64 v111; // rdi
  unsigned __int64 v112; // r10
  unsigned __int64 v113; // rdi
  signed __int64 v114; // rdx
  unsigned __int64 v115; // r8
  signed __int64 v116; // rdi
  unsigned __int64 v117; // r10
  unsigned __int64 v118; // rdi
  signed __int64 v119; // rdx
  unsigned __int64 v120; // r8
  Scaleform::GFx::TextKeyMap *result; // rax
  signed __int64 v122; // rdi

  v1 = this->Map.Data.Size;
  v2 = this;
  v3 = 0i64;
  v4 = v1;
  while ( v4 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v4 >> 1) + v3].KeyCode - 16) >= 0 )
    {
      v4 >>= 1;
    }
    else
    {
      v3 += (v4 >> 1) + 1;
      v4 += -1 - (v4 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Map.Data,
    v1 + 1);
  v5 = v2->Map.Data.Size;
  if ( v3 < v5 - 1 )
    memmove(&v2->Map.Data.Data[v3 + 1], &v2->Map.Data.Data[v3], 16 * (v5 - v3 - 1));
  v6 = (signed __int64)&v2->Map.Data.Data[v3];
  if ( v6 )
  {
    *(_DWORD *)v6 = 2;
    *(_QWORD *)(v6 + 4) = 16i64;
    *(_DWORD *)(v6 + 12) = 0;
  }
  v7 = v2->Map.Data.Size;
  v8 = 0i64;
  v9 = v7;
  while ( v9 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v9 >> 1) + v8].KeyCode - 16) >= 0 )
    {
      v9 >>= 1;
    }
    else
    {
      v8 += (v9 >> 1) + 1;
      v9 += -1 - (v9 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v7 + 1);
  v10 = v2->Map.Data.Size;
  if ( v8 < v10 - 1 )
    memmove(&v2->Map.Data.Data[v8 + 1], &v2->Map.Data.Data[v8], 16 * (v10 - v8 - 1));
  v11 = (signed __int64)&v2->Map.Data.Data[v8];
  if ( v11 )
  {
    *(_DWORD *)v11 = 3;
    *(_QWORD *)(v11 + 4) = 16i64;
    *(_DWORD *)(v11 + 12) = 1;
  }
  v12 = v2->Map.Data.Size;
  v13 = 0i64;
  v14 = v12;
  while ( v14 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v14 >> 1) + v13].KeyCode - 38) >= 0 )
    {
      v14 >>= 1;
    }
    else
    {
      v13 += (v14 >> 1) + 1;
      v14 += -1 - (v14 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v12 + 1);
  v15 = v2->Map.Data.Size;
  if ( v13 < v15 - 1 )
    memmove(&v2->Map.Data.Data[v13 + 1], &v2->Map.Data.Data[v13], 16 * (v15 - v13 - 1));
  v16 = (signed __int64)&v2->Map.Data.Data[v13];
  if ( v16 )
  {
    *(_DWORD *)v16 = 6;
    *(_QWORD *)(v16 + 4) = 38i64;
    *(_DWORD *)(v16 + 12) = 0;
  }
  v17 = v2->Map.Data.Size;
  v18 = 0i64;
  v19 = v17;
  while ( v19 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v19 >> 1) + v18].KeyCode - 40) >= 0 )
    {
      v19 >>= 1;
    }
    else
    {
      v18 += (v19 >> 1) + 1;
      v19 += -1 - (v19 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v17 + 1);
  v20 = v2->Map.Data.Size;
  if ( v18 < v20 - 1 )
    memmove(&v2->Map.Data.Data[v18 + 1], &v2->Map.Data.Data[v18], 16 * (v20 - v18 - 1));
  v21 = (signed __int64)&v2->Map.Data.Data[v18];
  if ( v21 )
  {
    *(_DWORD *)v21 = 7;
    *(_QWORD *)(v21 + 4) = 40i64;
    *(_DWORD *)(v21 + 12) = 0;
  }
  v22 = v2->Map.Data.Size;
  v23 = 0i64;
  v24 = v22;
  while ( v24 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v24 >> 1) + v23].KeyCode - 37) >= 0 )
    {
      v24 >>= 1;
    }
    else
    {
      v23 += (v24 >> 1) + 1;
      v24 += -1 - (v24 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v22 + 1);
  v25 = v2->Map.Data.Size;
  if ( v23 < v25 - 1 )
    memmove(&v2->Map.Data.Data[v23 + 1], &v2->Map.Data.Data[v23], 16 * (v25 - v23 - 1));
  v26 = (signed __int64)&v2->Map.Data.Data[v23];
  if ( v26 )
  {
    *(_DWORD *)v26 = 4;
    *(_QWORD *)(v26 + 4) = 37i64;
    *(_DWORD *)(v26 + 12) = 0;
  }
  v27 = v2->Map.Data.Size;
  v28 = 0i64;
  v29 = v27;
  while ( v29 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v29 >> 1) + v28].KeyCode - 39) >= 0 )
    {
      v29 >>= 1;
    }
    else
    {
      v28 += (v29 >> 1) + 1;
      v29 += -1 - (v29 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v27 + 1);
  v30 = v2->Map.Data.Size;
  if ( v28 < v30 - 1 )
    memmove(&v2->Map.Data.Data[v28 + 1], &v2->Map.Data.Data[v28], 16 * (v30 - v28 - 1));
  v31 = (signed __int64)&v2->Map.Data.Data[v28];
  if ( v31 )
  {
    *(_DWORD *)v31 = 5;
    *(_QWORD *)(v31 + 4) = 39i64;
    *(_DWORD *)(v31 + 12) = 0;
  }
  v32 = v2->Map.Data.Size;
  v33 = 0i64;
  v34 = v32;
  while ( v34 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v34 >> 1) + v33].KeyCode - 33) >= 0 )
    {
      v34 >>= 1;
    }
    else
    {
      v33 += (v34 >> 1) + 1;
      v34 += -1 - (v34 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v32 + 1);
  v35 = v2->Map.Data.Size;
  if ( v33 < v35 - 1 )
    memmove(&v2->Map.Data.Data[v33 + 1], &v2->Map.Data.Data[v33], 16 * (v35 - v33 - 1));
  v36 = (signed __int64)&v2->Map.Data.Data[v33];
  if ( v36 )
  {
    *(_DWORD *)v36 = 8;
    *(_QWORD *)(v36 + 4) = 33i64;
    *(_DWORD *)(v36 + 12) = 0;
  }
  v37 = v2->Map.Data.Size;
  v38 = 0i64;
  v39 = v37;
  while ( v39 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v39 >> 1) + v38].KeyCode - 34) >= 0 )
    {
      v39 >>= 1;
    }
    else
    {
      v38 += (v39 >> 1) + 1;
      v39 += -1 - (v39 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v37 + 1);
  v40 = v2->Map.Data.Size;
  if ( v38 < v40 - 1 )
    memmove(&v2->Map.Data.Data[v38 + 1], &v2->Map.Data.Data[v38], 16 * (v40 - v38 - 1));
  v41 = (signed __int64)&v2->Map.Data.Data[v38];
  if ( v41 )
  {
    *(_DWORD *)v41 = 9;
    *(_QWORD *)(v41 + 4) = 34i64;
    *(_DWORD *)(v41 + 12) = 0;
  }
  v42 = v2->Map.Data.Size;
  v43 = 0i64;
  v44 = v42;
  while ( v44 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v44 >> 1) + v43].KeyCode - 36) >= 0 )
    {
      v44 >>= 1;
    }
    else
    {
      v43 += (v44 >> 1) + 1;
      v44 += -1 - (v44 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v42 + 1);
  v45 = v2->Map.Data.Size;
  if ( v43 < v45 - 1 )
    memmove(&v2->Map.Data.Data[v43 + 1], &v2->Map.Data.Data[v43], 16 * (v45 - v43 - 1));
  v46 = (signed __int64)&v2->Map.Data.Data[v43];
  if ( v46 )
  {
    *(_DWORD *)v46 = 10;
    *(_QWORD *)(v46 + 4) = 36i64;
    *(_DWORD *)(v46 + 12) = 0;
  }
  v47 = v2->Map.Data.Size;
  v48 = 0i64;
  v49 = v47;
  while ( v49 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v49 >> 1) + v48].KeyCode - 35) >= 0 )
    {
      v49 >>= 1;
    }
    else
    {
      v48 += (v49 >> 1) + 1;
      v49 += -1 - (v49 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v47 + 1);
  v50 = v2->Map.Data.Size;
  if ( v48 < v50 - 1 )
    memmove(&v2->Map.Data.Data[v48 + 1], &v2->Map.Data.Data[v48], 16 * (v50 - v48 - 1));
  v51 = (signed __int64)&v2->Map.Data.Data[v48];
  if ( v51 )
  {
    *(_DWORD *)v51 = 11;
    *(_QWORD *)(v51 + 4) = 35i64;
    *(_DWORD *)(v51 + 12) = 0;
  }
  v52 = v2->Map.Data.Size;
  v53 = 0i64;
  v54 = v52;
  while ( v54 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v54 >> 1) + v53].KeyCode - 33) >= 0 )
    {
      v54 >>= 1;
    }
    else
    {
      v53 += (v54 >> 1) + 1;
      v54 += -1 - (v54 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v52 + 1);
  v55 = v2->Map.Data.Size;
  if ( v53 < v55 - 1 )
    memmove(&v2->Map.Data.Data[v53 + 1], &v2->Map.Data.Data[v53], 16 * (v55 - v53 - 1));
  v56 = (signed __int64)&v2->Map.Data.Data[v53];
  if ( v56 )
  {
    *(_DWORD *)v56 = 12;
    *(_DWORD *)(v56 + 4) = 33;
    *(_QWORD *)(v56 + 8) = 2i64;
  }
  v57 = v2->Map.Data.Size;
  v58 = 0i64;
  v59 = v57;
  while ( v59 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v59 >> 1) + v58].KeyCode - 34) >= 0 )
    {
      v59 >>= 1;
    }
    else
    {
      v58 += (v59 >> 1) + 1;
      v59 += -1 - (v59 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v57 + 1);
  v60 = v2->Map.Data.Size;
  if ( v58 < v60 - 1 )
    memmove(&v2->Map.Data.Data[v58 + 1], &v2->Map.Data.Data[v58], 16 * (v60 - v58 - 1));
  v61 = (signed __int64)&v2->Map.Data.Data[v58];
  if ( v61 )
  {
    *(_DWORD *)v61 = 13;
    *(_DWORD *)(v61 + 4) = 34;
    *(_QWORD *)(v61 + 8) = 2i64;
  }
  v62 = v2->Map.Data.Size;
  v63 = 0i64;
  v64 = v62;
  while ( v64 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v64 >> 1) + v63].KeyCode - 36) >= 0 )
    {
      v64 >>= 1;
    }
    else
    {
      v63 += (v64 >> 1) + 1;
      v64 += -1 - (v64 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v62 + 1);
  v65 = v2->Map.Data.Size;
  if ( v63 < v65 - 1 )
    memmove(&v2->Map.Data.Data[v63 + 1], &v2->Map.Data.Data[v63], 16 * (v65 - v63 - 1));
  v66 = (signed __int64)&v2->Map.Data.Data[v63];
  if ( v66 )
  {
    *(_DWORD *)v66 = 14;
    *(_DWORD *)(v66 + 4) = 36;
    *(_QWORD *)(v66 + 8) = 2i64;
  }
  v67 = v2->Map.Data.Size;
  v68 = 0i64;
  v69 = v67;
  while ( v69 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v69 >> 1) + v68].KeyCode - 35) >= 0 )
    {
      v69 >>= 1;
    }
    else
    {
      v68 += (v69 >> 1) + 1;
      v69 += -1 - (v69 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v67 + 1);
  v70 = v2->Map.Data.Size;
  if ( v68 < v70 - 1 )
    memmove(&v2->Map.Data.Data[v68 + 1], &v2->Map.Data.Data[v68], 16 * (v70 - v68 - 1));
  v71 = (signed __int64)&v2->Map.Data.Data[v68];
  if ( v71 )
  {
    *(_DWORD *)v71 = 15;
    *(_DWORD *)(v71 + 4) = 35;
    *(_QWORD *)(v71 + 8) = 2i64;
  }
  v72 = v2->Map.Data.Size;
  v73 = 0i64;
  v74 = v72;
  while ( v74 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v74 >> 1) + v73].KeyCode - 8) >= 0 )
    {
      v74 >>= 1;
    }
    else
    {
      v73 += (v74 >> 1) + 1;
      v74 += -1 - (v74 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v72 + 1);
  v75 = v2->Map.Data.Size;
  if ( v73 < v75 - 1 )
    memmove(&v2->Map.Data.Data[v73 + 1], &v2->Map.Data.Data[v73], 16 * (v75 - v73 - 1));
  v76 = (signed __int64)&v2->Map.Data.Data[v73];
  if ( v76 )
  {
    *(_DWORD *)v76 = 16;
    *(_QWORD *)(v76 + 4) = 8i64;
    *(_DWORD *)(v76 + 12) = 0;
  }
  v77 = v2->Map.Data.Size;
  v78 = 0i64;
  v79 = v77;
  while ( v79 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v79 >> 1) + v78].KeyCode - 46) >= 0 )
    {
      v79 >>= 1;
    }
    else
    {
      v78 += (v79 >> 1) + 1;
      v79 += -1 - (v79 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v77 + 1);
  v80 = v2->Map.Data.Size;
  if ( v78 < v80 - 1 )
    memmove(&v2->Map.Data.Data[v78 + 1], &v2->Map.Data.Data[v78], 16 * (v80 - v78 - 1));
  v81 = (signed __int64)&v2->Map.Data.Data[v78];
  if ( v81 )
  {
    *(_DWORD *)v81 = 17;
    *(_QWORD *)(v81 + 4) = 46i64;
    *(_DWORD *)(v81 + 12) = 0;
  }
  v82 = v2->Map.Data.Size;
  v83 = 0i64;
  v84 = v82;
  while ( v84 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v84 >> 1) + v83].KeyCode - 13) >= 0 )
    {
      v84 >>= 1;
    }
    else
    {
      v83 += (v84 >> 1) + 1;
      v84 += -1 - (v84 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v82 + 1);
  v85 = v2->Map.Data.Size;
  if ( v83 < v85 - 1 )
    memmove(&v2->Map.Data.Data[v83 + 1], &v2->Map.Data.Data[v83], 16 * (v85 - v83 - 1));
  v86 = (signed __int64)&v2->Map.Data.Data[v83];
  if ( v86 )
  {
    *(_DWORD *)v86 = 18;
    *(_QWORD *)(v86 + 4) = 13i64;
    *(_DWORD *)(v86 + 12) = 0;
  }
  v87 = v2->Map.Data.Size;
  v88 = 0i64;
  v89 = v87;
  while ( v89 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v89 >> 1) + v88].KeyCode - 67) >= 0 )
    {
      v89 >>= 1;
    }
    else
    {
      v88 += (v89 >> 1) + 1;
      v89 += -1 - (v89 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v87 + 1);
  v90 = v2->Map.Data.Size;
  if ( v88 < v90 - 1 )
    memmove(&v2->Map.Data.Data[v88 + 1], &v2->Map.Data.Data[v88], 16 * (v90 - v88 - 1));
  v91 = (signed __int64)&v2->Map.Data.Data[v88];
  if ( v91 )
  {
    *(_DWORD *)v91 = 19;
    *(_DWORD *)(v91 + 4) = 67;
    *(_QWORD *)(v91 + 8) = 2i64;
  }
  v92 = v2->Map.Data.Size;
  v93 = 0i64;
  v94 = v92;
  while ( v94 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v94 >> 1) + v93].KeyCode - 45) >= 0 )
    {
      v94 >>= 1;
    }
    else
    {
      v93 += (v94 >> 1) + 1;
      v94 += -1 - (v94 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v92 + 1);
  v95 = v2->Map.Data.Size;
  if ( v93 < v95 - 1 )
    memmove(&v2->Map.Data.Data[v93 + 1], &v2->Map.Data.Data[v93], 16 * (v95 - v93 - 1));
  v96 = (signed __int64)&v2->Map.Data.Data[v93];
  if ( v96 )
  {
    *(_DWORD *)v96 = 19;
    *(_DWORD *)(v96 + 4) = 45;
    *(_QWORD *)(v96 + 8) = 2i64;
  }
  v97 = v2->Map.Data.Size;
  v98 = 0i64;
  v99 = v97;
  while ( v99 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v99 >> 1) + v98].KeyCode - 86) >= 0 )
    {
      v99 >>= 1;
    }
    else
    {
      v98 += (v99 >> 1) + 1;
      v99 += -1 - (v99 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v97 + 1);
  v100 = v2->Map.Data.Size;
  if ( v98 < v100 - 1 )
    memmove(&v2->Map.Data.Data[v98 + 1], &v2->Map.Data.Data[v98], 16 * (v100 - v98 - 1));
  v101 = (signed __int64)&v2->Map.Data.Data[v98];
  if ( v101 )
  {
    *(_DWORD *)v101 = 20;
    *(_DWORD *)(v101 + 4) = 86;
    *(_QWORD *)(v101 + 8) = 2i64;
  }
  v102 = v2->Map.Data.Size;
  v103 = 0i64;
  v104 = v102;
  while ( v104 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v104 >> 1) + v103].KeyCode - 45) >= 0 )
    {
      v104 >>= 1;
    }
    else
    {
      v103 += (v104 >> 1) + 1;
      v104 += -1 - (v104 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v102 + 1);
  v105 = v2->Map.Data.Size;
  if ( v103 < v105 - 1 )
    memmove(&v2->Map.Data.Data[v103 + 1], &v2->Map.Data.Data[v103], 16 * (v105 - v103 - 1));
  v106 = (signed __int64)&v2->Map.Data.Data[v103];
  if ( v106 )
  {
    *(_DWORD *)v106 = 20;
    *(_DWORD *)(v106 + 4) = 45;
    *(_QWORD *)(v106 + 8) = 1i64;
  }
  v107 = v2->Map.Data.Size;
  v108 = 0i64;
  v109 = v107;
  while ( v109 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v109 >> 1) + v108].KeyCode - 88) >= 0 )
    {
      v109 >>= 1;
    }
    else
    {
      v108 += (v109 >> 1) + 1;
      v109 += -1 - (v109 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v107 + 1);
  v110 = v2->Map.Data.Size;
  if ( v108 < v110 - 1 )
    memmove(&v2->Map.Data.Data[v108 + 1], &v2->Map.Data.Data[v108], 16 * (v110 - v108 - 1));
  v111 = (signed __int64)&v2->Map.Data.Data[v108];
  if ( v111 )
  {
    *(_DWORD *)v111 = 21;
    *(_DWORD *)(v111 + 4) = 88;
    *(_QWORD *)(v111 + 8) = 2i64;
  }
  v112 = v2->Map.Data.Size;
  v113 = 0i64;
  v114 = v112;
  while ( v114 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v114 >> 1) + v113].KeyCode - 46) >= 0 )
    {
      v114 >>= 1;
    }
    else
    {
      v113 += (v114 >> 1) + 1;
      v114 += -1 - (v114 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v112 + 1);
  v115 = v2->Map.Data.Size;
  if ( v113 < v115 - 1 )
    memmove(&v2->Map.Data.Data[v113 + 1], &v2->Map.Data.Data[v113], 16 * (v115 - v113 - 1));
  v116 = (signed __int64)&v2->Map.Data.Data[v113];
  if ( v116 )
  {
    *(_DWORD *)v116 = 21;
    *(_DWORD *)(v116 + 4) = 46;
    *(_QWORD *)(v116 + 8) = 1i64;
  }
  v117 = v2->Map.Data.Size;
  v118 = 0i64;
  v119 = v117;
  while ( v119 > 0 )
  {
    if ( (signed int)(v2->Map.Data.Data[(v119 >> 1) + v118].KeyCode - 65) >= 0 )
    {
      v119 >>= 1;
    }
    else
    {
      v118 += (v119 >> 1) + 1;
      v119 += -1 - (v119 >> 1);
    }
  }
  Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->Map.Data,
    v117 + 1);
  v120 = v2->Map.Data.Size;
  if ( v118 < v120 - 1 )
    memmove(&v2->Map.Data.Data[v118 + 1], &v2->Map.Data.Data[v118], 16 * (v120 - v118 - 1));
  result = v2;
  v122 = (signed __int64)&v2->Map.Data.Data[v118];
  if ( v122 )
  {
    *(_DWORD *)v122 = 22;
    *(_DWORD *)(v122 + 4) = 65;
    *(_QWORD *)(v122 + 8) = 2i64;
  }
  return result;
}

// File Line: 288
// RVA: 0x870570
void __fastcall Scaleform::GFx::GFx_CSMTextSettings(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // rdi
  Scaleform::GFx::Stream *v3; // rbx
  __int64 v4; // r8
  unsigned __int16 v5; // si
  signed __int64 v6; // rbx
  unsigned int v7; // ebp
  __int64 v8; // r14
  __int64 v9; // r10
  __int64 v10; // r9
  const char *v11; // r8
  bool v12; // al
  Scaleform::GFx::Resource *v13; // rbx
  Scaleform::GFx::ResourceHandle::HandleType v14; // edi
  Scaleform::GFx::Resource *v15; // rbx
  Scaleform::GFx::ResourceLibBase *v16; // rcx
  Scaleform::GFx::ResourceHandle phandle; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ResourceId rid; // [rsp+60h] [rbp+8h]
  int v19; // [rsp+70h] [rbp+18h]

  v2 = p;
  v3 = p->pAltStream;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  v3->UnusedBits = 0;
  if ( (signed int)(v3->DataSize - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v4 = v3->Pos;
  v5 = (unsigned __int8)v3->pBuffer[v4] | (unsigned __int16)((unsigned __int8)v3->pBuffer[(unsigned int)(v4 + 1)] << 8);
  v3->Pos = v4 + 2;
  v6 = (signed __int64)v2->pAltStream;
  if ( !v6 )
    v6 = (signed __int64)&v2->ProcessInfo;
  v7 = Scaleform::GFx::Stream::ReadUInt((Scaleform::GFx::Stream *)v6, 2u);
  v8 = Scaleform::GFx::Stream::ReadUInt((Scaleform::GFx::Stream *)v6, 3u);
  *(_BYTE *)(v6 + 41) = 0;
  if ( *(_DWORD *)(v6 + 80) - *(_DWORD *)(v6 + 76) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer((Scaleform::GFx::Stream *)v6, 4);
  v9 = *(unsigned int *)(v6 + 76);
  v19 = *(unsigned __int8 *)(v9 + *(_QWORD *)(v6 + 96)) | ((*(unsigned __int8 *)((unsigned int)(v9 + 1)
                                                                               + *(_QWORD *)(v6 + 96)) | ((*(unsigned __int8 *)((unsigned int)(v9 + 2) + *(_QWORD *)(v6 + 96)) | (*(unsigned __int8 *)((unsigned int)(v9 + 3) + *(_QWORD *)(v6 + 96)) << 8)) << 8)) << 8);
  *(_DWORD *)(v6 + 76) = v9 + 4;
  *(_BYTE *)(v6 + 41) = 0;
  if ( *(_DWORD *)(v6 + 80) - ((signed int)v9 + 4) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer((Scaleform::GFx::Stream *)v6, 4);
  v10 = *(unsigned int *)(v6 + 76);
  rid.Id = *(unsigned __int8 *)(v10 + *(_QWORD *)(v6 + 96)) | ((*(unsigned __int8 *)((unsigned int)(v10 + 1)
                                                                                   + *(_QWORD *)(v6 + 96)) | ((*(unsigned __int8 *)((unsigned int)(v10 + 2) + *(_QWORD *)(v6 + 96)) | (*(unsigned __int8 *)((unsigned int)(v10 + 3) + *(_QWORD *)(v6 + 96)) << 8)) << 8)) << 8);
  *(_DWORD *)(v6 + 76) = v10 + 4;
  if ( *(_BYTE *)(v6 + 24) & 1 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "CSMTextSettings, id = %d\n",
      v5);
    v11 = "Internal";
    if ( !v7 )
      v11 = "System";
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "  FlagType = %s, GridFit = %s\n",
      v11,
      gridfittypes[v8],
      -2i64);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v2->vfptr,
      "  Thinkness = %f, Sharpnesss = %f\n",
      v19,
      rid.Id);
  }
  phandle.HType = 0;
  phandle.pResource = 0i64;
  rid.Id = v5;
  v12 = Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
          v2->pLoadData.pObject,
          &phandle,
          (Scaleform::GFx::ResourceId)&rid);
  v13 = phandle.pResource;
  v14 = phandle.HType;
  if ( v12 && phandle.HType == RH_Pointer && phandle.pResource )
  {
    if ( (phandle.pResource->vfptr->GetResourceTypeCode(phandle.pResource) & 0xFF00) == 33536 )
    {
      LOWORD(v13[5].RefCount.Value) |= 0x400u;
    }
    else if ( (v13->vfptr->GetResourceTypeCode(v13) & 0xFF00) == 33280 )
    {
      LOBYTE(v13[4].RefCount.Value) |= 1u;
    }
  }
  if ( v14 == RH_Pointer && v13 && !_InterlockedDecrement(&v13->RefCount.Value) )
  {
    v15 = phandle.pResource;
    v16 = phandle.pResource->pLib;
    if ( v16 )
    {
      v16->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v16->vfptr, (unsigned int)phandle.pResource);
      v15->pLib = 0i64;
    }
    v15->vfptr->__vecDelDtor(v15, 1u);
  }
}

// File Line: 358
// RVA: 0x90C800
void __fastcall Scaleform::GFx::Clipboard::SetText(Scaleform::GFx::Clipboard *this, Scaleform::String *str)
{
  Scaleform::GFx::Clipboard *v2; // rsi
  Scaleform::Render::Text::StyledText *v3; // rcx
  Scaleform::String *v4; // r14
  unsigned __int64 v5; // rbx
  char *v6; // rdx

  v2 = this;
  v3 = this->pStyledText;
  v4 = str;
  if ( v3 )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v3->vfptr);
    v2->pStyledText = 0i64;
  }
  v5 = Scaleform::String::GetLength(v4) + 1;
  Scaleform::WStringBuffer::Resize(&v2->PlainText, v5);
  Scaleform::UTF8Util::DecodeStringSafe(
    v2->PlainText.pText,
    v5,
    (const char *)((v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v6 = byte_1416A7BD8;
  if ( v2->PlainText.pText )
    v6 = (char *)v2->PlainText.pText;
  ((void (__fastcall *)(Scaleform::GFx::Clipboard *, char *, unsigned __int64))v2->vfptr[7].__vecDelDtor)(
    v2,
    v6,
    v2->PlainText.Length);
}

// File Line: 367
// RVA: 0x90C8B0
void __fastcall Scaleform::GFx::Clipboard::SetText(Scaleform::GFx::Clipboard *this, const wchar_t *ptext, unsigned __int64 len)
{
  Scaleform::GFx::Clipboard *v3; // rdi
  Scaleform::Render::Text::StyledText *v4; // rcx
  unsigned __int64 v5; // rsi
  const wchar_t *v6; // rbp
  char *v7; // rdx

  v3 = this;
  v4 = this->pStyledText;
  v5 = len;
  v6 = ptext;
  if ( v4 )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
    v3->pStyledText = 0i64;
  }
  Scaleform::WStringBuffer::SetString(&v3->PlainText, v6, v5);
  v7 = byte_1416A7BD8;
  if ( v3->PlainText.pText )
    v7 = (char *)v3->PlainText.pText;
  ((void (__fastcall *)(Scaleform::GFx::Clipboard *, char *, unsigned __int64))v3->vfptr[7].__vecDelDtor)(
    v3,
    v7,
    v3->PlainText.Length);
}

// File Line: 373
// RVA: 0x8DE810
Scaleform::WStringBuffer *__fastcall Scaleform::GFx::Clipboard::GetText(Scaleform::GFx::Clipboard *this)
{
  return &this->PlainText;
}

// File Line: 378
// RVA: 0x90C4E0
void __fastcall Scaleform::GFx::Clipboard::SetStyledText(Scaleform::GFx::Clipboard *this, Scaleform::Render::Text::StyledText *pstyledText)
{
  Scaleform::Render::Text::StyledText *v2; // r14
  Scaleform::GFx::Clipboard *v3; // rbp
  Scaleform::Render::Text::StyledText *v4; // rcx
  Scaleform::MemoryHeap *v5; // rsi
  Scaleform::Render::Text::Allocator *v6; // rax
  Scaleform::Render::Text::StyledText *v7; // rdi
  Scaleform::Render::Text::Allocator *v8; // rax
  Scaleform::Render::Text::Allocator *v9; // rbx
  Scaleform::Render::Text::StyledText *v10; // rax
  Scaleform::Render::Text::StyledText *v11; // rax

  v2 = pstyledText;
  v3 = this;
  v4 = this->pStyledText;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  v5 = Scaleform::Memory::pGlobalHeap;
  v6 = (Scaleform::Render::Text::Allocator *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               144ui64,
                                               0i64);
  v7 = 0i64;
  if ( v6 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v6, v5, 1);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = (Scaleform::Render::Text::StyledText *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v5->vfptr->Alloc)(
                                                 v5,
                                                 72i64);
  if ( v10 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v10, v9);
    v7 = v11;
  }
  v3->pStyledText = v7;
  Scaleform::Render::Text::StyledText::CopyStyledText(v2, v7, 0i64, 0xFFFFFFFFFFFFFFFFui64);
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v9->vfptr);
}

