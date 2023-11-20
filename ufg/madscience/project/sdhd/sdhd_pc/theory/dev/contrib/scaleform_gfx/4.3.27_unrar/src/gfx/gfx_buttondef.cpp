// File Line: 35
// RVA: 0x8F5FB0
char __fastcall Scaleform::GFx::ButtonRecord::Read(Scaleform::GFx::ButtonRecord *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::TagType v3; // er12
  Scaleform::GFx::LoadProcess *v4; // rsi
  Scaleform::GFx::ButtonRecord *v5; // rdi
  Scaleform::GFx::Stream *v6; // rbx
  __int64 v7; // rdx
  char v8; // cl
  char v9; // r14
  Scaleform::GFx::Stream *v11; // rbx
  Scaleform::GFx::Stream *v12; // rbp
  __int64 v13; // r9
  unsigned __int16 v14; // r8
  Scaleform::GFx::Stream *v15; // rbp
  __int64 v16; // r10
  unsigned __int16 v17; // r9
  __int64 v18; // r9
  __int64 v19; // rcx
  Scaleform::Render::FilterSet *v20; // rax
  Scaleform::GFx::Resource *v21; // rax
  Scaleform::GFx::Resource *v22; // rsi
  Scaleform::Render::RenderBuffer *v23; // rcx
  __int64 v24; // rdx
  unsigned __int8 v25; // r8
  unsigned __int8 v26; // dl

  v3 = tagType;
  v4 = p;
  v5 = this;
  v6 = p->pAltStream;
  if ( !v6 )
    v6 = &p->ProcessInfo.Stream;
  v6->UnusedBits = 0;
  if ( (signed int)(v6->DataSize - v6->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v6, 1);
  v7 = v6->Pos;
  v8 = v6->pBuffer[v7];
  v6->Pos = v7 + 1;
  v9 = v8;
  if ( !v8 )
    return 0;
  v11 = v4->pAltStream;
  if ( !v11 )
    v11 = &v4->ProcessInfo.Stream;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
    "-- action record:  ");
  v5->Flags = 0;
  if ( v9 & 8 )
  {
    v5->Flags = 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
      "HitTest ");
  }
  if ( v9 & 4 )
  {
    v5->Flags |= 2u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
      "Down ");
  }
  if ( v9 & 2 )
  {
    v5->Flags |= 4u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
      "Over ");
  }
  if ( v9 & 1 )
  {
    v5->Flags |= 8u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
      "Up ");
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
    "\n");
  v12 = v4->pAltStream;
  if ( !v12 )
    v12 = &v4->ProcessInfo.Stream;
  v12->UnusedBits = 0;
  if ( (signed int)(v12->DataSize - v12->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v12, 2);
  v13 = v12->Pos;
  v14 = (unsigned __int8)v12->pBuffer[v13] | (unsigned __int16)((unsigned __int8)v12->pBuffer[(unsigned int)(v13 + 1)] << 8);
  v12->Pos = v13 + 2;
  v5->CharacterId.Id = v14;
  v15 = v4->pAltStream;
  if ( !v15 )
    v15 = &v4->ProcessInfo.Stream;
  v15->UnusedBits = 0;
  if ( (signed int)(v15->DataSize - v15->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v15, 2);
  v16 = v15->Pos;
  v17 = (unsigned __int8)v15->pBuffer[v16] | (unsigned __int16)((unsigned __int8)v15->pBuffer[(unsigned int)(v16 + 1)] << 8);
  v15->Pos = v16 + 2;
  v5->Depth = v17;
  Scaleform::GFx::Stream::ReadMatrix(v11, &v5->ButtonMatrix);
  v18 = v5->Depth;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
    "   CharId = %d, Depth = %d\n");
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
    "   mat:\n");
  if ( v3 == 34 )
  {
    Scaleform::GFx::Stream::ReadCxformRgba(v11, &v5->ButtonCxform);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
      "   cxform:\n");
  }
  if ( v9 & 0x10 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
      "   HasFilters\n");
    v20 = (Scaleform::Render::FilterSet *)((__int64 (__fastcall *)(__int64, signed __int64))v4->pLoadData.pObject->pHeap->vfptr->Alloc)(
                                            v19,
                                            56i64);
    if ( v20 )
    {
      Scaleform::Render::FilterSet::FilterSet(v20, 0i64);
      v22 = v21;
    }
    else
    {
      v22 = 0i64;
    }
    if ( (unsigned int)Scaleform::GFx::LoadFilters<Scaleform::GFx::Stream>(v11, (Scaleform::Render::FilterSet *)v22) )
    {
      if ( v22 )
        Scaleform::Render::RenderBuffer::AddRef(v22);
      v23 = (Scaleform::Render::RenderBuffer *)v5->pFilters.pObject;
      if ( v23 )
        Scaleform::RefCountImpl::Release(v23);
      v5->pFilters.pObject = (Scaleform::Render::FilterSet *)v22;
    }
    if ( v22 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v22);
  }
  if ( v9 & 0x20 )
  {
    v11->UnusedBits = 0;
    if ( (signed int)(v11->DataSize - v11->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v11, 1);
    v24 = v11->Pos;
    v25 = v11->pBuffer[v24];
    v11->Pos = v24 + 1;
    v26 = v25;
    if ( (unsigned __int8)(v25 - 1) > 0xDu )
      v26 = 1;
    v5->BlendMode = v26;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v11->vfptr,
      "   HasBlending, %d\n");
  }
  else
  {
    v5->BlendMode = 0;
  }
  return 1;
}

