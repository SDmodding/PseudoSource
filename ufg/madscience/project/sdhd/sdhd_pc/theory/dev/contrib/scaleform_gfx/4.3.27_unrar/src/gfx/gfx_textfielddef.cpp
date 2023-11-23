// File Line: 45
// RVA: 0x89E6E0
void __fastcall Scaleform::GFx::TextFieldDef::TextFieldDef(Scaleform::GFx::TextFieldDef *this)
{
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->Id.Id = 0x40000;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::TextFieldDef::`vftable;
  this->pFont.HType = RH_Pointer;
  this->pFont.pResource = 0i64;
  this->FontId.Id = 0;
  Scaleform::StringLH::StringLH(&this->FontClass);
  *(_QWORD *)&this->TextRect.x1 = 0i64;
  *(_QWORD *)&this->TextRect.x2 = 0i64;
  this->TextHeight = 1.0;
  *(_QWORD *)&this->MaxLength = 0i64;
  *(_QWORD *)&this->RightMargin = 0i64;
  this->Leading = 0.0;
  Scaleform::StringLH::StringLH(&this->DefaultText);
  Scaleform::StringLH::StringLH(&this->VariableName);
  this->Flags = 0;
  this->Alignment = ALIGN_LEFT;
  *(_WORD *)&this->ColorV.Channels.Green = 0;
  this->ColorV.Channels.Blue = 0;
  this->ColorV.Channels.Alpha = -1;
  *(_QWORD *)&this->TextRect.x1 = 0i64;
  *(_QWORD *)&this->TextRect.x2 = 0i64;
}

// File Line: 50
// RVA: 0x8A8120
void __fastcall Scaleform::GFx::TextFieldDef::~TextFieldDef(Scaleform::GFx::TextFieldDef *this)
{
  Scaleform::GFx::Resource *pResource; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::TextFieldDef::`vftable;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->VariableName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->DefaultText.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( this->pFont.HType == RH_Pointer )
  {
    pResource = this->pFont.pResource;
    if ( pResource )
    {
      if ( !_InterlockedDecrement(&pResource->RefCount.Value) )
      {
        pLib = pResource->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
          pResource->pLib = 0i64;
        }
        pResource->vfptr->__vecDelDtor(pResource, 1u);
      }
    }
  }
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 54
// RVA: 0x8FA060
void __fastcall Scaleform::GFx::TextFieldDef::Read(
        Scaleform::GFx::TextFieldDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  bool v6; // r12
  bool v7; // r13
  bool v8; // r14
  bool v9; // bl
  bool v10; // r15
  __int64 Pos; // r9
  unsigned __int16 v12; // r8
  Scaleform::GFx::Resource *pResource; // rcx
  Scaleform::GFx::Resource *v14; // r14
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceHandle::HandleType HType; // eax
  Scaleform::GFx::Resource *v17; // rbx
  Scaleform::GFx::ResourceLibBase *v18; // rcx
  __int64 v19; // r9
  unsigned __int16 v20; // r8
  __int64 v21; // rdx
  char v22; // cl
  __int64 v23; // r9
  unsigned __int16 v24; // r8
  __int64 v25; // rdx
  Scaleform::GFx::TextFieldDef::alignment v26; // ecx
  __int64 v27; // r9
  unsigned __int16 v28; // r8
  __int64 v29; // r9
  unsigned __int16 v30; // r8
  __int64 v31; // r9
  __int16 v32; // r8
  __int64 v33; // r9
  __int16 v34; // r8
  Scaleform::GFx::ResourceHandle phandle; // [rsp+48h] [rbp-50h] BYREF
  bool v36; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::ResourceId rid; // [rsp+A8h] [rbp+10h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &this->TextRect);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &pAltStream->Stream,
    "  TextRect = { l: %f, t: %f, r: %f, b: %f }\n");
  pAltStream->Stream.UnusedBits = 0;
  v36 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 8u;
  else
    this->Flags &= ~8u;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &pAltStream->Stream,
    "  WordWrap = %d, Multiline = %d, Password = %d, ReadOnly = %d\n");
  v6 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  v7 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  v8 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  v9 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 0x10u;
  else
    this->Flags &= ~0x10u;
  v10 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags &= ~0x20u;
  else
    this->Flags |= 0x20u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 0x40u;
  else
    this->Flags &= ~0x40u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 0x1000u;
  else
    this->Flags &= ~0x1000u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 0x80u;
  else
    this->Flags &= ~0x80u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags &= ~0x100u;
  else
    this->Flags |= 0x100u;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &pAltStream->Stream,
    "  AutoSize = %d, Selectable = %d, Border = %d, Html = %d, UseDeviceFont = %d\n");
  if ( v8 )
  {
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    Pos = pAltStream->Stream.Pos;
    v12 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
    pAltStream->Stream.Pos = Pos + 2;
    this->FontId.Id = v12;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  HasFont: font id = %d\n");
    phandle.HType = RH_Pointer;
    phandle.pResource = 0i64;
    rid.Id = this->FontId.Id;
    Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(p->pLoadData.pObject, &phandle, &rid);
    pResource = phandle.pResource;
    if ( phandle.HType == RH_Pointer && phandle.pResource )
    {
      _InterlockedExchangeAdd(&phandle.pResource->RefCount.Value, 1u);
      pResource = phandle.pResource;
    }
    if ( this->pFont.HType == RH_Pointer )
    {
      v14 = this->pFont.pResource;
      if ( v14 )
      {
        if ( !_InterlockedDecrement(&v14->RefCount.Value) )
        {
          pLib = v14->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v14);
            v14->pLib = 0i64;
          }
          v14->vfptr->__vecDelDtor(v14, 1u);
        }
        pResource = phandle.pResource;
      }
    }
    HType = phandle.HType;
    this->pFont.HType = phandle.HType;
    this->pFont.pResource = pResource;
    if ( HType == RH_Pointer && pResource && !_InterlockedDecrement(&pResource->RefCount.Value) )
    {
      v17 = phandle.pResource;
      v18 = phandle.pResource->pLib;
      if ( v18 )
      {
        v18->vfptr[1].__vecDelDtor(v18, (unsigned int)phandle.pResource);
        v17->pLib = 0i64;
      }
      v17->vfptr->__vecDelDtor(v17, 1u);
    }
  }
  else
  {
    if ( !v9 )
      goto LABEL_57;
    Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->FontClass);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &pAltStream->Stream,
      "  HasFontClass: font class = %s\n");
  }
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v19 = pAltStream->Stream.Pos;
  v20 = (unsigned __int8)pAltStream->Stream.pBuffer[v19] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v19 + 1)] << 8);
  pAltStream->Stream.Pos = v19 + 2;
  this->TextHeight = (float)v20;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  FontHeight = %f\n");
