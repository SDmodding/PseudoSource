// File Line: 35
// RVA: 0x8F5FB0
char __fastcall Scaleform::GFx::ButtonRecord::Read(
        Scaleform::GFx::ButtonRecord *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 Pos; // rdx
  char v8; // cl
  char v9; // r14
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rbx
  Scaleform::GFx::SWFProcessInfo *v12; // rbp
  __int64 v13; // r9
  unsigned __int16 v14; // r8
  Scaleform::GFx::SWFProcessInfo *v15; // rbp
  __int64 v16; // r10
  unsigned __int16 v17; // r9
  __int64 v18; // rcx
  Scaleform::Render::FilterSet *v19; // rax
  Scaleform::GFx::Resource *v20; // rax
  Scaleform::GFx::Resource *v21; // rsi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  __int64 v23; // rdx
  unsigned __int8 v24; // r8
  unsigned __int8 v25; // dl

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  Pos = pAltStream->Stream.Pos;
  v8 = pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  v9 = v8;
  if ( !v8 )
    return 0;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "-- action record:  ");
  this->Flags = 0;
  if ( (v9 & 8) != 0 )
  {
    this->Flags = 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "HitTest ");
  }
  if ( (v9 & 4) != 0 )
  {
    this->Flags |= 2u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "Down ");
  }
  if ( (v9 & 2) != 0 )
  {
    this->Flags |= 4u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "Over ");
  }
  if ( (v9 & 1) != 0 )
  {
    this->Flags |= 8u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "Up ");
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "\n");
  v12 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v12 )
    v12 = &p->ProcessInfo;
  v12->Stream.UnusedBits = 0;
  if ( (signed int)(v12->Stream.DataSize - v12->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v12->Stream, 2);
  v13 = v12->Stream.Pos;
  v14 = (unsigned __int8)v12->Stream.pBuffer[v13] | ((unsigned __int8)v12->Stream.pBuffer[(unsigned int)(v13 + 1)] << 8);
  v12->Stream.Pos = v13 + 2;
  this->CharacterId.Id = v14;
  v15 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v15 )
    v15 = &p->ProcessInfo;
  v15->Stream.UnusedBits = 0;
  if ( (signed int)(v15->Stream.DataSize - v15->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v15->Stream, 2);
  v16 = v15->Stream.Pos;
  v17 = (unsigned __int8)v15->Stream.pBuffer[v16] | ((unsigned __int8)v15->Stream.pBuffer[(unsigned int)(v16 + 1)] << 8);
  v15->Stream.Pos = v16 + 2;
  this->Depth = v17;
  Scaleform::GFx::Stream::ReadMatrix(&p_ProcessInfo->Stream, &this->ButtonMatrix);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "   CharId = %d, Depth = %d\n");
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "   mat:\n");
  if ( tagType == Tag_ButtonCharacter2 )
  {
    Scaleform::GFx::Stream::ReadCxformRgba(&p_ProcessInfo->Stream, &this->ButtonCxform);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "   cxform:\n");
  }
  if ( (v9 & 0x10) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "   HasFilters\n");
    v19 = (Scaleform::Render::FilterSet *)((__int64 (__fastcall *)(__int64, __int64))p->pLoadData.pObject->pHeap->vfptr->Alloc)(
                                            v18,
                                            56i64);
    if ( v19 )
    {
      Scaleform::Render::FilterSet::FilterSet(v19, 0i64);
      v21 = v20;
    }
    else
    {
      v21 = 0i64;
    }
    if ( (unsigned int)Scaleform::GFx::LoadFilters<Scaleform::GFx::Stream>(
                         &p_ProcessInfo->Stream,
                         (Scaleform::Render::FilterSet *)v21) )
    {
      if ( v21 )
        Scaleform::Render::RenderBuffer::AddRef(v21);
      pObject = (Scaleform::Render::RenderBuffer *)this->pFilters.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      this->pFilters.pObject = (Scaleform::Render::FilterSet *)v21;
    }
    if ( v21 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v21);
  }
  if ( (v9 & 0x20) != 0 )
  {
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 1);
    v23 = p_ProcessInfo->Stream.Pos;
    v24 = p_ProcessInfo->Stream.pBuffer[v23];
    p_ProcessInfo->Stream.Pos = v23 + 1;
    v25 = v24;
    if ( (unsigned __int8)(v24 - 1) > 0xDu )
      v25 = 1;
    this->BlendMode = v25;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&p_ProcessInfo->Stream, "   HasBlending, %d\n");
  }
  else
  {
    this->BlendMode = Blend_None;
  }
  return 1;
}