// File Line: 134
// RVA: 0x8A35C0
void __fastcall Scaleform::GFx::ButtonDef::~ButtonDef(Scaleform::GFx::ButtonDef *this)
{
  Scaleform::GFx::ButtonDef *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ButtonDef::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pScale9Grid);
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayData<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->ButtonActions);
  Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *)&v1->ButtonRecords.Data.Data);
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 142
// RVA: 0x910960
void __fastcall Scaleform::GFx::SkipButtonSoundDef(Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::Stream *v1; // rbx
  Scaleform::GFx::LoadProcess *v2; // r14
  signed __int64 v3; // r15
  Scaleform::GFx::Stream *v4; // rdi
  unsigned int v5; // eax
  __int64 v6; // r9
  __int16 v7; // r8
  bool v8; // bp
  bool v9; // si
  bool v10; // di
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  __int64 v15; // rdx
  unsigned int v16; // ecx
  __int64 v17; // rdi
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax

  v1 = p->pAltStream;
  v2 = p;
  if ( !v1 )
    v1 = &p->ProcessInfo.Stream;
  v3 = 4i64;
  do
  {
    v4 = v2->pAltStream;
    if ( !v4 )
      v4 = &v2->ProcessInfo.Stream;
    v5 = v4->DataSize;
    v4->UnusedBits = 0;
    if ( (signed int)(v5 - v4->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v4, 2);
    v6 = v4->Pos;
    v7 = (unsigned __int8)v4->pBuffer[v6] | (unsigned __int16)((unsigned __int8)v4->pBuffer[(unsigned int)(v6 + 1)] << 8);
    v4->Pos = v6 + 2;
    if ( v7 )
    {
      Scaleform::GFx::Stream::ReadUInt(v1, 2u);
      Scaleform::GFx::Stream::ReadUInt(v1, 1u);
      Scaleform::GFx::Stream::ReadUInt(v1, 1u);
      v8 = (unsigned int)Scaleform::GFx::Stream::ReadUInt(v1, 1u) != 0;
      v9 = (unsigned int)Scaleform::GFx::Stream::ReadUInt(v1, 1u) != 0;
      v10 = (unsigned int)Scaleform::GFx::Stream::ReadUInt(v1, 1u) != 0;
      if ( (unsigned int)Scaleform::GFx::Stream::ReadUInt(v1, 1u) )
      {
        v11 = v1->DataSize;
        v1->UnusedBits = 0;
        if ( (signed int)(v11 - v1->Pos) < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(v1, 4);
        v1->Pos += 4;
      }
      if ( v10 )
      {
        v12 = v1->DataSize;
        v1->UnusedBits = 0;
        if ( (signed int)(v12 - v1->Pos) < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(v1, 4);
        v1->Pos += 4;
      }
      if ( v9 )
      {
        v13 = v1->DataSize;
        v1->UnusedBits = 0;
        if ( (signed int)(v13 - v1->Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(v1, 2);
        v1->Pos += 2;
      }
      if ( v8 )
      {
        v14 = v1->DataSize;
        v1->UnusedBits = 0;
        if ( (signed int)(v14 - v1->Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(v1, 1);
        v15 = v1->Pos;
        v16 = (unsigned __int8)v1->pBuffer[v15];
        v1->Pos = v15 + 1;
        if ( (signed int)v16 > 0 )
        {
          v17 = v16;
          do
          {
            v18 = v1->DataSize;
            v1->UnusedBits = 0;
            if ( (signed int)(v18 - v1->Pos) < 4 )
              Scaleform::GFx::Stream::PopulateBuffer(v1, 4);
            v1->Pos += 4;
            v19 = v1->DataSize;
            v1->UnusedBits = 0;
            if ( (signed int)(v19 - v1->Pos) < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(v1, 2);
            v1->Pos += 2;
            v20 = v1->DataSize;
            v1->UnusedBits = 0;
            if ( (signed int)(v20 - v1->Pos) < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(v1, 2);
            v1->Pos += 2;
            --v17;
          }
          while ( v17 );
        }
      }
    }
    --v3;
  }
  while ( v3 );
}

// File Line: 174
// RVA: 0x8F5A00
void __fastcall Scaleform::GFx::ButtonDef::Read(Scaleform::GFx::ButtonDef *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::LoadProcess *v3; // r13
  Scaleform::GFx::ButtonDef *v4; // rsi
  Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *v5; // r15
  unsigned int v6; // ecx
  unsigned __int64 v7; // rdx
  __int64 v8; // rax
  unsigned __int64 v9; // r12
  unsigned __int64 v10; // r14
  signed __int64 v11; // rbx
  signed __int64 v12; // rsi
  unsigned __int64 v13; // r8
  signed __int64 v14; // rbx
  Scaleform::Render::FilterSet *v15; // rax
  Scaleform::GFx::ASSupport *v16; // rcx
  const char *v17; // rdx
  int v18; // er12
  Scaleform::GFx::SWFProcessInfo *v19; // rcx
  int v20; // eax
  int v21; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *v22; // r15
  unsigned int v23; // ecx
  unsigned __int64 v24; // rdx
  __int64 v25; // rax
  unsigned __int64 v26; // rbx
  unsigned __int64 v27; // r14
  unsigned __int64 v28; // r8
  signed __int64 v29; // rbx
  bool v30; // zf
  Scaleform::GFx::ButtonRecord *v31; // rbx
  Scaleform::Render::FilterSet *v32; // rax
  Scaleform::GFx::Stream *v33; // rcx
  signed __int64 v34; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::ButtonRecord v35; // [rsp+30h] [rbp-39h]
  Scaleform::GFx::ButtonDef *v36; // [rsp+D0h] [rbp+67h]
  int v37; // [rsp+E0h] [rbp+77h]

  v36 = this;
  v3 = p;
  v4 = this;
  switch ( tagType )
  {
    case 7:
      *(_OWORD *)&v35.ButtonMatrix.M[0][0] = _xmm;
      *(__m128 *)&v35.ButtonMatrix.M[1][0] = _xmm;
      Scaleform::Render::Cxform::Cxform(&v35.ButtonCxform);
      v35.pFilters.pObject = 0i64;
      v35.CharacterId.Id = 0x40000;
      v35.Flags = 0;
      if ( Scaleform::GFx::ButtonRecord::Read(&v35, v3, Tag_ButtonCharacter) )
      {
        v5 = (Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *)&v4->ButtonRecords.Data.Data;
        do
        {
          v6 = 0;
          v7 = v4->ButtonRecords.Data.Size;
          if ( v7 )
          {
            v8 = 0i64;
            do
            {
              if ( v5->Data[v8].Depth > v35.Depth )
                break;
              v8 = ++v6;
            }
            while ( v6 < v7 );
          }
          v9 = v6;
          v10 = v5->Size;
          Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            v5,
            v5,
            v10 + 1);
          if ( v10 + 1 > v10 )
          {
            v11 = (signed __int64)&v5->Data[v10];
            v12 = 1i64;
            do
            {
              if ( v11 )
              {
                *(_QWORD *)v11 = 1065353216i64;
                *(_QWORD *)(v11 + 8) = 0i64;
                *(_DWORD *)(v11 + 16) = 0;
                *(_QWORD *)(v11 + 20) = 1065353216i64;
                *(_DWORD *)(v11 + 28) = 0;
                Scaleform::Render::Cxform::Cxform((Scaleform::Render::Cxform *)(v11 + 32));
                *(_QWORD *)(v11 + 64) = 0i64;
                *(_DWORD *)(v11 + 72) = 0x40000;
                *(_BYTE *)(v11 + 84) = 0;
              }
              v11 += 96i64;
              --v12;
            }
            while ( v12 );
          }
          v13 = v5->Size;
          if ( v9 < v13 - 1 )
            memmove(&v5->Data[v9 + 1], &v5->Data[v9], 96 * (v13 - v9 - 1));
          v14 = (signed __int64)&v5->Data[v9];
          v34 = (signed __int64)&v5->Data[v9];
          if ( v14 )
          {
            *(_OWORD *)v14 = *(_OWORD *)&v35.ButtonMatrix.M[0][0];
            *(_OWORD *)(v14 + 16) = *(_OWORD *)&v35.ButtonMatrix.M[1][0];
            *(_OWORD *)(v14 + 32) = *(_OWORD *)&v35.ButtonCxform.M[0][0];
            *(_OWORD *)(v14 + 48) = *(_OWORD *)&v35.ButtonCxform.M[1][0];
            v15 = v35.pFilters.pObject;
            if ( v35.pFilters.pObject )
            {
              Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v35.pFilters.pObject);
              v15 = v35.pFilters.pObject;
            }
            *(_QWORD *)(v14 + 64) = v15;
            *(_DWORD *)(v14 + 72) = v35.CharacterId.Id;
            *(_WORD *)(v14 + 76) = v35.Depth;
            *(_DWORD *)(v14 + 80) = v35.BlendMode;
            *(_BYTE *)(v14 + 84) = v35.Flags;
          }
          if ( v35.pFilters.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v35.pFilters.pObject);
          *(_OWORD *)&v35.ButtonMatrix.M[0][0] = _xmm;
          *(__m128 *)&v35.ButtonMatrix.M[1][0] = _xmm;
          Scaleform::Render::Cxform::Cxform(&v35.ButtonCxform);
          v35.pFilters.pObject = 0i64;
          v35.CharacterId.Id = 0x40000;
          v35.Flags = 0;
          v4 = v36;
        }
        while ( Scaleform::GFx::ButtonRecord::Read(&v35, v3, Tag_ButtonCharacter) );
      }
      if ( v35.pFilters.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v35.pFilters.pObject);
      if ( !(v3->pLoadData.pObject->FileAttributes & 8) )
      {
        v16 = v3->pLoadStates.pObject->pAS2Support.pObject;
        if ( v16 )
        {
          ((void (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::ButtonDef *, signed __int64, signed __int64, signed __int64))v16->vfptr[13].__vecDelDtor)(
            v16,
            v3,
            v4,
            7i64,
            -2i64,
            v34);
          return;
        }
        goto LABEL_27;
      }
LABEL_59:
      v17 = "GFx_ButtonLoader - AS3 Button shouldnt have AS2 actions. Skipped.";
      goto LABEL_60;
    case 17:
      Scaleform::GFx::SkipButtonSoundDef(p);
      return;
    case 34:
      this->Menu = Scaleform::GFx::LoadProcess::ReadU8(p) != 0;
      v18 = Scaleform::GFx::LoadProcess::ReadU16(v3);
      v19 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
      if ( !v19 )
        v19 = &v3->ProcessInfo;
      v20 = v19->Stream.Pos + v19->Stream.FilePos - v19->Stream.DataSize;
      v21 = v20 + v18 - 2;
      v37 = v20 + v18 - 2;
      *(_OWORD *)&v35.ButtonMatrix.M[0][0] = _xmm;
      *(__m128 *)&v35.ButtonMatrix.M[1][0] = _xmm;
      Scaleform::Render::Cxform::Cxform(&v35.ButtonCxform);
      v35.pFilters.pObject = 0i64;
      v35.CharacterId.Id = 0x40000;
      v35.Flags = 0;
      if ( Scaleform::GFx::ButtonRecord::Read(&v35, v3, Tag_ButtonCharacter2) )
      {
        v22 = (Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *)&v4->ButtonRecords.Data.Data;
        do
        {
          v23 = 0;
          v24 = v4->ButtonRecords.Data.Size;
          if ( v24 )
          {
            v25 = 0i64;
            do
            {
              if ( v22->Data[v25].Depth > v35.Depth )
                break;
              v25 = ++v23;
            }
            while ( v23 < v24 );
          }
          v26 = v23;
          v27 = v22->Size;
          Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            v22,
            v22,
            v27 + 1);
          if ( v27 + 1 > v27 )
            Scaleform::ConstructorMov<Scaleform::GFx::ButtonRecord>::ConstructArray(&v22->Data[v27], 1ui64);
          v28 = v22->Size;
          if ( v26 < v28 - 1 )
            memmove(&v22->Data[v26 + 1], &v22->Data[v26], 96 * (v28 - v26 - 1));
          v29 = v26;
          v30 = &v22->Data[v29] == 0;
          v31 = &v22->Data[v29];
          v34 = (signed __int64)v31;
          if ( !v30 )
          {
            *(_OWORD *)&v31->ButtonMatrix.M[0][0] = *(_OWORD *)&v35.ButtonMatrix.M[0][0];
            *(_OWORD *)&v31->ButtonMatrix.M[1][0] = *(_OWORD *)&v35.ButtonMatrix.M[1][0];
            *(_OWORD *)&v31->ButtonCxform.M[0][0] = *(_OWORD *)&v35.ButtonCxform.M[0][0];
            *(_OWORD *)&v31->ButtonCxform.M[1][0] = *(_OWORD *)&v35.ButtonCxform.M[1][0];
            v32 = v35.pFilters.pObject;
            if ( v35.pFilters.pObject )
            {
              Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v35.pFilters.pObject);
              v32 = v35.pFilters.pObject;
            }
            v31->pFilters.pObject = v32;
            v31->CharacterId.Id = v35.CharacterId.Id;
            v31->Depth = v35.Depth;
            v31->BlendMode = v35.BlendMode;
            v31->Flags = v35.Flags;
          }
          if ( v35.pFilters.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v35.pFilters.pObject);
          *(_OWORD *)&v35.ButtonMatrix.M[0][0] = _xmm;
          *(__m128 *)&v35.ButtonMatrix.M[1][0] = _xmm;
          Scaleform::Render::Cxform::Cxform(&v35.ButtonCxform);
          v35.pFilters.pObject = 0i64;
          v35.CharacterId.Id = 0x40000;
          v35.Flags = 0;
          v4 = v36;
        }
        while ( Scaleform::GFx::ButtonRecord::Read(&v35, v3, Tag_ButtonCharacter2) );
        v21 = v37;
      }
      if ( v35.pFilters.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v35.pFilters.pObject);
      if ( v18 > 0 )
      {
        if ( v3->pLoadData.pObject->FileAttributes & 8 )
          goto LABEL_59;
        if ( !v3->pLoadStates.pObject->pAS2Support.pObject )
        {
LABEL_27:
          v17 = "GFx_ButtonLoader - AS2 support is not installed. Actions are skipped.";
LABEL_60:
          Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
            (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&v3->vfptr,
            v17);
          return;
        }
        v33 = v3->pAltStream;
        if ( !v33 )
          v33 = &v3->ProcessInfo.Stream;
        Scaleform::GFx::Stream::SetPosition(v33, v21);
        ((void (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::ButtonDef *, signed __int64, signed __int64, signed __int64))v3->pLoadStates.pObject->pAS2Support.pObject->vfptr[14].__vecDelDtor)(
          v3->pLoadStates.pObject->pAS2Support.pObject,
          v3,
          v4,
          34i64,
          -2i64,
          v34);
      }
      break;
  }
}

// File Line: 279
// RVA: 0x8B03F0
void __fastcall Scaleform::GFx::ButtonDef::AddButtonAction(Scaleform::GFx::ButtonDef *this, Scaleform::GFx::ButtonActionBase *act)
{
  Scaleform::GFx::Resource *v2; // rdi
  Scaleform::GFx::ButtonDef *v3; // rbx
  _QWORD *v4; // rbx

  v2 = (Scaleform::GFx::Resource *)act;
  v3 = this;
  if ( act )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)act);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy> *)&v3->ButtonActions.Data.Data,
    &v3->ButtonActions,
    v3->ButtonActions.Data.Size + 1);
  v4 = &v3->ButtonActions.Data.Data[v3->ButtonActions.Data.Size - 1].pObject;
  if ( v4 )
  {
    if ( v2 )
      Scaleform::Render::RenderBuffer::AddRef(v2);
    *v4 = v2;
  }
  if ( v2 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v2);
}