LABEL_57:
  if ( v6 )
  {
    Scaleform::GFx::Stream::ReadRgb(&pAltStream->Stream, &this->ColorV);
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
    v21 = pAltStream->Stream.Pos;
    v22 = pAltStream->Stream.pBuffer[v21];
    pAltStream->Stream.Pos = v21 + 1;
    this->ColorV.Channels.Alpha = v22;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  HasColor\n");
  }
  if ( v7 )
  {
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v23 = pAltStream->Stream.Pos;
    v24 = (unsigned __int8)pAltStream->Stream.pBuffer[v23] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v23 + 1)] << 8);
    pAltStream->Stream.Pos = v23 + 2;
    this->MaxLength = v24;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  HasMaxLength: len = %d\n");
  }
  if ( v10 )
  {
    this->Flags |= 0x200u;
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
    v25 = pAltStream->Stream.Pos;
    v26 = (unsigned __int8)pAltStream->Stream.pBuffer[v25];
    pAltStream->Stream.Pos = v25 + 1;
    this->Alignment = v26;
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v27 = pAltStream->Stream.Pos;
    v28 = (unsigned __int8)pAltStream->Stream.pBuffer[v27] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v27 + 1)] << 8);
    pAltStream->Stream.Pos = v27 + 2;
    this->LeftMargin = (float)v28;
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v29 = pAltStream->Stream.Pos;
    v30 = (unsigned __int8)pAltStream->Stream.pBuffer[v29] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v29 + 1)] << 8);
    pAltStream->Stream.Pos = v29 + 2;
    this->RightMargin = (float)v30;
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v31 = pAltStream->Stream.Pos;
    v32 = (unsigned __int8)pAltStream->Stream.pBuffer[v31] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v31 + 1)] << 8);
    pAltStream->Stream.Pos = v31 + 2;
    this->Indent = (float)v32;
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v33 = pAltStream->Stream.Pos;
    v34 = (unsigned __int8)pAltStream->Stream.pBuffer[v33] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v33 + 1)] << 8);
    pAltStream->Stream.Pos = v33 + 2;
    this->Leading = (float)v34;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &pAltStream->Stream,
      "  HasLayout: alignment = %d, leftmarg = %f, rightmarg = %f, indent = %f, leading = %f\n");
  }
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->VariableName);
  if ( v36 )
    Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->DefaultText);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    &pAltStream->Stream,
    "EditTextChar, varname = %s, text = %s\n");
}