// File Line: 134
// RVA: 0x8A35C0
void __fastcall Scaleform::GFx::ButtonDef::~ButtonDef(Scaleform::GFx::ButtonDef *this)
{
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ButtonDef::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pScale9Grid);
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayData<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ButtonActions);
  Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>(&this->ButtonRecords.Data);
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::CharacterDef::`vftable;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 142
// RVA: 0x910960
void __fastcall Scaleform::GFx::SkipButtonSoundDef(Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  __int64 v3; // r15
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rdi
  unsigned int DataSize; // eax
  __int64 Pos; // r9
  __int16 v7; // r8
  bool v8; // bp
  bool v9; // si
  bool v10; // di
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  __int64 v15; // rdx
  int v16; // ecx
  __int64 v17; // rdi
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = 4i64;
  do
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    DataSize = p_ProcessInfo->Stream.DataSize;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( (int)(DataSize - p_ProcessInfo->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
    Pos = p_ProcessInfo->Stream.Pos;
    v7 = (unsigned __int8)p_ProcessInfo->Stream.pBuffer[Pos] | ((unsigned __int8)p_ProcessInfo->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
    p_ProcessInfo->Stream.Pos = Pos + 2;
    if ( v7 )
    {
      Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 2);
      Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
      Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
      v8 = (unsigned int)Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
      v9 = (unsigned int)Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
      v10 = (unsigned int)Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
      if ( (unsigned int)Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
      {
        v11 = pAltStream->Stream.DataSize;
        pAltStream->Stream.UnusedBits = 0;
        if ( (int)(v11 - pAltStream->Stream.Pos) < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
        pAltStream->Stream.Pos += 4;
      }
      if ( v10 )
      {
        v12 = pAltStream->Stream.DataSize;
        pAltStream->Stream.UnusedBits = 0;
        if ( (int)(v12 - pAltStream->Stream.Pos) < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
        pAltStream->Stream.Pos += 4;
      }
      if ( v9 )
      {
        v13 = pAltStream->Stream.DataSize;
        pAltStream->Stream.UnusedBits = 0;
        if ( (int)(v13 - pAltStream->Stream.Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        pAltStream->Stream.Pos += 2;
      }
      if ( v8 )
      {
        v14 = pAltStream->Stream.DataSize;
        pAltStream->Stream.UnusedBits = 0;
        if ( (int)(v14 - pAltStream->Stream.Pos) < 1 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
        v15 = pAltStream->Stream.Pos;
        v16 = (unsigned __int8)pAltStream->Stream.pBuffer[v15];
        pAltStream->Stream.Pos = v15 + 1;
        if ( v16 > 0 )
        {
          v17 = (unsigned int)v16;
          do
          {
            v18 = pAltStream->Stream.DataSize;
            pAltStream->Stream.UnusedBits = 0;
            if ( (int)(v18 - pAltStream->Stream.Pos) < 4 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
            pAltStream->Stream.Pos += 4;
            v19 = pAltStream->Stream.DataSize;
            pAltStream->Stream.UnusedBits = 0;
            if ( (int)(v19 - pAltStream->Stream.Pos) < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            pAltStream->Stream.Pos += 2;
            v20 = pAltStream->Stream.DataSize;
            pAltStream->Stream.UnusedBits = 0;
            if ( (int)(v20 - pAltStream->Stream.Pos) < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            pAltStream->Stream.Pos += 2;
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
void __fastcall Scaleform::GFx::ButtonDef::Read(
        Scaleform::GFx::ButtonDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::ButtonDef *v4; // rsi
  Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *p_Data; // r15
  unsigned int v6; // ecx
  unsigned __int64 Size; // rdx
  __int64 v8; // rax
  unsigned __int64 v9; // r12
  unsigned __int64 v10; // r14
  __int64 v11; // rbx
  __int64 v12; // rsi
  unsigned __int64 v13; // r8
  __int64 v14; // rbx
  Scaleform::Render::FilterSet *pObject; // rax
  Scaleform::GFx::ASSupport *v16; // rcx
  int U16; // r12d
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rcx
  int v19; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *v20; // r15
  unsigned int v21; // ecx
  unsigned __int64 v22; // rdx
  __int64 v23; // rax
  unsigned __int64 v24; // rbx
  unsigned __int64 v25; // r14
  unsigned __int64 v26; // r8
  __int64 v27; // rbx
  bool v28; // zf
  Scaleform::GFx::ButtonRecord *v29; // rbx
  Scaleform::Render::FilterSet *v30; // rax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // rcx
  __int64 v32; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::ButtonRecord v33; // [rsp+30h] [rbp-39h] BYREF
  int v35; // [rsp+E0h] [rbp+77h]

  v4 = this;
  switch ( tagType )
  {
    case Tag_ButtonCharacter:
      *(_OWORD *)&v33.ButtonMatrix.M[0][0] = _xmm;
      *(__m128 *)&v33.ButtonMatrix.M[1][0] = _xmm;
      Scaleform::Render::Cxform::Cxform(&v33.ButtonCxform);
      v33.pFilters.pObject = 0i64;
      v33.CharacterId.Id = 0x40000;
      v33.Flags = 0;
      if ( Scaleform::GFx::ButtonRecord::Read(&v33, p, Tag_ButtonCharacter) )
      {
        p_Data = &v4->ButtonRecords.Data;
        do
        {
          v6 = 0;
          Size = v4->ButtonRecords.Data.Size;
          if ( Size )
          {
            v8 = 0i64;
            do
            {
              if ( p_Data->Data[v8].Depth > v33.Depth )
                break;
              v8 = ++v6;
            }
            while ( v6 < Size );
          }
          v9 = v6;
          v10 = p_Data->Size;
          Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            p_Data,
            p_Data,
            v10 + 1);
          if ( v10 + 1 > v10 )
          {
            v11 = (__int64)&p_Data->Data[v10];
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
          v13 = p_Data->Size;
          if ( v9 < v13 - 1 )
            memmove(&p_Data->Data[v9 + 1], &p_Data->Data[v9], 96 * (v13 - v9 - 1));
          v14 = (__int64)&p_Data->Data[v9];
          v32 = v14;
          if ( v14 )
          {
            *(_OWORD *)v14 = *(_OWORD *)&v33.ButtonMatrix.M[0][0];
            *(_OWORD *)(v14 + 16) = *(_OWORD *)&v33.ButtonMatrix.M[1][0];
            *(Scaleform::Render::Cxform *)(v14 + 32) = v33.ButtonCxform;
            pObject = v33.pFilters.pObject;
            if ( v33.pFilters.pObject )
            {
              Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v33.pFilters.pObject);
              pObject = v33.pFilters.pObject;
            }
            *(_QWORD *)(v14 + 64) = pObject;
            *(_DWORD *)(v14 + 72) = v33.CharacterId.Id;
            *(_WORD *)(v14 + 76) = v33.Depth;
            *(_DWORD *)(v14 + 80) = v33.BlendMode;
            *(_BYTE *)(v14 + 84) = v33.Flags;
          }
          if ( v33.pFilters.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v33.pFilters.pObject);
          *(_OWORD *)&v33.ButtonMatrix.M[0][0] = _xmm;
          *(__m128 *)&v33.ButtonMatrix.M[1][0] = _xmm;
          Scaleform::Render::Cxform::Cxform(&v33.ButtonCxform);
          v33.pFilters.pObject = 0i64;
          v33.CharacterId.Id = 0x40000;
          v33.Flags = 0;
          v4 = this;
        }
        while ( Scaleform::GFx::ButtonRecord::Read(&v33, p, Tag_ButtonCharacter) );
      }
      if ( v33.pFilters.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v33.pFilters.pObject);
      if ( (p->pLoadData.pObject->FileAttributes & 8) == 0 )
      {
        v16 = p->pLoadStates.pObject->pAS2Support.pObject;
        if ( v16 )
        {
          ((void (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::ButtonDef *, __int64, __int64, __int64))v16->vfptr[13].__vecDelDtor)(
            v16,
            p,
            v4,
            7i64,
            -2i64,
            v32);
          return;
        }
        goto LABEL_27;
      }
      goto LABEL_59;
    case Tag_ButtonSound:
      Scaleform::GFx::SkipButtonSoundDef(p);
      return;
    case Tag_ButtonCharacter2:
      this->Menu = Scaleform::GFx::LoadProcess::ReadU8(p) != 0;
      U16 = Scaleform::GFx::LoadProcess::ReadU16(p);
      pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !pAltStream )
        pAltStream = &p->ProcessInfo;
      v19 = pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize + U16 - 2;
      v35 = v19;
      *(_OWORD *)&v33.ButtonMatrix.M[0][0] = _xmm;
      *(__m128 *)&v33.ButtonMatrix.M[1][0] = _xmm;
      Scaleform::Render::Cxform::Cxform(&v33.ButtonCxform);
      v33.pFilters.pObject = 0i64;
      v33.CharacterId.Id = 0x40000;
      v33.Flags = 0;
      if ( Scaleform::GFx::ButtonRecord::Read(&v33, p, Tag_ButtonCharacter2) )
      {
        v20 = &v4->ButtonRecords.Data;
        do
        {
          v21 = 0;
          v22 = v4->ButtonRecords.Data.Size;
          if ( v22 )
          {
            v23 = 0i64;
            do
            {
              if ( v20->Data[v23].Depth > v33.Depth )
                break;
              v23 = ++v21;
            }
            while ( v21 < v22 );
          }
          v24 = v21;
          v25 = v20->Size;
          Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            v20,
            v20,
            v25 + 1);
          if ( v25 + 1 > v25 )
            Scaleform::ConstructorMov<Scaleform::GFx::ButtonRecord>::ConstructArray((char *)&v20->Data[v25], 1ui64);
          v26 = v20->Size;
          if ( v24 < v26 - 1 )
            memmove(&v20->Data[v24 + 1], &v20->Data[v24], 96 * (v26 - v24 - 1));
          v27 = v24;
          v28 = &v20->Data[v27] == 0;
          v29 = &v20->Data[v27];
          v32 = (__int64)v29;
          if ( !v28 )
          {
            *(_OWORD *)&v29->ButtonMatrix.M[0][0] = *(_OWORD *)&v33.ButtonMatrix.M[0][0];
            *(_OWORD *)&v29->ButtonMatrix.M[1][0] = *(_OWORD *)&v33.ButtonMatrix.M[1][0];
            v29->ButtonCxform = v33.ButtonCxform;
            v30 = v33.pFilters.pObject;
            if ( v33.pFilters.pObject )
            {
              Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v33.pFilters.pObject);
              v30 = v33.pFilters.pObject;
            }
            v29->pFilters.pObject = v30;
            v29->CharacterId.Id = v33.CharacterId.Id;
            v29->Depth = v33.Depth;
            v29->BlendMode = v33.BlendMode;
            v29->Flags = v33.Flags;
          }
          if ( v33.pFilters.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v33.pFilters.pObject);
          *(_OWORD *)&v33.ButtonMatrix.M[0][0] = _xmm;
          *(__m128 *)&v33.ButtonMatrix.M[1][0] = _xmm;
          Scaleform::Render::Cxform::Cxform(&v33.ButtonCxform);
          v33.pFilters.pObject = 0i64;
          v33.CharacterId.Id = 0x40000;
          v33.Flags = 0;
          v4 = this;
        }
        while ( Scaleform::GFx::ButtonRecord::Read(&v33, p, Tag_ButtonCharacter2) );
        v19 = v35;
      }
      if ( v33.pFilters.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v33.pFilters.pObject);
      if ( U16 > 0 )
      {
        if ( (p->pLoadData.pObject->FileAttributes & 8) != 0 )
        {
LABEL_59:
          Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
            &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
            "GFx_ButtonLoader - AS3 Button shouldnt have AS2 actions. Skipped.");
          return;
        }
        if ( !p->pLoadStates.pObject->pAS2Support.pObject )
        {
LABEL_27:
          Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
            &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
            "GFx_ButtonLoader - AS2 support is not installed. Actions are skipped.");
          return;
        }
        p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !p_ProcessInfo )
          p_ProcessInfo = &p->ProcessInfo;
        Scaleform::GFx::Stream::SetPosition(&p_ProcessInfo->Stream, v19);
        ((void (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::ButtonDef *, __int64, __int64, __int64))p->pLoadStates.pObject->pAS2Support.pObject->vfptr[14].__vecDelDtor)(
          p->pLoadStates.pObject->pAS2Support.pObject,
          p,
          v4,
          34i64,
          -2i64,
          v32);
      }
      break;
  }
}

// File Line: 279
// RVA: 0x8B03F0
void __fastcall Scaleform::GFx::ButtonDef::AddButtonAction(
        Scaleform::GFx::ButtonDef *this,
        Scaleform::GFx::Resource *act)
{
  Scaleform::Ptr<Scaleform::GFx::ButtonActionBase> *v4; // rbx

  if ( act )
    Scaleform::Render::RenderBuffer::AddRef(act);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ButtonActions.Data,
    &this->ButtonActions,
    this->ButtonActions.Data.Size + 1);
  v4 = &this->ButtonActions.Data.Data[this->ButtonActions.Data.Size - 1];
  if ( v4 )
  {
    if ( act )
      Scaleform::Render::RenderBuffer::AddRef(act);
    v4->pObject = (Scaleform::GFx::ButtonActionBase *)act;
  }
  if ( act )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)act);
}