// File Line: 162
// RVA: 0x86DE30
void __fastcall Scaleform::GFx::GFx_DefineEditTextLoader(Scaleform::MemoryHeap *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAutoRelease; // rbx
  __int64 Pos; // r8
  unsigned __int16 v6; // si
  Scaleform::GFx::TextFieldDef *v7; // rax
  Scaleform::GFx::TextFieldDef *v8; // rax
  Scaleform::GFx::TextFieldDef *v9; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::MemoryHeap *rid; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::TextFieldDef *v12; // [rsp+58h] [rbp+10h]

  pAutoRelease = (Scaleform::GFx::SWFProcessInfo *)p[5].pAutoRelease;
  if ( !pAutoRelease )
    pAutoRelease = (Scaleform::GFx::SWFProcessInfo *)&p->Info.Desc.Reserve;
  pAutoRelease->Stream.UnusedBits = 0;
  if ( (signed int)(pAutoRelease->Stream.DataSize - pAutoRelease->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAutoRelease->Stream, 2);
  Pos = pAutoRelease->Stream.Pos;
  v6 = (unsigned __int8)pAutoRelease->Stream.pBuffer[Pos] | ((unsigned __int8)pAutoRelease->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAutoRelease->Stream.Pos = Pos + 2;
  rid = *(Scaleform::MemoryHeap **)(*(_QWORD *)&p->Info.Desc.Flags + 56i64);
  v7 = (Scaleform::GFx::TextFieldDef *)rid->vfptr->Alloc(p, 144ui64, 0i64);
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
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->RefCount,
    "EditTextChar, id = %d\n",
    v6);
  Scaleform::GFx::TextFieldDef::Read(v9, (Scaleform::GFx::LoadProcess *)p, tagInfo->TagType);
  if ( !LODWORD(p[4].HeapLock.cs.DebugInfo) )
  {
    LODWORD(rid) = v6;
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
      *(Scaleform::GFx::MovieDataDef::LoadTaskData **)&p->Info.Desc.Flags,
      (Scaleform::GFx::ResourceId)&rid,
      v9);
  }
  if ( v9 && !_InterlockedDecrement(&v9->RefCount.Value) )
  {
    pLib = v9->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v9);
      v9->pLib = 0i64;
    }
    v9->vfptr->__vecDelDtor(v9, 1u);
  }
}

// File Line: 219
// RVA: 0x8CBB80
Scaleform::GFx::TextKeyMap::KeyMapEntry *__fastcall Scaleform::GFx::TextKeyMap::FindFirstEntry(
        Scaleform::GFx::TextKeyMap *this,
        unsigned int keyCode)
{
  __int64 Size; // rax
  unsigned __int64 v3; // r9
  Scaleform::GFx::TextKeyMap::KeyMapEntry *result; // rax

  Size = this->Map.Data.Size;
  v3 = 0i64;
  while ( Size > 0 )
  {
    if ( (int)(this->Map.Data.Data[(Size >> 1) + v3].KeyCode - keyCode) >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v3 += (Size >> 1) + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v3 >= this->Map.Data.Size )
    return 0i64;
  result = &this->Map.Data.Data[v3];
  if ( result->KeyCode != keyCode )
    return 0i64;
  return result;
}

// File Line: 237
// RVA: 0x8CB6D0
Scaleform::GFx::TextKeyMap::KeyMapEntry *__fastcall Scaleform::GFx::TextKeyMap::Find(
        Scaleform::GFx::TextKeyMap *this,
        unsigned int keyCode,
        Scaleform::KeyModifiers *specKeys,
        Scaleform::GFx::TextKeyMap::KeyState state)
{
  Scaleform::GFx::TextKeyMap::KeyMapEntry *result; // rax
  Scaleform::GFx::TextKeyMap::KeyMapEntry *Data; // r8
  __int64 v9; // rdx
  __int64 v10; // rdx

  result = Scaleform::GFx::TextKeyMap::FindFirstEntry(this, keyCode);
  if ( !result )
    return 0i64;
  while ( result->mState != state
       || (result->SpecKeysPressed & (unsigned __int8)specKeys->States) != result->SpecKeysPressed )
  {
    Data = this->Map.Data.Data;
    v9 = result - Data;
    if ( v9 + 1 < this->Map.Data.Size )
    {
      v10 = v9;
      if ( Data[v10 + 1].KeyCode == result->KeyCode )
      {
        result = &Data[v10 + 1];
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
  unsigned __int64 Size; // r10
  unsigned __int64 v3; // rdi
  __int64 v4; // rdx
  unsigned __int64 v5; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v6; // rdi
  unsigned __int64 v7; // r10
  unsigned __int64 v8; // rdi
  __int64 v9; // rcx
  unsigned __int64 v10; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v11; // rdi
  unsigned __int64 v12; // r10
  unsigned __int64 v13; // rdi
  __int64 v14; // rcx
  unsigned __int64 v15; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v16; // rdi
  unsigned __int64 v17; // r10
  unsigned __int64 v18; // rdi
  __int64 v19; // rcx
  unsigned __int64 v20; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v21; // rdi
  unsigned __int64 v22; // r10
  unsigned __int64 v23; // rdi
  __int64 v24; // rcx
  unsigned __int64 v25; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v26; // rdi
  unsigned __int64 v27; // r10
  unsigned __int64 v28; // rdi
  __int64 v29; // rcx
  unsigned __int64 v30; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v31; // rdi
  unsigned __int64 v32; // r10
  unsigned __int64 v33; // rdi
  __int64 v34; // rcx
  unsigned __int64 v35; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v36; // rdi
  unsigned __int64 v37; // r10
  unsigned __int64 v38; // rdi
  __int64 v39; // rcx
  unsigned __int64 v40; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v41; // rdi
  unsigned __int64 v42; // r10
  unsigned __int64 v43; // rdi
  __int64 v44; // rcx
  unsigned __int64 v45; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v46; // rdi
  unsigned __int64 v47; // r10
  unsigned __int64 v48; // rdi
  __int64 v49; // rcx
  unsigned __int64 v50; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v51; // rdi
  unsigned __int64 v52; // r10
  unsigned __int64 v53; // rdi
  __int64 v54; // rcx
  unsigned __int64 v55; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v56; // rdi
  unsigned __int64 v57; // r10
  unsigned __int64 v58; // rdi
  __int64 v59; // rcx
  unsigned __int64 v60; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v61; // rdi
  unsigned __int64 v62; // r10
  unsigned __int64 v63; // rdi
  __int64 v64; // rcx
  unsigned __int64 v65; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v66; // rdi
  unsigned __int64 v67; // r10
  unsigned __int64 v68; // rdi
  __int64 v69; // rcx
  unsigned __int64 v70; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v71; // rdi
  unsigned __int64 v72; // r10
  unsigned __int64 v73; // rdi
  __int64 v74; // rdx
  unsigned __int64 v75; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v76; // rdi
  unsigned __int64 v77; // r10
  unsigned __int64 v78; // rdi
  __int64 v79; // rcx
  unsigned __int64 v80; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v81; // rdi
  unsigned __int64 v82; // r10
  unsigned __int64 v83; // rdi
  __int64 v84; // rcx
  unsigned __int64 v85; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v86; // rdi
  unsigned __int64 v87; // r10
  unsigned __int64 v88; // rdi
  __int64 v89; // rcx
  unsigned __int64 v90; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v91; // rdi
  unsigned __int64 v92; // r10
  unsigned __int64 v93; // rdi
  __int64 v94; // rcx
  unsigned __int64 v95; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v96; // rdi
  unsigned __int64 v97; // r10
  unsigned __int64 v98; // rdi
  __int64 v99; // rcx
  unsigned __int64 v100; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v101; // rdi
  unsigned __int64 v102; // r10
  unsigned __int64 v103; // rdi
  __int64 v104; // rdx
  unsigned __int64 v105; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v106; // rdi
  unsigned __int64 v107; // r10
  unsigned __int64 v108; // rdi
  __int64 v109; // rcx
  unsigned __int64 v110; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v111; // rdi
  unsigned __int64 v112; // r10
  unsigned __int64 v113; // rdi
  __int64 v114; // rdx
  unsigned __int64 v115; // r8
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v116; // rdi
  unsigned __int64 v117; // r10
  unsigned __int64 v118; // rdi
  __int64 v119; // rdx
  unsigned __int64 v120; // r8
  Scaleform::GFx::TextKeyMap *result; // rax
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v122; // rdi

  Size = this->Map.Data.Size;
  v3 = 0i64;
  v4 = Size;
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
    Size + 1);
  v5 = this->Map.Data.Size;
  if ( v3 < v5 - 1 )
    memmove(&this->Map.Data.Data[v3 + 1], &this->Map.Data.Data[v3], 16 * (v5 - v3 - 1));
  v6 = &this->Map.Data.Data[v3];
  if ( v6 )
  {
    v6->Action = KeyAct_EnterSelectionMode;
    *(_QWORD *)&v6->KeyCode = 16i64;
    v6->mState = State_Down;
  }
  v7 = this->Map.Data.Size;
  v8 = 0i64;
  v9 = v7;
  while ( v9 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v9 >> 1) + v8].KeyCode - 16) >= 0 )
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
    &this->Map.Data,
    v7 + 1);
  v10 = this->Map.Data.Size;
  if ( v8 < v10 - 1 )
    memmove(&this->Map.Data.Data[v8 + 1], &this->Map.Data.Data[v8], 16 * (v10 - v8 - 1));
  v11 = &this->Map.Data.Data[v8];
  if ( v11 )
  {
    v11->Action = KeyAct_LeaveSelectionMode;
    *(_QWORD *)&v11->KeyCode = 16i64;
    v11->mState = State_Up;
  }
  v12 = this->Map.Data.Size;
  v13 = 0i64;
  v14 = v12;
  while ( v14 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v14 >> 1) + v13].KeyCode - 38) >= 0 )
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
    &this->Map.Data,
    v12 + 1);
  v15 = this->Map.Data.Size;
  if ( v13 < v15 - 1 )
    memmove(&this->Map.Data.Data[v13 + 1], &this->Map.Data.Data[v13], 16 * (v15 - v13 - 1));
  v16 = &this->Map.Data.Data[v13];
  if ( v16 )
  {
    v16->Action = KeyAct_Up;
    *(_QWORD *)&v16->KeyCode = 38i64;
    v16->mState = State_Down;
  }
  v17 = this->Map.Data.Size;
  v18 = 0i64;
  v19 = v17;
  while ( v19 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v19 >> 1) + v18].KeyCode - 40) >= 0 )
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
    &this->Map.Data,
    v17 + 1);
  v20 = this->Map.Data.Size;
  if ( v18 < v20 - 1 )
    memmove(&this->Map.Data.Data[v18 + 1], &this->Map.Data.Data[v18], 16 * (v20 - v18 - 1));
  v21 = &this->Map.Data.Data[v18];
  if ( v21 )
  {
    v21->Action = KeyAct_Down;
    *(_QWORD *)&v21->KeyCode = 40i64;
    v21->mState = State_Down;
  }
  v22 = this->Map.Data.Size;
  v23 = 0i64;
  v24 = v22;
  while ( v24 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v24 >> 1) + v23].KeyCode - 37) >= 0 )
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
    &this->Map.Data,
    v22 + 1);
  v25 = this->Map.Data.Size;
  if ( v23 < v25 - 1 )
    memmove(&this->Map.Data.Data[v23 + 1], &this->Map.Data.Data[v23], 16 * (v25 - v23 - 1));
  v26 = &this->Map.Data.Data[v23];
  if ( v26 )
  {
    v26->Action = KeyAct_Left;
    *(_QWORD *)&v26->KeyCode = 37i64;
    v26->mState = State_Down;
  }
  v27 = this->Map.Data.Size;
  v28 = 0i64;
  v29 = v27;
  while ( v29 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v29 >> 1) + v28].KeyCode - 39) >= 0 )
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
    &this->Map.Data,
    v27 + 1);
  v30 = this->Map.Data.Size;
  if ( v28 < v30 - 1 )
    memmove(&this->Map.Data.Data[v28 + 1], &this->Map.Data.Data[v28], 16 * (v30 - v28 - 1));
  v31 = &this->Map.Data.Data[v28];
  if ( v31 )
  {
    v31->Action = KeyAct_Right;
    *(_QWORD *)&v31->KeyCode = 39i64;
    v31->mState = State_Down;
  }
  v32 = this->Map.Data.Size;
  v33 = 0i64;
  v34 = v32;
  while ( v34 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v34 >> 1) + v33].KeyCode - 33) >= 0 )
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
    &this->Map.Data,
    v32 + 1);
  v35 = this->Map.Data.Size;
  if ( v33 < v35 - 1 )
    memmove(&this->Map.Data.Data[v33 + 1], &this->Map.Data.Data[v33], 16 * (v35 - v33 - 1));
  v36 = &this->Map.Data.Data[v33];
  if ( v36 )
  {
    v36->Action = KeyAct_PageUp;
    *(_QWORD *)&v36->KeyCode = 33i64;
    v36->mState = State_Down;
  }
  v37 = this->Map.Data.Size;
  v38 = 0i64;
  v39 = v37;
  while ( v39 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v39 >> 1) + v38].KeyCode - 34) >= 0 )
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
    &this->Map.Data,
    v37 + 1);
  v40 = this->Map.Data.Size;
  if ( v38 < v40 - 1 )
    memmove(&this->Map.Data.Data[v38 + 1], &this->Map.Data.Data[v38], 16 * (v40 - v38 - 1));
  v41 = &this->Map.Data.Data[v38];
  if ( v41 )
  {
    v41->Action = KeyAct_PageDown;
    *(_QWORD *)&v41->KeyCode = 34i64;
    v41->mState = State_Down;
  }
  v42 = this->Map.Data.Size;
  v43 = 0i64;
  v44 = v42;
  while ( v44 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v44 >> 1) + v43].KeyCode - 36) >= 0 )
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
    &this->Map.Data,
    v42 + 1);
  v45 = this->Map.Data.Size;
  if ( v43 < v45 - 1 )
    memmove(&this->Map.Data.Data[v43 + 1], &this->Map.Data.Data[v43], 16 * (v45 - v43 - 1));
  v46 = &this->Map.Data.Data[v43];
  if ( v46 )
  {
    v46->Action = KeyAct_LineHome;
    *(_QWORD *)&v46->KeyCode = 36i64;
    v46->mState = State_Down;
  }
  v47 = this->Map.Data.Size;
  v48 = 0i64;
  v49 = v47;
  while ( v49 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v49 >> 1) + v48].KeyCode - 35) >= 0 )
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
    &this->Map.Data,
    v47 + 1);
  v50 = this->Map.Data.Size;
  if ( v48 < v50 - 1 )
    memmove(&this->Map.Data.Data[v48 + 1], &this->Map.Data.Data[v48], 16 * (v50 - v48 - 1));
  v51 = &this->Map.Data.Data[v48];
  if ( v51 )
  {
    v51->Action = KeyAct_LineEnd;
    *(_QWORD *)&v51->KeyCode = 35i64;
    v51->mState = State_Down;
  }
  v52 = this->Map.Data.Size;
  v53 = 0i64;
  v54 = v52;
  while ( v54 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v54 >> 1) + v53].KeyCode - 33) >= 0 )
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
    &this->Map.Data,
    v52 + 1);
  v55 = this->Map.Data.Size;
  if ( v53 < v55 - 1 )
    memmove(&this->Map.Data.Data[v53 + 1], &this->Map.Data.Data[v53], 16 * (v55 - v53 - 1));
  v56 = &this->Map.Data.Data[v53];
  if ( v56 )
  {
    v56->Action = KeyAct_PageHome;
    v56->KeyCode = 33;
    *(_QWORD *)&v56->SpecKeysPressed = 2i64;
  }
  v57 = this->Map.Data.Size;
  v58 = 0i64;
  v59 = v57;
  while ( v59 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v59 >> 1) + v58].KeyCode - 34) >= 0 )
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
    &this->Map.Data,
    v57 + 1);
  v60 = this->Map.Data.Size;
  if ( v58 < v60 - 1 )
    memmove(&this->Map.Data.Data[v58 + 1], &this->Map.Data.Data[v58], 16 * (v60 - v58 - 1));
  v61 = &this->Map.Data.Data[v58];
  if ( v61 )
  {
    v61->Action = KeyAct_PageEnd;
    v61->KeyCode = 34;
    *(_QWORD *)&v61->SpecKeysPressed = 2i64;
  }
  v62 = this->Map.Data.Size;
  v63 = 0i64;
  v64 = v62;
  while ( v64 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v64 >> 1) + v63].KeyCode - 36) >= 0 )
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
    &this->Map.Data,
    v62 + 1);
  v65 = this->Map.Data.Size;
  if ( v63 < v65 - 1 )
    memmove(&this->Map.Data.Data[v63 + 1], &this->Map.Data.Data[v63], 16 * (v65 - v63 - 1));
  v66 = &this->Map.Data.Data[v63];
  if ( v66 )
  {
    v66->Action = KeyAct_DocHome;
    v66->KeyCode = 36;
    *(_QWORD *)&v66->SpecKeysPressed = 2i64;
  }
  v67 = this->Map.Data.Size;
  v68 = 0i64;
  v69 = v67;
  while ( v69 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v69 >> 1) + v68].KeyCode - 35) >= 0 )
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
    &this->Map.Data,
    v67 + 1);
  v70 = this->Map.Data.Size;
  if ( v68 < v70 - 1 )
    memmove(&this->Map.Data.Data[v68 + 1], &this->Map.Data.Data[v68], 16 * (v70 - v68 - 1));
  v71 = &this->Map.Data.Data[v68];
  if ( v71 )
  {
    v71->Action = KeyAct_DocEnd;
    v71->KeyCode = 35;
    *(_QWORD *)&v71->SpecKeysPressed = 2i64;
  }
  v72 = this->Map.Data.Size;
  v73 = 0i64;
  v74 = v72;
  while ( v74 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v74 >> 1) + v73].KeyCode - 8) >= 0 )
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
    &this->Map.Data,
    v72 + 1);
  v75 = this->Map.Data.Size;
  if ( v73 < v75 - 1 )
    memmove(&this->Map.Data.Data[v73 + 1], &this->Map.Data.Data[v73], 16 * (v75 - v73 - 1));
  v76 = &this->Map.Data.Data[v73];
  if ( v76 )
  {
    v76->Action = KeyAct_Backspace;
    *(_QWORD *)&v76->KeyCode = 8i64;
    v76->mState = State_Down;
  }
  v77 = this->Map.Data.Size;
  v78 = 0i64;
  v79 = v77;
  while ( v79 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v79 >> 1) + v78].KeyCode - 46) >= 0 )
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
    &this->Map.Data,
    v77 + 1);
  v80 = this->Map.Data.Size;
  if ( v78 < v80 - 1 )
    memmove(&this->Map.Data.Data[v78 + 1], &this->Map.Data.Data[v78], 16 * (v80 - v78 - 1));
  v81 = &this->Map.Data.Data[v78];
  if ( v81 )
  {
    v81->Action = KeyAct_Delete;
    *(_QWORD *)&v81->KeyCode = 46i64;
    v81->mState = State_Down;
  }
  v82 = this->Map.Data.Size;
  v83 = 0i64;
  v84 = v82;
  while ( v84 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v84 >> 1) + v83].KeyCode - 13) >= 0 )
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
    &this->Map.Data,
    v82 + 1);
  v85 = this->Map.Data.Size;
  if ( v83 < v85 - 1 )
    memmove(&this->Map.Data.Data[v83 + 1], &this->Map.Data.Data[v83], 16 * (v85 - v83 - 1));
  v86 = &this->Map.Data.Data[v83];
  if ( v86 )
  {
    v86->Action = KeyAct_Return;
    *(_QWORD *)&v86->KeyCode = 13i64;
    v86->mState = State_Down;
  }
  v87 = this->Map.Data.Size;
  v88 = 0i64;
  v89 = v87;
  while ( v89 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v89 >> 1) + v88].KeyCode - 67) >= 0 )
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
    &this->Map.Data,
    v87 + 1);
  v90 = this->Map.Data.Size;
  if ( v88 < v90 - 1 )
    memmove(&this->Map.Data.Data[v88 + 1], &this->Map.Data.Data[v88], 16 * (v90 - v88 - 1));
  v91 = &this->Map.Data.Data[v88];
  if ( v91 )
  {
    v91->Action = KeyAct_Copy;
    v91->KeyCode = 67;
    *(_QWORD *)&v91->SpecKeysPressed = 2i64;
  }
  v92 = this->Map.Data.Size;
  v93 = 0i64;
  v94 = v92;
  while ( v94 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v94 >> 1) + v93].KeyCode - 45) >= 0 )
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
    &this->Map.Data,
    v92 + 1);
  v95 = this->Map.Data.Size;
  if ( v93 < v95 - 1 )
    memmove(&this->Map.Data.Data[v93 + 1], &this->Map.Data.Data[v93], 16 * (v95 - v93 - 1));
  v96 = &this->Map.Data.Data[v93];
  if ( v96 )
  {
    v96->Action = KeyAct_Copy;
    v96->KeyCode = 45;
    *(_QWORD *)&v96->SpecKeysPressed = 2i64;
  }
  v97 = this->Map.Data.Size;
  v98 = 0i64;
  v99 = v97;
  while ( v99 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v99 >> 1) + v98].KeyCode - 86) >= 0 )
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
    &this->Map.Data,
    v97 + 1);
  v100 = this->Map.Data.Size;
  if ( v98 < v100 - 1 )
    memmove(&this->Map.Data.Data[v98 + 1], &this->Map.Data.Data[v98], 16 * (v100 - v98 - 1));
  v101 = &this->Map.Data.Data[v98];
  if ( v101 )
  {
    v101->Action = KeyAct_Paste;
    v101->KeyCode = 86;
    *(_QWORD *)&v101->SpecKeysPressed = 2i64;
  }
  v102 = this->Map.Data.Size;
  v103 = 0i64;
  v104 = v102;
  while ( v104 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v104 >> 1) + v103].KeyCode - 45) >= 0 )
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
    &this->Map.Data,
    v102 + 1);
  v105 = this->Map.Data.Size;
  if ( v103 < v105 - 1 )
    memmove(&this->Map.Data.Data[v103 + 1], &this->Map.Data.Data[v103], 16 * (v105 - v103 - 1));
  v106 = &this->Map.Data.Data[v103];
  if ( v106 )
  {
    v106->Action = KeyAct_Paste;
    v106->KeyCode = 45;
    *(_QWORD *)&v106->SpecKeysPressed = 1i64;
  }
  v107 = this->Map.Data.Size;
  v108 = 0i64;
  v109 = v107;
  while ( v109 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v109 >> 1) + v108].KeyCode - 88) >= 0 )
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
    &this->Map.Data,
    v107 + 1);
  v110 = this->Map.Data.Size;
  if ( v108 < v110 - 1 )
    memmove(&this->Map.Data.Data[v108 + 1], &this->Map.Data.Data[v108], 16 * (v110 - v108 - 1));
  v111 = &this->Map.Data.Data[v108];
  if ( v111 )
  {
    v111->Action = KeyAct_Cut;
    v111->KeyCode = 88;
    *(_QWORD *)&v111->SpecKeysPressed = 2i64;
  }
  v112 = this->Map.Data.Size;
  v113 = 0i64;
  v114 = v112;
  while ( v114 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v114 >> 1) + v113].KeyCode - 46) >= 0 )
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
    &this->Map.Data,
    v112 + 1);
  v115 = this->Map.Data.Size;
  if ( v113 < v115 - 1 )
    memmove(&this->Map.Data.Data[v113 + 1], &this->Map.Data.Data[v113], 16 * (v115 - v113 - 1));
  v116 = &this->Map.Data.Data[v113];
  if ( v116 )
  {
    v116->Action = KeyAct_Cut;
    v116->KeyCode = 46;
    *(_QWORD *)&v116->SpecKeysPressed = 1i64;
  }
  v117 = this->Map.Data.Size;
  v118 = 0i64;
  v119 = v117;
  while ( v119 > 0 )
  {
    if ( (signed int)(this->Map.Data.Data[(v119 >> 1) + v118].KeyCode - 65) >= 0 )
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
    &this->Map.Data,
    v117 + 1);
  v120 = this->Map.Data.Size;
  if ( v118 < v120 - 1 )
    memmove(&this->Map.Data.Data[v118 + 1], &this->Map.Data.Data[v118], 16 * (v120 - v118 - 1));
  result = this;
  v122 = &this->Map.Data.Data[v118];
  if ( v122 )
  {
    v122->Action = KeyAct_SelectAll;
    v122->KeyCode = 65;
    *(_QWORD *)&v122->SpecKeysPressed = 2i64;
  }
  return result;
}

// File Line: 288
// RVA: 0x870570
void __fastcall Scaleform::GFx::GFx_CSMTextSettings(Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // r8
  unsigned __int16 v5; // si
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  unsigned int UInt; // ebp
  __int64 v8; // r14
  __int64 v9; // r10
  __int64 v10; // r9
  const char *v11; // r8
  bool ResourceHandle; // al
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceHandle::HandleType HType; // edi
  Scaleform::GFx::Resource *v15; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceHandle phandle; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+60h] [rbp+8h] BYREF
  int v19; // [rsp+70h] [rbp+18h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  UInt = Scaleform::GFx::Stream::ReadUInt(&p_ProcessInfo->Stream, 2u);
  v8 = Scaleform::GFx::Stream::ReadUInt(&p_ProcessInfo->Stream, 3u);
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 4);
  v9 = p_ProcessInfo->Stream.Pos;
  v19 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v9] | (((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v9 + 1)] | (((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v9 + 2)] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v9 + 3)] << 8)) << 8)) << 8);
  p_ProcessInfo->Stream.Pos = v9 + 4;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (signed int)(p_ProcessInfo->Stream.DataSize - (v9 + 4)) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 4);
  v10 = p_ProcessInfo->Stream.Pos;
  rid.Id = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[v10] | (((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v10 + 1)] | (((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v10 + 2)] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(v10 + 3)] << 8)) << 8)) << 8);
  p_ProcessInfo->Stream.Pos = v10 + 4;
  if ( (p_ProcessInfo->Stream.ParseFlags & 1) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "CSMTextSettings, id = %d\n",
      v5);
    v11 = "Internal";
    if ( !UInt )
      v11 = "System";
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  FlagType = %s, GridFit = %s\n",
      v11,
      gridfittypes[v8]);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  Thinkness = %f, Sharpnesss = %f\n",
      v19,
      rid.Id,
      -2i64);
  }
  phandle.HType = RH_Pointer;
  phandle.pResource = 0i64;
  rid.Id = v5;
  ResourceHandle = Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                     p->pLoadData.pObject,
                     &phandle,
                     (Scaleform::GFx::ResourceId)&rid);
  pResource = phandle.pResource;
  HType = phandle.HType;
  if ( ResourceHandle && phandle.HType == RH_Pointer && phandle.pResource )
  {
    if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))phandle.pResource->vfptr->GetResourceTypeCode)(phandle.pResource) & 0xFF00) == 33536 )
    {
      LOWORD(pResource[5].RefCount.Value) |= 0x400u;
    }
    else if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pResource->vfptr->GetResourceTypeCode)(pResource) & 0xFF00) == 33280 )
    {
      LOBYTE(pResource[4].RefCount.Value) |= 1u;
    }
  }
  if ( HType == RH_Pointer && pResource && !_InterlockedDecrement(&pResource->RefCount.Value) )
  {
    v15 = phandle.pResource;
    pLib = phandle.pResource->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)phandle.pResource);
      v15->pLib = 0i64;
    }
    v15->vfptr->__vecDelDtor(v15, 1u);
  }
}

// File Line: 358
// RVA: 0x90C800
void __fastcall Scaleform::GFx::Clipboard::SetText(Scaleform::GFx::Clipboard *this, Scaleform::String *str)
{
  Scaleform::Render::Text::StyledText *pStyledText; // rcx
  unsigned __int64 v5; // rbx
  wchar_t *pText; // rdx

  pStyledText = this->pStyledText;
  if ( pStyledText )
  {
    Scaleform::RefCountNTSImpl::Release(pStyledText);
    this->pStyledText = 0i64;
  }
  v5 = Scaleform::String::GetLength(str) + 1;
  Scaleform::WStringBuffer::Resize(&this->PlainText, v5);
  Scaleform::UTF8Util::DecodeStringSafe(
    this->PlainText.pText,
    v5,
    (const char *)((str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  pText = (wchar_t *)byte_1416A7BD8;
  if ( this->PlainText.pText )
    pText = this->PlainText.pText;
  ((void (__fastcall *)(Scaleform::GFx::Clipboard *, wchar_t *, unsigned __int64))this->vfptr[7].__vecDelDtor)(
    this,
    pText,
    this->PlainText.Length);
}

// File Line: 367
// RVA: 0x90C8B0
void __fastcall Scaleform::GFx::Clipboard::SetText(
        Scaleform::GFx::Clipboard *this,
        const wchar_t *ptext,
        unsigned __int64 len)
{
  Scaleform::Render::Text::StyledText *pStyledText; // rcx
  wchar_t *v7; // rdx

  pStyledText = this->pStyledText;
  if ( pStyledText )
  {
    Scaleform::RefCountNTSImpl::Release(pStyledText);
    this->pStyledText = 0i64;
  }
  Scaleform::WStringBuffer::SetString(&this->PlainText, ptext, len);
  v7 = (wchar_t *)byte_1416A7BD8;
  if ( this->PlainText.pText )
    v7 = this->PlainText.pText;
  ((void (__fastcall *)(Scaleform::GFx::Clipboard *, wchar_t *, unsigned __int64))this->vfptr[7].__vecDelDtor)(
    this,
    v7,
    this->PlainText.Length);
}

// File Line: 373
// RVA: 0x8DE810
Scaleform::WStringBuffer *__fastcall Scaleform::GFx::Clipboard::GetText(Scaleform::GFx::Clipboard *this)
{
  return &this->PlainText;
}

// File Line: 378
// RVA: 0x90C4E0
void __fastcall Scaleform::GFx::Clipboard::SetStyledText(
        Scaleform::GFx::Clipboard *this,
        Scaleform::Render::Text::StyledText *pstyledText)
{
  Scaleform::Render::Text::StyledText *v4; // rcx
  Scaleform::MemoryHeap *v5; // rsi
  Scaleform::Render::Text::Allocator *v6; // rax
  Scaleform::Render::Text::StyledText *v7; // rdi
  Scaleform::Render::Text::Allocator *v8; // rax
  Scaleform::Render::Text::Allocator *v9; // rbx
  Scaleform::Render::Text::StyledText *v10; // rax
  Scaleform::Render::Text::StyledText *v11; // rax

  v4 = this->pStyledText;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  v5 = Scaleform::Memory::pGlobalHeap;
  v6 = (Scaleform::Render::Text::Allocator *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               144i64,
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
  v10 = (Scaleform::Render::Text::StyledText *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v5->vfptr->Alloc)(
                                                 v5,
                                                 72i64);
  if ( v10 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v10, v9);
    v7 = v11;
  }
  this->pStyledText = v7;
  Scaleform::Render::Text::StyledText::CopyStyledText(pstyledText, v7, 0i64, 0xFFFFFFFFFFFFFFFFui64);
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
}

